// func_003E9690 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004CBF00.h"
#include "b3/classes/UnkStruct_D_004CBF04.h"

extern UnkStruct_D_004CBF00 D_004CBF00;
extern UnkStruct_D_004CBF04 D_004CBF04;

// 0x003E9690
extern "C" int func_003E9690(int n0, int p0)
{
    int v0;
    if (p0 != 0) {
        v0 = D_004CBF00.field_0[n0].field_0;
    } else {
        v0 = D_004CBF04.field_0[n0].field_0;
    }
    return v0;
}
