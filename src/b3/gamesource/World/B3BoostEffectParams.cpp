// B3BoostEffectParams.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3BoostEffectParams.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4BoostEffectParams.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3BoostEffectParams.h"
#include "b3/classes/CB3Burn.h"
#include "b3/classes/UnkStruct_D_004C4A10.h"
#include "b3/classes/UnkStruct_D_004C4A20.h"
#include "b3/classes/UnkStruct_D_004E09E4.h"
#include "b3/classes/UnkStruct_D_004E0E94.h"

struct UnkStruct_0030AAE0;
struct UnkStruct_0030AAE0_4;
struct UnkStruct_0030AAE0_a1;
struct UnkStruct_0030B110;

struct UnkStruct_0030AAE0_a1 {
    GtMathPs2::CGtV3d field_0;
    float field_10;
    int field_14;
};

struct UnkStruct_0030AAE0_4 {
    GtMathPs2::CGtV3d field_0;
};

struct UnkStruct_0030AAE0 {
    unsigned char pad_0[0x14];
    float field_14;
};

struct UnkStruct_0030B110 {
    unsigned char pad_0[0x1C];
    float field_1C;
};

extern UnkStruct_D_004C4A10 D_004C4A10;
extern UnkStruct_D_004E0E94 D_004E0E94;
extern UnkStruct_D_004C4A20 D_004C4A20;
extern UnkStruct_D_004E09E4 D_004E09E4;

// func_0030AAE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030AAE0
extern "C" void func_0030AAE0(UnkStruct_0030AAE0 * self, UnkStruct_0030AAE0_a1 * p0, int p1)
{
    UnkStruct_0030AAE0_4 local;
    if (self->field_14 > 0.0f) {
        float v1;
        if (p1 != 0) {
            local.field_0.mData = D_004C4A20.field_0;
            v1 = D_004E09E4.field_0;
            p0->field_14 = 2;
        } else {
            local.field_0.mData = D_004C4A10.field_0;
            v1 = D_004E0E94.field_0;
            p0->field_14 = 1;
        }
        float t = self->field_14;
        if (t >= 1.0f) {
            p0->field_10 = v1 * t;
            p0->field_0 = local.field_0;
        } else {
            p0->field_10 = v1;
            p0->field_0 = local.field_0 * t;
        }
    } else {
        p0->field_10 = 0.0f;
    }
}

// CB3BoostEffectParams::Stop() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BoostEffectParams.cpp.
// 0x0030B100
void CB3BoostEffectParams::Stop()
{
}

// func_0030B110 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030B110
extern "C" float func_0030B110(UnkStruct_0030B110 * self)
{
    float m0 = (self->field_1C - 1.0f);
    m0 = m0 * m0;
    return (1.0f - m0);
}

// CB3BoostEffectParams::Prepare(CB3Burn*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BoostEffectParams.cpp.
// 0x0030B530
int CB3BoostEffectParams::Prepare(CB3Burn* p0)
{
    field_0 = p0;
    field_4 = 0;
    field_8 = 0;
    field_C = 0;
    field_10 = 0;
    field_14 = 0;
    field_20 = 0;
    return 1;
}
