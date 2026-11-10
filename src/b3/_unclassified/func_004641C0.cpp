// func_004641C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FBC.h"

extern UnkStruct_D_004E2FBC D_004E2FBC;
extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x004641C0
extern "C" int func_004641C0(void * n0)
{
    if (n0 != 0) {
        memcpy(n0, (const void *)D_004E2FBC.field_0, 100);
        return 0;
    }
    return 4;
}
