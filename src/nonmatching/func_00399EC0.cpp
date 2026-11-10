// NONMATCHING: func_00399EC0 -- retail 293 / ours 284 instructions, 311 in changed runs
// draftAN C-first: [L] CB3ExplosionManager::DoAirRamExplosion (E map 0x3F3AD0, Revenge STABS + CB4AirRamFlashParams, same 0x48 layout as D_004A51C0): VU0 R seeded from mRandom; for the one params entry: count particles, each a normalised random direction from the (-0.5,0.005,-0.5)..(0.5,0.5,0.5) box, offset = direction x radius (one-t interpolate between min and max radius, y scaled), velocity = box (+-XZ randomness, YMin..YMax) + offset x inwards scale + lDirection x directional speed + lSourceVelocity x inheritance, func_00254A90 (array, pos + offset, vel, true, crash bank, time + variation, ambient, directional, 1, 1, angular velocity); 306/293, calls identical, FPU/VU op counts equal (1 vmove), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; register list from func_0025AC30's archive and Revenge's DoAirRamExplosion; the params fields (layout identical to Revenge's), each randomiser's pair (0x360/0x370, 0x340/0x350 one-t, 0x320/0x330, four-lane 0x300/0x310), the rsqrt normalise, the lane-to-argument map (f12 w, f17 z, t0 the byte at +0x44) and the do-while count (no entry test) traced; behaviour_audit quiet

// func_00399EC0 -- draftAN (C-first draft). 0x399EC0, 0x494. [L] identity: CB3ExplosionManager::DoAirRamExplosion(CGtV3d, CGtV3d,
// CGtV3d) (E map B3O0PCH 0x3F3AD0, 0x4A0) and Revenge STABS DoAirRamExplosion__19CB4ExplosionManager (this, lPos, lDirection,
// lSourceVelocity): retail a0 this (the caller func_0025AC30 passes D_01EA4BB0), a1..a3 the vectors by address. The link name stays
// the placeholder; declared as the caller's archive does. Local / field names from Revenge's stabs block and CB4AirRamFlashParams
// (types.h:41951, the same 0x48 layout as B3's D_004A51C0) [L].
// The random draws keep retail's VU0 R sequence: CV3dRandomiser (b3/_unclassified/CV3dRandomiser.h, this file's state = retail
// D_01EA4BA0 / D_004C9A00) and Revenge's CV4dRandomiser (local stand-in, as func_0039AD90; header gap queued).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

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

struct CB3AirRamFlashParams_unk {          // [L] Revenge CB4AirRamFlashParams (0x48); B3 D_004A51C0[1] [C] stride 0x48
    int meArrayID;                          // [C] particle array index (D_01D9D200 + 0x170 + i * 0x150)
    int mnNumParticles;
    float mrMinRadius;
    float mrMaxRadius;
    float mrRadiusYScale;
    float mrVelocityXZRandomness;
    float mrVelocityYMin;
    float mrVelocityYMax;
    float mrVelocityMinInheritance;
    float mrVelocityMaxInheritance;
    float mrInwardsVelocityXZScale;
    float mrMinDirectionalVelocity;
    float mrMaxDirectionalVelocity;
    float mrMaxAngularVelocity;
    float mrTimeVariation;
    float mrAmbient;
    float mrDirectional;
    bool mbCrashBank;
};
extern CB3AirRamFlashParams_unk D_004A51C0[1];   // [L] Revenge `static CB4AirRamFlashParams kaParams[1]`
extern unsigned char D_01D9D200[];          // the effects manager instance [G] (particle arrays at +0x170, time at +0x1F848), as func_0039A360
class CB3ExplosionManager {
public:
    unsigned char pad_0[0xF0];
    CGtRandom field_F0;                     // [L] Revenge mRandom (0xF0)
};
extern "C" int func_00254A90(void *, CGtV3d *, CGtV3d *, bool, bool, float, float, float, float, float, float);

