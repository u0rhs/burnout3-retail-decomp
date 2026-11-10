// func_003C21F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"

struct UnkStruct_003C21F0 {
    unsigned char pad_0[0x20];
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0x16];
    unsigned long field_38;
};

extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003C21F0
extern "C" void func_003C21F0(UnkStruct_003C21F0 * self, unsigned long p0)
{
    if (p0 == self->field_38) return;
    self->field_38 = p0;
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    self->field_20 = ((p0 & 0x419E9003) != 0);
    self->field_21 = ((p0 & 0x1C00020681C) != 0);
    func_0031ECD0(&D_01E89800, p0, 3);
}
