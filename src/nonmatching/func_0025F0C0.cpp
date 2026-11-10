// NONMATCHING: func_0025F0C0 -- retail 545 / ours 578 instructions, 702 in changed runs
// draftAO (2026-11-01): complete: [L] CB3EffectsManager::SpawnParticlesAlongLine (DNAT map, Revenge register list = the matched caller's prototype); written from retail: count = ppm x length x rate x (0.875 + 0.25 RandomReal), regular / crash split (crash ratios x array +0x108 / +0x134, the u8 accumulator /256 and x255.99 back), == 0 exit, pminw 8 caps, inheritance vel x C x 0.5 (half of it shifts the velocity box and scales by params.z), upward thrust (0, C1C x length x +0x1F850, 0) x params.w, CV3dRandomisers params (alpha / angular / size), pos (+-posRand), velocity, CV4dRandomiser ambient/directional (krAmbient.. statics), alpha <= 0.01 skip, the crash pass then the regular pass, spawn times spread over +0x1F84C, a full array ends the pass; 578/545, calls identical, every VU and FPU arithmetic op count equal | Before: fix2 (2026-11-01): gp-relative globals were named 0x7990 high (D_004E8xxx/9xxx for retail's D_004E0xxx/1xxx; same error as the son-series drafts func_0025BBC0/HandleRaceCarTraffic) [C] retail %gp_rel operands | Before: son9 first archive (545/333 instrs, 610 changed): skeleton only. Decoded: signature (3 floats, mgr, 3 vec ptrs, type, uv, byte accumulator, p11, pass flag), fx table D_004BC040 stri
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x25F0C0..0x25F940: every R draw (params, then V4 / pos / velocity only when alpha passes), randomiser pair (0x500/0x510, 0x520/0x530, 0x540/0x550, 0x4E0/0x4F0), lane, branch sense (two NaN-safe c.le tests), store (accumulator byte, the stack crash flag cleared for pass 2) and call argument traced; unset w lanes kept (xyz-only users)

// func_0025F0C0 -- [L] CB3EffectsManager::SpawnParticlesAlongLine(CGtV3d lStartPos, CGtV3d lEndPos, CGtV3d lVelocity,
// EParticleSpawnType, float lrLength, float lrSpawnRateScalar, const CLighting &, float lrAlpha, unsigned char *lpu8Accumulator,
// bool lbDestroyOldParticles, bool lbIsCrashRelated): the E maps list it in B3EffectsManager.cpp (DNAT 0x220B50, 0xFC4, the largest
// spawner, as here), and Revenge's SpawnParticlesAlongLine__17CB4EffectsManager has this register list (a1..a3 the vectors, t0 type,
// f12 length, f13 rate, t1 lighting, f14 alpha, t2 accumulator, t3 destroy-old, stack crash flag) [C retail 0x25F0C0..0x25F148 and
// the matched caller B3EffectsManager_00257C70.cpp]. Label kept (no B3 symbol). Locals named after Revenge's STABS locals [L]
// (research/stabs/revenge_jul14_functions.cpp, SpawnParticlesAlongLine__17CB4EffectsManager).
// draftAO fork B (2026-11-01): complete; was a skeleton with scalar stand-ins for every VU0 random.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

class CB3EffectsManager {
public:
    class CLighting {                          // [C] name (mangled B3 symbols); [L] fields Revenge STABS (types.h:33095)
    public:
        float mrAmbient;
        float mrDirectional;
    };
    unsigned char pad_0[0x170];
    unsigned char field_170[1][0x150];         // [C] particle arrays, stride 0x150 (meArray * 0x150 + 0x170)
    unsigned char pad_2C0[0x1F828 - 0x2C0];
    CGtRandom field_1F828;                     // [C] the manager's CGtRandom
    unsigned char pad_1F830[0x18];
    float field_1F848;                         // [G] the current time
    float field_1F84C;                         // [G] the frame time step (the spawn times spread over it)
    float field_1F850;                         // [G] an upward-thrust scale (times the line length)
};
struct UnkStruct_D_004BC040 {                  // [L] _gaSpawnParams (DNAT .rodata 0x5B0 = 26 x 0x38); fields Revenge CB4ParticleSpawnParams
    int field_0;                               // meArray
    float field_4;                             // mrParticlesPerMetre
    float field_8;                             // mrPosRandomness
    float field_C;                             // mrVelocityInheritance
    float field_10;                            // mrVelocityXZRandomness
    float field_14;                            // mrVelocityYRandomness
    float field_18;                            // mrAngularVelocityRandomness
    float field_1C;                            // mrUpwardsThrust
    float field_20[2];                         // mSizeScaleMinMax
    float field_28[2];                         // mAlphaScaleMinMax
    float field_30;                            // mrCrashRatioRegular
    float field_34;                            // mrCrashRatioCrash
};
extern UnkStruct_D_004BC040 D_004BC040[];
extern float D_004E19C8, D_004E19CC, D_004E19D0, D_004E19D4;   // [L] krAmbient$37268, krAmbientRandom$37269, krDirectional$37270,
                                                              // krDirectionalRandom$37271 (DNAT .sdata order; 0.9, 0.1, 0.75, 0.5)
