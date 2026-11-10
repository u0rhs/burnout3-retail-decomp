// NONMATCHING: UpdateCrashSteering__17CB3VehiclePhysicsFf -- retail 660 / ours 660 instructions, 426 in changed runs
// draftN: logic complete, calls identical (fabsf, sinf x4, cosf x2), FPU op counts equal; residue: retail keeps 1.0 in f22 (CSE with the CGtV3d(0,1,0) ctor) and reloads 0.1 per wheel where b119p hoists 0.1 and rematerialises 1.0; retail's matrix product re-qmtc2s lFrontWheelMatrix rows into vf1 per row (header op* holds them in vf4/vf3/vf2); TransformPoint's mPos lands in the point's register and is reused by the following -mPos; 2 vmoves from operator+ result registers; frame 0x2B0 vs 0x570
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every branch, call, store and VU op accounted for; ApplyPositionedForce parameter order (lPoint, lForce) from Revenge STABS

// CB3VehiclePhysics::UpdateCrashSteering(float) -- hand-written by draftN from the retail asm + Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G] (instruction widths).
// Locals named after Revenge's CB4VehiclePhysics::UpdateCrashSteering STABS where the role is clear [L] (Physics: hint only).
// The front wheels' frame is the body matrix rotated by the steering angle (field_1164, degrees) about Y; per grounded wheel
// (field_B3) whose part state is 0: the contact point's velocity split into lateral / longitudinal slip against the wheel's
// tread speed, a sine-curve friction factor, and the two road forces applied 0.1 above the contact point.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
#include "b3/classes/UnkStruct_D_0052267C.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);
extern "C" float sqrtf(float);
extern "C" float sinf(float);
extern "C" float cosf(float);
extern UnkStruct_D_0052267C D_0052267C;   // [G] field_0 = the game timestep (B3RaceCarPhysics passes it to UpdateSuspension)

struct UnkStruct_001CAD30_cc4 {      // [G]
    unsigned char pad_0[0x4AC];
    signed char field_4AC[4];        // [G] per-wheel part state (3 = detached in UpdateSuspension)
};
struct UnkStruct_001CAD30_wheel {    // [G] 0xC0 stride, base veh+0x820
    unsigned char pad_0[0x50];
    float field_50;                  // [G] wheel radius
    unsigned char pad_54[8];
    float field_5C;                  // [G] wheel spin rate
    unsigned char pad_60[0x14];
    float field_74;
    unsigned char pad_78[0x3B];
    unsigned char field_B3;          // [G] on the ground
    unsigned char pad_B4[0xC];
};

// [L] base class: Revenge's inlined CB4CollidingBody methods run on the vehicle's own `this` register (STABS).
class CB3CollidingBody {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;                  // [G] linear velocity, w = speed
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                  // [G] angular velocity
    unsigned char pad_E0[0x10];
    CGtV3d field_F0;                  // [G] force accumulator
    CGtV3d field_100;                 // [G] torque accumulator
    unsigned char pad_110[0xE0];
    float field_1F0;                  // [G] mass
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x18];

    // [L] E map names (B3O0PCH: CB3CollidingBody::ApplyPositionedForce(CGtV3d, CGtV3d), GetPointVelocity(CGtV3d),
    // LocalPointToWorldPoint(CGtV3d)); bodies [G] from retail's inlined copies (as in UpdateSuspension's archive).
    // [L] parameter order (lPoint, lForce): Revenge STABS CB4CollidingBody::ApplyPositionedForce(lPoint, lForce, leForceType)
    void ApplyPositionedForce(CGtV3d lPoint, CGtV3d lForce) {
        field_F0 += lForce;
        field_100 += CrossProduct(lPoint - field_204->mPos, lForce);
    }
    CGtV3d LocalPointToWorldPoint(CGtV3d p) { return TransformPoint(*field_204, p); }
    CGtV3d GetPointVelocity(CGtV3d pos) {
        CGtV3d v = CrossProduct(field_D0, pos - field_204->mPos) + field_B0;
        // [C] w = field_D0.w at this function's one call (0x1CB3A8 lqc2 vf1, 0xD0(s0); 0x1CB3B0 vopmsub.xyz vf1, vf2, vf1 into its register;
        // 0x1CB3B4/0x1CB3C0 qmfc2/qmtc2 to vf2; 0x1CB3C4 vadd.xyz vf2, vf2, vf1; 0x1CB3CC sqc2 vf2, 0x4E0(sp)) -- `a + b` took field_B0's w
        ((float *)&v)[3] = ((const float *)&field_D0)[3];
        return v;
    }
};

class CB3VehiclePhysics : public CB3CollidingBody {
public:
    void UpdateCrashSteering(float lrTimeStep);

    unsigned char pad_220[0x820 - 0x220];
    UnkStruct_001CAD30_wheel field_820[4];
    unsigned char pad_B20[0xCC4 - 0xB20];
    UnkStruct_001CAD30_cc4 *field_CC4;
    CGtMatrix3x4 *field_CC8[4];
    unsigned char pad_CD8[0x1164 - 0xCD8];
    float field_1164;                 // [G] steering angle, degrees
    unsigned char pad_1168;
    signed char field_1169;           // [G] wheel count
};

