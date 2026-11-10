// func_003F58D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004CE2E4.h"

extern UnkStruct_D_004CE2E4 D_004CE2E4;

// 0x003F58D0
extern "C" float func_003F58D0(int n0, int p0)
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
    return ((float)D_004CE2E4.field_0[(p0 + v0)].field_0);
}
