// Hand-written; the lifter refused it (N182 opt_repositioncode off + whole CGtV2d copy).

#include "b3/GtMathPs2.h"

// N182: retail compiled this function with `#pragma opt_repositioncode off` ([G] scoped to this function).
#pragma push
#pragma opt_repositioncode off
using GtMathPs2::CGtV2d;
class CGt2dObject;
struct UnkStruct_D_01E903E0_e { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x2C]; UnkStruct_D_01E903E0_e * field_2C; unsigned char pad_30[0x10]; };
struct UnkStruct_ReleaseExtraLeadIn {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E];
    float field_28;
    float field_2C;
    unsigned char pad_30[0x1D4];
    CGt2dObject * field_204[2];
    CGt2dObject * field_20C[2];
    unsigned char pad_214[0x4];
    CGt2dObject * field_218;
    unsigned char pad_21C[0x38];
    int field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x484];
    int field_704;
    unsigned char pad_708[0x1DC];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x1];
    unsigned char field_8E6;
    unsigned char pad_8E7[0xC9];
    int field_9B0;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void func_003D30D0(void *);
extern "C" CGtV2d func_003F5C70(int, int, int);

extern "C" void ReleaseExtraLeadIn__18CB3SatNavComponentFv(UnkStruct_ReleaseExtraLeadIn * self)
{
    int i;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int t0 = self->field_8;
    int a = t0 + 2;
    int c = t0 + 10;
    CGt2dObject ** p;
    i = 0;
    do {
        p = &self->field_204[i];
        if (*p != 0) goto f1;
n1:     i++;
    } while (i < 2);
    i = 0;
    do {
        p = &self->field_20C[i];
        if (*p != 0) goto f2;
n2:     i++;
    } while (i < 2);
    if (self->field_218 != 0) {
        func_003D30D0(self->field_218);
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, self->field_218);
        self->field_218 = 0;
    }
    CGtV2d v = func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1);
    *(CGtV2d *)&self->field_28 = v;
    self->field_8E4 = 2;
    self->field_704 = 0;
    self->field_9B0 = 0;
    goto done;
f1:
    scene->field_2C[t0 + i].field_0 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0 + i, *p);
    *p = 0;
    goto n1;
f2:
    scene->field_2C[a + i].field_0 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a + i, *p);
    *p = 0;
    goto n2;
done:
    return;
}

#pragma pop
