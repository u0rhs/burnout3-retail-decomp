// func_004690E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"

extern UnkStruct_D_004E2FC8 D_004E2FC8;

// 0x004690E0
extern "C" int func_004690E0(int n0)
{
    UnkStruct_00467580_2 * t0 = D_004E2FC8.field_0;
    int t1 = t0->field_4;
    if ((((t1 == 24) || (t1 == 8)) || (t1 == 12)) || (t1 == 16)) {
        if (((((n0 == 0) || (n0 == 3)) || (n0 == 4)) || (n0 == 9)) || (n0 == 17)) {
            return n0;
        }
        return 16;
    }
    return 18;
}
