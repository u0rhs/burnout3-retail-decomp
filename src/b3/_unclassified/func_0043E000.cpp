// func_0043E000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a67: CGtV2d operator temps, Prepare takes const CGtV2d& so *p0-size*p1 passed as temporary, no named locals).

// [L] Hand-finished: CGtV2d operator temporaries (size*p1, p0-..., 1/size), Prepare declared with const CGtV2d& so temporaries are passed by reference.
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_D_01E90350 {
    GtMathPs2::CGtV4d field_0;
};

struct UnkStruct_func_0043DE60 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043E000 {
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char field_2B;
    unsigned char field_2C;
};

extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_0043DE60 func_0043DE60;

extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);

// 0x0043E000
extern "C" void func_0043E000(UnkStruct_0043E000 * self, const CGtV2d * p0, const CGtV2d * p1, int p2, int p3, int p4, int p5)
{
    int n = (p5 + (p4 + (p2 + p3)) + 5) / 6;
    CGtV2d size(66.0f, 11.0f * n);
    self->field_20 = CGtV2d(1.0f, 1.0f) / size;
    self->field_2C = n;
    self->field_2B = p2;
    self->field_2A = p3;
    self->field_29 = p4;
    self->field_28 = p5;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, *p0 - size * *p1, size, D_01E90350.field_0, (const void *)&func_0043DE60, 64, 16);
}
