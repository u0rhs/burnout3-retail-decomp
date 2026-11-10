// NONMATCHING: func_004526F0 -- retail 503 / ours 501 instructions, 493 in changed runs
// audit1 (2026-11-01): text sizes: func_003D0710 takes 28.0 (not 30.0) and func_0033D4E0 22.0 (not 24.0) [C] retail 0x452B08 lui 0x41E0, func_0033D4E0 sites f12 = 0x41B00000 (behaviour_audit) | Before: lit4fix: .lit4 externs rewritten as literals; was: a179: logic complete (6-bit mask loop, two builders A (sub text present) / B, grad-label blocks via func_003D0710(obj,pos,anchor,col,1,1,1,(void *)(font),30.0,D_004E0C14,text,false)), 501 vs 503 instrs, ~500 changed because the loop layout differs: retail keeps only [flag test; shift; sltiu/bnez] in the loop 
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_004526F0_fr { CGtV2d field_0; CGtV2d field_8; };
struct UnkStruct_004526F0_txt {
    unsigned char pad_0[8];
    CGtV2d field_8;
    unsigned char pad_10[0x1C];
    int field_2C;
    CGtV2d field_30;
};
struct UnkStruct_004526F0_ob { CGtV2d field_0; float field_8; float field_C; };
struct UnkStruct_004526F0_row {
    UnkStruct_004526F0_fr * field_0;
    unsigned char pad_4[4];
    void * field_8;
    unsigned char pad_C[4];
    void * field_10;
    UnkStruct_004526F0_txt * field_14;
    void * field_18;
    UnkStruct_004526F0_txt * field_1C;
    void * field_20;
};
struct UnkStruct_004526F0_row2 {
    UnkStruct_004526F0_ob * field_0;
    unsigned char pad_4[0x20];
};
struct UnkStruct_004526F0 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_004526F0_row field_C[8];
    unsigned char pad_12C[4];
    const unsigned short * field_130;
    unsigned char pad_134[4];
    int field_138;
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_4D3130 { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_int D_01ECDA0C;
extern UnkStruct_D_byte D_01ECDAC5;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_Pad16 D_01E903E0;
extern UnkStruct_D_4D3130 D_004D3130;
extern CGtV4d D_01E903C0;
extern CGtV4d D_01E90250;
extern CGtV4d D_01E90350;
extern int D_00665ED0[4];
extern "C" const unsigned short * func_00452ED0(void *, int, int, unsigned char *);
extern "C" void func_00453680(void *, int, int, int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const void *, const CGtV2d *, int);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, void *, const void *, void *);
extern "C" void func_00453980(void *, const void *);
extern "C" void func_003D0710(void *, const CGtV2d &, const CGtV2d &, CGtV4d, int, int, int, void *, float, float, const unsigned short *, bool);

