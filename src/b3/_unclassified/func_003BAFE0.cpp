// func_003BAFE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E901C8.h"

struct UnkStruct_003BAFE0;

struct UnkStruct_003BAFE0 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    int field_10;
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x14];
    int field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x14];
    unsigned char field_44[1];  // [G] element count unknown
    unsigned char pad_45[0x5];
    unsigned char field_4A[1];  // [G] element count unknown
    unsigned char pad_4B[0xD];
    unsigned char field_58;
};

extern UnkStruct_D_01E901C8 D_01E901C8;
extern int D_01E901DC[];  // [G] element count unknown
extern "C" int func_003BA890(UnkStruct_003BAFE0 *);

// 0x003BAFE0
extern "C" int func_003BAFE0(UnkStruct_003BAFE0 * self)
{
    if (self->field_10 <= 0) {
        self->field_10 = 0;
        for (int i = 0; (i < 6); i++) {
            self->field_14[i] = 0;
            self->field_2C[i] = 0;
            self->field_44[i] = i;
            self->field_4A[i] = i;
        }
    }
    if (self->field_58 != 0) {
        return 1;
    }
    for (int i1 = 0; (i1 < 6); i1++) {
        self->field_14[i1] = 0;
        self->field_2C[i1] = 0;
        self->field_44[i1] = i1;
        self->field_4A[i1] = i1;
    }
    int r0 = func_003BA890(self);
    if (r0 != 0) {
        self->field_8 = D_01E901C8.field_0;
        self->field_C = D_01E901DC[self->field_10];
        self->field_58 = 1;
        return 1;
    }
    return 0;
}
