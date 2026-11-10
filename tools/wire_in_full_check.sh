#!/bin/bash
set -e
cd "$(dirname "$0")/.."
. tools/pipeline_guard.sh

# Objects whose classes declare virtuals (CB3MenuComponentBase) also define those classes' vtables
# (__vt__*, in a .vtables section the ld script discards). Weaken them so retail's asm vtables (data/*_vt.data.s)
# stay the definitions that get linked, until the vtables themselves are reconstructed. Idempotent; only objects
# written since the last run (newer than the stamp) need it, which keeps this fast with hundreds of units.
stamp=build/mw/.weakened
if [ -f "$stamp" ]; then objs=$(find build/mw -maxdepth 1 -name '*.o' -newer "$stamp"); else objs=$(ls build/mw/*.o); fi
for o in $objs; do
  mips-linux-gnu-objcopy --wildcard --weaken-symbol='__vt__*' "$o"
done
touch "$stamp"

for name in B3PlayerCarPhysics_001BD640 B3PlayerCarPhysics_001BDF10 B3VehiclePhysics_001CC3B0 B3VehiclePhysics_001CE450 B3SoundPlayerCar_0028CA50 GtVideoDecoderPS2_00325B90 B3TrackDataStruct_003A20E0 B3Globe2dObject_003B54D0; do
  cp "build/mw/${name}.o" "build/assembly/asm/b3/${name}.o"
done
cp build/mw/Gt2dObject.o build/assembly/asm/b3/GameShared/GameClasses/Gt2dObject.o
cp build/mw/Gt2dObjectBox.o build/assembly/asm/b3/GameShared/GameClasses/Gt2dObjectBox.o
mkdir -p build/assembly/asm/b3/gamesource/World build/assembly/asm/b3/gamesource/Graphics/TrackRenderer/Ps2 build/assembly/asm/b3/gamesource/Physics build/assembly/asm/b3/gamesource/Race
cp build/mw/B3AITarget.o build/assembly/asm/b3/gamesource/World/B3AITarget.o
cp build/mw/B3TrackRendererRuntimePS2.o build/assembly/asm/b3/gamesource/Graphics/TrackRenderer/Ps2/B3TrackRendererRuntimePS2.o
cp build/mw/B3CollidingBody.o build/assembly/asm/b3/gamesource/Physics/B3CollidingBody.o
cp build/mw/B3StreamedTrack.o build/assembly/asm/b3/gamesource/Race/B3StreamedTrack.o
cp build/mw/B3CollidingBody_001AC450.o build/assembly/asm/b3/gamesource/Physics/B3CollidingBody_001AC450.o
cp build/mw/B3CollidingBody_001ABDD0.o build/assembly/asm/b3/gamesource/Physics/B3CollidingBody_001ABDD0.o
cp build/mw/B3VehiclePhysicsAttribs.o build/assembly/asm/b3/gamesource/Physics/B3VehiclePhysicsAttribs.o
cp build/mw/B3RaceCarPhysicsAttribs.o build/assembly/asm/b3/gamesource/Physics/B3RaceCarPhysicsAttribs.o
mkdir -p build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components
mkdir -p build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages
cp build/mw/B3LoadingScreenPage_00321500.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage_00321500.o
cp build/mw/B3LoadingScreenPage_00321680.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage_00321680.o
cp build/mw/B3MyBurnoutPage_00322310.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage_00322310.o
cp build/mw/B3MyBurnoutPage_00322610.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages/B3MyBurnoutPage_00322610.o
cp build/mw/B3MenuPageBase_00318530.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Pages/B3MenuPageBase_00318530.o
cp build/mw/B3VListComponent.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent.o
cp build/mw/B3MenuComponentBase.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.o
cp build/mw/B3VListComponent_0032B200.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent_0032B200.o
cp build/mw/B3VListComponent_0032B290.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VListComponent_0032B290.o
cp build/mw/B3MenuPageManager_0030D6B0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/B3MenuPageManager_0030D6B0.o
cp build/mw/B3MenuPageManager_004D7120.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/B3MenuPageManager_004D7120.o
cp build/mw/B3MenuPageManager_0030D3B0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/B3MenuPageManager_0030D3B0.o
cp build/mw/B3HSelectComponent_0031CD90.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CD90.o
cp build/mw/B3BackgroundComponent_0031CDA0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031CDA0.o
cp build/mw/B3BackgroundComponent_0031D920.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031D920.o
cp build/mw/B3BackgroundComponent_0031E0D0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_0031E0D0.o
cp build/mw/B3BackgroundComponent_004D7EC0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent_004D7EC0.o
cp build/mw/B3PromptsComponent_0031E140.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031E140.o
cp build/mw/B3PromptsComponent_0031F5E0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031F5E0.o
cp build/mw/B3PromptsComponent_0031F760.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031F760.o
cp build/mw/B3PromptsComponent_004D8100.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_004D8100.o
cp build/mw/B3PromptsComponent_0031FD30.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent_0031FD30.o
cp build/mw/B3VSelectComponent_0031FDB0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_0031FDB0.o
cp build/mw/B3VSelectComponent_0031FE70.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_0031FE70.o
cp build/mw/B3VSelectComponent_00320E20.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00320E20.o
cp build/mw/B3VSelectComponent_00320EB0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00320EB0.o
cp build/mw/B3VSelectComponent_00321430.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_00321430.o
cp build/mw/B3VSelectComponent_004D81A0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_004D81A0.o
cp build/mw/B3VSelectComponent_003214B0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent_003214B0.o
cp build/mw/B3HSelectComponent_0031CC90.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CC90.o
cp build/mw/B3HSelectComponent_0031CCD0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent_0031CCD0.o
cp build/mw/B3HeadingComponent_003193D0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_003193D0.o
cp build/mw/B3HeadingComponent_0031B0F0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031B0F0.o
cp build/mw/B3HeadingComponent_00319A90.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319A90.o
cp build/mw/B3HeadingComponent_00319C80.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319C80.o
cp build/mw/B3HeadingComponent_00319E80.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319E80.o
cp build/mw/B3HeadingComponent_00319490.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_00319490.o
cp build/mw/B3HeadingComponent_0031A5D0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A5D0.o
cp build/mw/B3HeadingComponent_0031A9C0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A9C0.o
cp build/mw/B3HeadingComponent_0031A570.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A570.o
cp build/mw/B3HeadingComponent_0031A300.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_0031A300.o
cp build/mw/B3HelpBarComponent_0031B640.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B640.o
cp build/mw/B3HelpBarComponent_0031B6A0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B6A0.o
cp build/mw/B3HelpBarComponent_0031C590.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C590.o
cp build/mw/B3HelpBarComponent_0031B770.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031B770.o
cp build/mw/B3HelpBarComponent_0031C210.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C210.o
cp build/mw/B3HelpBarComponent_0031CB20.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031CB20.o
cp build/mw/B3HelpBarComponent_0031C990.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_0031C990.o
cp build/mw/B3MenuComponentBase_003192F0.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase_003192F0.o
cp build/mw/B3HeadingComponent_004D7E20.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent_004D7E20.o
cp build/mw/B3HelpBarComponent_004D7E70.o build/assembly/asm/b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent_004D7E70.o

# Units proven by the tiny-function batch (tools/tiny_batch.py).
# Batch units (tools/tiny_batch.py): one cp for all when every line is the standard
# `cp build/mw/X.o build/assembly/asm/b3/_unclassified/X.o`, else source the file line by line.
if [ -f tools/wire_in_batch.sh ]; then
  if awk '/^cp /{n=split($2,a,"/"); if ($3 != "build/assembly/asm/b3/_unclassified/" a[n]) bad=1} END{exit bad}' tools/wire_in_batch.sh; then
    mkdir -p build/assembly/asm/b3/_unclassified
    awk '/^cp /{print $2}' tools/wire_in_batch.sh | xargs cp -t build/assembly/asm/b3/_unclassified/
  else
    . tools/wire_in_batch.sh
  fi
fi

mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt config/undefined_syms_manual.txt build/lit4_retarget_defs.txt build/jtbl_retarget_defs.txt \
  --no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.full
mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.full build/SLUS_210.50.rom.full
echo "size: $(stat -c%s build/SLUS_210.50.rom.full)"
sha1sum build/SLUS_210.50.rom.full
# Since an earlier pass (N20 closed) the build reproduces retail exactly: compare against the load segment
# extracted from the retail ELF (orig/SLUS_210.50.rom, tools/elf_container.py extract; SHA-1 817cfb41...).
if [ -f orig/SLUS_210.50.rom ]; then
  if cmp -s build/SLUS_210.50.rom.full orig/SLUS_210.50.rom; then echo "MATCHES RETAIL"; else
    echo "DIFFERS FROM RETAIL: $(cmp -l build/SLUS_210.50.rom.full orig/SLUS_210.50.rom | wc -l) bytes"; fi
fi
