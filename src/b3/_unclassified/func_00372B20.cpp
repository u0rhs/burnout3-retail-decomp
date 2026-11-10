// func_00372B20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E898E8.h"

extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x00372B20
extern "C" void func_00372B20(int n0, void *a1 /* passed by every caller, not read here */)
{
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    if (n0 != 0) {
        func_0032D080(&D_01E898E8, 2, 56, 0, 0);
    } else {
        func_0032D080(&D_01E898E8, 2, 57, 0, 0);
    }
}
