// NONMATCHING: UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb -- retail 623 / ours 620 instructions, 156 in changed runs
// draftAL C-first: skid trails (AddTrailSegment types 2/3/1), smoke/dust/dirt bytes eased to the surface targets at 510/s, four func_0025F0C0 sprays (+ player smoke), chunk spray on rear wheels; 620/623, calls identical; real 7th argument (signed char player index, t2) through the link name; AddTrailSegment const& through its link name (retail passes the wheel's vectors without a copy)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every call's argument list (incl. func_0025F0C0's stack bool and t3 = crash && player), the jump table (jtbl_004BCA00: 1 clears the skid, 2/3/5/6 smoke 1.0, 4 trail only), thresholds (100, 0.001, 0.2, 1/255 from .lit4) and branch sense traced

// CB3EffectsManager::UpdateWheelEffects(CB3VehiclePhysics*, unsigned int, const CGtMatrix3x4*, const CLighting&, bool) --
// draftAL (C-first draft). 0x2603F0, 0x9BC. [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's
// draft as a reading aid); local names from the Revenge STABS of CB4EffectsManager::UpdateWheelEffects (tools/stabs_lookup.py),
// which has a 7th parameter `RwInt8 ln8PlayerIndex`.
// [C] retail reads a 7th argument (t2, sign-extended byte, indexes D_005179C0 by 0xBB0) that the B3 mangled name does not show:
// the definition goes through the link name with retail's real list (as Revenge's).
// What it does [L]:
//  - skid trails (CB3TrailSystem::AddTrailSegment at this+0x2600): type 2 on surfaces 4 / 14, type 3 on 11, type 1 for the
//    wheel's slip states 2-6 (state 1 clears the skid); a player car's front wheels skip them when its player flag 0x20 is set;
//  - three smoke / dust / dirt amounts per wheel (bytes +0xA0..+0xA2) eased towards the surface's targets
//    (_gaSurfaceEffects[surface] +0 / +4 / +8, x 255) at 510 per second;
//  - particle sprays (func_0025F0C0) along the wheel's last movement: smoke (type 0, plus type 1 for the player car), dust
//    (type 3), dirt (type 4), and the surface's chunk type (+0xC, rear wheels only; 26 = none).
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_002603F0_se {              // _gaSurfaceEffects entries (16 bytes)
    float field_0;                          // smoke amount
    float field_4;                          // dust amount
    float field_8;                          // dirt amount
    signed char field_C;                    // chunk particle type (26 = none)
    unsigned char pad_D[0x3];
};
extern UnkStruct_002603F0_se _gaSurfaceEffects[];

struct UnkStruct_002603F0_pl {              // D_005179C0[player], stride 0xBB0
    unsigned long field_0;                  // flags
    unsigned char pad_8[0xBA8];
};
extern UnkStruct_002603F0_pl D_005179C0[];

struct UnkStruct_002603F0_wheel {           // [L] CB3Wheel (Revenge STABS `CB4Wheel *lpWheel`), stride 0xC0 at vehicle +0x820
    CGtV3d field_0;                         // contact position
    CGtV3d field_10;                        // trail position
    CGtV3d field_20;                        // trail direction
    CGtV3d field_30;                        // previous contact position
    unsigned char pad_40[0x10];
    float field_50;
    unsigned char pad_54[0x8];
    float field_5C;
    unsigned char pad_60[0x18];
    int field_78;                           // slip state
    unsigned char pad_7C[0x4];
    unsigned char field_80[0x20];           // trail emitter data
    unsigned char field_A0;                 // smoke amount (0-255)
    unsigned char field_A1;                 // dust amount
    unsigned char field_A2;                 // dirt amount
    unsigned char pad_A3;
    unsigned char field_A4[4];              // spray emit accumulators (func_0025F0C0)
    unsigned char pad_A8[0x8];
    unsigned char field_B0;                 // surface type
    unsigned char pad_B1[0x2];
    bool field_B3;                          // on the ground
    unsigned char pad_B4[0xC];
};

struct UnkStruct_002603F0_inst { unsigned char pad_0[0x20]; CGtV3d field_20; };

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x215];
    signed char field_215;                  // 1: player car
    unsigned char pad_216[0x60A];
    UnkStruct_002603F0_wheel field_820[4];
    unsigned char pad_B20[0x1A0];
    UnkStruct_002603F0_inst *field_CC0;
};

class CB3TrailEmitterData;
enum EB3TrailType { EB3TrailType_0 };
class CB3TrailSystem;
// [C] retail passes the wheel's own vectors' addresses (no call-site copy): declared through the link name with const& (as
// draftAK's func_0027D380 rule; the by-value form makes b119p copy at the call site)
extern "C" void AddTrailSegment__14CB3TrailSystemFP19CB3TrailEmitterDataQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3TrailTypePCQ29GtMathPs212CGtMatrix3x4(
    CB3TrailSystem *, CB3TrailEmitterData *, const CGtV3d &, const CGtV3d &, EB3TrailType, const CGtMatrix3x4 *);

