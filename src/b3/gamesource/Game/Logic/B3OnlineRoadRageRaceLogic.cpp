// B3OnlineRoadRageRaceLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 10 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp, 8 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnlineRoadRageRaceLogic.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/EB3DamageType.h"
#include "b3/classes/EB3ScoreFinishState.h"

struct UnkStruct_0038ED30_a2;
struct UnkStruct_0038ED30_a3;
struct UnkStruct_0038EDA0_a1;

struct UnkStruct_0038ED30_a2 {
    unsigned char pad_0[0x4C];
    int field_4C;
};

struct UnkStruct_0038ED30_a3 {
    int field_0;
};

struct UnkStruct_0038ED90 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
};

struct UnkStruct_0038EDA0_a1 {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x7B3];
    int field_1914;
};

extern "C" void DamageRaceCar__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar13EB3DamageType(void *, void *, void *, EB3DamageType);  // CB3StageLogic::DamageRaceCar(CB3RaceCar*,CB3RaceCar*,EB3DamageType)
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);  // CB3Score::AddScore(int,int), passed 1 more argument(s) [G]
extern "C" void OnPostCrashReset__13CB3StageLogicFP17CB3RaceCarPhysics(void *, void *);  // CB3StageLogic::OnPostCrashReset(CB3RaceCarPhysics*)
extern "C" void HandleCrashReset__8CB3ScoreFv(void *);

// CB3OnlineRoadRageRaceLogic::DamageRaceCar(CB3RaceCar*,CB3RaceCar*,EB3DamageType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp.
// 0x0038ECF0
void CB3OnlineRoadRageRaceLogic::DamageRaceCar(CB3RaceCar* p0, CB3RaceCar* p1, EB3DamageType p2)
{
    if (p0->field_1160 == 0) {
        DamageRaceCar__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar13EB3DamageType(this, (CB3RaceCar*)p0, p1, p2);
    }
}

// func_0038ED30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED30
extern "C" void func_0038ED30(int n0, int p0, UnkStruct_0038ED30_a2 * p1, UnkStruct_0038ED30_a3 * p2)
{
    p2->field_0 = p1->field_4C;
}

// func_0038ED40 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED40
extern "C" int func_0038ED40()
{
    return 1;
}

// func_0038ED50 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED50
extern "C" int func_0038ED50()
{
    return 0;
}

// func_0038ED60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED60
extern "C" int func_0038ED60()
{
    return 0;
}

// func_0038ED70 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED70
extern "C" int func_0038ED70()
{
    return 5;
}

// func_0038ED80 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED80
extern "C" int func_0038ED80()
{
    return 9;
}

// func_0038ED90 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038ED90
extern "C" unsigned char func_0038ED90(UnkStruct_0038ED90 *self)
{
    return self->field_4;
}

// func_0038EDA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038EDA0
extern "C" void func_0038EDA0(int n0, UnkStruct_0038EDA0_a1 * p0, int p1)
{
    if (p0->field_1914 == 0) {
        if (p1 == 1) {
            if (p0->field_1160 == 0) {
                AddScore__8CB3ScoreFii(((char *)p0 + 0x10C0), 3000, -1, 3);
            }
        }
    }
}

// CB3OnlineRoadRageRaceLogic::OnPostCrashReset(CB3RaceCarPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp.
// 0x0038F3E0
void CB3OnlineRoadRageRaceLogic::OnPostCrashReset(CB3RaceCarPhysics* p0)
{
    OnPostCrashReset__13CB3StageLogicFP17CB3RaceCarPhysics(this, (CB3RaceCarPhysics*)p0);
    UnkStruct_0038F3E0_1 * t0 = p0->field_13F4;
    if (t0->field_1160 == 0) {
        t0->field_118C.SetInfiniteBoost(0);
        p0->field_13F4->field_118C.RemoveSegment();
    }
    HandleCrashReset__8CB3ScoreFv(((char *)p0->field_13F4 + 0x10C0));
}
