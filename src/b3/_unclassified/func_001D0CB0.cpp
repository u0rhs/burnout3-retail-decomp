// func_001D0CB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00522660.h"
#include "b3/classes/UnkStruct_D_0064D3A0.h"

struct UnkStruct_001D0CB0;

struct UnkStruct_001D0CB0 {
    unsigned char pad_0[0x1554];
    signed char field_1554;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;

// 0x001D0CB0
extern "C" void * func_001D0CB0(UnkStruct_001D0CB0 * self)
{
    void * v1;
    if (D_0064D3A0.field_0 == 0) {
        v1 = 0;
    } else {
        v1 = ((char *)((char *)&D_00522660 + (self->field_1554 * 10192)) + 0x12AD50);
    }
    return v1;
}
