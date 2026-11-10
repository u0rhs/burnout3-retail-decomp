// NONMATCHING: func_0039A360 -- retail 624 / ours 616 instructions, 607 in changed runs
// hard1 C-first: [L] a CB3ExplosionManager burst: box base centre / half size / aspect, a burst frame (body axes scaled, world centre) and rotation, VU0 R seeded from the manager's CGtRandom, 5 particle kinds of D_004A50A0 (count each: two R-random vectors lerped into angle/speed and particle parameters, SinCosFast2 direction, radius blend 2t-t^2, TransformPoint/TransformVector, func_00254A90 spawn, stop on failure), then 1+(Random&3) AddExplosionTrail calls and func_0027B1D0; 616/624, calls identical, every VU op count equal (incl. 9 vrnext, 3 vmr32, vrinit), the random state D_01EA4BA0 stored twice as retail, CGtRandom state accesses as retail; left: frame 0x5E0 vs 0x7F0, 3 vmove temps, stack homes
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm region by region: every call with its 6 float arguments, every branch, the VU0 R-register sequence (vrinit / vrnext per lane / ACC mix with D_004C9A00 / vmr32 rotation, in named asm helpers: no C or header form) and the non-stack stores checked; the ACC mix is kept literally: (z + t) - z - t is a fractional-part extraction when D_004C9A00 holds a large rounding constant [G] (the ELF image has zeros there: presumably set at run time); not "simplified"

// func_0039A360 -- hard1 (C-first draft; deferred-hard by draftAF: "VU0 R-register random; no header API"). 0x39A360, 0x9C0.
// Unnamed in every table, so a placeholder with C linkage. [L] a CB3ExplosionManager member (between AddExplosionTrail and
// func_0039AD20 in the explosion unit; its CGtRandom at +0xF0; called from the effects code at 0x25FB04). Written from the retail
// asm region by region. Meanings [G], types [G].
// What it does [L]: an explosion burst at a box on a body:
//  - the box's base centre c = hi * (0.5, 1, 0.5) + lo * (0.5, 0, 0.5), its half size d = lo - c and the aspect k = 0.5 + 0.5 x / z;
//    a burst frame: the body's axes scaled by d * (1/k, 1, k) / 2 at the world position of c, and its (right, (0,1,0), at) rotation;
//  - the VU0 random generator R seeded from the manager's CGtRandom;
//  - for the 5 particle kinds of D_004A50A0 (0x38 each: particle system index, count, timing/size ranges, speeds): count
//    particles, each from two random vectors (angles pi +- 2pi / pi, a speed; and three particle parameters), a direction from
//    SinCosFast2 of the two angles, position = the burst frame on that direction x a radius blending over the burst
//    (2t - t^2), velocity = the rotation on the direction x speed + the given vector x the speed lane; func_00254A90 spawns it
//    (stops the kind when it fails);
//  - then 1-4 explosion trails (AddExplosionTrail) from the burst centre in random directions, and func_0027B1D0 on
//    D_01E78510 with the body's position.
// The random vectors keep retail's exact VU0 sequence (R draws x a rotating state D_01EA4BA0, mixed through ACC with the
// vector D_004C9A00): one named helper per operation. gapO (N288): b3/_unclassified/CV3dRandomiser.h now has this pattern as
// CV3dRandomiser::RandomiseXYZ ([L] Revenge STABS names; D_01EA4BA0 / D_004C9A00 = this file's gEffectsRandomiserScales /
// kEffectsRandomiser2E23), but through it this archive scores 645 (641 instrs, 577 changed) vs 639 here: helpers kept.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_0039A360_k {               // D_004A50A0 entries (0x38)
    int field_0;                            // particle system index (D_01D9D200 + 0x170 + i * 0x150)
    int field_4;                            // count
    float field_8;                          // start time offset
    float field_C;                          // time spread
    float field_10;                         // radius at the start
    float field_14;                         // radius at the end
    float field_18;                         // vertical direction scale
    float field_1C;                         // speed scale
    float field_20;
    float field_24;
    float field_28;                         // speed range
    float field_2C;
    float field_30;
    float field_34;
};
extern UnkStruct_0039A360_k D_004A50A0[5];
extern unsigned char D_01D9D200[];          // the effects manager instance [G] (its particle systems at +0x170, time +0x1F848)
extern CGtV3d D_01EA4BA0;                   // the random generator's rotating state
extern CGtV3d D_004C9A00;
extern bool D_004E1E80;
struct UnkStruct_0039A360_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_0039A360_16 D_01E78510;
class CB3ExplosionManager {
public:
    unsigned char pad_0[0xF0];
    CGtRandom field_F0;
};
extern "C" int func_00254A90(void *, CGtV3d *, CGtV3d *, bool, bool, float, float, float, float, float, float);
extern "C" void AddExplosionTrail__19CB3ExplosionManagerFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ExplosionManager *, const CGtV3d *, const CGtV3d *);
extern "C" void func_0027B1D0(void *, const CGtV3d *);

// the VU0 random generator seeded (vrinit)
static inline void func_0039A360_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}
// [L] a random vector: three R draws times the rotating state, mixed through ACC with D_004C9A00 exactly as retail
// (`vmul; vadda.xyz ACC,z,t; vmsubaw.xyz ACC,z,w1; vmsubw.xyz d,t,w1`); the state then rotates one lane (vmr32)
static inline CGtV3d func_0039A360_inl2()
{
    u_long128 r, t, d, st, nst;
    // one statement per lane, "+j" and volatile: in a single statement MWCC drops the .x/.y draws as dead partial writes,
    // which would also skip two R advances (the random sequence)
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    asm volatile("vrnext.y %0, $R" : "+j"(r));
    asm volatile("vrnext.z %0, $R" : "+j"(r));
    st = D_01EA4BA0.mData;
    asm("vmul.xyz %0, %1, %2" : "=j"(t) : "j"(st), "j"(r));
    asm("vadda.xyz $ACC, %1, %2" "\n\t" "vmsubaw.xyz $ACC, %1, $vf0w" "\n\t" "vmsubw.xyz %0, %2, $vf0w"
        : "=j"(d) : "j"(D_004C9A00.mData), "j"(t));
    asm("vmr32.xyzw %0, %1" : "=j"(nst) : "j"(st));
    D_01EA4BA0.mData = nst;
    return CGtV3d(d);
}
// base + range * t per lane through ACC (`vaddax.xyz ACC, base, vf0x; vmadd.xyz d, range, t`)
static inline CGtV3d func_0039A360_inl3(const CGtV3d &base, const CGtV3d &range, const CGtV3d &t)
{
    u_long128 d;
    asm("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "vmadd.xyz %0, %2, %3" : "=j"(d) : "j"(base.mData), "j"(range.mData), "j"(t.mData));
    return CGtV3d(d);
}

// 0x0039A360
extern "C" void func_0039A360(CB3ExplosionManager *self, const CGtMatrix3x4 *m, const CGtV3d *box, const CGtV3d *push, float f12 /* passed by every caller, not read here */)
{
    CGtV3d lpush = *push;
    CGtV3d c = box[1] * CGtV3d(0.5f, 1.0f, 0.5f) + box[0] * CGtV3d(0.5f, 0.0f, 0.5f);
    CGtV3d d = box[0] - c;
    float k = 0.5f + 0.5f * ((float)d.X() / (float)d.Z());
    float ik = 1.0f / k;
    CGtV3d wc = m->mPos + m->mRight * c.X() + m->mUp * c.Y() + m->mAt * c.Z();
    CGtV3d sc(ik, 1.0f, k);
    CGtV3d hs = d * sc * 0.5f;
    CGtMatrix3x4 burst;
    burst.mRight = m->mRight * hs.X();
    burst.mUp = m->mUp * hs.Y();
    burst.mAt = m->mAt * hs.Z();
    burst.mPos = wc;
    CGtMatrix3x3 rot;
    rot.mRight = burst.mRight;
    rot.mUp = CGtV3d(0.0f, 1.0f, 0.0f);
    rot.mAt = burst.mAt;
    func_0039A360_inl1(self->field_F0.RandomReal());
    for (int i = 0; i < 5; i++) {
        UnkStruct_0039A360_k *e = &D_004A50A0[i];
        int n = e->field_4;
        float dt = 1.0f / (float)(n - 1);
        CGtV3d hi1(3.1415927f, 3.1415927f, e->field_28);
        CGtV3d lo1(-3.1415927f, 0.0f, 0.0f);
        void *pool = D_01D9D200 + e->field_0 * 0x150 + 0x170;
        CGtV3d base1 = hi1;
        CGtV3d range1 = hi1 - lo1;
        CGtV3d hi2(e->field_30, 1.0f, e->field_20);
        CGtV3d lo2(e->field_2C, e->field_24, -e->field_20);
        CGtV3d base2 = hi2;
        CGtV3d range2 = hi2 - lo2;
        for (int j = 0; j < n; j++) {
            CGtV3d a = func_0039A360_inl3(base1, range1, func_0039A360_inl2());
            CGtV3d b = func_0039A360_inl3(base2, range2, func_0039A360_inl2());
            float t = (float)j * dt;
            float f = t + t - t * t;
            float time = *(float *)(D_01D9D200 + 0x1F848);
            CGtV4d s = SinCosFast2((float)a.X(), (float)a.Y());
            float rad = e->field_10 + f * (e->field_14 - e->field_10);
            CGtV3d dir;
            dir.SetX(s.X() * s.W());
            dir.SetY(s.Z() * e->field_18);
            dir.SetZ(s.Y() * s.W());
            dir = dir * rad;
            CGtV3d vdir = dir * e->field_1C;
            CGtV3d pos = TransformPoint(burst, dir);
            CGtV3d vel = TransformVector(rot, vdir) + lpush * a.Z();
            if (!func_00254A90(pool, &pos, &vel, D_004E1E80, true, (time + e->field_8) + f * e->field_C, (float)b.X(), 0.0f,
                               (float)b.Y(), 1.0f, (float)b.Z()))
                break;
        }
    }
    // explosion trails
    CGtV3d hi(6.2831855f, 1.2566371f, 30.0f);
    CGtV3d lo(0.0f, 0.31415927f, 12.5f);
    int n = 1 + (self->field_F0.Random() & 3);
    CGtV3d base = hi;
    CGtV3d range = hi - lo;
    while (n != 0) {
        n--;
        CGtV3d a = func_0039A360_inl3(base, range, func_0039A360_inl2());
        CGtV4d s = SinCosFast2((float)a.X(), (float)a.Y());
        CGtV3d dir;
        dir.SetX(s.X() * s.W());
        dir.SetY(s.Z());
        dir.SetZ(s.Y() * s.W());
        dir = dir * a.Z();
        AddExplosionTrail__19CB3ExplosionManagerFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(self, &burst.mPos, &dir);
    }
    func_0027B1D0(&D_01E78510, &m->mPos);
}
