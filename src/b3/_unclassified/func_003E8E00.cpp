// func_003E8E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004CB2E0.h"

extern unsigned long kaB3HardCodedCrashStageList[];  // [G] element count unknown
extern UnkStruct_D_004CB2E0 D_004CB2E0;

// 0x003E8E00
// [G] an inlined linear search (retail falls through to i=-1, shares the address tail); real name unknown
static inline int func_003E8E00_inl0(unsigned long n0)
{
    for (int i = 0; i < 100; i++) {
        if (n0 == kaB3HardCodedCrashStageList[i]) return i;
    }
    return -1;
}
extern "C" void * func_003E8E00(unsigned long n0)
{
    return &D_004CB2E0.field_0[func_003E8E00_inl0(n0)];
}
