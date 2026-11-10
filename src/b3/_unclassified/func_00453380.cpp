// func_00453380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near15: d lanes read y-first into floats, CGtV2d(dx,dy) temporaries in the tail).

// func_00453380 -- hand-finished temporaries, which gives retail's f2/f3 colouring). Unnamed in every table, so a placeholder with C linkage; file and
// Area unknown, so _unclassified/. Every type is [G] (instruction widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00453380_s {
    GtMathPs2::CGtV2d * field_0;
    unsigned char pad_4[0x4];
    GtMathPs2::CGtV2d * field_8;
    unsigned char pad_C[0x4];
    GtMathPs2::CGtV2d * field_10;
    unsigned char pad_14[0x4];
};

struct UnkStruct_00453380_e0 {
    unsigned char pad_0[0xC];
    UnkStruct_00453380_s field_C;   // [G] sub-struct: retail addresses it as base+0xC (field_C/14/1C)
};

struct UnkStruct_00453380 {
    UnkStruct_00453380_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_004D3138 {
    GtMathPs2::CGtV2d field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004D3138 D_004D3138;

// [G] inlined helper (name unknown): sets a position from two floats
static inline void func_00453380_set(GtMathPs2::CGtV2d * o, float x, float y)
{
    GtMathPs2::CGtV2d p(x, y);
    *o = p;
}

// 0x00453380
extern "C" void func_00453380(UnkStruct_00453380 * self, int p0, int p1, float f0, float f1, float f2)
{
    if (p0 == p1) {
        return;
    }
    if (p0 != p1) {
        float k = (float)(p1 - p0 - 1);
        float m = f0 - 0.5f * (k * f1);
        for (int i = p0; i < p1; i++) {
            func_00453380_set(self->field_0[i].field_C.field_8, f2, m);
            m += f1;
        }
    }
    if (p1 - p0 == 1) {
        return;
    }
    UnkStruct_00453380_s * a = &self->field_0[p0].field_C;
    UnkStruct_00453380_s * b = &self->field_0[p1 - 1].field_C;
    GtMathPs2::CGtV2d d = D_004D3138.field_0;
    if (p1 - p0 == 2) {
        d *= 0.5f;
    }
    float dy = d.Y();
    float dx = d.X();
    *a->field_0 = *a->field_0 - GtMathPs2::CGtV2d(dx, dy);
    *a->field_10 = *a->field_10 - GtMathPs2::CGtV2d(dx, dy);
    *b->field_0 = *b->field_0 + GtMathPs2::CGtV2d(dx, dy);
    *b->field_10 = *b->field_10 + GtMathPs2::CGtV2d(dx, dy);
}
