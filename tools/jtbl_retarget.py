#!/usr/bin/env python3
"""Retarget a freshly-compiled function's switch jump table at retail's own table -- the jump-table
counterpart of tools/lit4_retarget.py (same reasoning, same objcopy technique).

Why this is needed: CodeWarrior emits each switch's jump table as a local object (`@NNN`) in the
compiled object's own .rodata, loaded with a lui/addiu (R_MIPS_HI16/LO16) pair. Retail's copy of that
table lives in the shared .rodata region at a fixed address, still assembled from the asm data units,
and its entries refer to the case labels (`.LXXXXXXXX`, global jlabels) of the asm function we are
replacing. Linking our object unchanged would place no table (the ld script only takes .text) and
leave retail's table pointing at labels that no longer exist.

The fix, for a function whose retail address we know:
  1. decode retail's lui/addiu at the same offsets as our HI16/LO16 pair -> retail table address;
  2. verify every retail table word equals function address + our table's matching entry (our
     entries are R_MIPS_32 against the function symbol, addend in place) -- the tables must agree;
  3. rename `@NNN` to `jtbl_XXXXXXXX` and make it global + weak, so the strong global of that name the
     asm .rodata unit already defines is what the link uses;
  4. write `.LXXXXXXXX = 0xXXXXXXXX;` definitions for every case label retail's table refers to, and
     `jtbl_XXXXXXXX = 0xXXXXXXXX;` for the table (retail may not label it: gif6, func_0030F620).

Usage: jtbl_retarget.py <object.o> <retail_rom> <defs_out.txt> <function_name>=0xVRAM [--apply]
"""
import re
import struct
import subprocess
import sys

ROM_BASE = 0x100000  # vram of rom offset 0 (same as lit4_retarget.py)


def run(*args):
    return subprocess.run(list(args), capture_output=True, text=True, check=True).stdout


def symbols(obj):
    syms = {}
    for line in run("mips-linux-gnu-readelf", "-sW", obj).splitlines():
        p = line.split()
        if len(p) >= 8 and p[0].rstrip(":").isdigit():
            syms[p[7]] = (int(p[1], 16), int(p[2], 0), p[3], p[6])   # readelf prints large sizes as 0x... (a258)
    return syms


def relocs(obj, section):
    """(offset, type, symbol) for each relocation in `section` (e.g. '.rel.text')."""
    out, cur = [], None
    for line in run("mips-linux-gnu-readelf", "-rW", obj).splitlines():
        m = re.match(r"^Relocation section '([^']+)'", line)
        if m:
            cur = m.group(1)
            continue
        p = line.split()
        if cur == section and len(p) >= 5 and re.fullmatch(r"[0-9a-f]{8}", p[0]):
            out.append((int(p[0], 16), p[2], p[4]))
    return out


def section_bytes(obj, shndx):
    data = b""
    for line in run("mips-linux-gnu-readelf", "-x", str(shndx), obj).splitlines():
        m = re.match(r"^\s*0x[0-9a-f]+\s+((?:[0-9a-f]{2,8}\s+){1,4})", line)
        if m:
            data += bytes.fromhex("".join(m.group(1).split()))
    return data


def main():
    obj, rom_path, defs_out, func_arg = sys.argv[1:5]
    apply_ = "--apply" in sys.argv
    func, func_addr = func_arg.split("=")
    func_addr = int(func_addr, 16)
    rom = open(rom_path, "rb").read()
    word = lambda vram: struct.unpack_from("<I", rom, vram - ROM_BASE)[0]

    syms = symbols(obj)
    text_relocs = relocs(obj, ".rel.text")
    tables = sorted({s for _, t, s in text_relocs if t in ("R_MIPS_HI16", "R_MIPS_LO16")
                     and s.startswith("@") and syms.get(s, (0, 0, ""))[2] == "OBJECT"})
    if not tables:
        print("No jump-table references found.")
        return

    defs = []
    renames = []
    for tab in tables:
        value, size, _, shndx = syms[tab]
        hi = [o for o, t, s in text_relocs if s == tab and t == "R_MIPS_HI16"]
        lo = [o for o, t, s in text_relocs if s == tab and t == "R_MIPS_LO16"]
        if len(hi) != 1 or len(lo) != 1:
            raise SystemExit(f"{tab}: expected one HI16/LO16 pair, got {len(hi)}/{len(lo)}")
        hi_imm = word(func_addr + hi[0]) & 0xFFFF
        lo_imm = word(func_addr + lo[0]) & 0xFFFF
        if lo_imm & 0x8000:
            lo_imm -= 0x10000
        target = ((hi_imm << 16) + lo_imm) & 0xFFFFFFFF

        ours = section_bytes(obj, int(shndx))[value:value + size]
        entries = struct.unpack(f"<{size // 4}I", ours)
        rodata_relocs = {o: s for o, t, s in relocs(obj, ".rel.rodata") if t == "R_MIPS_32"}
        bad = 0
        for i, addend in enumerate(entries):
            if rodata_relocs.get(value + 4 * i) != func:
                raise SystemExit(f"{tab}[{i}]: entry is not relocated against {func}")
            ok = word(target + 4 * i) == func_addr + addend
            bad += not ok
            if not ok:
                print(f"  {tab}[{i}]: ours {func_addr + addend:#x}, retail {word(target + 4 * i):#x}  MISMATCH")
        print(f"{tab}: {len(entries)} entries, retail table @ {target:#x}: "
              f"{'OK' if not bad else f'{bad} MISMATCH(ES)'}")
        if bad:
            continue
        new = f"jtbl_{target:08X}"
        # define the table symbol itself too: retail may not label it (gif6: func_0030F620's table is raw .words inside
        # maOffsetTable__14CB3MenuFlowFSM at +0x400), and then the weak jtbl_ in our discarded .rodata would win; the
        # assignment carries retail's own (verified) address, so it is a no-op where an asm unit defines the label
        defs.append((new, target))
        for addr in sorted({func_addr + a for a in entries}):
            defs.append((f".L{addr:08X}", addr))
        renames.append((tab, new))
    # rewrite the object only after every table has been checked: objcopy on the first table changed what the
    # second table's check read back, so every function with 2+ tables parked although exact (L264: SFIOProcessCallback,
    # func_0043FFB0, func_003EDFD0 -- dry run OK, --apply MISMATCH)
    if apply_:
        for tab, new in renames:
            run("mips-linux-gnu-objcopy", f"--redefine-sym={tab}={new}", obj)
            run("mips-linux-gnu-objcopy", f"--globalize-symbol={new}", f"--weaken-symbol={new}", obj)
            print(f"  -> redefined {tab} to {new} (weak) in {obj}")

    if defs and apply_:
        existing = set()
        try:
            with open(defs_out) as f:
                existing = {l.split("=")[0].strip() for l in f if "=" in l}
        except FileNotFoundError:
            pass
        with open(defs_out, "a") as f:
            for sym, addr in defs:
                if sym not in existing:
                    f.write(f"{sym} = 0x{addr:08X};\n")
        print(f"{len(defs)} case label(s) defined in {defs_out}")
    if not apply_:
        print("(dry run -- pass --apply to modify the object and write definitions)")


if __name__ == "__main__":
    main()