// 0x004526F0
extern "C" void func_004526F0(UnkStruct_004526F0 *self)
{
    unsigned int mask = 1;
    goto test;
body:
    {
        if ((D_01ECDA0C.field_0 & mask) == 0) goto next;
        unsigned char b0 = 0;
        unsigned char b1 = 0;
        const unsigned short *s1 = 0;
        const unsigned short *s2;
        s2 = func_00452ED0(self, mask, 0, &b0);
        if (s2 == 0) goto next;
        int sid;
        switch (mask) {
        case 0:
        case 1:
        default:
            sid = 0x375;
            break;
        case 2:
            sid = 0x372;
            break;
        case 4:
            sid = 0x2A3;
            break;
        case 8:
            sid = 0x2A2;
            break;
        case 0x10:
            sid = 0x9DA;
            break;
        case 0x20:
            sid = 0x9DB;
            break;
        }
        if (D_01ECDAC5.field_0 != 0) s1 = func_00452ED0(self, mask, 1, &b1);
        if (s1 != 0) {
            int row = self->field_138;
            int f7 = b0;
            int fp = b1;
            func_00453680(self, row, 0, 4);
            const unsigned short *str = func_00271A00(&D_0051BA44, sid);
            UnkStruct_004526F0_row *e = &self->field_C[row];
            float z = 0.0f;
            float f = 30.0f + ((z + e->field_0->field_0.marValues[0]) + z * e->field_0->field_8.marValues[0]);
            e->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
            func_0033D4E0(e->field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, (void *)(D_00665ED0[0]), str, &D_004D3130.field_0, 2);
            if (s1 != 0) {
                float g = e->field_0->field_0.marValues[0] + e->field_0->field_8.marValues[0];
                e->field_14 = (UnkStruct_004526F0_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
                CGtV4d col(D_01E903C0.mData);
                UnkStruct_004526F0_txt *t = e->field_14;
                PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + -30.0f, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), s1, (void *)func_00453980);
                t->field_30 = D_004D3130.field_0 / t->field_8;
                t->field_2C = 0;
            }
            if (fp != 0) {
                UnkStruct_004526F0_ob *o = (UnkStruct_004526F0_ob *)e->field_14;
                float oy = o->field_0.marValues[1];
                float ox = (o->field_0.marValues[0] + o->field_8) - 50.0f;
                e->field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 3, e->field_8);
                func_003D0710(e->field_18, CGtV2d(ox, oy), CGtV2d(1.0f, 0.7f), D_01E90350, 1, 1, 1, (void *)(D_00665ED0[0]), 28.0f, 3.4028235e+38f, self->field_130, false);
            }
            if (s2 != 0) {
                if (s2 != 0) {
                    float g = e->field_0->field_0.marValues[0] + e->field_0->field_8.marValues[0];
                    e->field_1C = (UnkStruct_004526F0_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
                    CGtV4d col(D_01E903C0.mData);
                    UnkStruct_004526F0_txt *t = e->field_1C;
                    PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + -190.0f, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), s2, (void *)func_00453980);
                    t->field_30 = D_004D3130.field_0 / t->field_8;
                    t->field_2C = 0;
                }
                if (f7 != 0) {
                    UnkStruct_004526F0_ob *o = (UnkStruct_004526F0_ob *)e->field_1C;
                    float oy = o->field_0.marValues[1];
                    float ox = (o->field_0.marValues[0] + o->field_8) - 50.0f;
                    e->field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 3, e->field_8);
                    func_003D0710(e->field_20, CGtV2d(ox, oy), CGtV2d(1.0f, 0.7f), D_01E90350, 1, 1, 1, (void *)(D_00665ED0[0]), 28.0f, 3.4028235e+38f, self->field_130, false);
                }
            }
        } else {
            int a3 = (mask & 0x10) ? 1 : ((mask & 0x20) ? 2 : 3);
            int row = self->field_138;
            int f5 = b0;
            func_00453680(self, row, 0, a3);
            const unsigned short *str = func_00271A00(&D_0051BA44, sid);
            UnkStruct_004526F0_row *e = &self->field_C[row];
            float z = 0.0f;
            float f = 30.0f + ((z + e->field_0->field_0.marValues[0]) + z * e->field_0->field_8.marValues[0]);
            e->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
            func_0033D4E0(e->field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &D_01E90250, (void *)(D_00665ED0[0]), str, &D_004D3130.field_0, 2);
            if (s2 != 0) {
                float g = e->field_0->field_0.marValues[0] + e->field_0->field_8.marValues[0];
                e->field_14 = (UnkStruct_004526F0_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, e->field_8);
                CGtV4d col(D_01E903C0.mData);
                UnkStruct_004526F0_txt *t = e->field_14;
                PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, CGtV2d(g + -30.0f, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, col, (void *)(D_00665ED0[0]), s2, (void *)func_00453980);
                t->field_30 = D_004D3130.field_0 / t->field_8;
                t->field_2C = 0;
            }
            if (f5 != 0) {
                UnkStruct_004526F0_ob *o = (UnkStruct_004526F0_ob *)e->field_14;
                float oy = o->field_0.marValues[1];
                float ox = (o->field_0.marValues[0] + o->field_8) - 50.0f;
                e->field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 3, e->field_8);
                func_003D0710(e->field_18, CGtV2d(ox, oy), CGtV2d(1.0f, 0.7f), D_01E90350, 1, 1, 1, (void *)(D_00665ED0[0]), 28.0f, 3.4028235e+38f, self->field_130, false);
            }
        }
        self->field_138 = self->field_138 + 1;
    }
next:
    mask <<= 1;
test:
    if (mask < 0x40) goto body;
}
