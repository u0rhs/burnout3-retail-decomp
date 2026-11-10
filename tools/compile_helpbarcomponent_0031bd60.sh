#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3HelpBarComponent_0031BD60.cpp" \
  -o "$R\build\mw\B3HelpBarComponent_0031BD60.o"
echo "COMPILE EXIT: $?"
# FLT_MAX lives in retail's shared .lit4 pool (D_004E0C14): retarget it (N23/N64).
cd ${B3_ROOT}
python3 -I tools/lit4_retarget.py build/mw/B3HelpBarComponent_0031BD60.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply --addr func_0031BD60=0x0031BD60 | tail -3
