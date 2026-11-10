#!/usr/bin/env python3
"""Show the differing bytes within one named unit's rom range, with surrounding context."""
import re
import sys

YAML = "config/b3_retail.yaml"
ROM_A = "build/SLUS_210.50.rom.full"     # ours (tools/wire_in_full_check.sh)
ROM_B = "orig/SLUS_210.50.rom"          # retail (tools/elf_container.py extract orig/SLUS_210.50)


def load_entries():
    entries = []
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
                entries.append((int(m2.group(1), 16), m2.group(2), m2.group(3).strip()))
    entries.sort(key=lambda e: e[0])
    return entries


def main():
    target_name = sys.argv[1]
    target_type = sys.argv[2] if len(sys.argv) > 2 else "asm"
    entries = load_entries()
    starts = [e[0] for e in entries]

    idx = next(i for i, e in enumerate(entries) if e[2] == target_name and e[1] == target_type)
    start = entries[idx][0]
    end = entries[idx + 1][0] if idx + 1 < len(entries) else None

    with open(ROM_A, "rb") as fa, open(ROM_B, "rb") as fb:
        fa.seek(start); fb.seek(start)
        size = (end - start) if end else 0x40
        a = fa.read(size)
        b = fb.read(size)

    print(f"{target_name} ({target_type}): rom {start:#x}-{start+size:#x} (vram {start+0x100000:#x})")
    diffs = [i for i in range(len(a)) if a[i] != b[i]]
    print(f"{len(diffs)} differing bytes")
    # group into contiguous runs
    runs = []
    for d in diffs:
        if runs and d == runs[-1][1]:
            runs[-1] = (runs[-1][0], d + 1)
        else:
            runs.append((d, d + 1))
    print(f"{len(runs)} contiguous runs; first 15:")
    for s, e in runs[:15]:
        off = start + s
        print(f"  rom {off:#x} (vram {off+0x100000:#x}), len {e-s}: mine={a[s:e].hex()} retail={b[s:e].hex()}")


if __name__ == "__main__":
    main()
