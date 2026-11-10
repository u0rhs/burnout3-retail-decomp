// B3StageLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3StageLogic.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [L] Revenge (SLUS_212.42) GameSource/Game/Logic/B4StageLogic.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/UnkStruct_D_0055EFEC.h"

struct UnkStruct_003959F0_a2;
struct UnkStruct_003959F0_a3;
struct UnkStruct_00395A00_a1;

struct UnkStruct_003959F0_a2 {
    unsigned char pad_0[0x4C];
    int field_4C;
};

struct UnkStruct_003959F0_a3 {
    int field_0;
};

struct UnkStruct_00395A00_a1 {
    unsigned char pad_0[0x16B4];
    float field_16B4;
    unsigned char pad_16B8[0x2F4];
    signed char field_19AC;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;

// CB3StageLogic::AssignStartPositionIndex(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3StageLogic.cpp.
// 0x00395920
int CB3StageLogic::AssignStartPositionIndex(int p0)
{
    return p0;
}

// func_003959E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003959E0
extern "C" void func_003959E0()
{
}

// func_003959F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003959F0
extern "C" void func_003959F0(int n0, int p0, UnkStruct_003959F0_a2 * p1, UnkStruct_003959F0_a3 * p2)
{
    p2->field_0 = p1->field_4C;
}

// ResetCarDamage__13CB3StageLogicFP10CB3RaceCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00395A00
extern "C" void ResetCarDamage__13CB3StageLogicFP10CB3RaceCar(void *n0_, UnkStruct_00395A00_a1 * p0)
{
    int n0 = (int)n0_;
    signed char t0 = p0->field_19AC;
    UnkStruct_00150E20_3 * t1 = D_0055EFEC.field_0[t0].field_0;
    p0->field_16B4 = 1.0f;
    t1->vfunc_14(p0, t0);
}
