// NONMATCHING: func_0025EA70 -- retail 404 / ours 393 instructions, 439 in changed runs
// fix2 (2026-11-01): func_00254A90 now gets its 11 arguments (bank = self+0x170+type*0x150, the draft passed +0x170 twice; f13..f17 = b.y*(t1[1]-b.x)+t1[0], b.x, a.z, a.x, a.y); the four vector draws are CV3dRandomiser RandomiseXYZ x3 / RandomInterpolate (the draft used raw R values: wrong ranges; vD0.z is e->field_10, not 0) [C] retail 0x25ED84..0x25F068 | Before: psweep: scoped #pragma inline_depth(3) [G] improves 676 -> 601
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix2: loop and setup re-derived from the retail asm 0x25ED84..0x25F078 (every func_00254A90 argument, randomiser ranges, lane sources); behaviour_audit quiet



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
static inline float func_0025EA70_inl1(UnkStruct_0025EA70_this *t)
{
    t->field_1F828 = (t->field_1F828 << 16) + (t->field_1F828 >> 16);
    t->field_1F828 = t->field_1F828 + t->field_1F82C;
    t->field_1F82C = t->field_1F82C + t->field_1F828;
    return (float)(unsigned int)t->field_1F828 * 2.3283064e-10f;
}

// 0x0025EA70
extern "C" void func_0025EA70(UnkStruct_0025EA70_this *self, CGtV3d p1, CGtV3d p2, CGtV3d p3, int idx, float fa, float fb, float *t1, unsigned char *t2, bool t3, bool flag)
{
    UnkStruct_0025EA70_tbl *e = &D_004BC040[idx];
    unsigned char *obj = self->field_170[0] + e->field_0 * 0x150;
    float frac = (t2 == 0) ? 0.5f : (float)*t2 * 0.00390625f;
    float r = func_0025EA70_inl1(self);
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
    float seed = func_0025EA70_inl1(self);
    asm("vrinit $R, %0x" : : "j"(seed));
    // [C] retail 0x25ED84..0x25EEA4: four randomisers (A = maximum, B = maximum - minimum, as CV3dRandomiser)
    CGtV3d vA, vA2;
    vA.Set(fb * e->field_28, -e->field_18, e->field_20);
    vA2.Set(fb * e->field_2C, e->field_18, e->field_24);
    CV3dRandomiser rA;                       // sp+0x340/0x350
    rA.mVecA = vA2;
    rA.mVecB = vA2 - vA;
    CGtV3d vB, vB2;
    vB.Set(t1[1], 1.0f, D_004E1180 * e->field_C);
    vB2.Set(t1[1] * 0.5f, 0.0f, e->field_C * 0.75f);
    CV3dRandomiser rB;                       // sp+0x320/0x330
    rB.mVecA = vB;
    rB.mVecB = vB - vB2;
    CV3dRandomiser rC;                       // sp+0x360/0x370
    rC.mVecA = p3;
    rC.mVecB = p3 - p2;
    CGtV3d vD0, vD1;
    vD0.Set(e->field_10, e->field_14, e->field_10);
    vD1.Set(-e->field_10, 0.0f, -e->field_10);
    CV3dRandomiser rD;                       // sp+0x380/0x390
    rD.mVecA = vD0;
    rD.mVecB = vD0 - vD1;
    float lim = D_004E1170;
    int i = n0 + n1;
    while (i-- > 0) {
        CGtV3d a = rA.RandomiseXYZ();
        if (((float *)&a)[0] <= lim) continue;
        CGtV3d b = rB.RandomiseXYZ();
        CGtV3d c = rC.RandomInterpolate() * ((float *)&b)[2];
        CGtV3d out = c + rD.RandomiseXYZ();
        // [C] retail 0x25F000..0x25F068: f12 = self+0x1F848, f13 = b.y * (t1[1] - b.x) + t1[0], f14 = b.x, f15 = a.z,
        // f16 = a.x, f17 = a.y; a0 = the particle bank (self + 0x170 + type * 0x150)
        func_00254A90(obj, &p1, &out, t3, n0 < i, self->field_1F848, ((float *)&b)[1] * (t1[1] - ((float *)&b)[0]) + t1[0], ((float *)&b)[0], ((float *)&a)[2], ((float *)&a)[0], ((float *)&a)[1]);
    }
}

#pragma pop
