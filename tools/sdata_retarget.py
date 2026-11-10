#!/usr/bin/env python3
"""Retarget a freshly-compiled function's gp-relative references to its private `.sdata` constants at
retail's copies in the shared .sdata -- the .sdata counterpart of tools/lit4_retarget.py (same reasoning,
same objcopy technique).

Why this is needed: MWCC emits the aggregate initialiser of a local array (`unsigned short sep[2] = {0x20, 0};`)
as an anonymous local object (`@NN`) in the object's own .sdata and copies it from there with $gp-relative
loads (R_MIPS_GPREL16, REL: the in-place immediate is the addend, e.g. `lh v0,2(gp)` = @NN+2). Retail's copy of
that template sits at a fixed address in the shared .sdata (still assembled from the asm data units, e.g.
D_004E1E88 in unit_003B8550.sdata). The ld script takes only each C object's .text and /DISCARD/s the rest, so
linking the object unchanged leaves the reference "defined in discarded section".

The fix, for a function whose retail address we know:
  1. for every R_MIPS_GPREL16 in .rel.text against a LOCAL symbol defined in .sdata, decode retail's
     instruction at the same offset (must be a $gp access) -> retail address; minus our in-place addend ->
     retail's base for the symbol; every reference to one symbol must agree on that base;
  2. verify the retail rom bytes at that base equal the symbol's bytes in our object (its whole size);
  3. rename `@NN` to `sdata_XXXXXXXX`, make it global + weak, and write `sdata_XXXXXXXX = 0xXXXXXXXX;` to the
     defs file, so the strong absolute definition is what the link uses (exactly as lit4_retarget).
Anything else parks (UNSUPPORTED): a global .sdata symbol (a real variable other objects name), relocations in or
against .sdata other than GPREL16 from .text (.rel.sdata pointer initialisers, %hi/%lo), section-symbol refs.

.sbss (near1, 2026-11-01): a function-local static (Revenge's `static RwInt32 lnRotate` in PresentDrawBuffer) is a
LOCAL zero-initialised object in the object's own .sbss, reached the same way (GPREL16). Retail's copy is a .sbss
dlabel in the asm data units (D_004E294C in unit_00222C90.sbss.s): the same base computation, then instead of the byte
check the base must be a `dlabel` of an asm .sbss data unit whose `nonmatching D_X, size` equals the symbol's size;
renamed `sbss_XXXXXXXX` (weak) with the absolute definition in the defs file, exactly as for .sdata.

Usage: sdata_retarget.py <object.o> <retail_rom> <defs_out.txt> <function_name>=0xVRAM [--apply]
"""
import glob
import re
import struct
import subprocess
import sys

GP_VALUE = 0x4E8670   # same as lit4_retarget.py
ROM_BASE = 0x100000   # vram of rom offset 0


def run(*args):
    return subprocess.run(list(args), capture_output=True, text=True, check=True).stdout


def sections(obj):
    """index -> (name, file offset)"""
    out = {}
    for line in run("mips-linux-gnu-readelf", "-SW", obj).splitlines():
        m = re.match(r"^\s*\[\s*(\d+)\]\s+(\S+)\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)", line)
        if m:
            out[int(m.group(1))] = (m.group(2), int(m.group(3), 16))
    return out


def symbols(obj):
    """name -> (value, size, type, bind, ndx); MWCC's binding-13 symbols print two extra fields, so Ndx/Name are
    taken from the end."""
    syms = {}
    for line in run("mips-linux-gnu-readelf", "-sW", obj).splitlines():
        p = line.split()
        if len(p) >= 8 and p[0].rstrip(":").isdigit():
            syms[p[-1]] = (int(p[1], 16), int(p[2], 0), p[3], p[4], p[-2])
    return syms


def relocs(obj):
    """section name -> [(offset, type, symbol)]"""
    out, cur = {}, None
    for line in run("mips-linux-gnu-readelf", "-rW", obj).splitlines():
        m = re.match(r"^Relocation section '([^']+)'", line)
        if m:
            cur = m.group(1)
            out.setdefault(cur, [])
            continue
        p = line.split()
        if cur and len(p) >= 5 and re.fullmatch(r"[0-9a-f]{8}", p[0]):
            out[cur].append((int(p[0], 16), p[2], p[4]))
    return out


def sbss_labels():
    """vram -> size of every dlabel in the asm .sbss data units (`nonmatching D_X, 0xN` gives the size)."""
    out = {}
    for f in glob.glob("assembly/asm/data/**/*.sbss.s", recursive=True):
        for m in re.finditer(r"^nonmatching D_([0-9A-F]{8}), (0x[0-9A-Fa-f]+|\d+)", open(f).read(), re.M):
            out[int(m.group(1), 16)] = int(m.group(2), 0)
    return out


