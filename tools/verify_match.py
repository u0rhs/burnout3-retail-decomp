#!/usr/bin/env python3
"""Compare a compiled object's concatenated .text bytes against the retail rom at a given VRAM range."""
import subprocess
import sys

def text_bytes(obj_path: str) -> bytes:
    merged = obj_path + ".merged.o"
    subprocess.run(["mips-linux-gnu-ld", "-EL", "-r", "-o", merged, obj_path], check=True)
    tmp = obj_path + ".textdump"
    subprocess.run(
        ["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", merged, tmp],
        check=True,
    )
    with open(tmp, "rb") as f:
        return f.read()

def main():
    obj_path, vram_start_hex, vram_end_hex, rom_path = sys.argv[1:5]
    vram_start = int(vram_start_hex, 16)
    vram_end = int(vram_end_hex, 16)
    rom_off = vram_start - 0x100000
    size = vram_end - vram_start
    with open(rom_path, "rb") as f:
        f.seek(rom_off)
        retail = f.read(size)
    mine = text_bytes(obj_path)
    print(f"{obj_path}: compiled .text = {len(mine)} bytes, retail range = {size} bytes")
    n = min(len(mine), len(retail))
    diffs = [i for i in range(n) if mine[i] != retail[i]]
    if mine == retail:
        print("  RESULT: 100% BYTE-IDENTICAL MATCH")
    else:
        print(f"  RESULT: MISMATCH -- {len(diffs)} differing bytes out of {n}; first diff at offset {diffs[0] if diffs else 'n/a'}; size diff {len(mine)-len(retail)}")

if __name__ == "__main__":
    main()