// [G] degrees to radians
static inline float func_001CAD30_inl1(float d) { return 0.017453292f * d; }

// [G] the friction curve: sin(a) - sin(x) + (x - a) cos(b), with a named zero ahead (retail adda.s from $zero)
static inline float func_001CAD30_inl2(float x, float a, float b)
{
    float s = sinf(x);
    float sa = sinf(a);
    float c = cosf(b);
    return (sa - s) + (x - a) * c;
}

// 0x001CAD30
void CB3VehiclePhysics::UpdateCrashSteering(float lrTimeStep)
{
    float lrOne = 1.0f;
    CGtV3d lVel = field_B0;
    float lrLinearSpeed = ((float *)&lVel)[3];
    CGtMatrix3x4 lFrontWheelMatrix = *field_204;
    CGtMatrix3x4 lRotationMatrix;
    lRotationMatrix = CreateRotationMatrix3x4(CGtV3d(0.0f, lrOne, 0.0f), func_001CAD30_inl1(field_1164));
    lFrontWheelMatrix = lRotationMatrix * lFrontWheelMatrix;
    for (int lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        if (field_820[lnWheel].field_B3 == 0) continue;
        if (field_CC4->field_4AC[lnWheel] != 0) continue;
        field_820[lnWheel].field_5C = GtMath::Min(lrLinearSpeed / field_820[lnWheel].field_50, 999.0f);
        float lrWeightPerWheel = 0.25f * (20.0f * field_1F0);
        CGtV3d p = field_CC8[lnWheel]->mPos;
        p.SetY(field_820[lnWheel].field_74);
        CGtV3d lContact = LocalPointToWorldPoint(p);
        CGtV3d lPointVel = GetPointVelocity(lContact);
        CGtV3d lWheelAt;
        CGtV3d lWheelRight;
        if (lnWheel < 2) {
            lWheelAt = lFrontWheelMatrix.mAt;
            lWheelRight = lFrontWheelMatrix.mRight;
        } else {
            lWheelAt = field_204->mAt;
            lWheelRight = field_204->mRight;
        }
        float lrWheelLatSpeed = DotProduct(lWheelRight, lPointVel);
        float lrWheelFwdSpeed = DotProduct(lWheelAt, lPointVel);
        float lrTreadSpeed = field_820[lnWheel].field_5C * field_820[lnWheel].field_50;
        field_820[lnWheel].field_5C = GtMath::Min(lrWheelFwdSpeed / field_820[lnWheel].field_50, 999.0f);
        float lrSlipSpeedLong = lrWheelFwdSpeed - lrTreadSpeed;
        float lrSlipSpeed = sqrtf(lrWheelLatSpeed * lrWheelLatSpeed + lrSlipSpeedLong * lrSlipSpeedLong);
        if (lrTreadSpeed == 0.0f) lrTreadSpeed = 1e-06f;
        if (lrSlipSpeed == 0.0f) lrSlipSpeed = 1e-07f;
        float lrK;
        float lrDynamicCoeff;
        float lrStaticCoeff;
        if (lnWheel < 2) {
            lrK = 60.0f;
            lrDynamicCoeff = 2.3f;
            lrStaticCoeff = 150000.0f;
        } else {
            lrK = 12.0f;
            lrDynamicCoeff = 6.0f;
            lrStaticCoeff = 500000.0f;
            float s = lrLinearSpeed / 40.0f;
            if (s < 0.5f) s = 0.5f;
            if (s > lrOne) s = lrOne;
            lrStaticCoeff *= s;
            lrDynamicCoeff *= s;
        }
        float lrNorm = lrTreadSpeed * (lrWeightPerWheel * lrK);
        float lrHackGameTimestepFactor = 60.0f * D_0052267C.field_0;
        lrStaticCoeff /= lrHackGameTimestepFactor;
        lrDynamicCoeff /= lrHackGameTimestepFactor;
        float lrClamped = fabsf(lrStaticCoeff * lrSlipSpeed / lrNorm);
        if (lrClamped > lrOne) lrClamped = lrOne;
        float lrAngle = 0.4f - 0.8f * lrClamped;
        float lrE = func_001CAD30_inl2(-0.4f, 0.4f, -0.4f);
        float lrFactor = func_001CAD30_inl2(lrAngle, 0.4f, -0.4f) / lrE;
        float lrTotalForce = -(0.5f * (lrStaticCoeff * (lrSlipSpeed * ((lrAngle - -0.4f) / lrTreadSpeed))) + lrDynamicCoeff * (lrWeightPerWheel * lrFactor));
        float lrLatForceFromRoad = lrTotalForce * lrWheelLatSpeed / lrSlipSpeed;
        float lrLongForceFromRoad = lrTotalForce * lrSlipSpeedLong / lrSlipSpeed;
        CGtV3d lUp = field_204->mUp * 0.1f;
        ApplyPositionedForce(lUp + lContact, lWheelRight * lrLatForceFromRoad);
        ApplyPositionedForce(field_204->mPos + field_204->mUp * 0.1f, lWheelAt * lrLongForceFromRoad);
    }
}