class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    unsigned char pad_0[0x2600];
    unsigned char field_2600[0x1D24C];       // CB3TrailSystem
    float field_1F84C;                      // frame time step
    float field_1F850;                      // 1 / time step
};
// signature as the proven B3EffectsManager_00257C70.cpp, the 12th (stack) argument a bool: retail stores lbIsCrashRelated with
// a plain sd (no andi), and the callee reads it with lbu
extern "C" void func_0025F0C0(CB3EffectsManager *, const void *, const void *, const void *, int, const void *, unsigned char *, int, float, float, float, bool);

// [L] Revenge STABS locals of this inline: lpu8Effect, lrDestinationValue, mrTimestep, lrCurrentValue, lrB (the Min/Max argument)
static inline void func_002603F0_inl1(unsigned char *lpu8Effect, float lrDestinationValue, float mrTimestep)
{
    float lrCurrentValue = *lpu8Effect;
    if (!(lrDestinationValue <= lrCurrentValue))
        lrCurrentValue = GtMath::Min(lrCurrentValue + mrTimestep * 510.0f, lrDestinationValue);
    else
        lrCurrentValue = GtMath::Max(lrCurrentValue - mrTimestep * 510.0f, lrDestinationValue);
    *lpu8Effect = (int)(0.5f + lrCurrentValue);
}

