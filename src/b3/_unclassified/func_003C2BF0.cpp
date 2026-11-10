// func_003C2BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004EE040.h"

struct UnkStruct_003C2BF0;

struct UnkStruct_003C2BF0 {
    unsigned char pad_0[0xA0];
    signed char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x7];
    unsigned char field_A8[1];  // [G] element count unknown
    unsigned char pad_A9[0x7];
    unsigned char field_B0;
    unsigned char field_B1;
    unsigned char field_B2;
    unsigned char field_B3;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131CA0(void *);
extern "C" void func_003C2960(UnkStruct_003C2BF0 *);
extern "C" void OnEndOfChallenge__12CB3ChallengeFv(UnkStruct_003C2BF0 *);

// 0x003C2BF0
extern "C" void func_003C2BF0(UnkStruct_003C2BF0 * self)
{
    int r0 = func_00131CA0(&D_004EE040);
    unsigned char v0;
    if ((r0 & 255) != 0) {
        v0 = (((unsigned int)self->field_B3 >> 1) & 255);
    } else {
        v0 = self->field_B3;
    }
    self->field_B1 = (self->field_B1 + 1);
    if (self->field_B1 < (v0 & 255)) {
        func_003C2960(self);
        return;
    }
    for (int i = 0; (i < 8); i++) {
        self->field_A8[i] = self->field_A0[i];
    }
    self->field_B0 = (self->field_B0 + 1);
    if (self->field_B0 >= self->field_B2) {
        OnEndOfChallenge__12CB3ChallengeFv(self);
    } else {
        self->field_B1 = 0;
        func_003C2960(self);
    }
}
