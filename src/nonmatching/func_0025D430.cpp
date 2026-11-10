// NONMATCHING: func_0025D430 -- retail 319 / ours 305 instructions, 246 in changed runs
// draftAN C-first: [L] CB3EffectsManager::SpawnPopcornFromPoint (E map 0x2708A0, Revenge STABS shape): fractional count carry D_004E19E0, spawn params D_004BC5F0[type] (popcorn array index, box), inheritance-scale range 0.95..1 for type 2 else 0.25..0.5, normal x 1.2, |lpVelocityC| for type 3 else |VelocityA| x 0.05 scales the box, VU0 R seeded from CGtRandom; per popcorn: RandomInterpolate(VelB..VelA) x scalar draw + box RandomiseXYZ, pushed out of the surface when dot(n, v) < 0, position = pos +- 0.25, one dead R advance, SpawnBouncyPopcorn; 330/319, calls identical, VU/FPU op counts equal, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; register list from the callers (UpdateTrafficWorldCollisionEffects, DoVehicleGlass) and Revenge's SpawnPopcornFromPoint; the table stride/fields, the type 2/3 tests (bne), the dot test sense (c.lt/bc1t), each randomiser's (max, max - min) pair (0x1E0/0x1F0, 0x200/0x210, 0x1C0/0x1D0, the scalar lanes at 0x1B0), draw order and the dead vrnext at 0x25D8D4 traced; audit: only the D_01D9D190 / gEffectsRandomiserScales spelling of the same state

// func_0025D430 -- draftAN (C-first draft). 0x25D430, 0x4FC. [L] identity: CB3EffectsManager::SpawnPopcornFromPoint (E map
// B3O0PCH 0x2708A0, "CB3EffectsManager::SpawnPopcornFromPoint(CGtV3d,CGtV3d,CGtV3d,CGtV3d*,CG..." in B3EffectsManager.cpp) and Revenge
// STABS SpawnPopcornFromPoint__17CB4EffectsManager (this, lPos, lVelocityA, lVelocityB, CGtV3d *lpVelocityC, lNormal, leSpawnType,
// lrNumSparks, lrHeightAboveGround, lbIsCrashRelated): the same register list as retail (a1..a3 by address, t0 the pointer, t1 the
// normal, t2 the type, t3 the bool, f12/f13). The link name stays the placeholder (retail's own tables do not name it). Local names
// from Revenge's stabs block [L]. Callers' archives: UpdateTrafficWorldCollisionEffects, DoVehicleGlass (same 10-argument list).
// The random draws keep retail's VU0 R sequence (CV3dRandomiser.h; the scalar draw is Revenge's CScalarRandomiser, below).
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

struct UnkStruct_0025D430_params {           // [L] CB4PopcornSpawnParams (Revenge lpSpawnParams); D_004BC5F0[4], 12 bytes each
    int field_0;                             // [C] the popcorn array index (x 0x40 from this + 0x20F0)
    float field_4;                           // [C] velocity box half-width in x and z
    float field_8;                           // [C] velocity box height (added to 0.25)
};
extern UnkStruct_0025D430_params D_004BC5F0[];   // [C] {0, 8, 8}, {1, 16, 18}, {2, 3, 20}, {3, 8, 20}
extern float D_004E19E0;                     // [L] Revenge `static RwReal lrFractionalSpark` (initial 0.9999)

struct UnkStruct_0025D430_mgr {              // [L] CB3EffectsManager (fields as func_0025D930)
    unsigned char pad_0[0x20F0];
    unsigned char field_20F0[4][0x40];       // [L] CB3PopcornArray x4 (SpawnBouncyPopcorn's this)
    unsigned char pad_21F0[0x1D638];
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x18];
    float field_1F848;                       // [G] spawn time (Revenge lrSpawnTime), as func_0025D930
};
extern "C" void SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff(void *, const CGtV3d *, const CGtV3d *, float, float);

// the VU0 random generator seeded (vrinit), as func_0025D930_inl1
static inline void func_0025D430_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}
// [C] 0x25D8D4 (jal delay slot): `vrnext.x $vf0, $R`, an R advance whose result nothing reads (a draw whose value the source
// dropped). Kept: it changes every later random value.
static inline void func_0025D430_inl2()
{
    asm volatile("vrnext.x $vf0, $R");
}

