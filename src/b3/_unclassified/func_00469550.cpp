// func_00469550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2668.h"
#include "b3/classes/UnkStruct_D_004E2FD0.h"
#include "b3/classes/UnkStruct_D_004E2FD8.h"

extern UnkStruct_D_004E2668 D_004E2668;
extern UnkStruct_D_004E2FD0 D_004E2FD0;
extern UnkStruct_D_004E2FD8 D_004E2FD8;

// 0x00469550
extern "C" int func_00469550()
{
    int t = D_004E2668.field_0;
    if (t == 5 || t == 7 || t == 8) {
        D_004E2FD8.field_0 = D_004E2FD0.field_0;
        D_004E2668.field_0 = 5;
    }
    return 0;
}
