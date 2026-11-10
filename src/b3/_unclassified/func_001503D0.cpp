// func_001503D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00665EA0.h"

struct UnkStruct_001503D0;

struct UnkStruct_001503D0 {
    unsigned char pad_0[0x18C0];
    int field_18C0;
    unsigned char pad_18C4[0x1C];
    int field_18E0;
    unsigned char pad_18E4[0xEE5];
    unsigned char field_27C9;
};

extern UnkStruct_D_00665EA0 D_00665EA0;

// 0x001503D0
extern "C" int func_001503D0(UnkStruct_001503D0 * self)
{
    int v1;
    if (self->field_27C9 != 0) {
        int v0;
        if (D_00665EA0.field_0 != 0) {
            v0 = self->field_18C0;
        } else {
            v0 = self->field_18E0;
        }
        v1 = v0;
    } else {
        v1 = self->field_18C0;
    }
    return v1;
}
