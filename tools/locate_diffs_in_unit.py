#!/usr/bin/env python3
"""Within one named unit's VRAM range, cluster the differing bytes and map each cluster to the
nearest preceding named function (from config/symbol_addrs_b3names.txt)."""
import re
import sys

ROM_A = "build/SLUS_210.50.rom.full"     # ours (tools/wire_in_full_check.sh)
ROM_B = "orig/SLUS_210.50.rom"          # retail (tools/elf_container.py extract orig/SLUS_210.50)
SYMS = "config/symbol_addrs_b3names.txt"


def load_funcs():
    funcs = []
    pat = re.compile(r"^([A-Za-z_][\w@$:<>,.~=\[\]]*)\s*=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func")
    with open(SYMS, errors="replace") as f:
        for line in f:
            m = pat.match(line)
            if m:
                funcs.append((int(m.group(2), 16), m.group(1)))
    funcs.sort()
    return funcs


def main():
    vram_start = int(sys.argv[1], 16)
    vram_end = int(sys.argv[2], 16)
    rom_start = vram_start - 0x100000
    rom_end = vram_end - 0x100000

    funcs = load_funcs()
    starts = [f[0] for f in funcs]
    import bisect

    with open(ROM_A, "rb") as fa, open(ROM_B, "rb") as fb:
        fa.seek(rom_start); fb.seek(rom_start)
        a = fa.read(rom_end - rom_start)
        b = fb.read(rom_end - rom_start)

    diffs = [i for i in range(len(a)) if a[i] != b[i]]
    print(f"{len(diffs)} differing bytes in VRAM {vram_start:#x}-{vram_end:#x}")

    runs = []
    for d in diffs:
        if runs and d <= runs[-1][1] + 8:
            runs[-1] = (runs[-1][0], d)
        else:
            runs.append((d, d))
    print(f"{len(runs)} clusters (gap<=8 merged)")

    from collections import defaultdict
    by_func = defaultdict(int)
    for s, e in runs:
        vram = vram_start + s
        idx = bisect.bisect_right(starts, vram) - 1
        name = funcs[idx][1] if idx >= 0 else "?"
        faddr = funcs[idx][0] if idx >= 0 else 0
        by_func[(name, faddr)] += (e - s + 1)

    ranked = sorted(by_func.items(), key=lambda kv: -kv[1])
    print(f"\n{len(ranked)} functions touched, top 30 by diff-byte count:")
    for (name, faddr), c in ranked[:30]:
        print(f"  {c:6d}  {faddr:#010x}  {name}")


if __name__ == "__main__":
    main()
