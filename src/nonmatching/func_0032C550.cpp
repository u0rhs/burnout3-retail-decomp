// NONMATCHING: func_0032C550 -- retail 428 / ours 416 instructions, 331 in changed runs
// sdra: const pointee on a read-only param [G] (const loads are not ordered after stores, sdra rule 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: func_0032C550 -- retail 428 / ours 416 instructions, 334 in changed runs
// a178: logic-complete hand-written source (416 vs 428 instrs, ~334 changed). Remaining: register allocation (self/args land s3/s5 vs retail s5/s4/s3; ours hoists float consts 2.0/40.0/10.0 into f20-f22 across calls, retail reloads them and keeps only g in f20; frame 288 vs 304), y-row expression (adda/madd forms) and vector-local stack order (0xF8..0x114).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_Sc { unsigned char pad_0[0x14]; void * field_14; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P2 { unsigned char pad_0[0x10]; };
struct UnkStruct_obj { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_A4A10 { int field_0; int field_4; };
struct UnkStruct_0032C550_line { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_Mc {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    unsigned short field_C;
    unsigned short field_E;
    UnkStruct_0032C550_line field_10[2];
    UnkStruct_obj * field_20[2];
    UnkStruct_obj * field_28[3];
    unsigned char pad_34[0x10];
    void * field_44;
    int field_48;
    unsigned char pad_4C[0x4];
    float field_50;
    unsigned char pad_54[0x8];
    float field_5C;
    unsigned char field_60;
    unsigned char pad_61[0x7];
    unsigned char field_68[0x18];
    void * field_80;
    void * field_84;
    unsigned char pad_88[0xC];
    signed char field_94;
};
extern UnkStruct_Sc D_01E903E0;
extern UnkStruct_P D_01E90240[];
extern UnkStruct_F D_004C565C;
extern UnkStruct_F D_004C5660;
extern UnkStruct_F D_004C5648;
struct UnkStruct_V2 { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_Fnt { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_V2 D_004C5658;
extern UnkStruct_V2 D_004C5650;
extern UnkStruct_Fnt D_00665ED0;
extern UnkStruct_A4A10 D_004A4A10[];
struct UnkStruct_D_01EA4070 { unsigned char pad_0[0x400]; int field_400[0x100]; };
extern UnkStruct_D_01EA4070 D_01EA4070;
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, void *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, float, const void *, const void *, void *, const CGtV2d &);
extern "C" void func_00372400(void *, const CGtV2d &, const CGtV2d &, const void *, float, float, float);
extern "C" void func_002F9690(void *, const CGtV2d &, const CGtV2d &, const void *, void *, void *, int, int, float);

static inline float func_0032C550_inl1(UnkStruct_Mc * self, int i)
{
    float y;
    if (self->field_94 == 8) {
        y = 0.0f + self->field_50 + 40.0f * (float)i;
    } else {
        y = 0.0f + self->field_50 + (2.0f + D_004C565C.field_0) * (float)i;
    }
    return y;
}

// 0x0032C550
extern "C" void func_0032C550(UnkStruct_Mc * self, CGtV2d * p1, CGtV2d * p2, const CGtV2d * p3, int p4, int p5, int p6, int p7)
{
    int i;
    int n;
    float g;
    UnkStruct_Sc * const sc = &D_01E903E0;
    void * fr = sc->field_14;
    unsigned int flags = 0x1B;
    if (self->field_94 != 1 && self->field_60 == 0) {
        flags |= 0x100;
    }
    {
        CGtV2d zero;
        zero.Set(0.0f, 0.0f);
        Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_80, *p1, zero, *p2, flags, 0);
    }
    if (D_004A4A10[self->field_94].field_0 != 15) {
        self->field_10[0].field_0 = p5;
        self->field_10[0].field_4 = 0;
        self->field_10[0].field_5 = 0;
    }
    if (D_004A4A10[self->field_94].field_4 != 15) {
        self->field_10[1].field_0 = p6;
        self->field_10[1].field_4 = 0;
        self->field_10[1].field_5 = 0;
        if (p7 == D_004A4A10[self->field_94].field_4) {
            self->field_C = 1;
            self->field_E = 2;
        } else {
            self->field_C = 0;
            self->field_E = 2;
        }
    } else {
        self->field_C = 0;
        self->field_E = 1;
    }
    self->field_48 = -1;
    self->field_5C = -1.0f;
    self->field_50 = p1->marValues[1] + p2->marValues[1];
    if (D_004A4A10[self->field_94].field_0 == 15) {
        n = 0;
    } else {
        n = self->field_E;
    }
    if (self->field_94 == 8) {
        n = 3;
        if (p7 < 6 || p7 >= 10) {
            self->field_C = 0;
            self->field_E = 3;
        } else {
            self->field_C = p7 - 6;
            self->field_E = 3;
        }
        g = D_004C565C.field_0;
        self->field_50 = self->field_50 - 32.0f - 2.0f * (10.0f + g);
        for (i = 0; i < 3; i++) {
            UnkStruct_obj ** e = &self->field_28[i];
            if (*e == 0) {
                *e = (UnkStruct_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, self->field_8 + 1, fr);
            }
            float y = func_0032C550_inl1(self, i);
            CGtV2d c1, c2, c3, c4;
            c1.Set(1.0f, 1.0f);
            c2.Set(0.0f, 0.0f);
            c3.Set(0.5f, 0.5f);
            c4.Set(320.0f, y);
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_28[i], c4, c3, D_004C5658.field_0, (char *)&D_01E90240[0] + 0x110, (void *)D_01EA4070.field_400[i + 0x76], c2, c1, 0);
        }
    } else {
        g = 30.0f;
        self->field_50 = self->field_50 - 32.0f - 32.0f * ((float)n - 1.0f);
        UnkStruct_P * col = &D_01E90240[0];
        for (i = 0; i < n; i++) {
            UnkStruct_obj ** e = &self->field_20[i];
            if (*e == 0) {
                *e = (UnkStruct_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, self->field_8 + 1, fr);
            }
            float y = func_0032C550_inl1(self, i);
            CGtV2d c1, c2;
            c1.Set(0.5f, 0.5f);
            c2.Set(320.0f, y);
            Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(self->field_20[i], c2, c1, 30.0f, col, D_00665ED0.field_0, (void *)(self->field_10[i].field_0), D_004C5650.field_0);
        }
    }
    if ((unsigned)self->field_94 < 2) {
        g = 0.0f;
    }
    self->field_44 = 0;
    if (n > 0) {
        if (self->field_44 == 0) {
            self->field_44 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, self->field_8 + 1, fr);
        }
        float half = 0.0f;
        float x;
        int idx = self->field_C;
        if (self->field_94 == 8) {
            x = D_004C5660.field_0 + self->field_28[idx]->field_8;
        } else {
            float t = D_004C5660.field_0;
            half = t / 2.0f;
            x = t + self->field_20[idx]->field_8;
        }
        float z = 0.0f;
        float x0 = z + 640.0f + z * (x - 640.0f);
        float yv = func_0032C550_inl1(self, idx);
        CGtV2d d1, d2;
        d1.Set(0.0f, 0.5f);
        d2.Set(0.0f, yv);
        func_00372400(self->field_44, d2, d1, (char *)&D_01E90240[0] + 0x110, 640.0f, (half + (640.0f - x0)) / 2.0f, x0);
    }
    {
        CGtV2d e1, e2;
        e1.Set(0.5f, 0.5f);
        float t = p1->marValues[1];
        e2.Set(p3->marValues[0], t + ((0.0f + self->field_50 - 0.5f * g - t) / 2.0f));
        func_002F9690(self->field_84, e2, e1, &D_01E90240[0], (void *)(p4), (char *)self + 0x68, 0x67, 0, D_004C5648.field_0);
    }
}
