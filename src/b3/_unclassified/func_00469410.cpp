// func_00469410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"

extern UnkStruct_D_004E2FC8 D_004E2FC8;

// 0x00469410
extern "C" void func_00469410(int n0)
{
    UnkStruct_00467580_2 * t0 = D_004E2FC8.field_0;
    int t1 = t0->field_0;
    if (t1 == 11) return;
    if (t1 != 12) {
        if (t1 != 13) {
            t0->field_8 = n0;
        }
    }
}
