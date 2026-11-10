// NONMATCHING: func_0044D6D0 -- retail 844 / ours 844 instructions, 93 in changed runs
// draftT: 844/844, 93 changed, all stack-slot offsets (code, registers, schedule otherwise identical). Found: one row-draw inline (row index, CB3MenuPageManager * const m inside, colour &m->field_0[1], float o = -30.0f) + 'off = 0x2DA04' per branch (s4/s5 CSE); value text through an inlined Prepare wrapper (by-value CGtV4d param, render cb func_00453980) fixes the schedule; 'case 0: default:' fills the first jal delay slot; frame block written out (p's at 0x228/0x220). Left: temp slot order -- MWCC allocates inlined temps by inline depth; retail = p1,p2 | reparent copies#1, captions, reparent copies#2 | value pairs | label pairs+div copies, reparent r#1, tail label, reparent r#2 | div r's
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] same calls/args/stores/CFG/registers as retail; residue is only stack-slot assignment of temporaries

// func_0044D6D0 -- hand-written from retail (lifter refused). Same component family as func_00451F70 /
// func_0044E400 / func_0044D180 / func_0044CF90 (rows at self+0xC, stride 0x24; counters at 0x180/0x1A0;
// texts at 0x140). Adds the profile-total row for `mode` (0: CB3Profile::GetBurnoutPointTotal [L] new_names.csv, 1: takedown
// totals, 2: GetCrashDamageTotal [L]), then, if func_003EABD0 reports a next goal, a goal row with two captions.
// [C] D_0051BA44 = &D_004EE040 + 0x2DA04 (retail keeps 0x2DA04 in s5 across the switch: `off` per branch, as matched func_0037F640).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;
struct UnkStruct_0044D6D0_fr {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    unsigned char pad_20[0x18];
    UnkStruct_0044D6D0_fr * field_38;
};
struct UnkStruct_0044D6D0_txt {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x1C];
    int field_2C;
    CGtV2d field_30;
};
struct UnkStruct_0044D6D0_row {
    UnkStruct_0044D6D0_fr * field_0;
    UnkStruct_0044D6D0_fr * field_4;
    void * field_8;
    UnkStruct_0044D6D0_fr * field_C;
    UnkStruct_0044D6D0_fr * field_10[5];
};
struct UnkStruct_0044D6D0_row2 {
    UnkStruct_0044D6D0_fr * field_0;
    UnkStruct_0044D6D0_fr * field_4;
    void * field_8;
    UnkStruct_0044D6D0_fr * field_C;
    void * field_10;
    UnkStruct_0044D6D0_txt * field_14;
    void * field_18;
    UnkStruct_0044D6D0_fr * field_1C;
    UnkStruct_0044D6D0_fr * field_20;
};
union UnkStruct_0044D6D0_r {
    UnkStruct_0044D6D0_row a;
    UnkStruct_0044D6D0_row2 b;
};
struct UnkStruct_0044D6D0 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_0044D6D0_r field_C[8];
    unsigned char pad_12C[0xC];
    int field_138;
    unsigned char pad_13C[4];
    const unsigned short * field_140[16];
    int field_180[8];
    int field_1A0[8];
    unsigned char pad_1C0[0x3E];
    signed char field_1FE;
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_4D3130 { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_Pad16 D_004EE040;
extern UnkStruct_Pad16 D_0051BA44;
extern CB3MenuPageManager D_01E90240;
extern UnkStruct_Pad16 D_01E90438;
extern UnkStruct_D_int D_0051BF9C, D_01ECDA68, D_01ECDA6C, D_01ECDA70;
extern UnkStruct_D_4D3130 D_004D3130;
extern CGtV4d D_004D3140;
extern CGtV4d D_01E903C0;
extern int D_00665ED0[4];
extern "C" int func_0013B660(void *);
extern "C" int func_0013B570(void *);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" int func_003EABD0(int, int, int);
extern "C" void func_00453680(void *, int, int, int);
extern "C" void func_0044CF90(void *, int, float);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" UnkStruct_0044D6D0_fr * ConstructChild__10CGt2dFrameFv(void *);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003D0960(unsigned short *, int, const unsigned short *, int);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const void *, const CGtV2d *, int);
extern "C" void func_003D0710(void *, const CGtV2d &, const CGtV2d &, const void *, int, int, int, void *, float, float, unsigned short *, int);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, void *, const void *, void *);
extern "C" void func_00453980(void *, const void *);

