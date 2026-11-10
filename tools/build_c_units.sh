#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# Rebuilds every proven C/C++ unit (config/proven_units.txt) into build/mw/<source basename>.o, then runs the
# full wire-in-and-relink check against retail. Run this after any shared-header change (N52 hygiene).
# Units that need post-processing (.lit4 / jump-table retargets) have their own tools/compile_*.sh, which is
# used when one names the source; every other source gets the plain compile with tools/mwcc_flags.sh.
REPO=${B3_ROOT}
cd "$REPO"
. tools/mwcc_flags.sh
R="Z:${B3_ROOT_WIN}"
export WINEDEBUG=-all
export MWCIncludes="$R"'\include'
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
mkdir -p build/mw
fail=0
for src in $(grep -v '^#' config/proven_units.txt | awk -F, 'NF>=5 {print $5}' | sort -u); do
  b=$(basename "$src" .cpp)
  # a regrouped translation unit (config/tu_units.txt) is compiled once and split by tools/tu_build.sh below
  if [ -f config/tu_units.txt ] && grep -q "^$src " config/tu_units.txt; then continue; fi
  script=$(grep -l "\\\\$b.cpp\"" tools/compile_*.sh 2>/dev/null | grep -v compile_all.sh | head -1)
  if [ -n "$script" ]; then
    out=$(bash "$script" 2>&1)
  else
    win=$(echo "$src" | tr '/' '\\')
    out=$(cd ${B3_MWCC_DIR} && mwcc_run $MWCC_FLAGS -c "$R"'\'"$win" -o "$R"'\build\mw\'"$b.o" 2>&1)
  fi
  if echo "$out" | grep -qi "error"; then echo "FAILED: $src"; echo "$out" | grep -i -A3 error | head -8; fail=1; fi
done
# GtMathPs2's `.i` VU0 moves -> `.ni` in every unit compiled above, the tools/compile_*.sh ones included
python3 -I tools/vu0_ni_fixup.py build/mw/*.o
bash tools/tu_build.sh || fail=1
[ $fail = 0 ] && echo "built all proven units"
bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX
