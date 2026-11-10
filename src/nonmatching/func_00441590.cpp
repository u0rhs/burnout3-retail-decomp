// NONMATCHING: func_00441590 -- retail 213 / ours 213 instructions, 8 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: v288: 213/213, frame exact (4 N140 pads + function-scope c0/c2/szA/szB in retail slot order), scoped opt_repositioncode off [G] + goto-form out-of-line blocks; 0.4f/0.3f literals (D_004E08B0/06B8 const externs lose gp). Left 8: in case 0/2 retail fills bnez's delay slot with qmfc2 a0,vf1 (sqc2 of c 
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00441590 -- hand-written (v288). Unnamed in every table: placeholder with C linkage. Neighbour of
// func_004413C0 ([L] DNAT: CB3InGameSettingsState::Action, low). Struct and field names are placeholders, types [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_00441590 {
    unsigned char pad_0[0xC];
    CGt2dObject *field_C;
    CGt2dObject *field_10;
    CGt2dObject *field_14;
    unsigned char pad_18[0x10];
    float field_28;
    float field_2C;
    signed char field_30;
    signed char field_31;
};
struct UnkStruct_D_0051BAA6 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0051BAA6 D_0051BAA6;
extern const CGtV2d D_004D2308;
extern "C" void SetTexture__16CGt2dObjectImageFP10CGtTexture(CGt2dObject *, CGtTexture *, int);
extern "C" void SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &);
extern CGtTexture *D_01EA4718[4];   // [G] sized so it is not $gp-addressed
extern CGtTexture *D_01EA471C[4];
// N140 frame pad: an unused 16-byte local object (retail's frame has four 16-byte slots no code touches).
struct UnkStruct_00441590_pad { int x[4]; UnkStruct_00441590_pad() {} ~UnkStruct_00441590_pad() {} };

#pragma push
#pragma opt_repositioncode off
extern "C" void func_00441590(UnkStruct_00441590 *self, float dt)
{
    UnkStruct_00441590_pad p0, p1;
    CGtV4d c2;
    UnkStruct_00441590_pad p2, p3;
    CGtV4d c0;
    CGtV2d szA;
    CGtV2d szB;
    if (D_0051BAA6.field_0) dt *= 2.0f;
    switch (self->field_30) {
    case 0: {
        float t = self->field_2C - dt;
        self->field_2C = t;
        if (t < 0.0f) goto L884;
        float a = 1.0f - 2.5f * t;
        CGt2dObject *o = self->field_10;
        o->mObjectSpace.mColour.SetA(a);
        c0 = o->mObjectSpace.mColour;
        if (self->field_31 == 0) c0.SetA(0.0f);
        self->field_14->mObjectSpace.mColour = c0;
        if (self->field_31 != 3) return;
        self->field_C->mObjectSpace.mColour.SetA(a);
        break;
    }
    case 1: {
        float t = self->field_28 - dt;
        self->field_28 = t;
        if (!(t < 0.0f)) return;
        self->field_30 = 2;
        self->field_2C = 0.4f;
        break;
    }
    case 2: {
        float t = self->field_2C - dt;
        self->field_2C = t;
        if (t < 0.0f) goto L894;
        float a = 2.5f * t;
        CGt2dObject *o = self->field_10;
        o->mObjectSpace.mColour.SetA(a);
        c2 = o->mObjectSpace.mColour;
        if (self->field_31 == 0) c2.SetA(0.0f);
        self->field_14->mObjectSpace.mColour = c2;
        if (self->field_31 != 1) return;
        self->field_C->mObjectSpace.mColour.SetA(a);
        break;
    }
    case 3: {
        self->field_30 = 0;
        self->field_2C = 0.4f;
        self->field_31--;
        if (self->field_31 == 0) goto L89C;
        if (self->field_31 < 0) {
            self->field_31 = 3;
            SetTexture__16CGt2dObjectImageFP10CGtTexture(self->field_10, D_01EA4718[0], 0);
            szB.Set(80.0f, 40.0f);
            self->field_10->mObjectSpace.mSize = szB;
        }
    L7D8:
        float x;
        if (self->field_31 == 0) x = 320.0f;
        else x = 220.0f - 65.0f * (float)(self->field_31 - 1);
        SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_10, CGtV2d(x, 413), D_004D2308);
        SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_14, CGtV2d(640.0f - x, 413), D_004D2308);
        break;
    }
    }
brk:
    return;
L884:
    self->field_30 = 1;
    self->field_28 = 0.3f;
    goto brk;
L894:
    self->field_30 = 3;
    goto brk;
L89C:
    SetTexture__16CGt2dObjectImageFP10CGtTexture(self->field_10, D_01EA471C[0], 0);
    szA.Set(180.0f, 90.0f);
    self->field_10->mObjectSpace.mSize = szA;
    goto L7D8;
}
#pragma pop
