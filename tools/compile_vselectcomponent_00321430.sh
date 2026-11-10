#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\src\b3\gamesource\Menu\DebugMenu\Components\B3VSelectComponent_00321430.cpp" \
  -o "$R\build\mw\B3VSelectComponent_00321430.o"
echo "COMPILE EXIT: $?"
# N104: retail's CB3VSelectComponent::Prepare overloads each take one more float (and the main one one more bool)
# than the E-build names the rest of the build labels them by. Map our (retail-signature) symbols onto those labels,
# in one objcopy pass (our 1-float wrapper's name is the label of the 2-float one).
O=${B3_ROOT}/build/mw/B3VSelectComponent_00321430.o
T=19CB3VSelectComponent
P=PC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData
mips-linux-gnu-objcopy \
  --redefine-sym Prepare__${T}Fbfffff${P}b=Prepare__${T}Fbffff${P} \
  --redefine-sym Prepare__${T}Fff${P}=Prepare__${T}Ff${P} \
  --redefine-sym Prepare__${T}Ff${P}=Prepare__${T}F${P} \
  --redefine-sym .mwcats_Prepare__${T}Fff${P}=.mwcats_Prepare__${T}Ff${P} \
  --redefine-sym .mwcats_Prepare__${T}Ff${P}=.mwcats_Prepare__${T}F${P} \
  "$O"
