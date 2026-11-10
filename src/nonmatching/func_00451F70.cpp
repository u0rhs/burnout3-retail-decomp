// NONMATCHING: func_00451F70 -- retail 429 / ours 433 instructions, 268 in changed runs
// a179: logic complete incl. 3 inlined parent/offset blocks (static inline _inl1) and entry-jump goto loop; 433 vs 429 instrs, registers shifted (ours uses s8: one value too many live -- sel*4 is CSE'd into the later D_01EA4070 lookups where retail recomputes 'sll v1,s2,2'; tried sel2 copy / off local, no change). Also second field_140[n] test via pointer q is kept separate (needed, else the two PCD blocks merge)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00451F70_fr {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x28];
    UnkStruct_00451F70_fr * field_38;
};
struct UnkStruct_00451F70_txt {
    unsigned char pad_0[8];
    CGtV2d field_8;
    unsigned char pad_10[0x1C];
    int field_2C;
    CGtV2d field_30;
};
struct UnkStruct_00451F70_row {
    UnkStruct_00451F70_fr * field_0;
    UnkStruct_00451F70_fr * field_4;
    void * field_8;
    UnkStruct_00451F70_fr * field_C;
    UnkStruct_00451F70_fr * field_10[5];
};
struct UnkStruct_00451F70_row2 {
    UnkStruct_00451F70_fr * field_0;
    UnkStruct_00451F70_fr * field_4;
    void * field_8;
    UnkStruct_00451F70_fr * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    UnkStruct_00451F70_txt * field_1C;
    UnkStruct_00451F70_txt * field_20;
};
union UnkStruct_00451F70_r {
    UnkStruct_00451F70_row a;
    UnkStruct_00451F70_row2 b;
};
struct UnkStruct_00451F70 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_00451F70_r field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
    const unsigned short * field_13C;
    const unsigned short * field_140[16];
    int field_180[8];
    int field_1A0[8];
    signed char field_1C0[0x3A];
    signed char field_1FA;
    unsigned char pad_1FB[2];
    unsigned char field_1FD;
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_4D3130 { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_Pad16 D_004EE040;
extern UnkStruct_Pad16 D_00522660;
extern UnkStruct_Pad16 D_01EA4070;
extern UnkStruct_Pad16 D_0051B928;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_Pad16 D_01E903E0;
extern UnkStruct_D_int D_0064D37C;
extern UnkStruct_D_4D3130 D_004D3130;
extern CGtV4d D_01E903C0;
extern CGtV4d D_01E90250;
extern CGtV4d D_01E90350;
extern int D_00665ED0[4];
extern UnkStruct_Pad16 D_01EA4790;
extern UnkStruct_Pad16 D_01EA4798;
extern "C" void func_00453560(void *);
extern "C" void func_00453680(void *, int, int, int);
extern "C" int func_003BA8B0(void *, int);
extern "C" void func_0044CF90(void *, int, float);
extern "C" void * func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" UnkStruct_00451F70_fr * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const void *, const CGtV2d *, int);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, void *, const void *, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const void *, const void *, unsigned int);
extern "C" void func_00453980(void *, const void *);

static inline void func_00451F70_inl1(UnkStruct_00451F70_fr *c, UnkStruct_00451F70_fr *p)
{
    if (c != 0) {
        c->field_0 = c->field_0 - p->field_0;
        c->field_38 = p;
    }
}

// 0x00451F70
extern "C" int func_00451F70(UnkStruct_00451F70 *self)
{
    func_00453560(self);
    int cnt = D_0064D37C.field_0;
    int n = 0;
    self->field_134 = 1;
    self->field_1FD = 1;
    goto test;
body:
    {
        int i = self->field_138;
        int sel = *((signed char *)&D_004EE040 + n + 0x2D932);
        func_00453680(self, i, 6, 3);
        self->field_1C0[n] = func_003BA8B0(&D_0051B928, sel);
        self->field_180[n] = *(int *)((char *)&D_004EE040 + sel * 4 + 0x2D914);
        self->field_1A0[n] = *(int *)((char *)&D_004EE040 + sel * 4 + 0x2D8FC);
        func_0044CF90(self, n, 0.0f);
        UnkStruct_00451F70_r *e = &self->field_C[i];
        float f = 20.0f + e->b.field_0->field_0.marValues[0];
        e->b.field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->b.field_8);
        const unsigned short *str = (const unsigned short *)func_00271A00(&D_0051BA44, n + 0x260);
        func_0033D4E0(e->b.field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 28.0f, &D_01E903C0, (void *)(D_00665ED0[0]), str, &D_004D3130.field_0, 2);
        const unsigned short *s2 = (const unsigned short *)(*(int *)((char *)&D_00522660 + sel * 4 + 0x12AD28) + 0x1974);
        float z = 0.0f;
        f = 90.0f + ((z + e->b.field_0->field_0.marValues[0]) + z * e->b.field_0->field_8.marValues[0]);
        e->b.field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->b.field_8);
        func_0033D4E0(e->b.field_14, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, (void *)(D_00665ED0[0]), s2, &D_004D3130.field_0, 2);
        const unsigned short * const *q = &self->field_140[n];
        if (self->field_140[n] != 0) {
            float g = e->b.field_0->field_0.marValues[0] + e->b.field_0->field_8.marValues[0];
            e->b.field_1C = (UnkStruct_00451F70_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->b.field_8);
            CGtV4d col(D_01E903C0.mData);
            UnkStruct_00451F70_txt *t = e->b.field_1C;
            PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + -30.0f, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), self->field_140[n], (void *)func_00453980);
            t->field_30 = D_004D3130.field_0 / t->field_8;
            t->field_2C = 0;
        }
        if (*q != 0) {
            float g = e->b.field_0->field_0.marValues[0] + e->b.field_0->field_8.marValues[0];
            e->b.field_20 = (UnkStruct_00451F70_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->b.field_8);
            CGtV4d col(D_01E903C0.mData);
            UnkStruct_00451F70_txt *t = e->b.field_20;
            PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + 30.0f, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), *q, (void *)func_00453980);
            t->field_30 = D_004D3130.field_0 / t->field_8;
            t->field_2C = 0;
        }
        e->b.field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->b.field_8);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(e->b.field_18, CGtV2d(410.0f, 0.0f), CGtV2d(0.5f, 0.5f), CGtV2d(80.0f, 40.0f), D_01E90350, (void *)(*(int *)((char *)&D_01EA4070 + sel * 4 + 0x6C8)), &D_01EA4790, &D_01EA4798, *(int *)((char *)&D_01EA4070 + sel * 4 + 0x6E8));
        if (sel == 0) {
            self->field_1FA = i;
            UnkStruct_00451F70_r *e2 = &self->field_C[self->field_1FA];
            float z2 = 0.0f;
            CGtV2d p(z2 + e2->a.field_0->field_0.marValues[0] + 0.5f * e2->a.field_0->field_8.marValues[0], 0.0f);
            e2->a.field_C = ConstructChild__10CGt2dFrameFv(e2->a.field_8);
            e2->a.field_C->field_0 = p;
            func_00451F70_inl1(e2->a.field_4, e2->a.field_C);
            func_00451F70_inl1(e2->a.field_0, e2->a.field_C);
            int k = 0;
            do {
                func_00451F70_inl1(e2->a.field_10[k], e2->a.field_C);
                k++;
            } while (k < 5);
        }
        n++;
        self->field_138 = self->field_138 + 1;
    }
test:
    if (n < cnt) goto body;
    int rows = self->field_138;
    if (rows != 0) {
        float y = 0.0f + 240.0f - 0.5f * ((float)(rows - 1) * 44.0f);
        int i;
        for (i = 0; i < rows; i++) {
            ((UnkStruct_00451F70_fr *)self->field_C[i].a.field_8)->field_0 = CGtV2d(0.0f, y);
            y += 44.0f;
        }
    }
    return 1;
}
