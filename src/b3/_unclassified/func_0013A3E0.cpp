// func_0013A3E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BFA0.h"
#include "b3/classes/UnkStruct_gCalculatedData.h"

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013A3E0
extern "C" int func_0013A3E0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    for (p0++; p0 < 20; p0++) {
        if (D_0051BFA0.field_43[p0] == 0) {
            continue;
        }
        if (((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_43[p0] != 0) {
            continue;
        }
        return p0;
    }
    return -1;
}
