// B3Score.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3Score.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3FinishedScore.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/UnkStruct_D_004E0C14.h"
#include "b3/classes/UnkStruct_D_0064D37C.h"

struct UnkStruct_00157360;
struct UnkStruct_00157360_1;
struct UnkStruct_00157360_a1;

struct UnkStruct_00157360_1 {
    unsigned char pad_0[0x16A0];
    void * field_16A0;
    unsigned char field_16A4;
};

struct UnkStruct_00157360_a1 {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x5DC];
    void * field_16AC;
    float field_16B0;
};

struct UnkStruct_00157360 {
    unsigned char pad_0[0xC8];
    UnkStruct_00157360_1 * field_C8;
};

extern UnkStruct_D_004E0C14 D_004E0C14;
extern UnkStruct_D_0064D37C D_0064D37C;

// func_00157360 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00157360
extern "C" void func_00157360(UnkStruct_00157360 * self, UnkStruct_00157360_a1 * p0)
{
    UnkStruct_00157360_1 * t0 = self->field_C8;
    t0->field_16A4 = 1;
    t0->field_16A0 = (void *)p0;
    p0->field_16AC = (void *)t0;
    p0->field_16B0 = p0->field_10CC;
}

// func_00157400 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00157400
extern "C" void func_00157400(CB3Score *self, CB3RaceCar* p0)
{
    self->OnTakeDown(p0);
}

// CB3FinishedScore::Prepare(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// 0x0015C9A0
int CB3FinishedScore::Prepare(int p0)
{
    field_0 = p0;
    field_2 = -1;
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = -1;
    field_18 = 0;
    float t0 = D_004E0C14.field_0;
    for (int i = 0; (i < 8); i++) {
        field_1C[i] = t0;
    }
    field_3C = t0;
    field_40 = -1;
    field_44 = D_0064D37C.field_0;
    field_48 = -1.0f;
    field_4C = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
    field_5C = 0;
    field_60 = 0;
    field_64 = 0;
    field_68 = 0;
    field_6C = 0;
    field_70 = 4;
    field_74 = 4;
    field_78 = 4;
    field_7C = 0;
    field_80 = 0;
    field_84 = -1;
    field_88 = -1;
    field_8C = 0;
    field_90 = 0;
    field_94 = 0;
    field_95 = 0;
    field_98 = 0;
    field_9C = 0;
    field_A0 = 0;
    field_A1 = 0;
    field_A2 = 0;
    for (int i1 = 0; (i1 < 4); i1++) {
        field_AC[i1] = 0;
    }
    for (int i2 = 0; (i2 < 3); i2++) {
        field_BC[i2] = 0;
    }
    return 1;
}
