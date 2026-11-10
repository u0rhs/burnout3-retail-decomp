// NONMATCHING: func_0025DF30 -- retail 311 / ours 297 instructions, 207 in changed runs
// draftAN C-first: [L] CB3EffectsManager::SpawnSparksFromPoint (E map 0x26FDD0, Revenge STABS shape): fractional count carry D_004E19D8 (regular sparks, then x7 crash sparks when flagged), velocity randomness min(|VelA|/50, 1) scales the spark box (-3,0.5,-3)..(3,13,3), normal x 1.2, VU0 R seeded from CGtRandom; per spark: RandomInterpolate(VelB..VelA) x scalar 0.25..0.5 + box RandomiseXYZ, pushed out of the surface when dot < 0, position +-0.25, SpawnBouncySpark with the crash flag while more than the regular count remain; then func_0025D430 (popcorn, type 0, 0.6 x count); 322/311, calls identical, VU/FPU op counts equal, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; register list from the caller func_0025BBC0's archive and Revenge's SpawnSparksFromPoint; the crash-count arm (bnez), the 2500 test (c.le/bc1t), the dot test (c.lt/bc1t), the bnez loop count, the slt flag on the decremented counter, each randomiser's pair (0x1D0/0x1E0, 0x1F0/0x200, 0x210/0x220, scalar 0x1C0 lanes folded to 0 / 0.25) and the tail call's ten arguments traced; audit: only the D_01D9D190 / gEffectsRandomiserScales spelling of the same state

// func_0025DF30 -- draftAN (C-first draft). 0x25DF30, 0x4DC. [L] identity: CB3EffectsManager::SpawnSparksFromPoint (E map
// B3O0PCH 0x26FDD0, "CB3EffectsManager::SpawnSparksFromPoint(CGtV3d,CGtV3d,CGtV3d,CGtV3d,float,float,bool)" in B3EffectsManager.cpp) and
// Revenge STABS SpawnSparksFromPoint__17CB4EffectsManager (this, lPos, lVelocityA, lVelocityB, lNormal, lrNumSparks,
// lrHeightAboveGround, lbIsCrashRelated): retail's list a0 this, a1..t0 by address, t1 the flag, f12/f13. The link name stays the
// placeholder; declared as the caller's archive does (func_0025BBC0: floats first, extern "C", same registers). Local names from
// Revenge's stabs block [L]. Its tail calls func_0025D430 ([L] SpawnPopcornFromPoint, draftAN archive) with type 0.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;
// [L] Revenge STABS `struct CScalarRandomiser { // 0x10  CGtV3d mVec; Prepare(); GtXAxisTypePS2 RandomInterpolate(); }` (types.h:41681),
// a local lVelInheritanceScaleRandomiser in SpawnPopcornFromPoint / SpawnSparksFromPoint. B3 shape [C] 0x25D740..0x25D7AC: only x
// (max - min) and y (min - (max - min)) are set, by lane inserts; the draw is a raw R value r in [1,2) (no state, no 2^23 trick):
// y + x * r, uniform in [min, max). Header gap queued (b3/_unclassified/CV3dRandomiser.h).
struct CScalarRandomiser {
    CGtV3d mVec;
    XAxisType RandomInterpolate();
};
inline XAxisType CScalarRandomiser::RandomInterpolate()
{
    u_long128 r, o;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    asm("vadday.x $ACC, $vf0, %1y" "\n\t" "vmaddx.x %0, %1, %2x" : "=j"(o) : "j"(mVec.mData), "j"(r));
    return XAxisType(o);
}

extern float D_004E19D8;                     // [L] Revenge `static RwReal lrFractionalSpark` (initial 0.9999)

struct UnkStruct_0025DF30_mgr {              // [L] CB3EffectsManager (fields as func_0025D930)
    unsigned char pad_0[0x21F0];
    unsigned char field_21F0[0x1D638];       // [L] a CB3SparkArray (SpawnBouncySpark's this)
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x18];
    float field_1F848;                       // [G] spawn time, as func_0025D930
};
extern "C" float sqrtf(float);
extern "C" void SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(void *, const CGtV3d *, const CGtV3d *, float, float, bool);
extern "C" void func_0025D430(UnkStruct_0025DF30_mgr *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *,
                              int, int, float, float);