static inline void func_0044D6D0_inl1(UnkStruct_0044D6D0_fr *c, UnkStruct_0044D6D0_fr *p)
{
    if (c != 0) {
        c->field_0 = c->field_0 - p->field_0;
        c->field_38 = p;
    }
}

// [G] an ItalicText subclass's Prepare (render callback func_00453980), inlined; cf. CB3FlashText2dObject::Prepare
static inline void func_0044D6D0_inl4(UnkStruct_0044D6D0_txt *t, const CGtV2d &p0, const CGtV2d &p1, float p2, const CGtV4d p3, int p4, const unsigned short *p5)
{
    PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, p0, p1, p2, p3, (void *)(p4), p5, (void *)func_00453980);
    t->field_30 = D_004D3130.field_0 / t->field_8;
    t->field_2C = 0;
}

// label at the row's left edge, value text right-aligned at its right edge
static inline UnkStruct_0044D6D0_r *func_0044D6D0_inl2(UnkStruct_0044D6D0 *self, int idx, const unsigned short *label, const unsigned short *txt)
{
    UnkStruct_0044D6D0_r *e = &self->field_C[idx];
    CB3MenuPageManager * const m = &D_01E90240;
    float z = 0.0f;
    float f = 30.0f + (e->b.field_0->field_0.marValues[0] + z * e->b.field_0->field_8.marValues[0]);
    e->b.field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, self->field_8 + 2, e->b.field_8);
    func_0033D4E0(e->b.field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &m->field_0[1], (void *)(D_00665ED0[0]), label, &D_004D3130.field_0, 2);
    if (txt != 0) {
        float g = e->b.field_0->field_0.marValues[0] + e->b.field_0->field_8.marValues[0];
        e->b.field_14 = (UnkStruct_0044D6D0_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, self->field_8 + 2, e->b.field_8);
        float o = -30.0f;
        func_0044D6D0_inl4(e->b.field_14, CGtV2d(g + o, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, D_01E903C0, D_00665ED0[0], txt);
    }
    return e;
}

