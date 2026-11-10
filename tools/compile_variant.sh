#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# Usage: compile_variant.sh <basename under build/variants/, no extension>
# Compiles build/variants/<name>.cpp to build/variants/<name>.o and disassembles it.
set -e
NAME="$1"
REPO=${B3_ROOT}
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
rm -f "$REPO/build/variants/$NAME.o"
# EXTRA_OPTS (env): extra compiler options for experiments only, e.g. EXTRA_OPTS="-inline auto".
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS $EXTRA_OPTS \
  -c "$R\build\variants\\$NAME.cpp" \
  -o "$R\build\variants\\$NAME.o"
mips-linux-gnu-objdump -d -z --no-show-raw-insn "$REPO/build/variants/$NAME.o" | tail -n +7
