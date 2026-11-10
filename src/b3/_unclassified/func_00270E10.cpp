// func_00270E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2A14.h"

struct UnkStruct_00270E10;

struct UnkStruct_00270E10 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x32638];
    int field_32664;
};

extern UnkStruct_D_004E2A14 D_004E2A14;
extern "C" void * func_002366D0(UnkStruct_00270E10 *, int);
extern "C" void func_0023B8C0(void *);
extern "C" void func_00236B30(UnkStruct_00270E10 *, int);

// 0x00270E10
extern "C" void func_00270E10(UnkStruct_00270E10 * self)
{
    if (self->field_32664 != 23) return;
    for (int i = 0; (i < self->field_28); i++) {
        void * r0 = func_002366D0(self, i);
        if (r0 != 0) {
            func_0023B8C0(r0);
        }
    }
    unsigned short v2 = D_004E2A14.field_0;
    if (D_004E2A14.field_0 == 65535) {
        v2 = 0;
    }
    func_00236B30(self, (v2 & 65535));
}
