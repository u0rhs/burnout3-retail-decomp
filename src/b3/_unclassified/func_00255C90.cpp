// func_00255C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (state 1/2 if-else (case 1 first), header CGtV4d ctor + SetA, 0.8f literal via a*=, scoped opt_pulloutconstants off [G] for the 1.0f rematerialisation).

// func_00255C90 -- hand-written (fresh1).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAC4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665EC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00255C90 {
    float field_0;
    float field_4;
    int field_8;
};

extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BAC4 D_0051BAC4;
extern float D_004E0F7C;
extern UnkStruct_D_00665EC0 D_00665EC0;

extern "C" void func_002276C0(void *, void *, int);

// N182: [G] scoped to this function -- opt_pulloutconstants off makes MWCC rematerialise 1.0f in case 2 (lui/sw
// into the colour, lui/mtc1 in the v = 1 block) instead of keeping it in one register, as retail does.
#pragma push
#pragma opt_pulloutconstants off
// 0x00255C90
extern "C" void func_00255C90(UnkStruct_00255C90 * self)
{
    self->field_0 = self->field_0 + D_004F509C.field_0 * (float)D_0051BAC4.field_0;
    int st = self->field_8;
    if (st == 1) {
        CGtV4d c(1.0f, 1.0f, 1.0f, 0.0f);
        float r = self->field_0 / self->field_4;
        float a;
        if (r < 0.5f) {
            a = r / 0.5f;
        } else {
            a = 1.0f - (r - 0.5f) / 0.5f;
        }
        if (!(self->field_0 < self->field_4)) {
            a = 0.0f;
            self->field_8 = 0;
        }
        a *= 0.8f;
        c.SetA(a);
        func_002276C0(&D_00665EC0, &c, 1);
    } else if (st == 2) {
        float t = self->field_0;
        float v;
        if (t < 0.125f) {
            v = 1.0f;
        } else {
            float x = (1.0f / self->field_4) * (self->field_4 - t);
            v = x * (x * x);
        }
        if (!(t < self->field_4)) {
            v = 0.0f;
            self->field_8 = 0;
        }
        CGtV4d c(1.0f, D_004E0F7C, 2.0f, v);
        func_002276C0(&D_00665EC0, &c, 1);
    }
}
#pragma pop
