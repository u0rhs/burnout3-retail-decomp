// NONMATCHING: func_0025AC30 -- retail 517 / ours 521 instructions, 604 in changed runs
// draftAO (2026-11-01): complete: [L] CB3EffectsManager::HandleAirRamEffects(CB3VehiclePhysics *, CLighting) (DNAT map + Revenge register list and locals; sole caller of DoAirRamExplosion); written from retail: the pending-explosion block (local point (FF0.x/2, 0, max(0, FF0.z+0.25)) through the vehicle matrix, y clamped to mPos.y - min(height, 1), mUp, velocity), intensity 1 - (rate t)^2 (rate 0.5 or 4/3 by +0x215), the inlined CLighting::SetFromIrradianceMap (overwrites the by-value lighting), _gaSpawnParams[9] accumulators, the box centre and intensity-scaled half axes from lBoundingBox (+0x1D0 sup / +0x1E0 inf), CV3dRandomisers PosZ / PosX / VelocityInheritance (0.1..0.3 of the velocity), CV4dRandomiser params (x -0.8..-1.2, y +-2 spin, z 0.5..3.5 dir, w 0.1..0.6 amb), the ambient/directional clamp, SpawnParticle(pos, vel, 0, regular < remaining, time, amb, dir, 1, intensity, params.y); 543/517, calls identical, every VU op count equal | Before: fix2 (2026-11-01): gp-relative globals were named 0x7990 high (D_004E8xxx/9xxx for retail's D_004E0xxx/1xxx; same error as the son-series drafts func_0025BBC0/HandleRaceCarTraffic) [C] retail %gp_rel operands | Before: son9 first archive (517/234 instrs, 541 changed): skeleton. Decoded: params (mgr, car, 3rd stored to stack), car+0xCC4 state (+0xFF0 vec, +0x49C float, +0x1015 flag bits 4/2), car+0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x25AC30..0x25B440: every R draw (V4 then Z, X, inheritance; one state rotation each), randomiser pair (stack 0x7C0/0x7D0, 0x800/0x810, 0x820/0x830, 0x7E0/0x7F0), lane, clamp (max.s/min.s), branch sense and call argument traced; the by-value CLighting is overwritten before it is read (retail too)

// func_0025AC30 -- [L] CB3EffectsManager::HandleAirRamEffects(CB3VehiclePhysics *, CB3EffectsManager::CLighting): the DNAT E map
// lists it in B3EffectsManager.cpp (0x21AF10, 0xAE0); Revenge HandleAirRamEffects__17CB4EffectsManager has the same register list
// (a0 this, a1 the vehicle, the CLighting by value in a2 stored to the frame [C retail 0x25AC78]) and the same locals (four
// randomisers, lBoundingBox, two static accumulators = B3 lrRegularAccumulator$37260 / lrCrashAccumulator$37261 .sbss = D_004E29F4 /
// D_004E29F8), and it is the one caller of func_00399EC0 = [L] DoAirRamExplosion (draftAN). Label kept (no B3 symbol). Locals named
// after Revenge's STABS locals [L] (research/stabs/revenge_jul14_functions.cpp:81158).
// draftAO fork B (2026-11-01): complete; was a skeleton with scalar stand-ins for every VU0 random.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

