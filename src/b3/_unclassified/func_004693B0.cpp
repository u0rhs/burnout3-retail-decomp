// func_004693B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"
#include "b3/classes/UnkStruct_D_004E2FCC.h"

struct UnkStruct_004693B0_a1;

struct UnkStruct_004693B0_a1 {
    int field_0;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;

// 0x004693B0
extern "C" int func_004693B0(void *n0_, UnkStruct_004693B0_a1 * p0)
{
    int n0 = (int)n0_;
    p0->field_0 = 1;
    D_004E2FC8.field_0->field_0 = 11;
    D_004E2FC8.field_0->field_4 = 24;
    ((void (*)(int))D_004E2FCC.field_0->field_38)(D_004E2FC8.field_0->field_C);
    return 0;
}
