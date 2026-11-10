#!/bin/bash
set -e
cd "$(dirname "$0")/.."

for name in B3PlayerCarPhysics_001BD640 B3PlayerCarPhysics_001BDF10 \
            B3VehiclePhysics_001CC3B0 B3VehiclePhysics_001CE450 \
            B3SoundPlayerCar_0028CA50 GtVideoDecoderPS2_00325B90 \
            B3TrackDataStruct_003A20E0 B3Globe2dObject_003B54D0; do
  cp "build/mw/$name.o" "build/assembly/asm/b3/$name.o"
done

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.wired2 2>&1 | tee build/wire_link2.log
echo "LINK EXIT: $?"
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.wired2 build/SLUS_210.50.rom.wired2
echo "size: $(stat -c%s build/SLUS_210.50.rom.wired2 2>/dev/null), expected $(stat -c%s build/SLUS_210.50.rom)"
sha1sum build/SLUS_210.50.rom.wired2 build/SLUS_210.50.rom
