// func_00255E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E0A40.h"

struct UnkStruct_00255E60;

struct UnkStruct_00255E60 {
    int field_0;
    float field_4;
    int field_8;
};

extern UnkStruct_D_004E0A40 D_004E0A40;

// 0x00255E60
extern "C" void func_00255E60(UnkStruct_00255E60 * self)
{
    if (self->field_8 == 0) {
        float t0 = D_004E0A40.field_0;
        self->field_8 = 2;
        self->field_0 = 0;
        self->field_4 = t0;
    }
}
