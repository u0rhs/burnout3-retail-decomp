#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3HeadingComponent_00319E80.cpp" \
  -o "$R\build\mw\B3HeadingComponent_00319E80.o"
echo "COMPILE EXIT: $?"
# The switch's jump table is retail's jtbl_004C51B0 in the shared .rodata, not a private copy: verify it
# entry by entry and retarget it; its case labels get linker definitions (tools/jtbl_retarget.py).
cd ${B3_ROOT}
python3 -I tools/jtbl_retarget.py build/mw/B3HeadingComponent_00319E80.o orig/SLUS_210.50.rom build/jtbl_retarget_defs.txt Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType=0x319E80 --apply | tail -2
