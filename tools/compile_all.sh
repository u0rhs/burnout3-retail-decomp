#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
OUT=${B3_ROOT}/build/mw
mkdir -p "$OUT"

compile() {
  src="$1"; obj="$2"
  . ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS -c "$R\\$src" -o "$R\\build\\mw\\$obj"
  echo "compiled $obj: $?"
}

compile 'src\b3\GameShared\GameClasses\Graphical\2d\Gt2dObjectBox.cpp' Gt2dObjectBox.o
compile 'src\b3\GameShared\GameClasses\Graphical\2d\Gt2dObjectImage.cpp' Gt2dObjectImage.o
compile 'src\b3\GameShared\GameClasses\Graphical\2d\Gt2dScene.cpp' Gt2dScene.o
compile 'src\b3\GameShared\GameClasses\Graphical\2d\Gt2dFont.cpp' Gt2dFont.o
compile 'src\b3\_unclassified\B3Globe2dObject_003B54D0.cpp' B3Globe2dObject_003B54D0.o
compile 'src\b3\_unclassified\B3PlayerCarPhysics_001BD640.cpp' B3PlayerCarPhysics_001BD640.o
compile 'src\b3\_unclassified\B3PlayerCarPhysics_001BDF10.cpp' B3PlayerCarPhysics_001BDF10.o
compile 'src\b3\_unclassified\B3SoundPlayerCar_0028CA50.cpp' B3SoundPlayerCar_0028CA50.o
compile 'src\b3\_unclassified\B3TrackDataStruct_003A20E0.cpp' B3TrackDataStruct_003A20E0.o
compile 'src\b3\_unclassified\B3VehiclePhysics_001CC3B0.cpp' B3VehiclePhysics_001CC3B0.o
compile 'src\b3\_unclassified\B3VehiclePhysics_001CE450.cpp' B3VehiclePhysics_001CE450.o
compile 'src\b3\_unclassified\GtVideoDecoderPS2_00325B90.cpp' GtVideoDecoderPS2_00325B90.o

echo "ALL DONE"
ls -la "$OUT"
