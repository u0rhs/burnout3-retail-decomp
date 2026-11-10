#!/usr/bin/env python3
"""List the first N differing-byte clusters inside one function's VRAM range, with context."""
import sys

ROM_A = "build/SLUS_210.50.rom.full"     # ours (tools/wire_in_full_check.sh)
ROM_B = "orig/SLUS_210.50.rom"          # retail (tools/elf_container.py extract orig/SLUS_210.50)


def main():
    vram_start = int(sys.argv[1], 16)
    size = int(sys.argv[2], 16)
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 20
    rom_start = vram_start - 0x100000

    with open(ROM_A, "rb") as fa, open(ROM_B, "rb") as fb:
        fa.seek(rom_start); fb.seek(rom_start)
        a = fa.read(size)
        b = fb.read(size)

    diffs = [i for i in range(len(a)) if a[i] != b[i]]
    print(f"{len(diffs)} differing bytes in this function ({size:#x} bytes total)")

    runs = []
    for d in diffs:
        if runs and d <= runs[-1][1] + 4:
            runs[-1] = (runs[-1][0], d)
        else:
            runs.append((d, d))
    print(f"{len(runs)} clusters")
    for s, e in runs[:limit]:
        off = vram_start + s
        wa = s - (s % 4)
        print(f"  vram {off:#x} len {e-s+1}: mine={a[wa:wa+8].hex()} retail={b[wa:wa+8].hex()}")


if __name__ == "__main__":
    main()
