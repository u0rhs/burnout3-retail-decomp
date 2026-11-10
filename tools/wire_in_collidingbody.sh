#!/bin/bash
set -e
cd "$(dirname "$0")/.."

mkdir -p build/assembly/asm/b3/gamesource/Physics
cp build/mw/B3CollidingBody.o build/assembly/asm/b3/gamesource/Physics/B3CollidingBody.o

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt build/lit4_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.cb
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.cb build/SLUS_210.50.rom.cb
echo "size: $(stat -c%s build/SLUS_210.50.rom.cb)"
sha1sum build/SLUS_210.50.rom.cb
