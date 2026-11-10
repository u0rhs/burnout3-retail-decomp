// func_002F4F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00665EA0.h"

struct UnkStruct_002F4F10;

struct UnkStruct_002F4F10 {
    float field_0;
    float field_4;
    unsigned char pad_8[0x4];
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    int field_24;
    int field_28;
};

extern UnkStruct_D_00665EA0 D_00665EA0;

// 0x002F4F10
extern "C" int func_002F4F10(UnkStruct_002F4F10 * self)
{
    self->field_0 = 0.5f;
    if (D_00665EA0.field_0 != 0) {
        self->field_C = 500.0f;
    } else {
        self->field_C = 50.0f;
    }
    self->field_10 = 150.0f;
    self->field_24 = 2;
    self->field_28 = 3;
    self->field_4 = 1.0f;
    self->field_14 = 150.0f;
    self->field_18 = 0.153f;
    self->field_1C = 0.6f;
    self->field_20 = 0.35f;
    return 1;
}
