// func_003C28E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004EE040.h"

struct UnkStruct_003C28E0;

struct UnkStruct_003C28E0 {
    unsigned char pad_0[0xB1];
    unsigned char field_B1;
    unsigned char pad_B2[0x1];
    unsigned char field_B3;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131CA0(void *);

// 0x003C28E0
extern "C" int func_003C28E0(UnkStruct_003C28E0 * self)
{
    int r0 = func_00131CA0(&D_004EE040);
    int v0;
    if ((r0 & 255) != 0) {
        v0 = (((unsigned int)self->field_B3 >> 1) & 255);
    } else {
        v0 = self->field_B3;
    }
    return (((self->field_B1 + 1) < (v0 & 255)) ^ 1);
}
