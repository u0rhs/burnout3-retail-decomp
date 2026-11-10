// func_0026C9C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2A24.h"
#include "b3/classes/UnkStruct_D_004E2A28.h"

extern UnkStruct_D_004E2A24 D_004E2A24;
extern UnkStruct_D_004E2A28 D_004E2A28;

// 0x0026C9C0
extern "C" int func_0026C9C0(int n0, int p0, int p1, int p2, int p3, int p4)
{
    if ((p4 & 2) == 2) {
        D_004E2A24.field_0 = (D_004E2A24.field_0 + 1);
    }
    D_004E2A28.field_0 = (D_004E2A28.field_0 + 1);
    return 1;
}
