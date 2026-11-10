// Hand-written; the lifter refused it (pass2c: const by-value CGtV4d colour (N206) hoists its lq above the FPR saves).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_003D0710_s20 {
    int field_0;
    const unsigned short *field_4;
    float field_8;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    float field_14;
};
struct UnkStruct_003D0710 {
    unsigned char pad_0[0x20];
    UnkStruct_003D0710_s20 field_20;
};
struct UnkStruct_bd { float field_0; float field_4; };
struct UnkStruct_cb { unsigned char pad_0[0x10]; };
extern UnkStruct_cb _RenderNormal__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern UnkStruct_cb _RenderDistort__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern UnkStruct_cb _RenderDisintegrate__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern UnkStruct_bd mgu8RenderBatchData__11CGt2dObject[];
extern const float D_004CA4D0[];
struct UnkStruct_D_004E08B0 { float field_0; };
extern UnkStruct_D_004E08B0 D_004E08B0;
extern "C" int func_003CDB80(CGtV2d *, UnkStruct_003D0710_s20 *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
// [L] N206: by-value colour declared const (not in the C link name) -- lets its lq schedule above the f20/f21 saves as retail
// 0x003D0710
extern "C" void func_003D0710(UnkStruct_003D0710 *obj, const CGtV2d &pos, const CGtV2d &anchor, const CGtV4d colour, int a, int b, int c, void *font_, float size, float maxWidth, const unsigned short *text, bool flag)
{
    int font = (int)font_;
    UnkStruct_003D0710_s20 *s = &obj->field_20;
    s->field_0 = font;
    s->field_4 = text;
    s->field_8 = 1.0f;
    s->field_C = 0;
    s->field_10 = a;
    s->field_11 = c;
    s->field_12 = 0;
    s->field_13 = flag;
    s->field_14 = D_004CA4D0[b];
    CGtV2d dim;
    CGtV2d unit(1.0f, 1.0f);
    int n = func_003CDB80(&unit, s);
    float k;
    if (n > 0) {
        const UnkStruct_bd *e = &mgu8RenderBatchData__11CGt2dObject[n - 1];
        k = e->field_0 - D_004E08B0.field_0 * (0.5f - e->field_4);
        if (k <= 0.0f) k = 1.0f;
    } else {
        k = 1.0f;
    }
    dim.marValues[0] = k * size;
    dim.marValues[1] = size;
    if (!(dim.marValues[0] <= maxWidth)) {
        float r = maxWidth / dim.marValues[0];
        k = k * r;
        s->field_14 = s->field_14 * r;
        dim.marValues[0] = maxWidth;
    }
    s->field_8 = 1.0f / k;
    const void *cb;
    switch (c) {
    case 0:
    case 1: cb = &_RenderNormal__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv; break;
    case 2: cb = &_RenderDistort__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv; break;
    case 3: cb = &_RenderDisintegrate__23CB3StylisedText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv; break;
    }
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(obj, pos - dim * anchor, dim, colour, cb, 0x40, 0xC);
}
