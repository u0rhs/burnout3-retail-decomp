// func_00456500 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051A9A0.h"

struct UnkStruct_00456500;

struct UnkStruct_00456500 {
    unsigned char pad_0[0x70];
    float field_70;
    unsigned char pad_74[0x8];
    int field_7C;
};

extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern "C" void func_00455B20(UnkStruct_00456500 *);

// 0x00456500
extern "C" void func_00456500(UnkStruct_00456500 * self, float f0, float f1, float f2)
{
    if (self->field_7C != 7 && D_0051A9A0.field_0 != 23) {
        return;
    }
    self->field_70 += f0;
    func_00455B20(self);
}
