#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3HeadingComponent_00319C80.cpp" \
  -o "$R\build\mw\B3HeadingComponent_00319C80.o"
echo "COMPILE EXIT: $?"
# Four float literals live in retail's shared .lit4 pool, not a private copy: retarget them (N23/N64).
cd ${B3_ROOT}
python3 -I tools/lit4_retarget.py build/mw/B3HeadingComponent_00319C80.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply --addr Prepare__19CB3HeadingComponentF14EGlobalStringsQ219CB3HeadingComponent12EHeadingType=0x319C80 | tail -3
