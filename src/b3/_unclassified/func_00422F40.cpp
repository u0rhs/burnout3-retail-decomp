// func_00422F40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0064EB08.h"
#include "b3/classes/UnkStruct_D_006512D8.h"

struct UnkStruct_00422F40;

struct UnkStruct_00422F40 {
    unsigned char pad_0[0x4];
    int field_4[1];  // [G] element count unknown
    unsigned char pad_8[0x70];
    int field_78[1];  // [G] element count unknown
    unsigned char pad_7C[0x70];
    int field_EC[1];  // [G] element count unknown
    unsigned char pad_F0[0x84];
    unsigned char field_174;
};

extern UnkStruct_D_006512D8 D_006512D8;
extern UnkStruct_D_0064EB08 D_0064EB08;

// 0x00422F40
extern "C" void func_00422F40(UnkStruct_00422F40 * self, int p0)
{
    if (p0 != 0) {
        self->field_4[self->field_174] = 14;
        self->field_78[self->field_174] = 0;
        self->field_EC[self->field_174] = 0;
        self->field_174 = (self->field_174 + 1);
        self->field_4[self->field_174] = 15;
        self->field_78[self->field_174] = 0;
        self->field_EC[self->field_174] = 0;
        self->field_174 = (self->field_174 + 1);
        self->field_4[self->field_174] = 16;
        self->field_78[self->field_174] = 0;
        self->field_EC[self->field_174] = 0;
        self->field_174 = (self->field_174 + 1);
    }
    int t1 = D_0064EB08.field_0;
    int t0 = D_006512D8.field_0;
    self->field_4[self->field_174] = 18;
    if (t1 != t0) {
        if (t1 > t0) {
            self->field_78[self->field_174] = 8;
            self->field_EC[self->field_174] = 8;
        } else {
            self->field_78[self->field_174] = 9;
            self->field_EC[self->field_174] = 9;
        }
    } else {
        self->field_78[self->field_174] = 10;
        self->field_EC[self->field_174] = 10;
    }
    self->field_174 = (self->field_174 + 1);
}
