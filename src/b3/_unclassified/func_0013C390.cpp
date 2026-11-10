// func_0013C390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BFA0.h"

struct UnkStruct_0013C390;

struct UnkStruct_0013C390 {
    unsigned char field_0[1];  // [G] element count unknown
    unsigned char pad_1[0x13];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;

// 0x0013C390
extern "C" void func_0013C390(UnkStruct_0013C390 * self, int a1 /* passed by every caller, not read here */)
{
    for (int i = 0; (i < 20); i++) {
        self->field_0[i] = D_0051BFA0.field_43[i];
    }
    self->field_14 = 0;
    self->field_18 = 0;
    self->field_1C = 0;
    self->field_20 = 0;
    self->field_24 = 0;
    self->field_28 = 0;
    self->field_2C = 0;
    self->field_30 = 0;
    self->field_34 = 0;
    self->field_38 = 0;
    self->field_3C = 0;
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
}
