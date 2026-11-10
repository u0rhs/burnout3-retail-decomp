#!/bin/bash
set -e
cd "$(dirname "$0")/.."

AS_FLAGS="-EL -march=r5900 -mabi=o64 -G 0 -no-pad-sections -I . -I assembly/include"

for s in assembly/asm/game/unit_001ABE70.s assembly/asm/game/unit_001AC470.s assembly/asm/game/unit_001AB6B0.s; do
  o="build/${s%.s}.o"
  mkdir -p "$(dirname "$o")"
  mips-linux-gnu-as $AS_FLAGS -o "$o" "$s"
  echo "assembled: $o"
done