extern float D_004E1170;                       // [G] the alpha below which a particle is not spawned (0.01)
// [L] CB3ParticleArray::SpawnParticle (archive func_00254A90: pos, vel, destroy-old, crash, then time, ambient, directional,
// size, alpha, angular velocity); returns 0 when it could not spawn
extern "C" int func_00254A90(void *, const CGtV3d *, const CGtV3d *, bool, bool, float, float, float, float, float, float);

// [L] Revenge STABS CV4dRandomiser: local copy of func_0039AD90's (header gap queued by draftAN)
struct CV4dRandomiser {
    CGtV4d mVecA;                              // 2 min - max
    CGtV4d mVecB;                              // max - min
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
// the VU0 random generator seeded (vrinit), as func_0025D930_inl1
static inline void func_0025F0C0_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// 0x0025F0C0
extern "C" void func_0025F0C0(CB3EffectsManager *self, CGtV3d lStartPos, CGtV3d lEndPos, CGtV3d lVelocity, int leSpawnType,
                              const CB3EffectsManager::CLighting &lLighting, unsigned char *lpu8Accumulator, bool lbDestroyOldParticles,
                              float lrLength, float lrSpawnRateScalar, float lrAlpha, bool lbIsCrashRelated)
{
    UnkStruct_D_004BC040 *lpSpawnParams = &D_004BC040[leSpawnType];
    unsigned char *lpParticleArray = self->field_170[lpSpawnParams->field_0];
    float lrFractionalPart = (float)(unsigned int)*lpu8Accumulator * (1.0f / 256.0f);
    float lrNumParticles = lpSpawnParams->field_4 * (lrLength * lrSpawnRateScalar) * (0.875f + 0.25f * self->field_1F828.RandomReal());
    int lnNumParticlesRegular, lnNumParticlesCrash;
    if (lbIsCrashRelated) {
        float lrNumParticlesRegular = lrNumParticles * lpSpawnParams->field_30 * *(float *)(lpParticleArray + 0x108);
        float lrNumParticlesCrash = lrNumParticles * lpSpawnParams->field_34 * *(float *)(lpParticleArray + 0x134);
        lrNumParticlesRegular += lrFractionalPart;   // [C] mul.s then add.s (not fused)
        lnNumParticlesRegular = (int)lrNumParticlesRegular;
        lrNumParticlesCrash = lrNumParticlesCrash + (lrNumParticlesRegular - (float)lnNumParticlesRegular);
        lnNumParticlesCrash = (int)lrNumParticlesCrash;
        lrFractionalPart = lrNumParticlesCrash - (float)lnNumParticlesCrash;
    } else {
        lnNumParticlesCrash = 0;
        float lrNumParticlesRegular = lrNumParticles * *(float *)(lpParticleArray + 0x108);
        lrNumParticlesRegular += lrFractionalPart;
        lnNumParticlesRegular = (int)lrNumParticlesRegular;
        lrFractionalPart = lrNumParticlesRegular - (float)lnNumParticlesRegular;
    }
    *lpu8Accumulator = (int)(255.99f * lrFractionalPart);   // [C] D_004E12CC = 0x437FFD71
    if (lnNumParticlesRegular + lnNumParticlesCrash == 0)    // [C] beqz (not <= 0)
        return;
    lnNumParticlesRegular = GtMath::Min(lnNumParticlesRegular, 8);   // [C] pminw + pextlw
    lnNumParticlesCrash = GtMath::Min(lnNumParticlesCrash, 8);
    // [C] 0x25F330..0x25F5C0: the velocity inheritance, the upward thrust and the four randomisers
    CGtV3d lInherited = lVelocity * lpSpawnParams->field_C * 0.5f;
    CGtV3d lUp;
    lUp.Zero();
    lUp.SetY(lpSpawnParams->field_1C * (lrLength * self->field_1F850));
    func_0025F0C0_inl1(self->field_1F828.RandomReal());
    CGtV3d lHalfInherited = lInherited * 0.5f;
    CV3dRandomiser lParamsRandomiser;          // [C] w lanes of the stack quads never written (xyz-only users)
    CGtV3d lParamsMax(lrAlpha * lpSpawnParams->field_28[1], lpSpawnParams->field_18, lpSpawnParams->field_20[1]);
    CGtV3d lParamsMin(lrAlpha * lpSpawnParams->field_28[0], -lpSpawnParams->field_18, lpSpawnParams->field_20[0]);
    lParamsRandomiser.mVecA = lParamsMax;
    lParamsRandomiser.mVecB = lParamsMax - lParamsMin;
    CGtV3d lVelMax(lpSpawnParams->field_10, lpSpawnParams->field_14, lpSpawnParams->field_10);
    CGtV3d lVelMin(-lpSpawnParams->field_10, 0.0f, -lpSpawnParams->field_10);
    CV3dRandomiser lVelRandomiser;
    lVelRandomiser.mVecA = lVelMax + lHalfInherited;
    lVelRandomiser.mVecB = lVelRandomiser.mVecA - (lVelMin + lHalfInherited);
    CGtV3d lPosMax(lpSpawnParams->field_8, lpSpawnParams->field_8, lpSpawnParams->field_8);
    CV3dRandomiser lPosRandomiser;
    lPosRandomiser.mVecA = lPosMax;
    lPosRandomiser.mVecB = lPosMax - (-lPosMax);
    float lrAmbMin = lLighting.mrAmbient * D_004E19C8;
    CGtV4d lMin(lrAmbMin, lLighting.mrDirectional * D_004E19D0, 0.0f, 0.0f);
    CGtV4d lMax(D_004E19CC + lrAmbMin, lLighting.mrDirectional * (D_004E19D0 + D_004E19D4), 1.0f, 1.0f);
    CV4dRandomiser lParamsRandomiserB;
    lParamsRandomiserB.mVecA = (lMin + lMin) - lMax;
    lParamsRandomiserB.mVecB = lMax - lMin;
    for (;;) {
        int lnNumParticles = lbIsCrashRelated ? lnNumParticlesCrash : lnNumParticlesRegular;
        if (lnNumParticles > 0) {
            float lrRecipNumParticles = 1.0f / (float)lnNumParticles;
            CGtV3d lStep = (lEndPos - lStartPos) * lrRecipNumParticles;
            CGtV3d lPos = lStartPos + lStep * self->field_1F828.RandomReal();   // [C] a random first offset along one step
            float lrSpawnTimeStep = self->field_1F84C * lrRecipNumParticles;
            float lrSpawnTime = self->field_1F848 - self->field_1F84C;
            do {
                CGtV3d lParams = lParamsRandomiser.RandomiseXYZ();
                float lrSpawnAlpha = lParams.X();
                float lrAngularVel = lParams.Y();
                float lrSizeScale = lParams.Z();
                if (!(lrSpawnAlpha <= D_004E1170)) {   // [C] c.le + bc1f into the spawn
                    CGtV4d lParamsB = lParamsRandomiserB.RandomiseXYZW();
                    CGtV3d lPosOffset = lPosRandomiser.RandomiseXYZ();
                    CGtV3d lRandomisedVelocity = lVelRandomiser.RandomiseXYZ();
                    lRandomisedVelocity = lRandomisedVelocity + lHalfInherited * lParamsB.Z();
                    lRandomisedVelocity = lRandomisedVelocity + lUp * lParamsB.W();
                    lRandomisedVelocity = lRandomisedVelocity - lPosOffset * 0.5f;
                    float lrAmbient, lrDirectional;
                    if (lParamsB.f[1] < 1.0f) {
                        lrDirectional = lParamsB.f[1];
                        lrAmbient = lParamsB.f[0];
                        if (!(lrDirectional + lrAmbient <= 1.0f))
                            lrAmbient = 1.0f - lrDirectional;
                    } else {
                        lrDirectional = 1.0f;
                        lrAmbient = 0.0f;
                    }
                    CGtV3d lSpawnPos = lPos + lPosOffset;
                    if (!func_00254A90(lpParticleArray, &lSpawnPos, &lRandomisedVelocity, lbDestroyOldParticles, lbIsCrashRelated,
                                       lrSpawnTime, lrAmbient, lrDirectional, lrSizeScale, lrSpawnAlpha, lrAngularVel))
                        break;                 // [C] 0x25F8DC: the array is full: end this pass
                }
                lrSpawnTime += lrSpawnTimeStep;
                lPos += lStep; // [C] w = lPos.w: 0x25F754 lqc2 vf2, 0x4D0(sp); 0x25F758 vadd.xyz vf2, vf2, vf1; 0x25F760 sqc2 vf2, 0x4D0(sp)
            } while (--lnNumParticles != 0);
        }
        if (!lbIsCrashRelated)
            return;
        lbIsCrashRelated = false;              // [C] the crash pass first, then the regular pass
    }
}
