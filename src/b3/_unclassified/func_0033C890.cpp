// func_0033C890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gMemoryAllocator.h"

extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
extern "C" void Free__9CGtMallocFPv(void *, void *);

// 0x0033C890
extern "C" void func_0033C890(int n0)
{
    if (n0 == 0) return;
    Free__9CGtMallocFPv(&_gMemoryAllocator, (void *)(n0));
}
