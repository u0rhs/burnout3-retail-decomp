// func_0023B6A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051B85C.h"

struct UnkStruct_0023B6A0;

struct UnkStruct_0023B6A0 {
    unsigned char pad_0[0x4F8];
    unsigned char field_4F8;
    unsigned char pad_4F9[0x3];
    int field_4FC;
};

extern UnkStruct_D_0051B85C D_0051B85C;

// 0x0023B6A0
extern "C" int func_0023B6A0(UnkStruct_0023B6A0 * self)
{
    int v0;
    if (self->field_4F8 != 0) {
        v0 = (((self->field_4FC + 1000) < D_0051B85C.field_0->field_14) ^ 1);
    } else {
        v0 = 0;
    }
    return v0;
}
