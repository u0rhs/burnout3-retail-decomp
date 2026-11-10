// B3AICar.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3AICar.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4AICar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3AICar.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3SoundRaceCarManager.h"
#include "b3/classes/EB3RaceCarType.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/UnkStruct_D_0064D370.h"
#include "b3/classes/UnkStruct_D_0064D37A.h"

extern UnkStruct_D_0064D370 D_0064D370;
extern CB3SoundRaceCarManager D_01E77550;
extern UnkStruct_D_0064D37A D_0064D37A;
extern "C" void PrepareSound__10CB3RaceCarFv(void *);  // CB3RaceCar::PrepareSound()
extern "C" void Release__10CB3RaceCarFv(void *);  // CB3RaceCar::Release()
extern "C" void StopCrashing__10CB3RaceCarFv(void *);  // CB3RaceCar::StopCrashing()
extern "C" void ResetTarget__11CB3AITargetFv(void *);  // CB3AITarget::ResetTarget()
extern "C" void func_00143860(CB3AICar *, unsigned char);

// CB3AICar::IncreaseAggression(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// 0x00141BC0
float CB3AICar::IncreaseAggression(float p0)
{
    field_23D0 = (field_23D0 + (field_23E0 * p0));
    float t0 = field_23E4;
    float t1 = field_23D0;
    if (!(t1 <= t0)) {
        field_23D0 = t0;
    }
    return t1;
}

// CB3AICar::PrepareSound() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// 0x00142350
int CB3AICar::PrepareSound()
{
    PrepareSound__10CB3RaceCarFv(this);
    if (D_0064D370.field_0 == 0) {
        return 1;
    }
    if (field_1918 == 0) {
        int r1 = D_01E77550.RequestRaceCar((EB3RaceCarType)1);
        field_1918 = (UnkStruct_00142350_2 *)r1;
    }
    if (field_1918 == 0) {
        return 1;
    }
    int r2 = field_1918->vfunc_8(field_1960, field_19AC);
    return r2;
}

// CB3AICar::StopCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// 0x00143A80
void CB3AICar::StopCrashing()
{
    func_00143860(this, D_0064D37A.field_0);
    StopCrashing__10CB3RaceCarFv(this);
    field_19B0.Zero();
    field_19C0.Zero();
    ResetTarget__11CB3AITargetFv(((char *)this + 0x19F0));
}

// CB3AICar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// 0x00143AD0
void CB3AICar::Release()
{
    field_19F0.Release();
    Release__10CB3RaceCarFv(this);
    field_2454 = 24;
}
