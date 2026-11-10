// func_004230D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0064EAE8.h"

struct UnkStruct_004230D0;

struct UnkStruct_004230D0 {
    unsigned char pad_0[0x4];
    int field_4[1];  // [G] element count unknown
    unsigned char pad_8[0x70];
    int field_78[1];  // [G] element count unknown
    unsigned char pad_7C[0x70];
    int field_EC[1];  // [G] element count unknown
    unsigned char pad_F0[0x84];
    unsigned char field_174;
};

extern UnkStruct_D_0064EAE8 D_0064EAE8;

// 0x004230D0
extern "C" void func_004230D0(UnkStruct_004230D0 * self)
{
    switch (D_0064EAE8.field_0) {
    case 4:
        return;
    case 0:
        self->field_4[self->field_174] = 17;
        self->field_78[self->field_174] = 11;
        break;
    case 1:
        self->field_4[self->field_174] = 17;
        self->field_78[self->field_174] = 12;
        break;
    case 2:
        self->field_4[self->field_174] = 17;
        self->field_78[self->field_174] = 13;
        break;
    }
    self->field_EC[self->field_174] = 0;
    self->field_174++;
}