struct CGtIrradianceMap {                      // [C] name: the DNAT map's SetFromIrradianceMap(const CGtIrradianceMap &)
    float marCoeff[9];                         // [L] Revenge STABS (types.h:5620, 0x24)
};
class CB3EffectsManager {
public:
    class CLighting {                          // [C] name (mangled B3 symbols); [L] fields Revenge STABS (types.h:33095)
    public:
        float mrAmbient;
        float mrDirectional;
        void SetFromIrradianceMap(const CGtIrradianceMap &lIrradiance);
    };
    unsigned char pad_0[0x170];
    unsigned char field_170[1][0x150];         // [C] particle arrays, stride 0x150 (meArray * 0x150 + 0x170)
    unsigned char pad_2C0[0x1F828 - 0x2C0];
    CGtRandom field_1F828;                     // [C] the manager's CGtRandom (RandomReal seeds VU0 R)
    unsigned char pad_1F830[0x18];
    float field_1F848;                         // [G] the current time (the air ram start time is subtracted from it)
    float field_1F84C;                         // [G] a particle count scale
};
struct UnkStruct_0025AC30_params {             // [L] Revenge CB4VehicleEssentialParams (types.h:5630): irradiance at +0x5C
    unsigned char pad_0[0x5C];
    CGtIrradianceMap field_5C;                 // [L] mIrradiance
};
struct UnkStruct_0025AC30_body {               // [G] the vehicle's colliding body (+0xCC4)
    unsigned char pad_0[0x490];
    CGtV4d field_490;                          // [G] w: height above the ground (as DoVehicleGlass)
    unsigned char pad_4A0[0xFF0 - 0x4A0];
    CGtV4d field_FF0;                          // [G] x / z: the explosion's local offsets; w: the air ram start time
    unsigned char pad_1000[0x15];
    unsigned char field_1015;                  // [C] flags: bit 4 = explosion pending, bit 2 = air ram effects active
};
struct CGtAxisAlignedBox {                     // [L] Revenge STABS (types.h:2726, 0x20); B3 has the name (BeginInstanceRender's list)
    CGtV3d mSup;
    CGtV3d mInf;
};
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;                           // [G] linear velocity (its length is the speed)
    unsigned char pad_C0[0x1D0 - 0xC0];
    CGtAxisAlignedBox field_1D0;               // [L] lBoundingBox's source
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 *field_204;                   // [L] lpVehicleMatrix
    unsigned char pad_208[0xD];
    signed char field_215;                     // [G] == 1 shortens the effect (0.5 vs 4/3 per second)
    unsigned char pad_216[0xCC0 - 0x216];
    UnkStruct_0025AC30_params *field_CC0;
    UnkStruct_0025AC30_body *field_CC4;
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
extern float D_004E29F4;                       // [L] lrRegularAccumulator$37260 (DNAT .sbss)
extern float D_004E29F8;                       // [L] lrCrashAccumulator$37261
extern float D_004E29E8;                       // [L] SetFromIrradianceMap's krTopThreshold (DNAT .sbss: 0 until written)
extern float D_004E19AC, D_004E19B0, D_004E19B4, D_004E19B8, D_004E19BC;   // [L] krTopScale, krBottomThreshold, krBottomScale,
                                                                          // krAmbScale, krDirScale (DNAT .sdata order; 1, 0.1, 1, 1, 1)
extern unsigned char D_01EA4BB0[];             // [L] the explosion manager (func_00399EC0's this)
// [L] CB3ExplosionManager::DoAirRamExplosion(pos, direction, source velocity) (draftAN archive)
extern "C" void func_00399EC0(void *, const CGtV3d *, const CGtV3d *, const CGtV3d *);
// [L] CB3ParticleArray::SpawnParticle (archive func_00254A90: pos, vel, bool, crash bool, six floats)
extern "C" int func_00254A90(void *, const CGtV3d *, const CGtV3d *, bool, bool, float, float, float, float, float, float);

// [L] Revenge STABS CScalarRandomiser / CV4dRandomiser: local copies of func_0039AD90's (header gap queued by draftAN)
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
static inline void func_0025AC30_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// [C] name: DNAT map (its .sbss/.sdata statics @LOCAL@SetFromIrradianceMap__Q217CB3EffectsManager9CLightingFRC16CGtIrradianceMap@..).
// [L] body: retail 0x25AEA4..0x25AF5C (inlined): Revenge locals lrTopLight / lrBottomLight / lrA / lrB / lrAmb / lrDir.
inline void CB3EffectsManager::CLighting::SetFromIrradianceMap(const CGtIrradianceMap &lIrradiance)
{
    float lrTopLight = lIrradiance.marCoeff[0];
    float lrBottomLight = lIrradiance.marCoeff[1];
    float lrAmb = GtMath::Min(lrBottomLight, lrTopLight);
    float lrA = GtMath::Min(GtMath::Max(D_004E19AC * (lrTopLight - D_004E29E8), 0.0f), 1.0f);
    float lrB = GtMath::Min(GtMath::Max(D_004E19B4 * (lrBottomLight - D_004E19B0), 0.0f), 1.0f);
    float lrDir = lrA + lrB;
    lrDir *= lrDir;
    if (lrA < lrB)                             // [C] 0x25AEF8: a branch (the delay slot squares in both arms)
        lrDir = lrDir + lrA;
    else
        lrDir = lrDir + lrB;
    mrDirectional = GtMath::Min(GtMath::Max(lrDir * D_004E19BC, 0.0f), 1.0f);
    mrAmbient = GtMath::Min(GtMath::Max(lrAmb * D_004E19B8, 0.0f), 1.0f - mrDirectional);
}

