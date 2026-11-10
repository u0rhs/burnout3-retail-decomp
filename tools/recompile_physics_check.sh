#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
for name in B3PlayerCarPhysics_001BD640 B3PlayerCarPhysics_001BDF10 B3VehiclePhysics_001CC3B0 B3VehiclePhysics_001CE450; do
  wine mwccps2.exe -O4 -str readonly -Cpp_exceptions off \
    -c "$R\src\b3\gamesource\Physics\\${name}.cpp" \
    -o "$R\build\mw\\${name}.o"
  echo "${name} COMPILE EXIT: $?"
done
