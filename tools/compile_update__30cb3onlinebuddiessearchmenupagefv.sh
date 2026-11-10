#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# Update__30CB3OnlineBuddiesSearchMenuPageFv: float literals in retail's shared .lit4 pool, retargeted after the compile (tools/tiny_batch.py; N23/N64).
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\_unclassified\Update__30CB3OnlineBuddiesSearchMenuPageFv.cpp" \
  -o "$R\build\mw\Update__30CB3OnlineBuddiesSearchMenuPageFv.o"
echo "COMPILE EXIT: $?"
cd ${B3_ROOT}
python3 -I tools/jtbl_retarget.py build/mw/Update__30CB3OnlineBuddiesSearchMenuPageFv.o orig/SLUS_210.50.rom build/jtbl_retarget_defs.txt Update__30CB3OnlineBuddiesSearchMenuPageFv=0x373270 --apply | tail -2
