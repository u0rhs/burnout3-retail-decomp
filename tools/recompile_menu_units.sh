#!/bin/bash
# Recompiles every proven Menu/DebugMenu unit (N52 hygiene: shared headers changed), then runs the
# full wire-in-and-relink check.
cd "$(dirname "$0")/.."
for s in menupagemanager_construct menupagemanager_addcomponent menucomponentbase \
         vlistcomponent vlistcomponent_release vlistcomponent_update \
         hselectcomponent_construct hselectcomponent_release hselectcomponent_update \
         headingcomponent_construct headingcomponent_release headingcomponent_prepare headingcomponent_prepare_strid \
         headingcomponent_prepare_type headingcomponent_update headingcomponent_0031a5d0 \
         headingcomponent_0031a9c0 headingcomponent_0031a570 headingcomponent_0031a300; do
  [ -f "tools/compile_$s.sh" ] || continue
  printf '%s: ' "$s"
  bash "tools/compile_$s.sh" 2>&1 | tail -1
done
bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX
