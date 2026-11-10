#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# tiny_compile.sh <src relative path> <out relative path>: one MWCC compile with the project flags (tools/tiny_batch.py).
# The host (wine or wibo/native) comes from tools/mwcc_flags.sh's mwcc_run: MWCC_HOST, or the source's
# `// BUILD-HOST:` marker (N165).
cd ${B3_ROOT}
. tools/mwcc_flags.sh
R="Z:${B3_ROOT_WIN}\\"
export WINEDEBUG=-all MWCIncludes="${R}include" LM_LICENSE_FILE="${B3_LICENSE_WIN}"
src=$(echo "$1" | tr '/' '\\')
out=$(echo "$2" | tr '/' '\\')
cd ${B3_MWCC_DIR} && mwcc_run $MWCC_FLAGS -c "${R}${src}" -o "${R}${out}" 2>&1 | grep -i -B1 -A4 "error"
# GtMathPs2's `.i` VU0 moves -> `.ni`, as retail encodes them (tools/vu0_ni_fixup.py; no-op without such moves)
cd ${B3_ROOT} && [ -f "$2" ] && python3 -I tools/vu0_ni_fixup.py "$2"
exit 0
