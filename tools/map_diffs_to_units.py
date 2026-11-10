#!/usr/bin/env python3
"""Map byte-level differences between our rebuilt rom and the retail rom to named units.

Reads every subsegment (name, type, vram) from config/b3_retail.yaml in file order (covering the
whole 'main' segment, not just code), builds a sorted boundary table, then for every differing byte
offset buckets it into the unit whose [start, next_start) range contains it. Reports per-unit diff
counts, sorted descending, plus a rollup by top-level category (game/, sce/, runtime/, lg/, ea/, rw/,
rwa/, data/, vu/, b3/).
"""
import re
import subprocess
import sys
from collections import defaultdict

YAML = "config/b3_retail.yaml"
ROM_A = "build/SLUS_210.50.rom.full"     # ours (tools/wire_in_full_check.sh)
ROM_B = "orig/SLUS_210.50.rom"          # retail (tools/elf_container.py extract orig/SLUS_210.50)


def load_entries():
    entries = []
    pat = re.compile(r"^\s*-\s*\{?\s*(?:type:\s*(\w+),\s*)?.*vram:\s*0x([0-9A-Fa-f]+),\s*name:\s*([^\s,}]+)")
    pat2 = re.compile(r"^\s*-\s*\[0x([0-9A-Fa-f]+),\s*(\w+),\s*([^\]]+)\]")
    in_main = False
    with open(YAML) as f:
        for line in f:
            if line.startswith("  - name: main"):
                in_main = True
            if not in_main:
                continue
            m2 = pat2.match(line)
            if m2:
                rom_off = int(m2.group(1), 16)
                entries.append((rom_off, m2.group(2), m2.group(3).strip()))
                continue
            m1 = pat.match(line)
            if m1:
                vram = int(m1.group(2), 16)
                rom_off = vram - 0x100000
                entries.append((rom_off, m1.group(1) or "data", m1.group(3).strip()))
    entries.sort(key=lambda e: e[0])
    return entries


def main():
    entries = load_entries()
    print(f"Loaded {len(entries)} subsegment boundaries")

    starts = [e[0] for e in entries]

    with open(ROM_A, "rb") as fa, open(ROM_B, "rb") as fb:
        a = fa.read()
        b = fb.read()
    n = min(len(a), len(b))
    diff_offsets = [i for i in range(n) if a[i] != b[i]]
    print(f"Total differing bytes: {len(diff_offsets)} / {n}")

    import bisect
    counts = defaultdict(int)
    for off in diff_offsets:
        idx = bisect.bisect_right(starts, off) - 1
        if idx < 0:
            counts[("<before first>", "?")] += 1
            continue
        _, typ, name = entries[idx]
        counts[(name, typ)] += 1

    ranked = sorted(counts.items(), key=lambda kv: -kv[1])
    print(f"\n{len(ranked)} units contain at least one differing byte. Top 40:")
    for (name, typ), c in ranked[:40]:
        print(f"  {c:6d}  {typ:8s} {name}")

    cat_counts = defaultdict(int)
    for (name, typ), c in counts.items():
        cat = name.split("/")[0] if "/" in name else name
        cat_counts[cat] += c
    print("\nBy top-level category:")
    for cat, c in sorted(cat_counts.items(), key=lambda kv: -kv[1]):
        print(f"  {c:6d}  {cat}")


if __name__ == "__main__":
    main()
