// func_003D2AA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-written with GtMathPs2 temporaries: CGtV4d(float x4) / CGtV2d ctor arguments, CGt2dObjectImage::Prepare's stack argument (N68), const CGtV2d externs (absolute addressing), lit4 floats 0.47/0.72/FLT_MAX, gradient positions as top-declared CGtV2d locals assigned from an inline returning CGtV2d (retail's ld/sd copy and slot order), sub-struct element pointer at +0x14).

// func_003D2AA0 -- hand-written from the retail structure (lifted draft compiled but far: missing CGt2dObjectImage's
// stack argument, constructor temporaries).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003D2AA0_e1 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003D2AA0_e0s {
    unsigned char pad_0[0x2C];
    UnkStruct_003D2AA0_e1 * field_2C;
};

struct UnkStruct_003D2AA0_e0 {
    unsigned char pad_0[0x14];
    UnkStruct_003D2AA0_e0s field_14;
    unsigned char pad_44[0x2C];
};

struct UnkStruct_003D2AA0_3 {
    unsigned char pad_0[0x250];
    int field_250;
};

struct UnkStruct_003D2AA0 {
    unsigned char pad_0[0x4];
    UnkStruct_003D2AA0_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    void * field_20;
    void * field_24;
    void * field_28;
    void * field_2C;
    unsigned char pad_30[0x4];
    void * field_34;
    UnkStruct_003D2AA0_3 * field_38;
};

struct UnkStruct_D_01EA46B4 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA46B4 D_01EA46B4;
extern const CGtV2d D_004CA638;
extern const CGtV2d D_004CA640;
extern const CGtV2d D_004CA650;
extern const CGtV2d D_004CA658;
extern const CGtV2d D_004CA660;
extern const CGtV2d D_004CA670;
extern const CGtV2d D_01EA3190;
extern const CGtV2d D_01EA3198;
extern int D_00665ED0[4];  // [G] size: absolute addressing
extern char D_0051BA44[];

extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);  // CGt2dObjectBox::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);  // CGt2dObjectImage::Prepare(...), plus retail's stack argument (N68)
extern "C" void Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtV4d, float);  // CB32dObjectGradient::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,GtMathPs2::CGtV4d,float)
extern "C" int func_003F5F50(int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003D0710(void *, const CGtV2d &, const CGtV2d &, CGtV4d, int, int, int, void *, void *, int, float, float);

// [G] inlined helper, placeholder name: the point below a rectangle (pos + its height)
static inline CGtV2d func_003D2AA0_inl1(const CGtV2d & pos, const CGtV2d & size)
{
    return CGtV2d(pos.marValues[0], pos.marValues[1] + size.marValues[1]);
}

// 0x003D2AA0
extern "C" void func_003D2AA0(UnkStruct_003D2AA0 * self, int p0)
{
    CGtV2d pos1;
    CGtV2d pos2;
    int str = 0;
    UnkStruct_003D2AA0_e0s * e = &self->field_4[self->field_1C].field_14;
    int idx = self->field_10 + 2;
    if (p0 == 3) {
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_20, D_004CA638, CGtV2d(0.0f, 0.0f), D_004CA640, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), D_01EA46B4.field_0, D_01EA3190, D_01EA3198, 0);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_28, D_004CA658, CGtV2d(0.0f, 0.0f), D_004CA660, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), D_01EA46B4.field_0, D_01EA3190, D_01EA3198, 0);
        if (self->field_38->field_250 != -1) {
            str = func_00271A00(D_0051BA44, func_003F5F50(self->field_38->field_250));
        }
    } else {
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_20, D_004CA638, CGtV2d(0.0f, 0.0f), D_004CA640, CGtV4d(0.0f, 0.0f, 0.0f, 1.0f));
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_28, D_004CA658, CGtV2d(0.0f, 0.0f), D_004CA660, CGtV4d(0.0f, 0.0f, 0.0f, 1.0f));
    }
    pos1 = func_003D2AA0_inl1(D_004CA638, D_004CA640);
    Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_24, pos1, CGtV2d(0.0f, 0.0f), D_004CA650, CGtV4d(0.47f, 0.72f, 1.0f, 1.0f), CGtV4d(0.0f, 0.0f, 0.0f, 1.0f), 0.0f);
    pos2 = func_003D2AA0_inl1(D_004CA658, D_004CA660);
    Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_2C, pos2, CGtV2d(0.0f, 1.0f), D_004CA650, CGtV4d(0.47f, 0.72f, 1.0f, 1.0f), CGtV4d(0.0f, 0.0f, 0.0f, 1.0f), 0.0f);
    if (str != 0) {
        func_003D0710(self->field_34, D_004CA670, CGtV2d(1.0f, 1.0f), CGtV4d(0.0f, 0.0f, 0.0f, 0.0f), 1, 1, 0, (void *)(D_00665ED0[0]), (void *)(str), 1, 36.0f, 3.4028235e+38f);
        e->field_2C[idx].field_0 = 0;
    } else {
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_34, D_004CA670, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), CGtV4d(0.0f, 0.0f, 0.0f, 0.0f));
        e->field_2C[idx].field_0 = 1;
    }
}
