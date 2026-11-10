// func_00335F60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gMemoryAllocator.h"

struct UnkStruct_00335F60;

struct UnkStruct_00335F60 {
    unsigned char pad_0[0x638];
    void * field_638;
    unsigned char pad_63C[0x8];
    void * field_644;
};

extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
extern "C" void Free__9CGtMallocFPv(void *, void *);
extern "C" void func_00403830(void *);

// 0x00335F60
extern "C" void func_00335F60(UnkStruct_00335F60 * self)
{
    void * t0 = self->field_644;
    if (t0 != 0) {
        if (t0 != 0) {
            Free__9CGtMallocFPv(&_gMemoryAllocator, t0);
        }
        self->field_644 = 0;
    }
    void * t1 = self->field_638;
    if (t1 != 0) {
        func_00403830(t1);
        self->field_638 = 0;
    }
}
