// func_003BB270 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtMalloc.h"
#include "b3/classes/UnkStruct_D_01EA50F0.h"

extern UnkStruct_D_01EA50F0 D_01EA50F0;
extern "C" void * memset(void *, int, unsigned int);

// 0x003BB270
extern "C" int func_003BB270(void *a0 /* passed by every caller, not read here */)
{
    CGtMalloc::mnPoolOffset = 0;
    memset(&D_01EA50F0, 0, 892);
    return 1;
}
