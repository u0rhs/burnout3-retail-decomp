#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# tu_build.sh: build every translation unit listed in config/tu_units.txt (tools/tu_merge.py): compile its source once
# (build/mw/tu/<stem>.o) and split the object into one build/mw/<unit>.o per function (tools/split_tu_obj.py), the
# objects the link script places. Float literals (.lit4) are retargeted at retail's shared pool on the merged object
# before the split (tools/lit4_retarget.py; no-op without R_MIPS_LITERAL relocations; log build/mw/tu/<stem>.lit4.log).
# Prints "FAILED: <source>" for a unit that doesn't compile or split.
cd ${B3_ROOT}
[ -f config/tu_units.txt ] || exit 0
mkdir -p build/mw/tu
fail=0
while read -r src rest; do
  case "$src" in ''|'#'*) continue ;; esac
  stem=$(basename "$src" .cpp)
  rm -f "build/mw/tu/$stem.o"
  out=$(bash tools/tiny_compile.sh "$src" "build/mw/tu/$stem.o")
  if [ ! -f "build/mw/tu/$stem.o" ]; then echo "FAILED: $src"; echo "$out" | head -8; fail=1; continue; fi
  python3 -I tools/lit4_retarget.py "build/mw/tu/$stem.o" orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply \
    > "build/mw/tu/$stem.lit4.log" 2>&1 || { echo "FAILED: $src (lit4)"; tail -3 "build/mw/tu/$stem.lit4.log"; fail=1; continue; }
  python3 -I tools/split_tu_obj.py "build/mw/tu/$stem.o" build/mw $rest || { echo "FAILED: $src (split)"; fail=1; }
done < config/tu_units.txt
exit $fail
