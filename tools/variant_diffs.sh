#!/bin/bash
# Usage: variant_diffs.sh <retail.s> <glabel> <name>...
# Compiles each build/variants/<name>.cpp (tools/compile_variant.sh) and scores it against retail function
# <glabel> in <retail.s> with tools/diff_vs_retail.py --seq. Writes build/variants/<name>.diff and prints
# one summary line per variant. EXTRA_OPTS passes through to the compiler, as for compile_variant.sh.
cd "$(dirname "$0")/.."
S="$1"; G="$2"; shift 2
for n in "$@"; do
  out=$(bash tools/compile_variant.sh "$n" 2>&1)
  if echo "$out" | grep -q rror; then
    echo "== $n: COMPILE ERROR"; echo "$out" | grep -B3 -A8 rror | head -30; continue
  fi
  python3 -I tools/diff_vs_retail.py "build/variants/$n.o" "$S" "$G" --seq > "build/variants/$n.diff"
  frame=$(mips-linux-gnu-objdump -d "build/variants/$n.o" | awk -v g="<$G>:" '$0 ~ g {on=1} on && /addiu.*sp,sp,-/ {print $NF; exit}')
  echo "== $n: $(tail -1 "build/variants/$n.diff"), frame $frame"
done
