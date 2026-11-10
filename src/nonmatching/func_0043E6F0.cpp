// NONMATCHING: func_0043E6F0 -- retail 441 / ours 441 instructions, 166 in changed runs
// a179: logic complete, 441/441 instrs, float regs f20-f24 and spill count match; 166 changed. Left: (1) temp frame slots: retail puts loop-1 CGtV2d temps lowest (0x118/0x120) and loop-2 temps highest, ours the reverse (appearance order); (2) loop-1 slot-pointer spill: retail 'addiu v0,v0,52; sq v0,0xE0' with i*4 at 0xF0, ours 'sw' of the unfolded base (self+i*4) at 0xF0 and i4 at 0xE0; (3) self+j*4 base is s0 in retail, s5 in ours (swap with the &field_4C reg). Float decl order must be b(ph), c(px), a(py) before e. Inline helpers: _inl1 (switch of 3 getters, k=3,2,1,0), _inl2 (CGtV2d(x+d,y+d) result)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_0043E6F0_o { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_0043E6F0_row { int field_0[3]; };
struct UnkStruct_0043E6F0 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[6];
    UnkStruct_0043E6F0_o * field_10[3];
    UnkStruct_0043E6F0_o * field_1C[3];
    UnkStruct_0043E6F0_o * field_28[3];
    UnkStruct_0043E6F0_o * field_34[3];
    unsigned char pad_40[0xC];
    UnkStruct_0043E6F0_o * field_4C[3];
    UnkStruct_0043E6F0_o * field_58[3];
    UnkStruct_0043E6F0_row field_64[3];
    UnkStruct_0043E6F0_row field_88[3];
    unsigned char pad_AC[0x28];
    int field_D4;
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { CGtV4d field_0; CGtV4d field_10; };
struct UnkStruct_D_ptr { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[8]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_ptr D_0051BF9C;
extern CGtV4d D_004D2050;
extern CGtV4d D_004D2060;
extern CGtV4d D_004D2070;
extern CGtV4d D_004D2080;
extern float D_004D2090[];
extern float D_004D20A0[];
extern float D_004D20C0[];
extern float D_004D20D0[];
extern float D_004E0C50;
extern int D_00665ED0[4];
extern "C" int func_0013AB80(void *, int, int);
extern "C" int func_0013AA10(void *, int);
extern "C" int func_0013A8A0(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_0043E000(void *, const CGtV2d *, const CGtV2d *, int, int, int, int);
extern "C" void Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtV4d, float);
extern "C" void func_001D6AD0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, void *, const CGtV2d *, int);

static inline CGtV2d func_0043E6F0_inl2(float x, float y, float d)
{
    CGtV2d r;
    r.marValues[0] = x + d;
    r.marValues[1] = y + d;
    return r;
}

static inline int func_0043E6F0_inl1(void *h, int i, int k, int d)
{
    switch (i) {
    case 0: return func_0013AB80(h, k, d);
    case 1: return func_0013AA10(h, k);
    case 2: return func_0013A8A0(h, k);
    }
    return 0;
}

// 0x0043E6F0
extern "C" void func_0043E6F0(UnkStruct_0043E6F0 *self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    void *root = scene->field_14;
    void *h = D_0051BF9C.field_0;
    int i;
    for (i = 0; i < 3; i++) {
        int a = func_0043E6F0_inl1(h, i, 3, self->field_D4);
        int b = func_0043E6F0_inl1(h, i, 2, self->field_D4);
        int c = func_0043E6F0_inl1(h, i, 1, self->field_D4);
        int d = func_0043E6F0_inl1(h, i, 0, self->field_D4);
        self->field_34[i] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 2, root);
        CGtV2d p(D_004D20C0[i], D_004D20D0[i]);
        CGtV2d q(0.0f, 0.0f);
        func_0043E000(self->field_34[i], &p, &q, a, b, c, d);
    }
    int j;
    for (j = 0; j < 3; j++) {
        self->field_1C[j] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        self->field_28[j] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        self->field_10[j] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, root);
        self->field_4C[j] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 2, root);
        self->field_58[j] = (UnkStruct_0043E6F0_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 2, root);
        UnkStruct_0043E6F0_o *fr = self->field_34[j];
        float b = (fr->field_4 + fr->field_C) - fr->field_4;
        float c = D_004D2090[j];
        float a = D_004D20A0[j];
        float e = (12.0f + b) + 30.0f;
        Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_1C[j], CGtV2d(c, a), CGtV2d(0.0f, 0.0f), CGtV2d(95.0f, 2.0f), D_004D2060, D_004D2050, 0.0f);
        float d = 2.0f + a;
        Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_28[j], CGtV2d(c, e + d), CGtV2d(0.0f, 0.0f), CGtV2d(95.0f, 2.0f), D_004D2060, D_004D2050, 0.0f);
        Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_10[j], CGtV2d(c, d), CGtV2d(0.0f, 0.0f), CGtV2d(95.0f, e), D_004D2070, D_004D2080, 0.0f);
        a = 47.5f + c;
        b = b + (12.0f + d);
        func_001D6AD0(self->field_4C[j], CGtV2d(a, b), CGtV2d(0.5f, 0.0f), 36.0f, &mgr->field_10, (void *)(D_00665ED0[0]), (void *)(self->field_64[j].field_0[self->field_D4]), &CGtV2d(2.0f, 2.0f), 2);
        func_001D6AD0(self->field_58[j], func_0043E6F0_inl2(a + self->field_4C[j]->field_8, b, D_004E0C50 * self->field_4C[j]->field_C), CGtV2d(0.5f, 0.0f), 24.0f, &mgr->field_0, (void *)(D_00665ED0[0]), (void *)(self->field_88[j].field_0[self->field_D4]), &CGtV2d(2.0f, 2.0f), 2);
        a = a - (6.0f + (self->field_4C[j]->field_8 + self->field_58[j]->field_8)) / 2.0f;
        func_001D6AD0(self->field_4C[j], CGtV2d(a, (self->field_28[j]->field_4 + self->field_28[j]->field_C) - 4.0f), CGtV2d(0.0f, 1.0f), 36.0f, &mgr->field_10, (void *)(D_00665ED0[0]), (void *)(self->field_64[j].field_0[self->field_D4]), &CGtV2d(2.0f, 2.0f), 2);
        func_001D6AD0(self->field_58[j], CGtV2d(3.0f + (a + self->field_4C[j]->field_8), (self->field_28[j]->field_4 + self->field_28[j]->field_C) - 4.0f), CGtV2d(0.0f, 1.0f), 24.0f, &mgr->field_0, (void *)(D_00665ED0[0]), (void *)(self->field_88[j].field_0[self->field_D4]), &CGtV2d(2.0f, 2.0f), 2);
    }
}
