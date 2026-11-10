// func_0030A990 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E0FC8.h"

struct UnkStruct_0030A990;

struct UnkStruct_0030A990 {
    unsigned char pad_0[0x1C];
    float field_1C;
    float field_20;
};

extern UnkStruct_D_004E0FC8 D_004E0FC8;

// 0x0030A990
extern "C" float func_0030A990(UnkStruct_0030A990 * self)
{
    float a = self->field_20 - 1.0f;
    a *= a;
    float b = self->field_1C - 1.0f;
    b *= b;
    float r = D_004E0FC8.field_0 * (1.0f - a);
    return r * (1.0f - b);
}
