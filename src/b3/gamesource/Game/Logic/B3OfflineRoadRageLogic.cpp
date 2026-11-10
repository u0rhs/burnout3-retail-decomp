// B3OfflineRoadRageLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 11 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3OfflineRoadRageLogic.cpp, 2 by a medium-confidence name confirmed by a neighbour, 9 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashActionDirector.h"
#include "b3/classes/CB3OfflineRoadRageLogic.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/UnkStruct_D_004E0F5C.h"
#include "b3/classes/UnkStruct_D_0055EFEC.h"

struct UnkStruct_0038C060_a2;
struct UnkStruct_0038C060_a3;
struct UnkStruct_0038C360_a1;
struct UnkStruct_00395A00_a1;

struct UnkStruct_0038C060_a2 {
    unsigned char pad_0[0x68];
    int field_68;
};

struct UnkStruct_0038C060_a3 {
    int field_0;
};

struct UnkStruct_0038C360_a1 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_004E0F5C D_004E0F5C;
extern CB3CrashActionDirector D_0055E948;
extern "C" void func_001CC520(UnkStruct_00150E20_3 *, int, int, float);

// CB3OfflineRoadRageLogic::GetHUDType() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineRoadRageLogic.cpp.
// 0x0038BFD0
int CB3OfflineRoadRageLogic::GetHUDType()
{
    return 7;
}

// func_0038BFE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038BFE0
extern "C" int func_0038BFE0()
{
    return 1;
}

// func_0038BFF0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038BFF0
extern "C" int func_0038BFF0()
{
    return 3;
}

// func_0038C000 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C000
extern "C" int func_0038C000()
{
    return 1;
}

// func_0038C010 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C010
extern "C" int func_0038C010()
{
    return 0;
}

// CB3OfflineRoadRageLogic::GetScoreModeFlags() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineRoadRageLogic.cpp.
// 0x0038C020
int CB3OfflineRoadRageLogic::GetScoreModeFlags()
{
    return 2;
}

// func_0038C030 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C030
extern "C" int func_0038C030()
{
    return 3;
}

// func_0038C040 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C040
extern "C" int func_0038C040()
{
    return 6;
}

// func_0038C050 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C050
extern "C" int func_0038C050()
{
    return 1;
}

// func_0038C060 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C060
extern "C" void func_0038C060(int n0, int p0, UnkStruct_0038C060_a2 * p1, UnkStruct_0038C060_a3 * p2)
{
    p2->field_0 = p1->field_68;
}

// OnPlayerCarDeath__23CB3OfflineRoadRageLogicFP12CB3PlayerCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0038C360
extern "C" void OnPlayerCarDeath__23CB3OfflineRoadRageLogicFP12CB3PlayerCar(CB3OfflineRoadRageLogic * self, UnkStruct_0038C360_a1 * p0)
{
    self->RaceCarKilled((CB3RaceCar*)p0, 0);
    signed char t0 = p0->field_19AC;
    UnkStruct_00150E20_3 * t1 = D_0055EFEC.field_0[t0].field_0;
    D_0055E948.StartRaceCarCrashing((CB3RaceCarPhysics*)t1, t0, 0, 0);
    func_001CC520(t1, 10, 0, D_004E0F5C.field_0);
    t1->field_CC4->field_1015 = (t1->field_CC4->field_1015 | 24);
}
