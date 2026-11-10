#!/usr/bin/env python3
"""Force each assembled code object's .text alignment to match its true VRAM address.

CodeWarrior-built game functions start on 16-byte boundaries; ee-gcc-built library objects start on
8-byte boundaries (sometimes less). The assembler has no way to know which, so it emits a blanket
16-byte .text alignment for every object; where a library unit's real start address isn't itself
16-aligned, that overstates the alignment and the linker inserts padding that the original binary
never had. This recomputes the correct alignment per object from its VRAM address (the largest power
of two, up to 16, that divides it) and forces it with objcopy --set-section-alignment, same technique
`configure.py`'s `as_aligned` rule describes in a comment -- reimplemented fresh, not copied.
"""
import re
import subprocess
import sys

YAML = "config/b3_retail.yaml"
BUILD_ASM = "build/assembly/asm"


# Objects whose true alignment exceeds the 16 the assembler gives (parkfix, 2026-10-27): retail pads the last game
# function func_00469CC0 (ends 0x469D90) with 0x70 zero bytes up to the VU microcode at 0x469E00 [C]; [L] the VU
# section starts 128-aligned. While func_00469CC0's asm unit carries those bytes it is moot; its C object (0xD0) let
# rw_00469E00 land at 0x469D90, shifting .lit4 by -0x70 against the fixed _gp (0x4E8670) -> GPREL16 overflows
# (D_004E06B8: 0x7FB8 + 0x70 > 0x8000). With 128 the private link of the C object gives retail's SHA-1.
ALIGN_OVERRIDE = {"vu/rw_00469E00": 128}


def align_of(vram: int) -> int:
    for a in (16, 8, 4, 2, 1):
        if vram % a == 0:
            return a
    return 1


def main():
    entries = []
    pat = re.compile(r"^\s*-\s*\[0x([0-9A-Fa-f]+),\s*(asm|textbin),\s*([^\]]+)\]")
    with open(YAML) as f:
        in_main = False
        for line in f:
            if line.startswith("  - name: main"):
                in_main = True
            m = pat.match(line)
            if in_main and m:
                vram = int(m.group(1), 16) + 0x100000
                name = m.group(3).strip()
                entries.append((name, vram, m.group(2)))

    fixed = 0
    for name, vram, kind in entries:
        align = ALIGN_OVERRIDE.get(name, align_of(vram))
        if align == 16:
            continue  # already what the assembler defaults to
        obj = f"{BUILD_ASM}/{name}.o"
        if kind == "textbin":
            obj = f"{BUILD_ASM}/data/{name}.o"     # textbin objects are built under data/ (the ld script's path)
        tmp = obj + ".realign"
        try:
            subprocess.run(
                ["mips-linux-gnu-objcopy", f"--set-section-alignment=.text={align}", obj, tmp],
                check=True, capture_output=True,
            )
        except subprocess.CalledProcessError as e:
            print(f"FAILED {name}: {e.stderr.decode(errors='replace')}", file=sys.stderr)
            continue
        import os
        os.replace(tmp, obj)
        print(f"{name} @ {vram:#x}: realigned .text to {align}")
        fixed += 1
    print(f"\nFixed {fixed} objects")
    fix_data_sections()


# Data subsegments have the same problem (N20): the assembler gives every .bss/.data section a
# 16-byte alignment regardless of where the unit really starts, so e.g. sce/libdma's .bss (retail 0x4E3008,
# right after runtime/mwrt's 8 bytes) was placed at 0x4E3010, and every later .bss symbol drifted. Same
# fix: force each data object's section alignment to the one its retail address implies.
DATA_SECTION = {"data": ".data", "rodata": ".rodata", "sdata": ".sdata", "bss": ".bss", "sbss": ".sbss"}


def data_entries():
    pat_list = re.compile(r"^\s*-\s*\[0x([0-9A-Fa-f]+),\s*(data|rodata|sdata|bss|sbss),\s*([^\]]+)\]")
    pat_dict = re.compile(r"^\s*-\s*\{(.*)\}\s*$")
    out = []
    in_main = False
    with open(YAML) as f:
        for line in f:
            if line.startswith("  - name: main"):
                in_main = True
            if not in_main:
                continue
            m = pat_list.match(line)
            if m:
                out.append((m.group(3).strip(), m.group(2), int(m.group(1), 16) + 0x100000))
                continue
            m = pat_dict.match(line)
            if m:
                kv = dict(p.split(":", 1) for p in m.group(1).split(",") if ":" in p)
                kv = {k.strip(): v.strip() for k, v in kv.items()}
                typ = kv.get("type")
                if typ not in DATA_SECTION:
                    continue
                if "vram" in kv:
                    vram = int(kv["vram"], 16)
                elif "start" in kv:
                    vram = int(kv["start"], 16) + 0x100000
                else:
                    continue
                out.append((kv["name"], typ, vram))
    return out


def fix_data_sections():
    import os
    fixed = 0
    for name, typ, vram in data_entries():
        align = align_of(vram)
        obj = f"{BUILD_ASM}/data/{name}.{typ}.o"
        if not os.path.exists(obj):
            continue
        sec = DATA_SECTION[typ]
        cur = subprocess.run(["mips-linux-gnu-objdump", "-h", obj], capture_output=True, text=True).stdout
        m = re.search(r"^\s*\d+\s+%s\s+\S+\s+\S+\s+\S+\s+\S+\s+2\*\*(\d+)" % re.escape(sec), cur, re.M)
        # Absent, or already right. Under-aligned sections are raised too: an object whose retail
        # start is 16-aligned but whose data has only .word alignment would otherwise slide back over padding
        # that a neighbour used to carry (unit_0031CDA0.rodata after B3HelpBarComponent_004D7E70's .rodata).
        if not m or 2 ** int(m.group(1)) == align:
            continue
        tmp = obj + ".realign"
        subprocess.run(["mips-linux-gnu-objcopy", f"--set-section-alignment={sec}={align}", obj, tmp],
                       check=True, capture_output=True)
        os.replace(tmp, obj)
        fixed += 1
    print(f"Fixed {fixed} data objects")


if __name__ == "__main__":
    main()
