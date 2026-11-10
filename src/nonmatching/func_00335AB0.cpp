// NONMATCHING: func_00335AB0 -- retail 190 / ours 190 instructions, 16 in changed runs
// 16 off: else-arm FP schedule (retail computes the y madd before 1.0f+(x+w); 1.0 in f1 not f0) + Interpolate 0.25 lui one slot early; logic exact
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (fresh5): lifter refused; cloned from the proven sibling func_00335450 (B3HUDTakedowns-style HUD Prepare).
// [G] config/symbol_addrs_b3names.txt low row: CB3HUDPos::Prepare(int,EHUDAlign,int,bool,bool) at 0x00335AB0; retail
// also reads t2 (stored to +0x52), so a sixth parameter is passed.

#include "b3/GtMathPs2.h"
enum EHUDAlign {};
class CGt2dFrame;
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    CGtV4d field_40;
    unsigned char pad_50[0x10];
    CGtV4d field_60;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_00335AB0_font { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_D_00665ED0 { UnkStruct_00335AB0_font *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00335AB0_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_00335AB0_obj { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_00335AB0 {
    unsigned char pad_0[0x4];
    UnkStruct_00335AB0_e1 *field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_00335AB0_obj *field_20[4];
    int field_30;
    unsigned char pad_34[0x8];
    int field_3C;
    unsigned char pad_40[0x2];
    short field_42;
    unsigned short field_44[4];
    int field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
};
extern UnkStruct_D_00522660 D_00522660[];
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);
extern "C" UnkStruct_00335AB0_obj *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_003824D0(UnkStruct_00335AB0_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" void func_003356A0(void *);

// 0x00335AB0
extern "C" int func_00335AB0(UnkStruct_00335AB0 *self, int p0, EHUDAlign p1, int p2, bool p3, bool p4, bool p5)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 4, 1, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * scene = (char *)&self->field_4[self->field_1C] + 0x14;
    int i;
    int layer = self->field_10;
    self->field_3C = 0;
    self->field_30 = (int)((char *)&D_00522660[p0] + 0x12BE10);
    self->field_50 = p3;
    self->field_4C = 0;
    self->field_51 = p4;
    self->field_52 = p5;
    for (i = 3; i >= 0; i--)
        self->field_20[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)self->field_8);
    self->field_44[0] = 0x2F;
    self->field_44[2] = 0;
    self->field_42 = 0;
    const unsigned short *text = func_00271A00(&D_0051BA44, 0x7E7);
    func_003824D0(self->field_20[1], CGtV2d(0.0f, 14.0f), CGtV2d(0.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, text, 9, 1.0f, 3.402823466e+38f);
    float w;
    if (self->field_52 != 0)
        w = 148.0f;
    else
        w = 125.0f;
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(self->field_20[0], CGtV2d(-30.0f, 14.0f), CGtV2d(0.0f, 0.5f), CGtV2d(w, 27.0f), mgr->field_10, 2);
    func_003356A0(self);
    CGtV2d pos;
    CGtV2d anchor;
    if (self->field_52 != 0) {
        anchor.Set(0.0f, 0.0f);
        pos.Set(1.0f + (self->field_20[3]->field_0 + self->field_20[3]->field_8), self->field_20[1]->field_4);
    } else {
        anchor.Set(0.0f, D_00665ED0.field_0->field_10);
        UnkStruct_00335AB0_obj *o = self->field_20[3];
        float x = o->field_0 + o->field_8;
        pos.SetY(0.0f + o->field_4 + o->field_C * anchor.Y());
        pos.SetX(1.0f + x);
        UnkStruct_00335AB0_obj *t = self->field_20[1];
        *(CGtV2d *)t = CGtV2d(pos.X(), t->field_4);
    }
    float k = 0.25f;
    func_003824D0(self->field_20[2], pos, anchor, 27.0f, GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, k), mgr->field_30, self->field_44, 1, 1.5f, 3.402823466e+38f);
    return 1;
}
