// func_003D1000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedCrashStageList.h"

struct UnkStruct_003D1000;
struct UnkStruct_003D1000_e0;

struct UnkStruct_003D1000_e0 {
    unsigned char pad_0[0x17C];
};

struct UnkStruct_003D1000 {
    UnkStruct_003D1000_e0 field_0[1];  // [G] element count unknown
};

// 0x003D1000
extern "C" void * func_003D1000(UnkStruct_003D1000 * self, unsigned long p0)
{
    int r0 = CB3HardCodedCrashStageList::FindCrashStage(p0);
    return ((char *)&self->field_0[r0] + 0x4EC0);
}
