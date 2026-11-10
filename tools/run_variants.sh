#!/bin/bash
# Usage: run_variants.sh name... -- compiles each build/variants/<name>.cpp and prints size, s-regs and frame.
cd "$(dirname "$0")/.."
for n in "$@"; do
  out=$(bash tools/compile_variant.sh "$n" 2>&1)
  if echo "$out" | grep -q rror; then echo "== $n: COMPILE ERROR"; echo "$out" | grep -A3 rror | head -8; continue; fi
  last=$(echo "$out" | grep -E '^ +[0-9a-f]+:' | tail -1 | awk '{print $1}' | tr -d ':')
  echo "== $n: last=0x$last frame=$(echo "$out" | grep -m1 -oE 'addiu	sp,sp,-[0-9]+') sregs=$(echo "$out" | grep -oE 'sq	s[0-9]' | sort -u | tr '\n' ' ')"
done
