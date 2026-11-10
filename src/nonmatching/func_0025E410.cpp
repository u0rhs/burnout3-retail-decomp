// NONMATCHING: func_0025E410 -- retail 408 / ours 373 instructions, 506 in changed runs
// fix2 (2026-11-01): func_00254A90 now gets its 11 arguments (bank = self+0x170+type*0x150, the draft passed +0x170 twice; f13..f17 = c.w*(t1[1]-c.z)+t1[0], c.z, c.y, threshold draw, c.x); the two vector draws are CV3dRandomiser RandomiseXYZ / RandomInterpolate (the draft used raw R values: wrong ranges); c lerps all four lanes (v100 w 0, v110 w 1) [C] retail 0x25E728..0x25EA08 | Before: psweep: scoped #pragma inline_depth(3) [G] improves 648 -> 607
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix2: loop and setup re-derived from the retail asm 0x25E728..0x25EA38 (every func_00254A90 argument, randomiser ranges, lane sources); behaviour_audit quiet



#include "b3/GtMathPs2.h"
#include "b3/_unclassified/CV3dRandomiser.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;

extern float D_004E1180;
extern float D_004E1170;
extern float D_004E12CC;
// [C] reads a0..a3, t0, f12..f17 (its own retail code; archive func_00254A90: SpawnParticle-like (pos, vel, bool, bool, 6 floats))
extern "C" int func_00254A90(void *, const CGtV3d *, const CGtV3d *, bool, bool, float, float, float, float, float, float);

struct UnkStruct_0025EA70_tbl {   // [G] D_004BC040, stride 0x38
    int field_0;
    unsigned char pad_4[8];
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[4];
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
};
extern UnkStruct_0025EA70_tbl D_004BC040[];

struct UnkStruct_0025EA70_this {   // [G]
    unsigned char pad_0[0x170];
    unsigned char field_170[0x150][1];
    unsigned char pad_2C0[0x1F828 - 0x2C0];
    int field_1F828;
    int field_1F82C;
    unsigned char pad_1F830[0x1F848 - 0x1F830];
    float field_1F848;
};

// [G] one draw from the member LCG as a float in [0,1)
static inline float func_0025E410_inl1(UnkStruct_0025EA70_this *t)
{
    t->field_1F828 = (t->field_1F828 << 16) + (t->field_1F828 >> 16);
    t->field_1F828 = t->field_1F828 + t->field_1F82C;
    t->field_1F82C = t->field_1F82C + t->field_1F828;
    return (float)(unsigned int)t->field_1F828 * 2.3283064e-10f;
}

// [C] four raw VU0 R-register draws (each in [1, 2)), one per lane (retail 0x25E964..0x25E970); one volatile statement each
static inline CGtV4d func_0025E410_inl2()
{
    u_long128 r;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    asm volatile("vrnext.y %0, $R" : "+j"(r));
    asm volatile("vrnext.z %0, $R" : "+j"(r));
    asm volatile("vrnext.w %0, $R" : "+j"(r));
    return CGtV4d(r);
}
// [C] one raw draw in x (retail 0x25E83C)
static inline float func_0025E410_inl3()
{
    u_long128 r;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    return CGtV4d(r).f[0];
}

// 0x0025E410
extern "C" void func_0025E410(UnkStruct_0025EA70_this *self, CGtV3d p1, CGtV3d p2, CGtV3d p3, int idx, float fa, float fb, float *t1, unsigned char *t2, bool t3, bool flag)
{
    UnkStruct_0025EA70_tbl *e = &D_004BC040[idx];
    unsigned char *obj = self->field_170[0] + e->field_0 * 0x150;
    float frac = (t2 == 0) ? 0.5f : (float)*t2 * 0.00390625f;
    float r = func_0025E410_inl1(self);
    float k = fa * (0.875f + 0.25f * r);
    int n0, n1;
    if (!flag) {
        n1 = 0;
        float s = k * *(float *)(obj + 0x108) + frac;
        n0 = (int)s;
        frac = s - (float)n0;
    } else {
        float s = k * e->field_30 * *(float *)(obj + 0x108) + frac;
        n0 = (int)s;
        s = k * e->field_34 * *(float *)(obj + 0x134) + (s - (float)n0);
        n1 = (int)s;
        frac = s - (float)n1;
    }
    if (t2 != 0) {
        *t2 = (unsigned char)(int)(D_004E12CC * frac);
    }
    float seed = func_0025E410_inl1(self);
    asm("vrinit $R, %0x" : : "j"(seed));
    // [C] retail 0x25E728..0x25E838: randomiser A = (v220, 2*v220) (uniform in [-v220, v220]), B = (p3*k, p3*k - p3*k*0.5)
    // (one draw along the line), C = lerp(v100, v110, R - 1) on all four lanes, v300 = (lo, hi) for the threshold draw
    CGtV3d v220;
    v220.Set(e->field_10, e->field_14, e->field_10);
    CV3dRandomiser rA;
    rA.mVecA = v220;
    rA.mVecB = v220 + v220;
    CGtV3d vf5 = p3 * *(float *)&e->field_C;   // [G] field_C is read as a raw word broadcast
    CV3dRandomiser rB;
    rB.mVecA = vf5;
    rB.mVecB = vf5 - vf5 * 0.5f;
    CGtV4d v100(-e->field_18, e->field_20, t1[1] * 0.5f, 0.0f);
    CGtV4d v110(e->field_18, e->field_24, t1[1], 1.0f);
    CGtV4d baseC = v100 + v100 - v110;
    CGtV4d rangeC = v110 - v100;
    float lo = fb * e->field_2C - fb * e->field_28;
    float hi2 = fb * e->field_28 + fb * e->field_28 - fb * e->field_2C;
    float lim = D_004E1170;
    int i = n0 + n1;
    while (i-- != 0) {
        float rx = hi2 + lo * func_0025E410_inl3();
        if (rx <= lim) continue;
        CGtV3d a = rA.RandomiseXYZ();
        if ((float)DotProduct(a, p2) < 0.0f) a = -a;
        CGtV3d out = a + rB.RandomInterpolate();
        CGtV4d c = baseC + rangeC * func_0025E410_inl2();
        // [C] retail 0x25E994..0x25EA08: f12 = self+0x1F848, f13 = c.w * (t1[1] - c.z) + t1[0], f14 = c.z, f15 = c.y,
        // f16 = the threshold draw, f17 = c.x; a0 = the particle bank (self + 0x170 + type * 0x150)
        func_00254A90(obj, &p1, &out, t3, i >= n0, self->field_1F848, c.f[3] * (t1[1] - c.f[2]) + t1[0], c.f[2], c.f[1], rx, c.f[0]);
    }
}

#pragma pop
