#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3PromptsComponent_0031F5E0.cpp" \
  -o "$R\build\mw\B3PromptsComponent_0031F5E0.o"
echo "COMPILE EXIT: $?"
# 386.75 and 447.5 live in retail's shared .lit4 pool (D_004E0A1C/D_004E0A04): retarget them (N23/N64).
cd ${B3_ROOT}
python3 -I tools/lit4_retarget.py build/mw/B3PromptsComponent_0031F5E0.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply --addr func_0031F5E0=0x0031F5E0 | tail -3
