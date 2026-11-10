#!/bin/bash
set -e
cd "$(dirname "$0")/.."   # repo root

AS_FLAGS="-EL -march=r5900 -mabi=o64 -G 0 -no-pad-sections -I . -I assembly/include"

count=0
while IFS= read -r -d '' s; do
  o="build/${s%.s}.o"
  mkdir -p "$(dirname "$o")"
  mips-linux-gnu-as $AS_FLAGS -o "$o" "$s"
  count=$((count+1))
done < <(find assembly/asm -iname "*.s" -print0)
echo "Assembled $count files"

mips-linux-gnu-ld -EL -T build/SLUS_210.50.ld build/undefined_syms_auto.txt --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.tmp
echo "Link done"

mips-linux-gnu-objcopy -O binary build/SLUS_210.50.elf.tmp build/SLUS_210.50.rom.out
echo "Extracted rom.out: $(stat -c%s build/SLUS_210.50.rom.out 2>/dev/null) bytes"

python3 -I tools/elf_container.py rebuild build/SLUS_210.50.rom.out build/SLUS_210.50.rebuilt --check