// the VU0 random generator seeded (vrinit), as func_0025D930_inl1
static inline void func_0025DF30_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// 0x0025DF30
extern "C" void func_0025DF30(float lrNumSparks, float lrHeightAboveGround, UnkStruct_0025DF30_mgr *self, const CGtV3d *pPos,
                              const CGtV3d *pVelA, const CGtV3d *pVelB, const CGtV3d *pNormal, int lbIsCrashRelated)
{
    CGtV3d lNormal = *pNormal;
    CGtV3d lPos = *pPos;
    CGtV3d lVelocityB = *pVelB;
    CGtV3d lVelocityA = *pVelA;
    float f = D_004E19D8 + lrNumSparks;
    int lnNumRegularSparks = (int)f;
    D_004E19D8 = f - (float)lnNumRegularSparks;
    int lnNumCrashSparks = 0;
    if (lbIsCrashRelated) {
        f = D_004E19D8 + 7.0f * lrNumSparks;
        lnNumCrashSparks = (int)f;
        D_004E19D8 = f - (float)lnNumCrashSparks;
    }
    float lrLengthSq = lVelocityA.GetSquaredLength();
    float lrVelocityRandomness;
    if (lrLengthSq <= (float)2500)          // [C] c.le / bc1t: the int 2500 converted at run time
        lrVelocityRandomness = 0.02f * sqrtf(lrLengthSq);
    else
        lrVelocityRandomness = 1.0f;
    CGtV3d lNormalScaled = lNormal * 1.2f;
    func_0025DF30_inl1(self->field_1F828.RandomReal());
    int lnNumSparks = lnNumRegularSparks + lnNumCrashSparks;
    CGtV3d lBoxMin(-3.0f, 0.5f, -3.0f);
    CGtV3d lBoxMax(3.0f, 13.0f, 3.0f);
    CGtV3d lJitter(0.25f, 0.25f, 0.25f);
    float lrMin = 0.25f, lrMax = 0.5f;      // [C] folded by the compiler: lanes y = 0, x = 0.25
    CScalarRandomiser lVelInheritanceScaleRandomiser;   // [C] z / w never set (stack bytes)
    lVelInheritanceScaleRandomiser.mVec.SetY(lrMin + lrMin - lrMax);
    lVelInheritanceScaleRandomiser.mVec.SetX(lrMax - lrMin);
    CV3dRandomiser lVelInheritanceRandomiser;
    lVelInheritanceRandomiser.mVecA = lVelocityB;
    lVelInheritanceRandomiser.mVecB = lVelocityB - lVelocityA;
    ((float *)&lVelInheritanceRandomiser.mVecB)[3] = ((const float *)&lVelocityA)[3]; // [C] 0x25E1A0 lqc2 vf1, 0x250(sp) (lVelocityA,
    // 0x25DF80 lq a1, 0(a2) / 0x25DF94 sq); 0x25E1A8 vsub.xyz vf1, vf2, vf1 keeps its w; 0x25E1B4 sqc2 vf1 -- `a - b` took lVelocityB's w
    CV3dRandomiser lVelRandomiser;
    lVelRandomiser.mVecA = lBoxMax * lrVelocityRandomness;
    lVelRandomiser.mVecB = lVelRandomiser.mVecA - lBoxMin * lrVelocityRandomness;
    CV3dRandomiser lPosRandomiser;
    lPosRandomiser.mVecA = lPos + lJitter;
    lPosRandomiser.mVecB = lPosRandomiser.mVecA - (lPos - lJitter);
    while (lnNumSparks-- != 0) {            // [C] bnez: a negative count never ends (retail)
        CGtV3d lInherit = lVelInheritanceRandomiser.RandomInterpolate();
        CGtV3d lRandomisedVelocity = lInherit * lVelInheritanceScaleRandomiser.RandomInterpolate();
        lRandomisedVelocity += lVelRandomiser.RandomiseXYZ();
        float d = DotProduct(lNormalScaled, lRandomisedVelocity);
        if (d < 0.0f)                       // [C] c.lt d, 0 / bc1t
            lRandomisedVelocity -= lNormalScaled * d;
        CGtV3d lSpawnPos = lPosRandomiser.RandomiseXYZ();
        // [C] slt a3, s0, s2 with s2 already decremented: the flag is set while more than lnNumRegularSparks sparks remain
        SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(self->field_21F0, &lSpawnPos, &lRandomisedVelocity,
                                                                                 self->field_1F848, lrHeightAboveGround,
                                                                                 lnNumRegularSparks < lnNumSparks);
    }
    func_0025D430(self, &lPos, &lVelocityA, &lVelocityB, 0, &lNormal, 0, lbIsCrashRelated, 0.6f * lrNumSparks, lrHeightAboveGround);
}
