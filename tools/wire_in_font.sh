#!/bin/bash
set -e
cd "$(dirname "$0")/.."

mkdir -p build/assembly/asm/b3/GameShared/GameClasses/Graphical/2d
cp build/mw/Gt2dFont_retargeted.o build/assembly/asm/b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.o

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt build/lit4_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.font2 2>&1 | tee build/wire_font2.log
echo "LINK EXIT: $?"
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.font2 build/SLUS_210.50.rom.font2
echo "size: $(stat -c%s build/SLUS_210.50.rom.font2 2>/dev/null), expected $(stat -c%s build/SLUS_210.50.rom)"
sha1sum build/SLUS_210.50.rom.font2 build/SLUS_210.50.rom
