// NONMATCHING: func_0044A430 -- retail 132 / ours 132 instructions, 23 in changed runs
// near29: goto entry-jump j loop (retail keeps the b to the test), j = 0 between base and row, slot = (off + (int)row + 0x1C), x + kf*sz.x without the zero local, pads (UnkStruct_0044A430_pad) inside a static inline division helper -> 23. Left: div r at 0x98 vs retail 0xA8 (retail's two dead 8-byte slots lie below r), colour lq not hoisted (retail lq t3 with the first loads), lui 1.0/0.5 register order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_0044A430 -- retail 132 / ours 132 instructions, 39 in changed runs
// a224: two 8-byte N140 pads (char[8] ctor/dtor) after sz fix the frame (0xD0) but sit above the temps: retail has the dead 8-byte slots BELOW the div temps (anchor 0xB8, temps 0xA8/0xB0); pads in an inline helper get optimised away. Also loop base order (row 0x24 addr after i*4 base) and operand orders
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_16 D_004D3130;
extern UnkStruct_D_16 D_004D3134;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" const unsigned short *func_00450EF0(void *, int, int, int);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    void *, const CGtV2d &, const CGtV2d &, float, const void *, const CGt2dFont *, const unsigned short *, void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));
struct UnkStruct_0044A430_data {
    unsigned char pad_0[0xC];
    float field_C;
    CGtV2d field_10;
};
struct UnkStruct_0044A430_row { unsigned char pad_0[0x1C]; CGt2dObject *field_1C[3]; };
struct UnkStruct_44A430_pad { char x[8]; UnkStruct_44A430_pad() {} ~UnkStruct_44A430_pad() {} };
struct UnkStruct_0044A430 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char field_A;
    unsigned char pad_B[0x129];
    int field_134;
    int field_138;
    unsigned char pad_13C[0x9C];
    short field_1D8[1][2];
};

// 0x0044A430
struct UnkStruct_0044A430_pad { char x[8]; UnkStruct_0044A430_pad() {} ~UnkStruct_0044A430_pad() {} };
static inline CGtV2d func_0044A430_inl1(const CGtV2d &s)
{
    UnkStruct_0044A430_pad p0, p1;
    return CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / s;
}
extern "C" void func_0044A430(UnkStruct_0044A430 *self)
{
    int j;
    int i;
    if (self->field_A == 0) return;
    if (self->field_134 != 3) return;
    for (i = 0; i < self->field_138; i++) {
        char *base = (char *)self + i * 4;
        j = 0;
        UnkStruct_0044A430_row *row = (UnkStruct_0044A430_row *)((char *)self + i * 0x24);
        goto jtest;
    jbody: {
            short *fp = (short *)(base + j * 2 + 0x1D8);
            int f = *fp;
            if (f & 0x400) goto jnext;
            bool sel = (f & 0x100) != 0;
            const unsigned short *txt = func_00450EF0(self, i, f, j);
            if (!(*fp & 0x400)) goto jnext;
            int idx;
            if (sel) idx = 1; else if (j == 0) idx = 2; else idx = 1;
            int off = idx * 4;
            CGt2dObject **slot = (CGt2dObject **)(off + (int)row + 0x1C);
            CGt2dObject *obj = *slot;
            if (obj == 0) goto jnext;
            if (txt != 0) {
                CGtV2d sz = obj->mObjectSpace.mSize;
                float kf = 1.0f;
                CGtV2d pos(obj->mObjectSpace.mTopLeftPos.marValues[0] + kf * sz.marValues[0], 0.0f);
                CGtV2d anchor(1.0f, 0.5f);
                u_long128 colq = *(const u_long128 *)&obj->mObjectSpace.mColour;
                PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
                    obj, pos, anchor, sz.marValues[1], &colq, D_00665ED0.pFont, txt, func_00453980);
                UnkStruct_0044A430_data *d = (UnkStruct_0044A430_data *)obj->mauDataBlock;
                d->field_10 = func_0044A430_inl1(obj->mObjectSpace.mSize);
                d->field_C = 0.0f;
            } else {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, self->field_8 + 2, obj);
                *slot = 0;
            }
        }
    jnext:
        j++;
    jtest:
        if (j < 2) goto jbody;
    }
}