// the VU0 random generator seeded (vrinit), as func_0039A360_inl1
static inline void func_00399EC0_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// 0x00399EC0
extern "C" void func_00399EC0(CB3ExplosionManager *self, const CGtV3d *pPos, const CGtV3d *pDirection, const CGtV3d *pSourceVelocity)
{
    CGtV3d lPos = *pPos;
    CGtV3d lDirection = *pDirection;
    CGtV3d lSourceVelocity = *pSourceVelocity;
    float lrCurrentTime = *(float *)(D_01D9D200 + 0x1F848);
    func_00399EC0_inl1(self->field_F0.RandomReal());
    for (int i = 0; i < 1; i++) {
        CB3AirRamFlashParams_unk *lpParams = &D_004A51C0[i];
        unsigned char *lpArray = D_01D9D200 + lpParams->meArrayID * 0x150 + 0x170;   // [L] CB3ParticleArray
        int lnNumParticles = lpParams->mnNumParticles;
        CV3dRandomiser lPosRandomiser;      // [G] a direction in the upper half box
        lPosRandomiser.mVecA = CGtV3d(0.5f, 0.5f, 0.5f);
        lPosRandomiser.mVecB = lPosRandomiser.mVecA - CGtV3d(-0.5f, 0.005f, -0.5f);
        CV3dRandomiser lPosScaleRandomiser;
        lPosScaleRandomiser.mVecA = CGtV3d(lpParams->mrMaxRadius, lpParams->mrMaxRadius * lpParams->mrRadiusYScale, lpParams->mrMaxRadius);
        lPosScaleRandomiser.mVecB = lPosScaleRandomiser.mVecA -
                                    CGtV3d(lpParams->mrMinRadius, lpParams->mrMinRadius * lpParams->mrRadiusYScale, lpParams->mrMinRadius);
        CV3dRandomiser lVelRandomiser;
        lVelRandomiser.mVecA = CGtV3d(lpParams->mrVelocityXZRandomness, lpParams->mrVelocityYMax, lpParams->mrVelocityXZRandomness);
        lVelRandomiser.mVecB = lVelRandomiser.mVecA - CGtV3d(-lpParams->mrVelocityXZRandomness, lpParams->mrVelocityYMin,
                                                             -lpParams->mrVelocityXZRandomness);
        // lanes: x directional velocity, y inheritance, z angular velocity, w spawn time
        CGtV4d lMin(lpParams->mrMinDirectionalVelocity, lpParams->mrVelocityMinInheritance, -lpParams->mrMaxAngularVelocity, lrCurrentTime);
        CGtV4d lMax(lpParams->mrMaxDirectionalVelocity, lpParams->mrVelocityMaxInheritance, lpParams->mrMaxAngularVelocity,
                    lrCurrentTime + lpParams->mrTimeVariation);
        CV4dRandomiser lParamsRandomiser;
        lParamsRandomiser.mVecA = lMin + lMin - lMax;
        lParamsRandomiser.mVecB = lMax - lMin;
        do {                                // [C] no entry test: the count is read from the table (addiu -1 / bnez at the bottom)
            CGtV4d lParams = lParamsRandomiser.RandomiseXYZW();
            CGtV3d lDir = lPosRandomiser.RandomiseXYZ();
            lDir.Normalise();
            CGtV3d lOffset = lDir * lPosScaleRandomiser.RandomInterpolate();
            CGtV3d lVel = lVelRandomiser.RandomiseXYZ();
            lVel = lVel + lOffset * lpParams->mrInwardsVelocityXZScale;
            CGtV3d lSpawnPos = lOffset;
            lSpawnPos += lPos; // [C] w = lOffset.w: 0x39A2A4 qmtc2 t0, vf5 (lOffset); 0x39A2E0 vadd.xyz vf5, vf5, vf4 (vf4 = lPos, 0x39A2CC);
            // 0x39A2F0 sqc2 vf5, 0x2F0(sp) -- `a + b` took lPos's w
            lVel = lVel + lDirection * lParams.X();
            lVel = lVel + lSourceVelocity * lParams.Y();
            func_00254A90(lpArray, &lSpawnPos, &lVel, true, lpParams->mbCrashBank, (float)lParams.W(), lpParams->mrAmbient,
                          lpParams->mrDirectional, 1.0f, 1.0f, (float)lParams.Z());
        } while (--lnNumParticles != 0);
    }
}
