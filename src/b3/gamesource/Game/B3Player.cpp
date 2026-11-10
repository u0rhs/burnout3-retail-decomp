// B3Player.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3Player.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4Player.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_004F50C0.h"

struct UnkStruct_00135A90;
struct UnkStruct_00135AF0;

struct UnkStruct_00135A90 {
    unsigned char pad_0[0x1C];
    float field_1C;
};

struct UnkStruct_00135AF0 {
    void * field_0;
    unsigned char pad_4[0x14];
    signed char field_18;
    unsigned char pad_19[0x3];
    float field_1C;
};

struct UnkStruct_00135B40 {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x4];
    unsigned char field_20;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern signed char D_004F6061[];  // [G] element count unknown
extern UnkStruct_D_004F50C0 D_004F50C0;

// func_00135A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135A90
extern "C" void func_00135A90(UnkStruct_00135A90 * self)
{
    self->field_1C = D_004F50A0.field_0;
}

// Prepare__9CB3PlayerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135AF0
extern "C" int Prepare__9CB3PlayerFv(UnkStruct_00135AF0 * self)
{
    self->field_0 = ((char *)&D_004F50C0.field_0[D_004F6061[self->field_18]] + 0xD48);
    self->field_1C = D_004F50A0.field_0;
    return 1;
}

// func_00135B40 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00135B40
extern "C" void func_00135B40(UnkStruct_00135B40 *self, int p0)
{
    self->field_20 = 0;
    self->field_18 = p0;
}
