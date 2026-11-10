// func_003EA4C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004A5420.h"
#include "b3/classes/UnkStruct_D_004A5424.h"

struct UnkStruct_003EA4C0_a2;
struct UnkStruct_003EA4C0_a3;

struct UnkStruct_003EA4C0_a2 {
    int field_0;
};

struct UnkStruct_003EA4C0_a3 {
    int field_0;
};

extern UnkStruct_D_004A5420 D_004A5420;
extern UnkStruct_D_004A5424 D_004A5424;

// 0x003EA4C0
extern "C" void func_003EA4C0(int n0, int p0, UnkStruct_003EA4C0_a2 * p1, UnkStruct_003EA4C0_a3 * p2)
{
    int v0;
    switch (n0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    p1->field_0 = D_004A5420.field_0[(p0 + v0)].field_0;
    p2->field_0 = D_004A5424.field_0[(p0 + v0)].field_0;
}
