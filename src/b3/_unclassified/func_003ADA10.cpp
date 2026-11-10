// Hand-written; the lifter refused it (mwperm: +'int t2; UnkStruct_3ADA10_obj * src; int i;'; 'int i; UnkStruct_3ADA10_obj ** slot;' -> ''; +'UnkStruct_3ADA10_obj * o;'; 'for (i = 0; i < n; i++) { slot = &self->field_18C[i]; UnkStr' -> 'i = 0; goto loop0_t; loop0: UnkStruct_3ADA10_obj ** slot = &self->field_18C[i]; '; 'float frac = t - (float)(int)t; func_003ADA10_inl1(&self->fi' -> '} float t0 = t - (float)(int)t; const float t3 = t0; const f).

// func_003ADA10 -- hand-written from retail (lifter refused); SatNav popup-row highlight update (floor/frac pulse on the selected row)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dFrame;

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_3ADA10_blk {
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    signed char field_14;
    signed char field_15;
    signed char field_16;
};
struct UnkStruct_3ADA10_obj {
    CGtV2d field_0;
    CGtV2d field_8;
    u_long128 field_10;
    UnkStruct_3ADA10_blk field_20;
    unsigned char pad_38[0x8];
};
struct UnkStruct_3ADA10 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x182];
    UnkStruct_3ADA10_obj * field_18C[1];
    unsigned char pad_190[0x2C];
    UnkStruct_3ADA10_obj * field_1BC;
    unsigned char pad_1C0[0x68];
    CGt2dFrame * field_228;
    unsigned char pad_22C[0x28];
    int field_254;
    unsigned char pad_258[0x20];
    int field_278;
    int field_27C;
    unsigned char pad_280[0x24];
    int field_2A4[1];
    unsigned char pad_2A8[0x640];
    unsigned char field_8E8;
    unsigned char pad_8E9[0xC7];
    float field_9B0;
};
extern UnkStruct_P D_01E903E0, D_0051A870, D_01E7A800;
extern float D_004E06A8, D_004E06DC;
extern "C" int func_003F5D10(int);
extern "C" void func_00324EC0(void *);
extern "C" void func_00285050(void *);
extern "C" UnkStruct_3ADA10_obj * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, const void *, void *, unsigned int, unsigned int);
extern "C" void func_003B0160(void *, void *);

static inline void func_003ADA10_inl1(UnkStruct_3ADA10_blk * b, float t, float frac)
{
    float m2 = -2.0f;
    float one = 1.0f;
    if (t >= 0.0f) {
        if (frac >= 0.5f) {
            b->field_4 = -2.0f * (frac - 1.0f);
        } else {
            b->field_4 = 2.0f * frac;
        }
    } else {
        b->field_4 = -1.0f;
    }
    if (t >= 0.5f) {
        b->field_8 = one;
    } else {
        b->field_8 = 2.0f * frac;
    }
}

// 0x003ADA10
extern "C" void func_003ADA10(UnkStruct_3ADA10 * self)
{
    int t2;
    UnkStruct_3ADA10_obj * src;
    int i;
    float t;
    int n;
    UnkStruct_3ADA10_obj * o;
    self->field_8E8 = 0;
    n = func_003F5D10(self->field_254);
    i = 0;
    goto loop0_t;
loop0:
    UnkStruct_3ADA10_obj ** slot = &self->field_18C[i];
    o = *slot;
    if (0 == o) {
    } else {
        t = 1.25f * self->field_9B0;
        bool t5 = i == self->field_27C;
        if (t5) {
            if (self->field_1BC) {
            } else {
                self->field_1BC = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 0xD, self->field_228);
                src = self->field_18C[self->field_27C];
                UnkStruct_3ADA10_obj *const  no = self->field_1BC;
                no->field_20 = src->field_20;
                u_long128 col = src->field_10;
                Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(no, src->field_0, src->field_8, &col, (void *)&func_003B0160, 0x40, 0x18);
                no->field_20.field_C = 1.0f;
                if (self->field_278 != -1) {
                    self->field_18C[self->field_27C]->field_20.field_C = 0.0f;
                }
            }
            float t0 = t - (float)(int)t;
            const float t3 = t0;
            const float frac = t3;
            func_003ADA10_inl1(&self->field_1BC->field_20, t, frac);
            self->field_1BC->field_20.field_C = 1.0f;
            func_003ADA10_inl1(&(*slot)->field_20, t, frac);
            (*slot)->field_20.field_C = 1.0f;
        } else {
            o->field_20.field_4 = 0.0f;
            o->field_20.field_8 = 0.0f;
            t2 = self->field_2A4[i];
            if (3 != t2 && self->field_2A4[i] != 2) {
                (*slot)->field_20.field_C = 0.5f;
            } else {
                (*slot)->field_20.field_C = 1.0f;
            }
        }
    }
    ++i;
        
loop0_t:
    bool t4;
    t4 = n > i;
    if (t4) goto loop0;
    func_00324EC0(&D_0051A870);
    if (t > D_004E06A8 && t < D_004E06DC) {
        func_00285050(&D_01E7A800);
    }
}