// 0x0025D430
extern "C" void func_0025D430(UnkStruct_0025D430_mgr *self, const CGtV3d *pPos, const CGtV3d *pVelA, const CGtV3d *pVelB,
                              const CGtV3d *lpVelocityC, const CGtV3d *pNormal, int leSpawnType, int lbIsCrashRelated,
                              float lrNumSparks, float lrHeightAboveGround)
{
    // lbIsCrashRelated: [C] never read (t3 is overwritten at 0x25D5A8 before any use)
    CGtV3d lPos = *pPos;
    CGtV3d lVelocityA = *pVelA;
    CGtV3d lVelocityB = *pVelB;
    CGtV3d lNormal = *pNormal;
    float f = D_004E19E0 + lrNumSparks;
    int lnNumSparks = (int)f;
    D_004E19E0 = f - (float)lnNumSparks;
    UnkStruct_0025D430_params *lpSpawnParams = &D_004BC5F0[leSpawnType];
    void *lpArray = self->field_20F0[lpSpawnParams->field_0];
    float lrMax, lrMin;                     // Revenge lrSparksVelocityInheritanceMax / Min
    if (leSpawnType == 2) {
        lrMax = 1.0f;
        lrMin = 0.95f;
    } else {
        lrMin = 0.25f;
        lrMax = 0.5f;
    }
    CGtV3d lNormalScaled = lNormal * 1.2f;
    float lrLength;
    if (leSpawnType == 3)
        lrLength = lpVelocityC->GetLength();
    else
        lrLength = lVelocityA.GetLength();
    func_0025D430_inl1(self->field_1F828.RandomReal());
    float lrVelScale = 0.05f * lrLength;
    CGtV3d lJitter(0.25f, 0.25f, 0.25f);
    CV3dRandomiser lPosRandomiser;
    lPosRandomiser.mVecA = lPos + lJitter;
    lPosRandomiser.mVecB = lPosRandomiser.mVecA - (lPos - lJitter);
    CGtV3d lBoxMin(-lpSpawnParams->field_4, 0.25f, -lpSpawnParams->field_4);
    CGtV3d lBoxMax(lpSpawnParams->field_4, 0.25f + lpSpawnParams->field_8, lpSpawnParams->field_4);
    CV3dRandomiser lVelRandomiser;
    lVelRandomiser.mVecA = lBoxMax * lrVelScale;
    lVelRandomiser.mVecB = lVelRandomiser.mVecA - lBoxMin * lrVelScale;
    CV3dRandomiser lVelInheritanceRandomiser;
    lVelInheritanceRandomiser.mVecA = lVelocityB;
    lVelInheritanceRandomiser.mVecB = lVelocityB - lVelocityA;
    ((float *)&lVelInheritanceRandomiser.mVecB)[3] = ((const float *)&lVelocityA)[3]; // [C] 0x25D724 lqc2 vf1, 0x240(sp) (lVelocityA,
    // 0x25D494); 0x25D72C vsub.xyz vf1, vf2, vf1 keeps its w; 0x25D730 sqc2 vf1 -- `a - b` took lVelocityB's w
    CScalarRandomiser lVelInheritanceScaleRandomiser;   // [C] z / w never set (stack bytes)
    lVelInheritanceScaleRandomiser.mVec.SetY(lrMin + lrMin - lrMax);
    lVelInheritanceScaleRandomiser.mVec.SetX(lrMax - lrMin);
    while (lnNumSparks-- > 0) {
        CGtV3d lInherit = lVelInheritanceRandomiser.RandomInterpolate();
        CGtV3d lRandomisedVelocity = lInherit * lVelInheritanceScaleRandomiser.RandomInterpolate();
        lRandomisedVelocity += lVelRandomiser.RandomiseXYZ();
        float d = DotProduct(lNormalScaled, lRandomisedVelocity);
        if (d < 0.0f)                       // [C] c.lt d, 0 / bc1t: push the velocity out of the surface
            lRandomisedVelocity -= lNormalScaled * d;
        CGtV3d lSpawnPos = lPosRandomiser.RandomiseXYZ();
        func_0025D430_inl2();
        SpawnBouncyPopcorn__15CB3PopcornArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dff(lpArray, &lSpawnPos, &lRandomisedVelocity,
                                                                                     self->field_1F848, lrHeightAboveGround);
    }
}
