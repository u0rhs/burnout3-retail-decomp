// B3World.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3World.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4World.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundGameModeManager.h"
#include "b3/classes/CB3TrailEmitterData.h"
#include "b3/classes/EB3RaceCarType.h"
#include "b3/classes/UnkStruct_D_01E77544.h"

struct UnkStruct_00199D90;
struct UnkStruct_00199D90_a1;

struct UnkStruct_00199D90_a1 {
    unsigned char pad_0[0x4];
    float field_4;
};

struct UnkStruct_00199D90 {
    unsigned char pad_0[0x4];
    float field_4;
};

extern UnkStruct_D_01E77544 D_01E77544;
extern CB3SoundGameModeManager D_01E77540;

// func_00199D90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00199D90
extern "C" int func_00199D90(UnkStruct_00199D90 * self, UnkStruct_00199D90_a1 * p0)
{
    return self->field_4 > p0->field_4 ? -1 : 1;
}

// UpdateSound__8CB3WorldFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00199DC0
extern "C" void UpdateSound__8CB3WorldFv()
{
    if (D_01E77544.field_0 == 23) {
        D_01E77540.Update();
    }
}

// CB3TrailEmitterData::CB3TrailEmitterData() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3World.cpp.
// 0x0019B6B0
CB3TrailEmitterData::CB3TrailEmitterData()
{
}

// GtMathPs2::CGtV3d::CGtV3d() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3World.cpp.
// 0x0019B6C0
extern "C" void *__ct__Q29GtMathPs26CGtV3dFv(void *self) { return self; }

// GtMathPs2::CGtMatrix3x3::CGtMatrix3x3() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3World.cpp.
// 0x0019B6D0
extern "C" void *__ct__Q29GtMathPs212CGtMatrix3x3Fv(void *self) { return self; }
