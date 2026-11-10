// func_00420FC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01EBE3B0.h"

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;
extern "C" int func_00421700(void *);

// 0x00420FC0
extern "C" int func_00420FC0(void *a0, int a1 /* passed by every caller, not read here */)
{
    return func_00421700(&D_01EBE3B0);
}
