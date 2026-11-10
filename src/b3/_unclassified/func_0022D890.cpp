// func_0022D890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gpEncryptMessageContentsFunction.h"

struct UnkStruct_0022D890;

struct UnkStruct_0022D890 {
    unsigned char field_0;
    unsigned char pad_1[0x2];
    signed char field_3;
};

extern UnkStruct__gpEncryptMessageContentsFunction _gpEncryptMessageContentsFunction;
extern "C" void func_0022D5E0(UnkStruct_0022D890 *, int, int);

// 0x0022D890
extern "C" void func_0022D890(UnkStruct_0022D890 * self, int p0)
{
    int v0 = 0;
    if (p0 > 16) {
        int r0 = ((int (*)(signed char))_gpEncryptMessageContentsFunction.field_0)(self->field_3);
        v0 = (r0 & 255);
    }
    func_0022D5E0(self, 3, 13);
    if (v0 != 0) {
        func_0022D5E0(self, 16, (p0 + -16));
    } else {
    }
    self->field_0 = (self->field_0 | 2);
}
