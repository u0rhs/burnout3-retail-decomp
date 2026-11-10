#!/bin/bash
set -e
cd "$(dirname "$0")/.."

mkdir -p build/assembly/asm/b3/GameShared/GameClasses

# restore the original disassembled-asm objects for the 3 units that are NOT "linked: true"
# in the earlier research repo's b3_units.json (Gt2dObjectImage, Gt2dScene are explicitly linked:false;
# Gt2dFont isn't listed there at all) -- only Gt2dObject/Gt2dObjectBox are safe to substitute.
AS_FLAGS="-EL -march=r5900 -mabi=o64 -G 0 -no-pad-sections -I . -I assembly/include"
for name in Gt2dObjectImage Gt2dScene; do
  mips-linux-gnu-as $AS_FLAGS -o "build/assembly/asm/b3/GameShared/GameClasses/$name.o" \
    "assembly/asm/b3/GameShared/GameClasses/$name.s"
done
python3 tools/fix_alignment.py >/dev/null

for name in Gt2dObject Gt2dObjectBox; do
  cp "build/mw/$name.o" "build/assembly/asm/b3/GameShared/GameClasses/$name.o"
done

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.wired 2>&1 | tee build/wire_link.log
echo "LINK EXIT: $?"
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.wired build/SLUS_210.50.rom.wired
echo "size: $(stat -c%s build/SLUS_210.50.rom.wired 2>/dev/null), expected $(stat -c%s build/SLUS_210.50.rom)"
