#!/bin/bash
set -e
cd "$(dirname "$0")/.."

mkdir -p build/assembly/asm/b3/gamesource/Graphics/TrackRenderer/Ps2
cp build/mw/B3TrackRendererRuntimePS2.o build/assembly/asm/b3/gamesource/Graphics/TrackRenderer/Ps2/B3TrackRendererRuntimePS2.o

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt build/lit4_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.trk 2>&1 | grep -viE "relocation truncated|GPREL16|small-data|RWX"
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.trk build/SLUS_210.50.rom.trk
echo "size: $(stat -c%s build/SLUS_210.50.rom.trk 2>/dev/null), expected $(stat -c%s build/SLUS_210.50.rom)"
sha1sum build/SLUS_210.50.rom.trk build/SLUS_210.50.rom
