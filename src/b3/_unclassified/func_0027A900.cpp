// func_0027A900 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1AE4.h"

struct UnkStruct_0027A900;

struct UnkStruct_0027A900 {
    unsigned char pad_0[0x834];
    float field_834;
    float field_838;
    float field_83C;
};

extern UnkStruct_D_004E1AE4 D_004E1AE4;

// 0x0027A900
extern "C" float func_0027A900(UnkStruct_0027A900 * self, float f0)
{
    self->field_834 = f0;
    self->field_838 = (0.85f * f0);
    float t0 = D_004E1AE4.field_0;
    self->field_83C = (f0 * t0);
    return (f0 * t0);
}
