#!/usr/bin/env python3
"""Find which assembled .text piece(s) are larger than their true VRAM-derived size.

Parses the 'main' segment's subsegment list in config/b3_retail.yaml (name, type, vram in order),
computes each piece's expected size as (next piece's vram - this piece's vram), and compares against
the actual .text size of the corresponding assembled object under build/assembly/asm/<name>.o.
Only looks at contiguous same-kind runs (code/textbin) since data/bss pieces use different output
sections and aren't part of the main .text+VU run we're debugging.
"""
import re
import subprocess
import sys

YAML = "config/b3_retail.yaml"
BUILD_ASM = "build/assembly/asm"


def text_size(obj_path: str) -> int:
    try:
        out = subprocess.run(
            ["mips-linux-gnu-size", "-A", obj_path], capture_output=True, text=True, check=True
        ).stdout
    except FileNotFoundError:
        out = subprocess.run(
            ["mips-linux-gnu-objdump", "-h", obj_path], capture_output=True, text=True, check=True
        ).stdout
        total = 0
        for line in out.splitlines():
            m = re.match(r"\s*\d+\s+\.text\s+([0-9a-fA-F]+)", line)
            if m:
                total += int(m.group(1), 16)
        return total
    total = 0
    for line in out.splitlines():
        m = re.match(r"^\.text\s+(\d+)", line)
        if m:
            total += int(m.group(1))
    return total


def main():
    entries = []  # (name, vram)
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
                entries.append((name, vram))

    print(f"Found {len(entries)} code/textbin subsegments")
    total_expected = 0
    total_actual = 0
    mismatches = []
    for i, (name, vram) in enumerate(entries):
        expected = (entries[i + 1][1] - vram) if i + 1 < len(entries) else None
        if expected is None:
            continue
        obj = f"{BUILD_ASM}/{name}.o"
        try:
            actual = text_size(obj)
        except Exception as e:
            print(f"  SKIP {name}: {e}")
            continue
        total_expected += expected
        total_actual += actual
        if actual != expected:
            mismatches.append((name, vram, expected, actual, actual - expected))

    print(f"\nTotal expected: {total_expected:#x}  total actual: {total_actual:#x}  diff: {total_actual - total_expected:#x}")
    print(f"\n{len(mismatches)} mismatching pieces:")
    for name, vram, expected, actual, diff in mismatches:
        print(f"  {name} @ {vram:#x}: expected {expected:#x}, actual {actual:#x}, diff {diff:+#x}")


if __name__ == "__main__":
    main()
