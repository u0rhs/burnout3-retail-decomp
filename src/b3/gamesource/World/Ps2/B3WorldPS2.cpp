// B3WorldPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3WorldPS2.cpp.
// Area: src/b3/gamesource/World/Ps2, [L] Revenge (SLUS_212.42) GameSource/World/Ps2/B4WorldPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_00665F18.h"

struct UnkStruct_00276870;
struct UnkStruct_00276870_2;
struct UnkStruct_002768F0;
struct UnkStruct_002768F0_3;

struct UnkStruct_00276870_2 {
    unsigned char pad_0[0x18E8];
    unsigned char field_18E8;
};

struct UnkStruct_00276870 {
    unsigned char pad_0[0x12AD1C];
    int field_12AD1C;
    unsigned char pad_12AD20[0x8];
    UnkStruct_00276870_2 * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_002768F0_3 {
    unsigned char pad_0[0x18E8];
    unsigned char field_18E8;
};

struct UnkStruct_002768F0 {
    unsigned char pad_0[0x12AD1C];
    int field_12AD1C;
    unsigned char pad_12AD20[0x8];
    UnkStruct_002768F0_3 * field_12AD28[1];  // [G] element count unknown
};

extern UnkStruct_D_00665F18 D_00665F18;
extern "C" void Render__8CB3WorldFi(void *, int);  // CB3World::Render(int)

// RenderTwoPlayer__8CB3WorldFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00276870
extern "C" void RenderTwoPlayer__8CB3WorldFv(UnkStruct_00276870 * self)
{
    Render__8CB3WorldFi(self, 0);
    Render__8CB3WorldFi(self, 1);
    for (int i = 0; (i < self->field_12AD1C); i++) {
        self->field_12AD28[i]->field_18E8 = 1;
    }
}

// func_002768F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002768F0
extern "C" void func_002768F0(UnkStruct_002768F0 * self)
{
    if (D_00665F18.field_0 == 0) {
        Render__8CB3WorldFi(self, 0);
    } else {
        Render__8CB3WorldFi(self, 1);
    }
    for (int i = 0; (i < self->field_12AD1C); i++) {
        self->field_12AD28[i]->field_18E8 = 1;
    }
}
