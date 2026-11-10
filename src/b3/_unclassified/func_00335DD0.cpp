// func_00335DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtMalloc.h"
#include "b3/classes/UnkStruct__gMemoryAllocator.h"

extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
extern "C" void *Malloc__9CGtMallocFUi(void *, unsigned);  // CGtMalloc::Malloc(unsigned int)

// 0x00335DD0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void *func_00335DD0(void *self, unsigned n)  // self (a0) unread: callers pass &D_01E3CD44 [C 0x41C930]
{
    return Malloc__9CGtMallocFUi(&_gMemoryAllocator, n);
}
