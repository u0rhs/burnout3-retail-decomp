// func_00469310 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"
#include "b3/classes/UnkStruct_D_004E2FCC.h"

struct UnkStruct_00469310_a1;

struct UnkStruct_00469310_a1 {
    int field_0;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;

// 0x00469310
extern "C" int func_00469310(int n0, UnkStruct_00469310_a1 * p0)
{
    p0->field_0 = 1;
    D_004E2FC8.field_0->field_0 = 13;
    D_004E2FC8.field_0->field_4 = 26;
    ((void (*)(int, int))D_004E2FCC.field_0->field_14)(n0, 13);
    return 0;
}
