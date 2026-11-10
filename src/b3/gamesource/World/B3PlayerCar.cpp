// B3PlayerCar.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PlayerCar.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4PlayerCar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3AICar.h"
#include "b3/classes/CB3CrashStartInfo.h"
#include "b3/classes/CB3HUD.h"
#include "b3/classes/CB3PlayerCar.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3SoundRaceCarManager.h"
#include "b3/classes/EB3RaceCarType.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/EHUDMode.h"
#include "b3/classes/UnkStruct_D_0066A3D0.h"

struct UnkStruct_001507D0;

struct UnkStruct_001507D0 {
    unsigned char pad_0[0x27C0];
    int field_27C0;
};

extern UnkStruct_D_0066A3D0 D_0066A3D0;
extern CB3SoundRaceCarManager D_01E77550;
extern int D_0064CE38[];  // [G] element count unknown
extern "C" void StartCrashing__10CB3RaceCarFP17CB3CrashStartInfo(void *, void *);  // CB3RaceCar::StartCrashing(CB3CrashStartInfo*)
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, EHUDMode);  // CB3HUD::SetHUDMode(EHUDMode)
extern "C" int Prepare__8CB3AICarFv(void *);  // CB3AICar::Prepare()
extern "C" void Construct__8CB3AICarFi(void *, int);  // CB3AICar::Construct(int)

// StartCrashing__12CB3PlayerCarFP17CB3CrashStartInfo -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001507D0
extern "C" void StartCrashing__12CB3PlayerCarFP17CB3CrashStartInfo(UnkStruct_001507D0 * self, int p0)
{
    StartCrashing__10CB3RaceCarFP17CB3CrashStartInfo(self, (CB3CrashStartInfo*)p0);
    SetHUDMode__6CB3HUDF8EHUDMode(&D_0066A3D0.field_0[self->field_27C0], (EHUDMode)2);
}

// CB3PlayerCar::PrepareSound() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCar.cpp.
// 0x00150820
int CB3PlayerCar::PrepareSound()
{
    if (field_1918 == 0) {
        int r0 = D_01E77550.RequestRaceCar((EB3RaceCarType)0);
        field_1918 = (UnkStruct_00150820_1 *)r0;
    }
    if (field_1918 == 0) {
        return 1;
    }
    int r1 = field_1918->vfunc_8(field_1960, field_19AC);
    return r1;
}

// CB3PlayerCar::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCar.cpp.
// 0x00150BE0
int CB3PlayerCar::Prepare()
{
    field_2464 = (field_2464 & 224);
    field_2464 = (field_2464 & 31);
    field_2465 = 0;
    field_2466 = (field_2466 & -8);
    field_2466 = (field_2466 & 247);
    field_2466 = (field_2466 & 239);
    int r0 = Prepare__8CB3AICarFv(this);
    if ((r0 & 255) != 0) {
        UnkStruct_00150BE0_1 * t0 = field_1788;
        if (t0 != 0) {
            UnkStruct_00150BE0_2 * t1 = t0->field_0;
            if (t1 != 0) {
                D_0064CE38[field_27C0] = t1->field_40;
            }
        }
    }
    field_27C4 = -1.0f;
    field_27C8 = 0;
    field_27C9 = 0;
    field_2470.Prepare((CB3RaceCar*)this);
    return (r0 & 255);
}

// CB3PlayerCar::Construct(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCar.cpp.
// 0x00150CB0
void CB3PlayerCar::Construct(int p0)
{
    field_27C0 = p0;
    Construct__8CB3AICarFi(this, -1);
    field_1914 = 0;
    field_27C9 = 0;
    field_2470.Construct();
    field_1338 = ((char *)this + 0x2470);
}
