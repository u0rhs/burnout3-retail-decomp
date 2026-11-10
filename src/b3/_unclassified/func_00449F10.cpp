// func_00449F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);

// 0x00449F10
extern "C" void func_00449F10(void *n0_, int p0, int p1, int p2, int p3, int p4)
{
    int n0 = (int)n0_;
    int r0 = func_00271A00(&D_0051BA44, p1);
    func_00449B70((void *)(n0), p0, r0, p2, p3, p4);
}
