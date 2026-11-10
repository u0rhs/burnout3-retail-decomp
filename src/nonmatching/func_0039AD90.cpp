// NONMATCHING: func_0039AD90 -- retail 304 / ours 308 instructions, 264 in changed runs
// draftAN C-first: [L] CB3ExplosionManager::UpdateFire (E map 0x3F28E0, Revenge STABS UpdateFire + CFireElementParams): quantity = timestep x quantity x (0.8 + 0.4 RandomReal), VU0 R seeded from mRandom; for the 3 fire elements D_004A4FE0: count from the accumulator D_01EA4CB0[i] + pps x quantity x array+0x134, position box (+-radius, minY..maxY), velocity box (+-randomness, YMin..YMax) + offset x (XZScale, 0, XZScale), angular velocity +-max (scalar draw), (size, alpha, ambient, directional) between min and (1, 1, max, max) (four-lane draw); func_00254A90 (array, pos, vel, true, true, time, ambient, directional, size, alpha, angvel); 330/304, calls identical, FPU/VU op counts equal, non-stack stores identical but the state store per draw (retail merges the two into one)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; register list from DoVehicleFire's archive and Revenge's UpdateFire (f13 unread [C]); the params table stride/fields, the accumulator update, each randomiser's pair (0x280/0x290, 0x260/0x270, scalar 0x230, four-lane 0x240/0x250 = 2min-max / max-min), the draw order, the spawn's lane-to-register map (f13 z, f14 w, f15 x, f16 y, f17 angvel) and the bnez / slti 3 loops traced; behaviour_audit quiet

// func_0039AD90 -- draftAN (C-first draft). 0x39AD90, 0x4C0. [L] identity: CB3ExplosionManager::UpdateFire(CGtV3d, float, float,
// float) (E map B3O0PCH 0x3F28E0, 0x4C4) and Revenge STABS UpdateFire__19CB4ExplosionManager (this, lPos, lrQuantity, lrAlpha,
// lrTimestep): retail a0 this (the caller DoVehicleFire passes &D_01EA4BB0), a1 the position by address, f12 / f13 / f14. The link
// name stays the placeholder (retail's own tables do not name it); declared as the caller's archive does. Local and field names from
// Revenge's stabs block / CFireElementParams [L]. lrAlpha (f13) is never read [C].
// The random draws keep retail's VU0 R sequence: CV3dRandomiser (b3/_unclassified/CV3dRandomiser.h, this file's state =
// retail D_01EA4BA0 / D_004C9A00), plus Revenge's CScalarRandomiser and CV4dRandomiser (raw R draws in [1,2), no state), local
// stand-ins below (header gap queued).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

// [L] Revenge STABS CScalarRandomiser (types.h:41681): mVec x = max - min, y = 2 min - max; y + x * r, r a raw R draw in [1,2)
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
// [L] Revenge STABS `struct CV4dRandomiser { // 0x20  CGtV4d mVecA; CGtV4d mVecB; Prepare(); CGtV4d RandomiseXYZW(); }`
// (types.h:41691). B3 shape [C] 0x39B140..0x39B174: mVecA = 2 min - max, mVecB = max - min, four raw R draws (one per lane),
// `vaddax.xyzw ACC, A, vf0x; vmadd.xyzw d, B, r`: uniform in [min, max) per lane.
struct CV4dRandomiser {
    CGtV4d mVecA;
    CGtV4d mVecB;
    CGtV4d RandomiseXYZW();
};
inline CGtV4d CV4dRandomiser::RandomiseXYZW()
{
    u_long128 r, o;
    asm volatile("vrnext.x %0, $R" : "=j"(r));
    asm volatile("vrnext.y %0, $R" : "+j"(r));
    asm volatile("vrnext.z %0, $R" : "+j"(r));
    asm volatile("vrnext.w %0, $R" : "+j"(r));
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "vmadd.xyzw %0, %2, %3" : "=j"(o) : "j"(mVecA.mData), "j"(mVecB.mData), "j"(r));
    return CGtV4d(o);
}

struct CFireElementParams {                 // [L] Revenge STABS (types.h:41915, 0x40); D_004A4FE0[3] [C] stride 0x40
    int meParticleArray;                    // [C] the particle array index (D_01D9D200 + 0x170 + i * 0x150)
    float mrParticlesPerSec;
    float mrSpawnRadiusXZ;
    float mrSpawnPosMinY;
    float mrSpawnPosMaxY;
    float mrSpawnVelocityXZScale;
    float mrSpawnVelocityXZRandomness;
    float mrSpawnVelocityYMin;
    float mrSpawnVelocityYMax;
    float mrAngularVelocityMax;
    float mrSizeScaleMin;
    float mrAlphaMin;
    float mrAmbientMin;
    float mrAmbientMax;
    float mrDirectionalMin;
    float mrDirectionalMax;
};
extern CFireElementParams D_004A4FE0[3];    // [L] Revenge `static CFireElementParams laFireElementParams[4]` (B3: 3 used)
extern float D_01EA4CB0[];                  // [L] Revenge `static float larAccumulators[4]`
extern unsigned char D_01D9D200[];          // the effects manager instance [G] (particle arrays at +0x170, time at +0x1F848), as func_0039A360
class CB3ExplosionManager {
public:
    unsigned char pad_0[0xF0];
    CGtRandom field_F0;                     // [L] Revenge mRandom (0xF0)
};
extern "C" int func_00254A90(void *, CGtV3d *, CGtV3d *, bool, bool, float, float, float, float, float, float);