// 0x0025AC30
extern "C" void func_0025AC30(CB3EffectsManager *self, CB3VehiclePhysics *lpVehiclePhysics, CB3EffectsManager::CLighting lLighting)
{
    CGtV3d lVelocity = lpVehiclePhysics->field_B0;
    UnkStruct_0025AC30_body *lpBody = lpVehiclePhysics->field_CC4;
    CGtMatrix3x4 *lpVehicleMatrix = lpVehiclePhysics->field_204;
    float lrAirRamTime = self->field_1F848 - lpBody->field_FF0.W();
    // [C] 0x25ACB0..0x25ACC8: NaN-safe test (c.le + bc1t skips)
    if ((lpBody->field_1015 & 4) && !(lrAirRamTime <= 0.025f)) {
        CGtV4d lGround = lpBody->field_490;
        float lrHeight = GtMath::Min(lGround.f[3], 1.0f);
        CGtV3d lLocal;                         // [C] w lane: the body vector's (unused by TransformPoint)
        lLocal.SetX(lpBody->field_FF0.X() * 0.5f);
        lLocal.SetY(0.0f);
        lLocal.SetZ(GtMath::Max(0.0f, (float)(lpBody->field_FF0.Z() + 0.25f)));
        CGtV3d lPos = TransformPoint(*lpVehicleMatrix, lLocal);
        CGtV3d lDirection = lpVehicleMatrix->mUp;
        lPos.SetY(GtMath::Min((float)lPos.Y(), (float)(lpVehicleMatrix->mPos.Y() - lrHeight)));
        func_00399EC0(D_01EA4BB0, &lPos, &lDirection, &lVelocity);
        lpVehiclePhysics->field_CC4->field_1015 &= ~4;
    }
    float lrRate;
    if (lpVehiclePhysics->field_215 == 1)
        lrRate = 0.5f * lrAirRamTime;
    else
        lrRate = 1.3333334f * lrAirRamTime;   // [C] D_004E12D8 = 0x3FAAAAAB
    float lrAirRamIntensity = 1.0f - lrRate * lrRate;
    if (lrAirRamIntensity <= 0.0f) {
        lpVehiclePhysics->field_CC4->field_1015 &= ~2;
        return;
    }
    float lrNum = (float)(lVelocity.GetLength() * 10.0f * lrAirRamIntensity * self->field_1F84C);
    // [C] the incoming lighting is overwritten here (both fields) before any read
    lLighting.SetFromIrradianceMap(lpVehiclePhysics->field_CC0->field_5C);
    UnkStruct_D_004BC040 *lpSpawnParams = &D_004BC040[9];
    unsigned char *lpParticleArray = self->field_170[lpSpawnParams->field_0];
    D_004E29F4 = D_004E29F4 + lrNum * lpSpawnParams->field_30 * *(float *)(lpParticleArray + 0x108);
    D_004E29F8 = D_004E29F8 + lrNum * lpSpawnParams->field_34 * *(float *)(lpParticleArray + 0x134);
    int lnNumParticlesRegular = (int)D_004E29F4;
    D_004E29F4 = D_004E29F4 - (float)lnNumParticlesRegular;
    int lnNumParticlesCrash = (int)D_004E29F8;
    int lnNumParticles = lnNumParticlesRegular + lnNumParticlesCrash;
    D_004E29F8 = D_004E29F8 - (float)lnNumParticlesCrash;
    if (lnNumParticles <= 0)
        return;
    // [C] 0x25AFD4..0x25B0D4: the box centre in the vehicle's xz plane and its two half-axes scaled by the intensity
    CGtAxisAlignedBox lBoundingBox = lpVehiclePhysics->field_1D0;
    CGtV3d lCorner = lpVehicleMatrix->mPos + lpVehicleMatrix->mRight * lBoundingBox.mInf.X() + lpVehicleMatrix->mAt * lBoundingBox.mInf.Z();
    CGtV3d lAxisX = lpVehicleMatrix->mRight * (lBoundingBox.mSup.X() - lBoundingBox.mInf.X());
    CGtV3d lAxisZ = lpVehicleMatrix->mAt * (lBoundingBox.mSup.Z() - lBoundingBox.mInf.Z());
    CGtV3d lCentre = lCorner + (lAxisX + lAxisZ) * 0.5f;
    lAxisX = lAxisX * lrAirRamIntensity;
    lAxisZ = lAxisZ * lrAirRamIntensity;
    func_0025AC30_inl1(self->field_1F828.RandomReal());
    CV3dRandomiser lPosXRandomiser;
    lPosXRandomiser.mVecA = lAxisX * 0.5f;
    lPosXRandomiser.mVecB = lPosXRandomiser.mVecA - lAxisX * -0.5f;
    CV3dRandomiser lPosZRandomiser;
    lPosZRandomiser.mVecA = lAxisZ * 0.5f;
    lPosZRandomiser.mVecB = lPosZRandomiser.mVecA - lAxisZ * -0.5f;
    CV3dRandomiser lVelocityInheritanceRandomiser;
    lVelocityInheritanceRandomiser.mVecA = lVelocity * 0.3f;                    // [C] D_004E127C
    lVelocityInheritanceRandomiser.mVecB = lVelocityInheritanceRandomiser.mVecA - lVelocity * 0.1f;   // [C] D_004E1278
    float lrSpin = 2.0f * lpSpawnParams->field_18;
    CGtV4d lMin(-0.8f, -lrSpin, 0.5f * lLighting.mrDirectional, 0.1f * lLighting.mrAmbient);    // [C] D_004E12DC, D_004E1278
    CGtV4d lMax(-1.2f, lrSpin, 3.5f * lLighting.mrDirectional, 0.6f * lLighting.mrAmbient);     // [C] D_004E12E0, D_004E0E94
    CV4dRandomiser lParamsRandomiser;
    lParamsRandomiser.mVecA = (lMin + lMin) - lMax;
    lParamsRandomiser.mVecB = lMax - lMin;
    do {
        CGtV4d lParams = lParamsRandomiser.RandomiseXYZW();
        CGtV3d lOffsetZ = lPosZRandomiser.RandomInterpolate();
        CGtV3d lOffsetX = lPosXRandomiser.RandomInterpolate();
        CGtV3d lOffset = lOffsetX + lOffsetZ;
        CGtV3d lPos = lCentre;
        lPos += lOffset; // [C] w = lCentre.w: 0x25B300 lqc2 vf2, 0x790(sp); 0x25B308 vadd.xyz vf2, vf2, vf3; 0x25B30C sqc2 vf2, 0x760(sp)
        // (`a + b` took lOffset's w). lCentre's own w is retail's stale vf4 (0x25B098 / 0x25B0C8, vf4 not written before 0x25B03C): not modelled
        CGtV3d lSpread = lOffset * lParams.X();
        CGtV3d lVel = lSpread + lVelocityInheritanceRandomiser.RandomInterpolate();
        float lrAmbient, lrDirectional;
        if (lParams.f[2] < 1.0f) {
            lrDirectional = lParams.f[2];
            lrAmbient = lParams.f[3];
            if (!(lrDirectional + lrAmbient <= 1.0f))
                lrAmbient = 1.0f - lrDirectional;
        } else {
            lrDirectional = 1.0f;
            lrAmbient = 0.0f;
        }
        func_00254A90(lpParticleArray, &lPos, &lVel, false, lnNumParticlesRegular < lnNumParticles, self->field_1F848, lrAmbient,
                      lrDirectional, 1.0f, lrAirRamIntensity, lParams.f[1]);
    } while (--lnNumParticles != 0);
}
