// NONMATCHING: func_003D8920 -- retail 164 / ours 165 instructions, 3 in changed runs
// near2: 3 off (archive 18, hdr12 reroute 5). Header N224 Interpolate; func_003824D0's 7th param typed const unsigned short* (self->field_30 passed bare) fixed the first call's addiu t1 order. Left: 2nd Interpolate's mfc1 a0,f20 (t held in f20 across func_00271A00) -- retail schedules it right after lqc2 a, ours after vaddax + a nop. Tried: t2 = t / 0.25f locals, named CGtV4d result, *(const float*)&t, text/o2 statement order, t/size declaration order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003D8920 -- retail 164 / ours 163 instructions, 18 in changed runs
// v272: logic/layout/frame right (CB3HUDEscapeDistance helper, called from ActualPrepare; named CGtV2d pos/anchor locals put func_00271A00 before the 2nd Interpolate). Left 18: header gap N94 -- retail's Interpolate keeps qmfc2.ni + sq right after vmaddx (ours folds to sqc2 with .ni, or schedules the .i qmfc2 late) and the 2nd call's mfc1 f20 placement. Stand-in v272_lerpn on retail's vf1/vf2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// [L] CB3HUDEscapeDistance helper: called from CB3HUDEscapeDistance::ActualPrepare (0x3D8BC0) with `this`. Finds the
// leading active car (lowest score field_10C0 among cars with field_1160 == 0 and func_00150D00 == 0), prints its
// func_0015A7F0 distance in km or miles (D_004E2918 > 1: /1000, string 0x7DC; else * 0.000621371204, 0x7DD) and lays
// out two text objects. Types and fields are placeholders [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003D8920_score { short field_0; };
struct UnkStruct_003D8920_car {
    unsigned char pad_0[0x10C0];
    UnkStruct_003D8920_score field_10C0;
    unsigned char pad_10C2[0x1160 - 0x10C2];
    unsigned char field_1160;
};
struct UnkStruct_003D8920_g {
    unsigned char pad_0[0x12AD28];
    UnkStruct_003D8920_car * field_12AD28[1];
};
struct UnkStruct_003D8920_obj { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_003D8920_font { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_D_00665ED0_v272 { UnkStruct_003D8920_font * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2918 { unsigned int field_0; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0066A4C0_v272 {
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
class CB3HUDEscapeDistance {
public:
    unsigned char pad_0[0x20];
    UnkStruct_003D8920_obj * field_20;
    UnkStruct_003D8920_obj * field_24;
    UnkStruct_003D8920_obj * field_28;
    unsigned char pad_2C[0x4];
    unsigned short field_30[8];   // [G] text buffer
};
extern UnkStruct_003D8920_g D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_00665ED0_v272 D_00665ED0;
extern UnkStruct_D_0066A4C0_v272 D_0066A4C0;
extern "C" int func_00150D00(UnkStruct_003D8920_car * self);
extern "C" float func_0015A7F0(UnkStruct_003D8920_score * self);
extern "C" void PrintReal__10CGtUnicodeFPUsfi(unsigned short * buf, float f, int a, int b);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
// [L] N185: GtMathPs2::Interpolate(CGtV4d, CGtV4d, float) stand-in on retail's registers ($vf1/$vf2), b's move in and the
// result's move out kept (.i, restored to .ni by the fixup, N188/N190) -- the header body folds them (N94)






// 0x003D8920
extern "C" void func_003D8920(CB3HUDEscapeDistance * self)
{
    UnkStruct_003D8920_car * best = 0;
    UnkStruct_D_0066A4C0_v272 * const mgr = &D_0066A4C0;
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_003D8920_car * c = D_00522660.field_12AD28[i];
        if (c->field_1160 == 0 && func_00150D00(c) == 0) {
            if (best == 0 || c->field_10C0.field_0 < best->field_10C0.field_0)
                best = c;
        }
    }
    float d;
    if (best != 0)
        d = func_0015A7F0(&best->field_10C0);
    else
        d = 0.0f;
    int id;
    if (D_004E2918.field_0 > 1) {
        id = 0x7DC;
        d = d / 1000.0f;
    } else {
        id = 0x7DD;
        d = d * 0.000621371204f;
    }
    PrintReal__10CGtUnicodeFPUsfi(self->field_30, d, 1, 0);
    float t = 0.25f;
    float size = 25.0f;
    UnkStruct_003D8920_obj * o = self->field_24;
    float y = size + (-5.0f + (o->field_4 + o->field_C));
    CGtV2d p1(o->field_0, y);
    CGtV2d a1(0.0f, D_00665ED0.field_0->field_10);
    func_003824D0((void *)((int)self->field_20), p1, a1, size,
        GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, t), mgr->field_30, self->field_30, 0x61, 1.0f, 3.402823466e+38f);
    UnkStruct_003D8920_obj * o2 = self->field_20;
    CGtV2d p2(5.0f + (o2->field_0 + o2->field_8), y);
    CGtV2d a2(0.0f, D_00665ED0.field_0->field_10);
    int text = func_00271A00(&D_0051BA44, id);
    func_003824D0((void *)((int)self->field_28), p2, a2, size,
        GtMathPs2::Interpolate(mgr->field_60, mgr->field_30, t), mgr->field_30, (const unsigned short *)text, 1, 1.0f, 3.402823466e+38f);
}