// the VU0 random generator seeded (vrinit), as func_0039A360_inl1
static inline void func_0039AD90_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}
// [G] an inline a + d * t (retail's unfolded `0 + a` through adda.s: an inline's parameter)
static inline float func_0039AD90_inl2(float a, float d, float t) { return a + d * t; }

// 0x0039AD90
extern "C" void func_0039AD90(CB3ExplosionManager *self, const CGtV3d *pPos, float lrQuantity, float lrAlpha, float lrTimestep)
{
    CGtV3d lPos = *pPos;
    float lrCurrentTime = *(float *)(D_01D9D200 + 0x1F848);
    float lrRand = self->field_F0.RandomReal();
    float lrTimesteppedQuantity = lrTimestep * lrQuantity;
    lrTimesteppedQuantity *= 0.8f + 0.4f * lrRand;
    func_0039AD90_inl1(self->field_F0.RandomReal());
    float lrZero = 0.0f, lrOne = 1.0f;
    CGtV3d lVelScale;                       // [C] w keeps the slot's previous bytes
    CScalarRandomiser lAngVelRandomiser;    // [C] z / w keep the slot's previous bytes
    for (int lnElement = 0; lnElement < 3; lnElement++) {
        CFireElementParams *lpParams = &D_004A4FE0[lnElement];
        unsigned char *lpArray = D_01D9D200 + lpParams->meParticleArray * 0x150 + 0x170;   // [L] CB3ParticleArray
        float lrNumParticles = func_0039AD90_inl2(D_01EA4CB0[lnElement],
                                                  lpParams->mrParticlesPerSec * lrTimesteppedQuantity, *(float *)(lpArray + 0x134));
        int lnNumParticles = (int)lrNumParticles;
        D_01EA4CB0[lnElement] = lrNumParticles - (float)lnNumParticles;
        CV3dRandomiser lPosRandomiser;
        lPosRandomiser.mVecA = CGtV3d(lpParams->mrSpawnRadiusXZ, lpParams->mrSpawnPosMaxY, lpParams->mrSpawnRadiusXZ);
        lPosRandomiser.mVecB = lPosRandomiser.mVecA - CGtV3d(-lpParams->mrSpawnRadiusXZ, lpParams->mrSpawnPosMinY, -lpParams->mrSpawnRadiusXZ);
        lVelScale.SetX(lpParams->mrSpawnVelocityXZScale);
        lVelScale.SetY(lrZero);
        lVelScale.SetZ(lpParams->mrSpawnVelocityXZScale);
        float lrMin = -lpParams->mrAngularVelocityMax, lrMax = lpParams->mrAngularVelocityMax;
        lAngVelRandomiser.mVec.SetY(lrMin + lrMin - lrMax);
        lAngVelRandomiser.mVec.SetX(lrMax - lrMin);
        CV3dRandomiser lVelRandomiser;
        lVelRandomiser.mVecA = CGtV3d(lpParams->mrSpawnVelocityXZRandomness, lpParams->mrSpawnVelocityYMax, lpParams->mrSpawnVelocityXZRandomness);
        lVelRandomiser.mVecB = lVelRandomiser.mVecA - CGtV3d(-lpParams->mrSpawnVelocityXZRandomness, lpParams->mrSpawnVelocityYMin,
                                                             -lpParams->mrSpawnVelocityXZRandomness);
        CGtV4d lMin(lpParams->mrSizeScaleMin, lpParams->mrAlphaMin, lpParams->mrAmbientMin, lpParams->mrDirectionalMin);
        CGtV4d lMax(lrOne, lrOne, lpParams->mrAmbientMax, lpParams->mrDirectionalMax);
        CV4dRandomiser lParamsRandomiser;
        lParamsRandomiser.mVecA = lMin + lMin - lMax;
        lParamsRandomiser.mVecB = lMax - lMin;
        while (lnNumParticles-- != 0) {      // [C] bnez
            CGtV3d lOffset = lPosRandomiser.RandomiseXYZ();
            CGtV3d lVel = lVelRandomiser.RandomiseXYZ();
            CGtV3d lSpawnPos = lOffset;
            lSpawnPos += lPos; // [C] w = lOffset.w: 0x39B14C qmtc2 a0, vf2 (lOffset); 0x39B158 vadd.xyz vf2, vf2, vf4 (vf4 = lPos, 0x39B150);
            // 0x39B15C sqc2 vf2, 0x220(sp) -- `a + b` took lPos's w
            lVel += lOffset * lVelScale; // [C] w = lVel.w: 0x39B160 qmtc2 v1, vf4; 0x39B168 vadd.xyz vf4, vf4, vf1; 0x39B170 sqc2 vf4, 0x210(sp)
            float lrAngVel = lAngVelRandomiser.RandomInterpolate();
            CGtV4d lParams = lParamsRandomiser.RandomiseXYZW();
            func_00254A90(lpArray, &lSpawnPos, &lVel, true, true, lrCurrentTime, (float)lParams.Z(), (float)lParams.W(),
                          (float)lParams.X(), (float)lParams.Y(), lrAngVel);
        }
    }
}
