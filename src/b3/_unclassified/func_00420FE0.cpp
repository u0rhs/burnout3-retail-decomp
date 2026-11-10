// func_00420FE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01EBE3B0.h"

extern UnkStruct_D_01EBE3B0 D_01EBE3B0;

// 0x00420FE0
extern "C" void * func_00420FE0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    return ((char *)((char *)&D_01EBE3B0 + (p0 * 1180)) + 0xE390);
}