// 0x002603F0
extern "C" void UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb(
    CB3EffectsManager *self, CB3VehiclePhysics *lpVehiclePhysics, unsigned int luWheelIndex, const CGtMatrix3x4 *lpMatrix,
    const CB3EffectsManager::CLighting &lLighting, bool lbIsCrashRelated, signed char ln8PlayerIndex)
{
    CGtV3d lOffset(0.0f, 0.125f, 0.0f);
    float lrSmoke = 0.0f;
    UnkStruct_002603F0_wheel *lpWheel = &lpVehiclePhysics->field_820[luWheelIndex];
    bool lbIsPlayerCar = lpVehiclePhysics->field_215 == 1;
    bool lbAllowParticles = lpWheel->field_B3;
    int leSurface = lpWheel->field_B0;
    UnkStruct_002603F0_se *lpSurfaceEffects = &_gaSurfaceEffects[leSurface];
    bool lbAllowSkid = lbAllowParticles;
    if (lbAllowParticles && lbIsPlayerCar && (D_005179C0[ln8PlayerIndex].field_0 & 0x20) != 0 && luWheelIndex < 2)
        lbAllowSkid = false;
    if (lbAllowSkid) {
        if (leSurface == 4 || leSurface == 14) {
            AddTrailSegment__14CB3TrailSystemFP19CB3TrailEmitterDataQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3TrailTypePCQ29GtMathPs212CGtMatrix3x4(
                (CB3TrailSystem *)self->field_2600, (CB3TrailEmitterData *)lpWheel->field_80, lpWheel->field_10, lpWheel->field_20,
                                             (EB3TrailType)2, lpMatrix);
            lbAllowSkid = false;
        } else if (leSurface == 11) {
            AddTrailSegment__14CB3TrailSystemFP19CB3TrailEmitterDataQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3TrailTypePCQ29GtMathPs212CGtMatrix3x4(
                (CB3TrailSystem *)self->field_2600, (CB3TrailEmitterData *)lpWheel->field_80, lpWheel->field_10, lpWheel->field_20,
                                             (EB3TrailType)3, lpMatrix);
            lbAllowSkid = false;
        }
    }
    if (lpWheel->field_B3) {
        switch (lpWheel->field_78) {
        case 1:
            lbAllowSkid = false;
        case 2:
        case 3:
        case 5:
        case 6:
            lrSmoke = 1.0f;
        case 4:
            if (lbAllowSkid)
                AddTrailSegment__14CB3TrailSystemFP19CB3TrailEmitterDataQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3TrailTypePCQ29GtMathPs212CGtMatrix3x4(
                (CB3TrailSystem *)self->field_2600, (CB3TrailEmitterData *)lpWheel->field_80, lpWheel->field_10,
                                                 lpWheel->field_20, (EB3TrailType)1, lpMatrix);
            break;
        }
    }
    int leChunkType = 26;
    float lrAmountSmoke;
    float lrAmountDust;
    float lrAmountDirt;
    if (lbAllowParticles) {
        if (luWheelIndex >= 2)
            leChunkType = lpSurfaceEffects->field_C;
        lrAmountDust = lpSurfaceEffects->field_4;
        lrAmountDirt = lpSurfaceEffects->field_8;
        lrAmountSmoke = lpSurfaceEffects->field_0 * lrSmoke;
    } else {
        lrAmountSmoke = 0.0f;
        lrAmountDust = lrAmountSmoke;
        lrAmountDirt = lrAmountSmoke;
    }
    func_002603F0_inl1(&lpWheel->field_A0, lrAmountSmoke * 255.0f, self->field_1F84C);
    func_002603F0_inl1(&lpWheel->field_A1, lrAmountDust * 255.0f, self->field_1F84C);
    func_002603F0_inl1(&lpWheel->field_A2, lrAmountDirt * 255.0f, self->field_1F84C);
    if (leChunkType == 26 && (lpWheel->field_A0 | lpWheel->field_A1 | lpWheel->field_A2) == 0)
        return;

    CGtV3d lDifference = lpWheel->field_0 - lpWheel->field_30;
    CGtV3d lVelocity = lDifference * self->field_1F850;
    float lrLength = lDifference.GetLength();
    if (lrLength > 100.0f) {
        lrLength = 0.0f;
        lDifference.Set(0.0f, 0.0f, 0.0f);
        lVelocity.Set(0.0f, 0.0f, 0.0f);
    }
    float lrSpawnScale = 1.0f;
    if (luWheelIndex >= 2) {
        float k = lpWheel->field_50 * lpWheel->field_5C;
        lVelocity -= lpVehiclePhysics->field_CC0->field_20 * k * 0.2f;
        if (lpWheel->field_78 == 1) {
            lrLength = 0.2f * (k * self->field_1F84C);
            lDifference = lVelocity * -self->field_1F84C * 0.2f;
        }
        float lrSpeed = lVelocity.GetLength() * self->field_1F84C;
        if (lrSpeed > lrLength) {
            if (lrSpeed <= lrLength + lrLength)
                lrSpawnScale = lrSpeed / lrLength;
            else
                lrSpawnScale = 2.0f;
        }
    }
    if (lrLength < 0.001f)
        return;
    CGtV3d lLineStart = lpWheel->field_10 + lOffset;
    CGtV3d lLineEnd = lLineStart - lDifference;
    ((float *)&lLineEnd)[3] = ((const float *)&lDifference)[3]; // [C] 0x2608F4 lqc2 vf1, 0x140(sp) (lDifference); 0x2608FC vsub.xyz vf1,
    // vf6, vf1 keeps its w; 0x260904 sqc2 vf1, 0x170(sp) -- `a - b` took lLineStart's w
    if (lpMatrix) {
        lLineEnd = TransformPoint(*lpMatrix, lLineEnd);
        lLineStart = TransformPoint(*lpMatrix, lLineStart);
    }
    if (lpWheel->field_A0) {
        float a = (1.0f / 255.0f) * lpWheel->field_A0;
        func_0025F0C0(self, &lLineEnd, &lLineStart, &lVelocity, 0, &lLighting, &lpWheel->field_A4[0],
                      lbIsCrashRelated && lbIsPlayerCar, lrLength, (0.75f + 0.25f * a) * lrSpawnScale, GtMath::Min(a + a, 1.0f),
                      lbIsCrashRelated);
        if (lbIsPlayerCar)
            func_0025F0C0(self, &lLineEnd, &lLineStart, &lVelocity, 1, &lLighting, &lpWheel->field_A4[0], 1, lrLength, 1.0f,
                          GtMath::Min(a + a, 1.0f), 0);
    }
    if (lpWheel->field_A1) {
        float a = (1.0f / 255.0f) * lpWheel->field_A1;
        func_0025F0C0(self, &lLineEnd, &lLineStart, &lVelocity, 3, &lLighting, &lpWheel->field_A4[1], 0, lrLength,
                      (0.75f + 0.25f * a) * lrSpawnScale, GtMath::Min(a + a, 1.0f), lbIsCrashRelated);
    }
    if (lpWheel->field_A2) {
        float a = (1.0f / 255.0f) * lpWheel->field_A2;
        func_0025F0C0(self, &lLineEnd, &lLineStart, &lVelocity, 4, &lLighting, &lpWheel->field_A4[2], 0, lrLength,
                      (0.75f + 0.25f * a) * lrSpawnScale, GtMath::Min(a + a, 1.0f), lbIsCrashRelated);
    }
    if (leChunkType != 26)
        func_0025F0C0(self, &lLineEnd, &lLineStart, &lVelocity, leChunkType, &lLighting, &lpWheel->field_A4[3], 0, lrLength,
                      lrSpawnScale, 1.0f, lbIsCrashRelated);
}
