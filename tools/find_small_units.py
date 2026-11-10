#!/usr/bin/env python3
"""List 'game/unit_*' asm units sorted by size (small first), as decompilation candidates."""
import re

entries = []
pat = re.compile(r"^\s*-\s*\[0x([0-9A-Fa-f]+),\s*asm,\s*(game/unit_[0-9A-Fa-f]+)\]")
in_main = False
with open("config/b3_retail.yaml") as f:
    for line in f:
        if line.startswith("  - name: main"):
            in_main = True
        if not in_main:
            continue
        m = pat.match(line)
        if m:
            entries.append((int(m.group(1), 16), m.group(2)))

entries.sort()
sized = []
for i in range(len(entries) - 1):
    size = entries[i + 1][0] - entries[i][0]
    sized.append((size, entries[i][1], entries[i][0] + 0x100000))

sized.sort()
print(f"{len(sized)} game/unit_* asm units total\n")
print("Smallest 40:")
for size, name, vram in sized[:40]:
    print(f"  {size:#6x} ({size:4d})  {vram:#010x}  {name}")
