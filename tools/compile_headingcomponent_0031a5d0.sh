#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3HeadingComponent_0031A5D0.cpp" \
  -o "$R\build\mw\B3HeadingComponent_0031A5D0.o"
echo "COMPILE EXIT: $?"
# func_0031A5D0 and func_0031A840 (Target #35). One float literal (FLT_MAX) in retail's shared .lit4 pool.
cd ${B3_ROOT}
python3 -I tools/lit4_retarget.py build/mw/B3HeadingComponent_0031A5D0.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply --addr func_0031A5D0=0x31A5D0 --addr func_0031A840=0x31A840 | tail -3
