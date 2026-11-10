// NONMATCHING: func_0025CD60 -- retail 433 / ours 404 instructions, 410 in changed runs
// draftAO (2026-11-01): complete: [L] CB3EffectsManager::SpawnDebrisFromPoint (E map neighbour of SpawnPopcornFromPoint, Revenge register list); the son6 skeleton's VU middle written from retail 0x25CF7C..0x25D3A8: CV4dRandomiser params (min (0.8, 0.669, 0, 0.75), max (5, 0.905, lighting.x, 1)), CV3dRandomiser velocity (+-4, 2..2.9, +-4) + inherit lerp velB..velA scaled by a CScalarRandomiser 0.5..0.9, the component against normal*1.2 removed when the dot is negative, a normalised axis randomiser (0.001..1), prelight (z, z, z*w), size y^8; SpawnDebris(pos, vel, axis, prelight, x, y^8, height, +0x1F848) on the 4 arrays round-robin from Random() % 4 (the draft passed normal*1.2 and the velocity twice and y^4); 426/433, calls identical, VU op counts equal but 1 vmove | Before: fix2 (2026-11-01): the four func_0025EA70 calls pass f13 = 1.0f (the draft passed its incoming f13) [C] retail 0x25CDC4..0x25CEAC | Before: son6 first-pass skeleton (284 vs 433): signature, 4x func_0025EA70 (idx 0xE-0x11), func_0025D430, member LCG x2 (s0=x&3, R seed via vrinit), debris loop with SpawnDebris slot ring (stride 0x30, 4 slots) right; left: the per-iteration VU0 vector math (base+rang
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x25CD60..0x25D420: every R draw group, randomiser pair (stack 0x3F0/0x400, 0x410/0x420, 0x430/0x440, 0x450/0x460, 0x3E0), lane and call argument traced; unset w lanes of the stack constants and of the prelight kept (xyz-only users)

// func_0025CD60 -- [L] CB3EffectsManager::SpawnDebrisFromPoint(CGtV3d lPos, CGtV3d lVelocityA, CGtV3d lVelocityB, CGtV3d lNormal,
// float lrNumParticles, float lrHeightAboveGround, const CLighting &, bool lbIsCrashRelated): the E maps list it in
// B3EffectsManager.cpp right after SpawnPopcornFromPoint (B3O0PCH 0x270D50 after 0x2708A0; retail 0x25CD60 just before
// func_0025D430 = SpawnPopcornFromPoint [L], draftAN), and Revenge's SpawnDebrisFromPoint__17CB4EffectsManager has the same
// register list (a0 this, a1..t0 four vectors, f12 count, f13 height, t1 lighting, t2 bool) [C retail 0x25CD60..0x25CE00].
// Label kept (no B3 symbol). Locals named after Revenge's STABS locals [L] (research/stabs/revenge_jul14_functions.cpp:80712).
// draftAO fork B (2026-11-01): complete; every VU op from retail 0x25CF7C..0x25D3A8.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

class CB3DebrisArray {                         // [C] SpawnDebris's mangled name
public:
    void SpawnDebris(CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, float, float, float);
    unsigned char pad_0[0x30];                 // [C] stride 0x30 (retail 0x25D348: luDebrisType * 0x30 + 0xB0)
};
struct UnkStruct_0025CD60_mgr {                // [L] CB3EffectsManager
    unsigned char pad_0[0xB0];
    CB3DebrisArray field_B0[4];                // [C] four debris arrays, chosen by luDebrisType
    unsigned char pad_170[0x1F828 - 0x170];
    CGtRandom field_1F828;                     // [C] the manager's CGtRandom (rotate-add step x2, RandomReal seed)
    unsigned char pad_1F830[0x18];
    float field_1F848;                         // [G] passed as SpawnDebris's last float (as func_0025D930's spawns)
};
struct UnkStruct_0025CD60_lighting {           // [L] CB3EffectsManager::CLighting (DoVehicleGlass builds one from two floats)
    float field_0;                             // [C] read as the params randomiser's maximum z
    float field_4;
};
// [L] Revenge SpawnParticlesFromPoint order (pos, velocity A/B, spawn type, number, lighting, alpha, accumulator, destroy-old,
// crash-related) -- the matched B3EffectsManager_0025FCF0.cpp prototype, lighting as this file's placeholder
extern "C" void func_0025EA70(UnkStruct_0025CD60_mgr *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, float,
                              const UnkStruct_0025CD60_lighting &, float, void *, bool, bool);
