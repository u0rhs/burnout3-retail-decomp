#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# GtInputDevicePS2DualShock2_00214CD0: float literals in retail's shared .lit4 pool, retargeted after the compile (tools/tiny_batch.py; N23/N64).
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\_unclassified\GtInputDevicePS2DualShock2_00214CD0.cpp" \
  -o "$R\build\mw\GtInputDevicePS2DualShock2_00214CD0.o"
echo "COMPILE EXIT: $?"
cd ${B3_ROOT}
python3 -I tools/vu0_ni_fixup.py build/mw/GtInputDevicePS2DualShock2_00214CD0.o > /dev/null
python3 -I tools/jtbl_retarget.py build/mw/GtInputDevicePS2DualShock2_00214CD0.o orig/SLUS_210.50.rom build/jtbl_retarget_defs.txt Update__27CGtInputDevicePS2DualShock2Fv=0x214CD0 --apply | tail -2
