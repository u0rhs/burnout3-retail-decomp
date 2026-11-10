// func_00335DB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gMemoryAllocator.h"

extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
extern "C" void Free__9CGtMallocFPv(void *, void *);

// 0x00335DB0
extern "C" void func_00335DB0(void *n0_, void *p0_)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    if (p0 == 0) return;
    Free__9CGtMallocFPv(&_gMemoryAllocator, p0_);
}
