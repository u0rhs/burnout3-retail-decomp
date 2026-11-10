#!/usr/bin/env python3
"""Retarget R_MIPS_LITERAL relocations in a freshly-compiled object at the real, shared retail
.lit4 pool, instead of the object's own private .lit4 copy -- a fresh reimplementation of the
*technique* the earlier research repo's tools/litfix.py comment describes, not a copy of that script.

Why this is needed: CodeWarrior puts every float constant it can't build with `lui` into a private
`.lit4` section per compiled object and loads it via an R_MIPS_LITERAL relocation. The real retail
binary pools all such literals into ONE shared .lit4 region (built once, in original link order,
across the whole game) -- an object compiled today has no way to reproduce that order, so its own
.lit4 entry is not the one the final binary actually uses. Linking the object directly makes the
relocation's local symbol unresolvable once nothing else needs that private section ("defined in
discarded section").

The fix: for a relocation inside a function whose retail address we already know (i.e. we are
re-verifying an already-matched function, which is the only case this build process substitutes
objects for), the real compiled retail instruction at that same offset already encodes the correct
$gp-relative offset to the real shared pool entry. Decode it directly from the retail rom, verify the
literal value still matches, then redirect the relocation (via `objcopy --redefine-sym`) at a new
absolute-value symbol placed at that address, and record the symbol's definition for the linker.

Usage: lit4_retarget.py <object.o> <retail_rom> <defs_out.txt> [--apply] [--addr NAME=0xVRAM ...]
(--addr: retail VRAM for a function our symbol tables only know by its func_XXXXXXXX placeholder)
Requires GP_VALUE and the object's function names to resolve via config/symbol_addrs_b3names.txt
(or config/symbol_addrs.txt) for their retail VRAM.
"""
import re
import struct
import subprocess
import sys

GP_VALUE = 0x4E8670
SYMBOL_FILES = ["config/symbol_addrs_b3names.txt", "config/symbol_addrs.txt"]


def load_symbol_addrs():
    addrs = {}
    for path in SYMBOL_FILES:
        try:
            f = open(path)
        except FileNotFoundError:
            continue
        with f:
            for line in f:
                m = re.match(r"^([A-Za-z_][\w@$]*)\s*=\s*0x([0-9A-Fa-f]+)", line)
                if m:
                    addrs.setdefault(m.group(1), int(m.group(2), 16))
    return addrs


def objdump(args):
    return subprocess.run(["mips-linux-gnu-objdump", *args], capture_output=True, text=True, check=True).stdout


def find_literal_relocs(obj):
    """Yield (function_name, offset_within_function, local_symbol) for each R_MIPS_LITERAL."""
    out = objdump(["-dr", obj])
    cur_func = None
    cur_func_start = None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <([^>]+)>:", line)
        if m:
            cur_func = m.group(1)
            continue
        m = re.match(r"^\s*([0-9a-f]+):.*$", line)
        # relocation lines look like: "\t0:\tR_MIPS_LITERAL\t@214"
        m2 = re.match(r"^\s*([0-9a-f]+):\s+R_MIPS_LITERAL\s+(\S+)", line)
        if m2 and cur_func:
            off = int(m2.group(1), 16)
            yield cur_func, off, m2.group(2)


def lit4_value_in_object(obj, local_symbol):
    """The 4 bytes `local_symbol` labels. CodeWarrior emits one separate .lit4 section per literal (all
    named ".lit4"), so the symbol's own section index has to be resolved -- reading "the" .lit4 section
    only ever sees the first literal (fine for Gt2dFont's single one, wrong once there are several)."""
    shndx = value = None
    out = subprocess.run(["mips-linux-gnu-readelf", "-sW", obj], capture_output=True, text=True, check=True).stdout
    for line in out.splitlines():
        parts = line.split()
        # Num: Value Size Type Bind Vis Ndx Name
        if len(parts) >= 8 and parts[7] == local_symbol and parts[6].isdigit():
            value, shndx = int(parts[1], 16), int(parts[6])
            break
    if shndx is None:
        raise SystemExit(f"{local_symbol}: not found in {obj}'s symbol table")
    out = subprocess.run(["mips-linux-gnu-readelf", "-x", str(shndx), obj],
                         capture_output=True, text=True, check=True).stdout
    data = b""
    for line in out.splitlines():
        m = re.match(r"^\s*0x[0-9a-f]+\s+((?:[0-9a-f]{2,8}\s+){1,4})", line)
        if m:
            data += bytes.fromhex("".join(m.group(1).split()))
    return data[value:value + 4]


def patch_addend(obj, func, off, delta):
    """Write `delta` into the 16-bit immediate of the instruction at func+off (func's own section)."""
    shndx = None
    for line in subprocess.run(["mips-linux-gnu-readelf", "-sW", obj], capture_output=True, text=True,
                               check=True).stdout.splitlines():
        parts = line.split()
        if len(parts) >= 8 and parts[7] == func and parts[3] == "FUNC":
            if int(parts[1], 16) != 0:
                raise SystemExit(f"{func}: not at the start of its section; offsets would be wrong")
            shndx = int(parts[6])
    sec_off = None
    for line in subprocess.run(["mips-linux-gnu-readelf", "-SW", obj], capture_output=True, text=True,
                               check=True).stdout.splitlines():
        m = re.match(r"^\s*\[\s*(\d+)\]\s+\S+\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)", line)
        if m and int(m.group(1)) == shndx:
            sec_off = int(m.group(2), 16)
    if shndx is None or sec_off is None:
        raise SystemExit(f"{func}: section not found in {obj}")
    with open(obj, "r+b") as f:
        f.seek(sec_off + off)
        word = struct.unpack("<I", f.read(4))[0]
        if word & 0xFFFF:
            raise SystemExit(f"{func}+{off:#x}: immediate already non-zero ({word:#010x})")
        f.seek(sec_off + off)
        f.write(struct.pack("<I", (word & 0xFFFF0000) | (delta & 0xFFFF)))


