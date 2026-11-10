// func_004667D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC4.h"

struct UnkStruct_004667D0;

struct UnkStruct_004667D0 {
    int field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

// 0x004667D0
extern "C" void func_004667D0(UnkStruct_004667D0 * self)
{
    D_004E2FC4.field_0->field_DC = 10;
    D_004E2FC4.field_0->field_E0 = 0;
    D_004E2FC4.field_0->field_E4 = 0;
    D_004E2FC4.field_0->field_E8 = 0;
    D_004E2FC4.field_0->field_F0 = 5;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        D_004E2FC4.field_0->field_F4[i] = 0;
    }
    i++;
loop0_test:
    if (i <= 2) goto loop0_body;
    D_004E2FC4.field_0->field_100 = 0;
    D_004E2FC4.field_0->field_104 = 0;
    self->field_0 = 2;
}
