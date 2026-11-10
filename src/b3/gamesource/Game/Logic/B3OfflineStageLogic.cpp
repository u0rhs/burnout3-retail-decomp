// B3OfflineStageLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OfflineStageLogic.cpp, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OfflineStageLogic.h"

struct UnkStruct_003952F0;
struct UnkStruct_003952F0_e0;

struct UnkStruct_003952F0_e0 {
    unsigned char pad_0[0xE];
    unsigned char field_E;
    unsigned char pad_F[0x1];
};

struct UnkStruct_003952F0 {
    unsigned char pad_0[0x20];
    UnkStruct_003952F0_e0 field_20[1];  // [G] element count unknown
};

struct UnkStruct_00395560 {
    unsigned char pad_0[0x5];
    unsigned char field_5;
};

struct UnkStruct_00395570 {
    unsigned char pad_0[0x5];
    unsigned char field_5;
};

// func_003952F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003952F0
extern "C" unsigned char func_003952F0(UnkStruct_003952F0 * self, int p0)
{
    return self->field_20[p0].field_E;
}

// func_00395300 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00395300
extern "C" int func_00395300()
{
    return 0;
}

// func_00395560 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00395560
extern "C" void func_00395560(UnkStruct_00395560 *self)
{
    self->field_5 = 0;
}

// func_00395570 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00395570
extern "C" void func_00395570(UnkStruct_00395570 *self)
{
    self->field_5 = 0;
}

// CB3OfflineStageLogic::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// 0x003957D0
void CB3OfflineStageLogic::Construct()
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        field_20[i].field_8 = i;
    }
    i++;
loop0_test:
    if (i < 2) goto loop0_body;
    field_5 = 0;
}
