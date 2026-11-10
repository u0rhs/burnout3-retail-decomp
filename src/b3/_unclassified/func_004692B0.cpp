// func_004692B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"

extern UnkStruct_D_004E2FC8 D_004E2FC8;

// 0x004692B0
extern "C" int func_004692B0(int n0)
{
    if (D_004E2FC8.field_0->field_4 != 1) {
        return 18;
    }
    if (((n0 == 0) || (n0 == 3)) || (n0 == 17)) {
        return n0;
    }
    return 16;
}