def main():
    obj, rom_path, defs_out, func_arg = sys.argv[1:5]
    apply_ = "--apply" in sys.argv
    func, func_addr = func_arg.split("=")
    func_addr = int(func_addr, 16)
    rom = open(rom_path, "rb").read()
    raw = open(obj, "rb").read()

    secs = sections(obj)
    sdata = {str(i) for i, (n, _) in secs.items() if n in (".sdata", ".sbss")}
    nobits = {str(i) for i, (n, _) in secs.items() if n == ".sbss"}
    if not sdata:
        print("No .sdata section.")
        return
    syms = symbols(obj)
    rels = relocs(obj)
    fsym = syms.get(func)
    if not fsym or fsym[2] != "FUNC" or fsym[0] != 0:
        raise SystemExit(f"{func}: not a FUNC at the start of its section in {obj}")
    text_ndx = fsym[4]
    text_off = secs[int(text_ndx)][1]
    in_sdata = {n: s for n, s in syms.items() if s[4] in sdata and s[2] != "SECTION"}

    bad = []
    for rs, lst in rels.items():
        if rs in (".rel.sdata", ".rel.sbss") and lst:
            bad.append(".rel.sdata (pointer initialiser)")
        for o, t, s in lst:
            if s in (".sdata", ".sbss"):
                bad.append(f"{rs}+{o:#x} {t} against the .sdata section symbol")
            elif s in in_sdata and (rs != ".rel.text" or t != "R_MIPS_GPREL16"):
                bad.append(f"{rs}+{o:#x} {t} {s}")
    for n, s in in_sdata.items():
        if s[3] != "LOCAL":
            bad.append(f"{n} is {s[3]} (a variable other objects may name)")
    if bad:
        for b in bad:
            print(f"UNSUPPORTED: {b}")
        return

    refs = [(o, s) for o, t, s in rels.get(".rel.text", []) if t == "R_MIPS_GPREL16" and s in in_sdata]
    if not refs:
        print("No .sdata references from .text.")
        return
    base = {}
    mism = 0
    for o, s in refs:
        if o >= fsym[1]:
            raise SystemExit(f"{s}: reference at {o:#x} is outside {func} (size {fsym[1]:#x})")
        w = struct.unpack_from("<I", rom, func_addr + o - ROM_BASE)[0]
        ours = struct.unpack_from("<I", raw, text_off + o)[0]
        if (w >> 21) & 31 != 28:
            print(f"{s} @+{o:#x}: retail {w:#010x} is not a $gp access  [MISMATCH: the instructions differ here]")
            mism += 1
            continue
        sx = lambda v: v - 0x10000 if v & 0x8000 else v
        tgt = (GP_VALUE + sx(w & 0xFFFF)) & 0xFFFFFFFF
        b = tgt - sx(ours & 0xFFFF)          # REL addend in place
        if base.setdefault(s, b) != b:
            print(f"{s} @+{o:#x}: retail base {b:#x} != {base[s]:#x} from its first reference  [MISMATCH]")
            mism += 1
    renames = []
    sbss = None
    for s, b in base.items():
        value, size = in_sdata[s][0], in_sdata[s][1]
        if in_sdata[s][4] in nobits:
            if sbss is None:
                sbss = sbss_labels()
            ok = sbss.get(b) == size
            print(f"{s}: {size} byte(s) .sbss, retail @ {b:#x}  [{'OK' if ok else 'MISMATCH'}: retail .sbss dlabel "
                  f"size {sbss.get(b)}]")
            if not ok:
                mism += 1
                continue
            renames.append((s, f"sbss_{b:08X}", b))
            continue
        ours = raw[secs[int(in_sdata[s][4])][1] + value:][:size]
        theirs = rom[b - ROM_BASE: b - ROM_BASE + size]
        ok = len(theirs) == size and ours == theirs
        print(f"{s}: {size} byte(s), retail @ {b:#x}  [{'OK' if ok else 'MISMATCH'}: object .sdata={ours.hex()} "
              f"retail={theirs.hex() or '(past the rom image: .sbss)'}]")
        if not ok:
            mism += 1
            continue
        renames.append((s, f"sdata_{b:08X}", b))
    if mism:
        print(f"{mism} MISMATCH(ES); object left unchanged")
        return
    # rewrite only after every symbol has been checked (the jtbl_retarget lesson, N211)
    if apply_:
        for s, new, _ in renames:
            run("mips-linux-gnu-objcopy", f"--redefine-sym={s}={new}", obj)
            run("mips-linux-gnu-objcopy", f"--globalize-symbol={new}", f"--weaken-symbol={new}", obj)
            print(f"  -> redefined {s} to {new} (weak) in {obj}")
        existing = set()
        try:
            with open(defs_out) as f:
                existing = {l.split("=")[0].strip() for l in f if "=" in l}
        except FileNotFoundError:
            pass
        with open(defs_out, "a") as f:
            for _, new, b in renames:
                if new not in existing:
                    f.write(f"{new} = 0x{b:08X};\n")
        print(f"{len(renames)} .sdata symbol(s) retargeted; definitions in {defs_out}")
    else:
        print("(dry run -- pass --apply to modify the object and write definitions)")


if __name__ == "__main__":
    main()
