// func_0021B4E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E75640.h"

extern UnkStruct_D_01E75640 D_01E75640;
extern "C" void func_0028B220(void *, void *);

// 0x0021B4E0
extern "C" void func_0021B4E0(void *n0_)
{
    int n0 = (int)n0_;
    func_0028B220(&D_01E75640, (void *)(n0));
}