def main():
    obj, rom_path, defs_out = sys.argv[1], sys.argv[2], sys.argv[3]
    apply_ = "--apply" in sys.argv

    addrs = load_symbol_addrs()
    for i, a in enumerate(sys.argv):
        if a == "--addr":
            name, val = sys.argv[i + 1].split("=")
            addrs[name] = int(val, 16)
    with open(rom_path, "rb") as f:
        rom = f.read()

    relocs = list(find_literal_relocs(obj))
    if not relocs:
        print("No R_MIPS_LITERAL relocations found.")
        return

    # Pass 1: verify every reference against retail before touching the object. One literal symbol can
    # be referenced more than once (same constant used twice in a function), and retail can use two
    # different pool entries for those references (an inline function expanded twice, CB3HeadingComponent::
    # Update): the symbol is renamed once, at its first reference's target, and every other reference to a
    # different target gets the difference written into its instruction's 16-bit immediate -- R_MIPS_LITERAL
    # is a REL relocation, so that immediate is the addend (S + A - GP).
    defs = []
    sym_target = {}
    patches = []
    for func, off, sym in relocs:
        # MWCC pads some local symbol names with trailing spaces (__sinit_<file>.cpp): match them stripped
        if func not in addrs and func.strip() in addrs:
            addrs[func] = addrs[func.strip()]
        if func not in addrs:
            print(f"SKIP {func}+{off:#x} ({sym}): retail address unknown, can't retarget safely")
            continue
        func_addr = addrs[func]
        instr_addr = func_addr + off
        rom_off = instr_addr - 0x100000
        word = struct.unpack_from("<I", rom, rom_off)[0]
        if ((word >> 21) & 31) != 28:
            # retail's instruction there is no $gp-relative access, so the code itself differs (parkfix: a lifter draft
            # of Update__20CB3LoadingScreenPage hit adda.s; its "target" fell past the rom image, retail@target= empty)
            print(f"{func}+{off:#x} ({sym}): retail instr @ {instr_addr:#x} = {word:#010x} is not a $gp access  "
                  f"[VALUE MISMATCH: the instructions differ here -- not a match]")
            continue
        imm16 = word & 0xFFFF
        if imm16 & 0x8000:
            imm16 -= 0x10000
        target = (GP_VALUE + imm16) & 0xFFFFFFFF

        obj_val = lit4_value_in_object(obj, sym)
        retail_val = rom[target - 0x100000: target - 0x100000 + 4]
        if len(retail_val) < 4:
            print(f"{func}+{off:#x} ({sym}): retail instr @ {instr_addr:#x} -> {target:#x}, past the rom image (.sbss/.bss: "
                  f"a variable, not a literal)  [VALUE MISMATCH]")
            continue
        status = "OK" if obj_val == retail_val else "VALUE MISMATCH"
        print(f"{func}+{off:#x} ({sym}): retail instr @ {instr_addr:#x} -> pool target {target:#x}  "
              f"[{status}: object .lit4={obj_val.hex()} retail@target={retail_val.hex()}]")
        if obj_val != retail_val:
            continue
        if sym in sym_target and sym_target[sym] != target:
            delta = target - sym_target[sym]
            if not -0x8000 <= delta < 0x8000:
                raise SystemExit(f"{sym}: second pool target {target:#x} too far from {sym_target[sym]:#x}")
            patches.append((func, off, delta))
            print(f"  (second pool entry for {sym}: addend {delta:+#x} at {func}+{off:#x})")
            continue
        sym_target[sym] = target

    # Pass 2: one rename per literal symbol.
    for sym, target in sym_target.items():
        new_sym = f"lit4_{target:08X}"
        defs.append((new_sym, target))
        if apply_:
            # Rename the relocation's target, then remove the object's own private .lit4
            # definition entirely -- a *local* symbol always wins over a same-named external
            # one in the same object, so renaming alone isn't enough; the local definition has
            # to go so the reference actually falls through to the absolute symbol we define
            # for the linker (in defs_out).
            # Local symbols always win within their own object, so a plain rename isn't enough:
            # promote the renamed symbol to global, then weak, so the absolute (strong) global
            # definition we add to defs_out is what the linker actually picks; the object's own
            # .lit4 section is never pulled into the final link anyway (the ld script only asks
            # for each object's .text), so it is harmless left in place.
            subprocess.run(
                ["mips-linux-gnu-objcopy", f"--redefine-sym={sym}={new_sym}", obj],
                check=True,
            )
            subprocess.run(
                ["mips-linux-gnu-objcopy", f"--globalize-symbol={new_sym}", f"--weaken-symbol={new_sym}", obj],
                check=True,
            )
            print(f"  -> redefined {sym} to {new_sym} (weak) in {obj}")

    if apply_:
        for func, off, delta in patches:
            patch_addend(obj, func, off, delta)
            print(f"  -> addend {delta:+#x} written at {func}+{off:#x}")

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
        print(f"\n{len(defs)} literal(s) retargeted; definitions in {defs_out}")
    if not apply_:
        print("\n(dry run -- pass --apply to actually redefine symbols in the object)")


if __name__ == "__main__":
    main()
