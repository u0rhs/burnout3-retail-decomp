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

python3 -I tools/fix_alignment.py

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt config/undefined_syms_manual.txt build/lit4_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.fresh
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.fresh build/SLUS_210.50.rom
echo "size: $(stat -c%s build/SLUS_210.50.rom)"
sha1sum build/SLUS_210.50.rom
