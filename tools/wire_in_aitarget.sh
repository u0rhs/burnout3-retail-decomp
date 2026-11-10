#!/bin/bash
set -e
cd "$(dirname "$0")/.."

mkdir -p build/assembly/asm/b3/gamesource/World
cp build/mw/B3AITarget.o build/assembly/asm/b3/gamesource/World/B3AITarget.o

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt build/lit4_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.ait 2>&1 | grep -viE "relocation truncated|GPREL16|small-data|RWX"
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.ait build/SLUS_210.50.rom.ait
echo "size: $(stat -c%s build/SLUS_210.50.rom.ait 2>/dev/null), expected $(stat -c%s build/SLUS_210.50.rom)"
sha1sum build/SLUS_210.50.rom.ait build/SLUS_210.50.rom