// [L] SpawnPopcornFromPoint (draftAN func_0025D430's own list: pos, velocity A/B, a fourth vector, normal, count, crash, num, height)
extern "C" void func_0025D430(UnkStruct_0025CD60_mgr *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *,
                              const CGtV3d *, int, int, float, float);

// [L] Revenge STABS CScalarRandomiser (types.h:41681): mVec x = max - min, y = 2 min - max; y + x * r, r a raw R draw in [1,2)
// (local copy of func_0039AD90's; header gap queued by draftAN)
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
// [L] Revenge STABS CV4dRandomiser (types.h:41691): mVecA = 2 min - max, mVecB = max - min, four raw R draws (local copy of
// func_0039AD90's; header gap queued by draftAN)
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
// the VU0 random generator seeded (vrinit), as func_0025D930_inl1
static inline void func_0025CD60_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}
// [G] z * w in the z lane (`vmulw.z`, retail 0x25D390); no ZAxisType x WAxisType operator in the E maps: header gap
static inline ZAxisType func_0025CD60_inl2(ZAxisType z, WAxisType w)
{
    u_long128 r;
    asm("vmulw.z %0, %1, %2w" : "=j"(r) : "j"(z.lVector), "j"(w.lVector));
    return ZAxisType(r);
}

// 0x0025CD60
extern "C" void func_0025CD60(UnkStruct_0025CD60_mgr *self, CGtV3d lPos, CGtV3d lVelocityA, CGtV3d lVelocityB, CGtV3d lNormal,
                              float lrNumParticles, float lrHeightAboveGround, const UnkStruct_0025CD60_lighting &lLighting,
                              bool lbIsCrashRelated)
{
    // [C] retail 0x25CDC4..0x25CEE4: four particle bursts (types 14..17) and the popcorn, f13 = 1.0 for the bursts
    func_0025EA70(self, &lPos, &lVelocityA, &lVelocityB, 14, 4.0f * lrNumParticles, lLighting, 1.0f, 0, false, lbIsCrashRelated);
    func_0025EA70(self, &lPos, &lVelocityA, &lVelocityB, 15, 4.0f * lrNumParticles, lLighting, 1.0f, 0, false, lbIsCrashRelated);
    func_0025EA70(self, &lPos, &lVelocityA, &lVelocityB, 16, 6.0f * lrNumParticles, lLighting, 1.0f, 0, false, lbIsCrashRelated);
    func_0025EA70(self, &lPos, &lVelocityA, &lVelocityB, 17, 6.0f * lrNumParticles, lLighting, 1.0f, 0, false, lbIsCrashRelated);
    func_0025D430(self, &lPos, &lVelocityA, &lVelocityB, 0, &lNormal, 1, lbIsCrashRelated, 16.0f * lrNumParticles, lrHeightAboveGround);
    // [C] 0x25CEE8..0x25CF74: one Random() step, kept modulo 4 (`x - (x & -4)`)
    unsigned int luDebrisType = self->field_1F828.Random() % 4;
    CGtV3d lNormalScaled = lNormal * 1.2f;     // [C] D_004E0E60 = 1.2 (xyz; w keeps the normal's)
    func_0025CD60_inl1(self->field_1F828.RandomReal());
    // [C] 0x25D04C..0x25D178: the five randomisers; stack quads' w lanes are never written (unset reads, xyz-only users)
    CV3dRandomiser lVelocityRandomiser;
    CGtV3d lVelMax(4.0f, 2.9f, 4.0f);
    CGtV3d lVelMin(-4.0f, 2.0f, -4.0f);
    lVelocityRandomiser.mVecA = lVelMax;
    lVelocityRandomiser.mVecB = lVelMax - lVelMin;
    CV3dRandomiser lVelocityInheritanceRandomiser;
    lVelocityInheritanceRandomiser.mVecA = lVelocityB;
    lVelocityInheritanceRandomiser.mVecB = lVelocityB - lVelocityA;
    CV3dRandomiser lAxisRandomiser;
    CGtV3d lAxisMax(1.0f, 1.0f, 1.0f);
    CGtV3d lAxisMin(0.001f, 0.001f, 0.001f);
    lAxisRandomiser.mVecA = lAxisMax;
    lAxisRandomiser.mVecB = lAxisMax - lAxisMin;
    CV4dRandomiser lParamsRandomiser;
    CGtV4d lParamsMin(0.8f, 0.66874f, 0.0f, 0.75f);           // [C] D_004E0A40, D_004E1338 (0x3F2B328B), 0, 0.75
    CGtV4d lParamsMax(5.0f, 0.905006f, lLighting.field_0, 1.0f);   // [C] 5.0, D_004E1334 (0x3F67AE79), lighting, 1.0
    lParamsRandomiser.mVecA = (lParamsMin + lParamsMin) - lParamsMax;
    lParamsRandomiser.mVecB = lParamsMax - lParamsMin;
    CScalarRandomiser lVelInheritanceScaleRandomiser;          // [C] z / w lanes never written
    lVelInheritanceScaleRandomiser.mVec.SetY(0.5f + 0.5f - 0.9f);   // [C] D_004E07E8 = 0x3DCCCCD0 (folded: min 0.5, max 0.9)
    lVelInheritanceScaleRandomiser.mVec.SetX(0.9f - 0.5f);         // [C] D_004E133C = 0x3ECCCCCC
    int lnNumParticles = (int)lrNumParticles;
    while (lnNumParticles-- > 0) {
        CGtV4d lParams = lParamsRandomiser.RandomiseXYZW();
        CGtV3d lRandomisedVelocity = lVelocityRandomiser.RandomiseXYZ();
        CGtV3d lInherit = lVelocityInheritanceRandomiser.RandomInterpolate();
        XAxisType lrScale = lVelInheritanceScaleRandomiser.RandomInterpolate();
        lRandomisedVelocity += lInherit * lrScale; // [C] w = lRandomisedVelocity.w: 0x25D270 qmtc2 a1, vf4; 0x25D274 vadd.xyz vf4, vf4, vf1;
        // 0x25D280 sqc2 vf4, 0x3C0(sp) -- `a + b` took lInherit's w
        // [C] 0x25D278..0x25D2A8, 0x25D3D4: never move into the ground: remove the component along the scaled normal
        XAxisType lrDot = DotProduct(lNormalScaled, lRandomisedVelocity);
        if ((float)lrDot < 0.0f)
            lRandomisedVelocity = lRandomisedVelocity - lNormalScaled * lrDot;
        CGtV3d lAxis = lAxisRandomiser.RandomiseXYZ();
        func_002EBED0_inl1(lAxis);             // [C] in-place normalise (vrsqrt; vmulq.xyz on the squared register)
        // [C] 0x25D37C..0x25D394: prelight (z, z, z * w); its w lane is the slot's unset stack bytes
        CGtV3d lPrelight;
        lPrelight.SetX(lParams.Z());
        lPrelight.SetY(lParams.Z());
        lPrelight.SetZ(func_0025CD60_inl2(lParams.Z(), lParams.W()));
        float lrSizeScale = lParams.f[1];
        lrSizeScale *= lrSizeScale;
        lrSizeScale *= lrSizeScale;
        lrSizeScale *= lrSizeScale;            // [C] y^8 (three mul.s, 0x25D38C..0x25D3A8)
        self->field_B0[luDebrisType].SpawnDebris(lPos, lRandomisedVelocity, lAxis, lPrelight, lParams.f[0], lrSizeScale,
                                                 lrHeightAboveGround, self->field_1F848);
        luDebrisType++;
        if (luDebrisType == 4)
            luDebrisType = 0;
    }
}
