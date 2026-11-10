// func_004669E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC4.h"

struct UnkStruct_004669E0;
struct UnkStruct_004669E0_a1;

struct UnkStruct_004669E0_a1 {
    int field_0;
};

struct UnkStruct_004669E0 {
    int field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;
extern "C" int func_00465D00(int, int);

// Returns the tail call's value (retail `j func_00465D00`: v0 passes through to the caller).
// 0x004669E0
extern "C" int func_004669E0(UnkStruct_004669E0 * self, UnkStruct_004669E0_a1 * p0)
{
    self->field_0 = 1;
    D_004E2FC4.field_0->field_14C = p0->field_0;
    p0->field_0 = 0;
    return func_00465D00(7, 0);
}