// 0x0044D6D0
extern "C" void func_0044D6D0(UnkStruct_0044D6D0 *self, int mode)
{
    int t0 = D_0051BF9C.field_0;
    int value;
    int next;
    int idx;
    int off;
    const unsigned short *txt;
    const unsigned short *label;
    switch (mode) {
    case 0:
    default:
        value = func_0013B660((void *)(t0));
        idx = self->field_138;
        self->field_180[idx] = D_01ECDA68.field_0;
        self->field_1A0[idx] = value;
        func_0044CF90(self, idx, 0.0f);
        txt = self->field_140[idx];
        func_00453680(self, idx, 10, 4);
        off = 0x2DA04;
        label = func_00271A00(&D_0051BA44, 2542);
        func_0044D6D0_inl2(self, idx, label, txt);
        next = func_003EABD0(D_01ECDA68.field_0, value, 4);
        break;
    case 1:
        value = func_0013B200((void *)(t0), 0, 1) + func_0013B200((void *)(t0), 0, 0);
        idx = self->field_138;
        self->field_180[idx] = D_01ECDA6C.field_0;
        self->field_1A0[idx] = value;
        func_0044CF90(self, idx, 0.0f);
        txt = self->field_140[idx];
        func_00453680(self, idx, 10, 4);
        off = 0x2DA04;
        label = func_00271A00(&D_0051BA44, 2551);
        func_0044D6D0_inl2(self, idx, label, txt);
        next = func_003EABD0(D_01ECDA6C.field_0, value, 5);
        break;
    case 2:
        value = func_0013B570((void *)(t0));
        idx = self->field_138;
        self->field_180[idx] = D_01ECDA70.field_0;
        self->field_1A0[idx] = value;
        func_0044CF90(self, idx, 0.0f);
        txt = self->field_140[idx];
        func_00453680(self, idx, 10, 4);
        off = 0x2DA04;
        label = func_00271A00(&D_0051BA44, 2541);
        func_0044D6D0_inl2(self, idx, label, txt);
        next = func_003EABD0(D_01ECDA70.field_0, value, 10);
        break;
    }
    {   // the row's frame: centred on the row's background, every object re-parented to it (written out: p at the top of the frame)
        UnkStruct_0044D6D0_r *e2 = &self->field_C[self->field_138];
        CGtV2d p(e2->a.field_0->field_0.marValues[0] + 0.5f * e2->a.field_0->field_8.marValues[0], 0.0f);
        e2->a.field_C = ConstructChild__10CGt2dFrameFv(e2->a.field_8);
        e2->a.field_C->field_0 = p;
        func_0044D6D0_inl1(e2->a.field_4, e2->a.field_C);
        func_0044D6D0_inl1(e2->a.field_0, e2->a.field_C);
        int k = 0;
        do {
            func_0044D6D0_inl1(e2->a.field_10[k], e2->a.field_C);
            k++;
        } while (k < 5);
    }
    self->field_138 = self->field_138 + 1;
    if (next > 0) {
        idx = self->field_138;
        self->field_180[idx] = next;
        self->field_1A0[idx] = next;
        func_0044CF90(self, idx, 0.0f);
        txt = self->field_140[idx];
        func_00453680(self, idx, 11, 4);
        label = func_00271A00((char *)&D_004EE040 + off, 0x9F5);
        UnkStruct_0044D6D0_r *e = func_0044D6D0_inl2(self, idx, label, txt);
        int layer = self->field_8 + 2;
        unsigned short *s1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        func_003D0960(s1, 0x40, func_00271A00(&D_0051BA44, 0xC09), 0);
        float x1 = e->b.field_14->field_0.marValues[0] - 20.0f;
        e->b.field_1C = (UnkStruct_0044D6D0_fr *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, layer, e->b.field_8);
        func_003D0710(e->b.field_1C, CGtV2d(x1, 0.0f), CGtV2d(1.0f, 0.5f), &D_01E90240.field_110, 1, 1, 1, (void *)(D_00665ED0[0]), 30.0f, 3.402823466e+38f, s1, 0);
        layer = self->field_8 + 2;
        unsigned short *s2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        func_003D0960(s2, 0x40, func_00271A00(&D_0051BA44, 0xC0A), 0);
        float z2 = 0.0f;
        float x2 = (30.0f + e->b.field_0->field_0.marValues[0]) + z2 * (e->b.field_0->field_8.marValues[0] - 60.0f);
        e->b.field_20 = (UnkStruct_0044D6D0_fr *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, layer, e->b.field_8);
        func_003D0710(e->b.field_20, CGtV2d(x2, 0.0f), CGtV2d(0.0f, 0.5f), &D_01E90240.field_110, 1, 1, 0, (void *)(D_00665ED0[0]), 36.0f, 3.402823466e+38f, s2, 0);
        e->b.field_1C->field_10 = D_004D3140;
        e->b.field_20->field_10 = D_004D3140;
        {
            UnkStruct_0044D6D0_r *e2 = &self->field_C[self->field_138];
            CGtV2d p(e2->a.field_0->field_0.marValues[0] + 0.5f * e2->a.field_0->field_8.marValues[0], 0.0f);
            e2->a.field_C = ConstructChild__10CGt2dFrameFv(e2->a.field_8);
            e2->a.field_C->field_0 = p;
            func_0044D6D0_inl1(e2->a.field_4, e2->a.field_C);
            func_0044D6D0_inl1(e2->a.field_0, e2->a.field_C);
            int k = 0;
            do {
                func_0044D6D0_inl1(e2->a.field_10[k], e2->a.field_C);
                k++;
            } while (k < 5);
        }
        if (!(next > value)) {
            self->field_1FE = self->field_138;
        }
        self->field_138 = self->field_138 + 1;
    }
}


