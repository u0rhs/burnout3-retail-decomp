// func_00379380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGtV2d copy p of *field_18 with SetY/Y(); CGtV2d temp for *field_24; lim declared before t).

// func_00379380 -- hand-finished from the lifted source.
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_00379380;
struct UnkStruct_D_01EA4994;

struct UnkStruct_D_01EA4994 {
    short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00379380 {
    unsigned char pad_0[0x14];
    float field_14;
    CGtV2d * field_18;
    unsigned char pad_1C[0x8];
    CGtV2d * field_24;
    float field_28;
};

extern UnkStruct_D_01EA4994 D_01EA4994;

// 0x00379380
extern "C" int func_00379380(UnkStruct_00379380 * self)
{
    float lim = self->field_14;
    float t = self->field_28 - 27.0f;
    if (t < lim) {
        CGtV2d p = *self->field_18;
        if (!(p.Y() < lim)) {
            p.SetY(lim);
            *self->field_18 = p;
            return 0;
        }
        p.SetY(27.0f + p.Y());
        *self->field_18 = p;
        D_01EA4994.field_0 = (short)((self->field_14 - p.Y()) / 27.0f) - 1;
        return 1;
    }
    self->field_28 = t;
    *self->field_24 = CGtV2d(self->field_24->X(), self->field_28);
    return 1;
}
