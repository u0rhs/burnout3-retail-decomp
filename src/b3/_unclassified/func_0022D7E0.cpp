// func_0022D7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gpEncryptMessageContentsFunction.h"

struct UnkStruct_0022D7E0;

struct UnkStruct_0022D7E0 {
    unsigned char pad_0[0x3];
    signed char field_3;
};

extern UnkStruct__gpEncryptMessageContentsFunction _gpEncryptMessageContentsFunction;
extern "C" void DecryptData__17CGtNetworkMessageFii(UnkStruct_0022D7E0 *, int, int);

// 0x0022D7E0
extern "C" void func_0022D7E0(UnkStruct_0022D7E0 * self, int p0)
{
    if (p0 >= 17) {
        int r0 = ((int (*)(signed char))_gpEncryptMessageContentsFunction.field_0)(self->field_3);
        if (r0 == 0) {
        } else {
            DecryptData__17CGtNetworkMessageFii(self, 16, (p0 + -16));
        }
    } else {
    }
}
