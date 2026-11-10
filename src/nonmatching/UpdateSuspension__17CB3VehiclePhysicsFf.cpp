// NONMATCHING: UpdateSuspension__17CB3VehiclePhysicsFf -- retail 1180 / ours 1149 instructions, 934 in changed runs
// draftK: logic complete, calls identical (fabsf x3, Impact); residue: retail hoists every loop-1 float constant (0.25/0.75/0.12/0.001/1.2/0.5/-1 into f23-f30, 2.0/2000/-3/4/0.1 spilled to sp+0xFC..0x10C) where b119p reloads them per use and hoists 1.2*dt instead; retail recomputes &field_820[i] (sll/addu) per block, ours keeps it in s0; lScalingMat built in memory and passed through GPRs (ours vmove); frame 0x470 vs 0x990 (retail keeps op* result copies at sp+0x1F0/0x730, inline temporaries)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] behaviour-equivalent: every branch, call, store and VU op decoded from retail asm; airborne clamp store unconditional as retail (bc1t to the next instruction, 0x1CD5F0)

// CB3VehiclePhysics::UpdateSuspension(float) -- hand-written by draftK from the retail asm + Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G] (instruction widths).
// Locals named after Revenge's CB4VehiclePhysics::UpdateSuspension STABS where the role is clear [L] (Physics: hint only).
// Per wheel (count field_1169): airborne -> spring the wheel down towards 0.75 of its travel; grounded -> spring + damper force
// along the contact normal (ApplyPositionedForce), bottoming-out impulse (point velocity, inverse inertia at +0x40) with a
// deformation Impact above 2000, kerb force; then the averaged constraint push, the impulses, and the wheel matrices
// (steer, spin, a 20-degree loose rotation for wheel state 2, the wheel scale).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);
extern "C" float sqrtf(float);
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    void *, void *, void *, void *, unsigned long, int, int, int, const CGtV3d &, const CGtV3d &, int, float);
extern unsigned char D_00665ECE;   // [G] a gGraphicsManager byte (0x665EC0 + 0xE)

struct UnkStruct_001CC900_cc4 {      // [G]
    unsigned char pad_0[0x300];
    unsigned char field_300[0x1AC];   // CB3VehicleDeform (Impact's this) [L]
    signed char field_4AC[4];
    unsigned char pad_4B0[0x38];
    float field_4E8[4];
    unsigned char pad_4F8[0x101B - 0x4F8];
    unsigned char field_101B;
};
struct UnkStruct_001CC900_13F4 { unsigned char pad_0[0x1960]; unsigned long field_1960; };
struct UnkStruct_001CC900_wheel {    // [G] 0xC0 stride, base veh+0x820
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    unsigned char pad_30[0x28];
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    unsigned char pad_68[4];
    float field_6C;
    float field_70;
    float field_74;
    int field_78;
    unsigned char pad_7C[0x36];
    unsigned char field_B2;
    unsigned char field_B3;
    unsigned char field_B4;
    unsigned char pad_B5[0xB];
};

// [L] base class: Revenge's inlined CB4CollidingBody methods run on the vehicle's own `this` register (STABS).
class CB3CollidingBody {
public:
    unsigned char pad_0[0x40];
    CGtMatrix3x4 field_40;            // [G] inverse inertia (rows 0x40/0x50/0x60 used)
    unsigned char pad_80[0x30];
    CGtV3d field_B0;                  // [G] linear velocity, w = speed
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                  // [G] angular velocity
    unsigned char pad_E0[0x10];
    CGtV3d field_F0;
    CGtV3d field_100;
    CGtV3d field_110;
    CGtV3d field_120;
    CGtV3d field_130;
    unsigned char pad_140[0xB0];
    float field_1F0;                  // [G] mass
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[4];
    signed char field_215;
    unsigned char pad_216[0xA];

    // [L] E map names (B3O0PCH: CB3CollidingBody::ApplyPositionedForce/ApplyPositionedImpulse(CGtV3d, CGtV3d),
    // GetPointVelocity(CGtV3d)); bodies [G] from retail's inlined copies here.
    void ApplyPositionedForce(CGtV3d force, CGtV3d pos) {
        field_F0 += force;
        field_100 += CrossProduct(pos - field_204->mPos, force);
    }
    void ApplyPositionedImpulse(CGtV3d imp, CGtV3d pos) {
        field_110 += imp;
        field_120 += CrossProduct(pos - field_204->mPos, imp);
    }
    CGtV3d LocalPointToWorldPoint(CGtV3d p) { return TransformPoint(*field_204, p); }
    CGtV3d GetPointVelocity(CGtV3d pos) {
        return CrossProduct(field_D0, pos - field_204->mPos) + field_B0;
    }
};

class CB3VehiclePhysics : public CB3CollidingBody {
public:
    void UpdateSuspension(float lrTimeStep);

    unsigned char pad_220[0x820 - 0x220];
    UnkStruct_001CC900_wheel field_820[4];
    unsigned char pad_B20[0xCA4 - 0xB20];
    float field_CA4;
    float field_CA8;
    float field_CAC;
    unsigned char pad_CB0[4];
    float field_CB4;
    float field_CB8;
    float field_CBC;
    void *field_CC0;
    UnkStruct_001CC900_cc4 *field_CC4;
    CGtMatrix3x4 *field_CC8[4];
    unsigned char pad_CD8[0x1164 - 0xCD8];
    float field_1164;
    unsigned char pad_1168;
    signed char field_1169;
    unsigned char pad_116A;
    unsigned char field_116B;
    unsigned char pad_116C[0x13F4 - 0x116C];
    UnkStruct_001CC900_13F4 *field_13F4;
};

// [G] degrees to radians
static inline float func_001CC900_inl1(float d) { return 0.017453292f * d; }
// [G] scalar sine: odd Taylor polynomial to x^13 (the GtMathPs2Quat.h Slerp form)
static inline float func_001CC900_inl2(float x)
{
    float x2 = x * x;
    return x + x2 * x * (-0.1666666716f + x2 * (0.008333333768f + x2 * (-0.0001984127011f + x2 * (2.75573143e-06f + x2 * (-2.505075969e-08f + 1.589691018e-10f * x2)))));
}
// [G] (unsigned)(t - 1) < 3
static inline bool func_001CC900_inl3(signed char t) { return (unsigned int)(t - 1) < 3; }

// [L] an inlined CB3VehiclePhysics method taking the wheel index (Revenge STABS: `this`, `lnWheelIndex`, then an inlined
// CB4CollidingBody point transform -- E map CB3CollidingBody::LocalPointToWorldPoint(CGtV3d)): the wheel's attach point in world space.
static inline void func_001CC900_inl4(CB3VehiclePhysics *self, int lnWheelIndex)
{
    CGtV3d p = self->field_CC8[lnWheelIndex]->mPos;
    p.SetY(self->field_820[lnWheelIndex].field_60);
    self->field_820[lnWheelIndex].field_0 = self->LocalPointToWorldPoint(p);
}

// 0x001CC900
void CB3VehiclePhysics::UpdateSuspension(float lrTimeStep)
{
    int lnNumImpulses = 0;
    int lnNumConstraints = 0;
    CGtV3d lConstrain(0.0f, 0.0f, 0.0f);
    CGtV3d lAxis(0.0f, 0.0f, 1.0f);
    float lrLooseAngle = 20.0f;
    CGtV3d *lpUpVec = &field_204->mUp;
    CGtV3d laImpulse[4];
    int lnWheel;
    for (lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        field_820[lnWheel].field_B2 = 0;
        field_820[lnWheel].field_B4 = 0;
        if (field_CC4->field_4AC[lnWheel] == 3) continue;
        float lrAttachHeight = field_820[lnWheel].field_74;
        float lrSusSpringConstant;
        float lrSusSpringDamp;
        float lrSusSpringLength;
        if (lnWheel < 2) {
            lrSusSpringConstant = field_CA8;
            lrSusSpringDamp = field_CA4;
            lrSusSpringLength = field_CAC;
        } else {
            lrSusSpringLength = field_CBC;
            lrSusSpringConstant = field_CB8;
            lrSusSpringDamp = field_CB4;
        }
        if (field_820[lnWheel].field_B3 != 0) {
            field_820[lnWheel].field_B2 = 0;
            bool lbBump = false;
            if (field_820[lnWheel].field_64 - field_820[lnWheel].field_60 > 0.12f) field_820[lnWheel].field_B2 = 1;
            float lrPenetration = lrAttachHeight - field_820[lnWheel].field_64;
            if (lrPenetration < 0.25f * lrSusSpringLength) {
                float lrMin = 0.25f * lrSusSpringLength;
                field_820[lnWheel].field_64 = lrAttachHeight - lrMin;
                float lrKerbed = lrMin - lrPenetration;
                CGtV3d v = field_B0;
                lrPenetration = lrMin;
                if (((float *)&v)[3] > 1.0f || field_210 == 0) lbBump = true;
                if (lrKerbed > 0.001f) {
                    lConstrain += field_820[lnWheel].field_20 * lrKerbed;
                    lnNumConstraints++;
                }
            } else if (field_210 != 0 && lrPenetration > 0.75f * lrSusSpringLength) {
                lrPenetration = 0.75f * lrSusSpringLength;
            }
            float lrDampVel;
            if (D_00665ECE != 0) {
                lrDampVel = (field_820[lnWheel].field_64 - field_820[lnWheel].field_60) / (1.2f * lrTimeStep);
            } else {
                lrDampVel = (field_820[lnWheel].field_64 - field_820[lnWheel].field_60) / lrTimeStep;
            }
            field_820[lnWheel].field_60 = field_820[lnWheel].field_64;
            float lrSpringForce = lrSusSpringDamp * lrDampVel + -lrSusSpringConstant * (lrPenetration - lrSusSpringLength);
            func_001CC900_inl4(this, lnWheel);
            CGtV3d lTemp = field_820[lnWheel].field_20 * lrSpringForce;
            if (field_210 != 0) {
                float r = lrPenetration / (0.75f * lrSusSpringLength);
                if (r > 0.5f) lTemp = lTemp * (2.0f * (1.0f - r));
            }
            ApplyPositionedForce(lTemp, field_820[lnWheel].field_0);
            field_820[lnWheel].field_B4 = 0;
            if (lbBump) {
                CGtV3d pv = GetPointVelocity(field_820[lnWheel].field_0);
                CGtV3d n = *lpUpVec;
                float num = DotProduct(n, pv) * -1.0f;
                CGtV3d r = field_820[lnWheel].field_0 - field_204->mPos;
                float den = DotProduct(CrossProduct(TransformVector(field_40, CrossProduct(r, n)), r), n) + 1.0f / field_1F0;
                float lrImp = num / den;
                laImpulse[lnWheel] = n * fabsf(lrImp);
                if (lrImp > 0.0f) {
                    field_820[lnWheel].field_B4 = 1;
                    lnNumImpulses++;
                    if (field_210 != 0 && field_215 == 1 && lnWheel < 2 && lrImp > 2000.0f) {
                        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
                            field_CC4->field_300, this, field_CC0, field_CC4, field_13F4->field_1960, 1, 2, 2, field_820[lnWheel].field_0, field_820[lnWheel].field_20, 0, 0.5f * lrImp);
                    }
                }
            }
            bool b = func_001CC900_inl3(field_215);
            if (field_210 == 0) continue;
            if (field_116B != 0) continue;
            field_820[lnWheel].field_78 = 5;
            CGtV3d vel = field_B0;
            if (!(((float *)&vel)[3] > 0.1f)) continue;
            CGtV3d dir = CrossProduct(field_D0, field_820[lnWheel].field_10 - field_204->mPos) + vel;
            dir.Normalise();
            float a = fabsf(DotProduct(dir, field_204->mRight));
            CGtV3d lFriction = dir * ((float)field_1169 * ((1.0f + a) * (-3.0f * field_1F0)) / 4.0f);
            if (!b && field_CC4->field_101B == 0) lFriction = lFriction * 0.5f;
            ApplyPositionedForce(lFriction, field_820[lnWheel].field_10);
        } else {
            float lrSpringPush = 0.75f * lrSusSpringLength;
            float lrSpringExtension = lrAttachHeight - lrSpringPush;
            float k = GtMath::Min(GtMath::Max(1.0f - lrSusSpringLength / (lrAttachHeight - lrSpringExtension), 0.0f), 1.0f);
            field_820[lnWheel].field_60 = lrSpringExtension - lrSusSpringConstant * k * lrTimeStep * lrTimeStep * lrTimeStep;
            float d = lrAttachHeight - field_820[lnWheel].field_60;
            if (d < 0.25f * lrSusSpringLength) {
                field_820[lnWheel].field_60 = lrAttachHeight - 0.25f * lrSusSpringLength;
            } else {
                field_820[lnWheel].field_60 = lrSpringExtension;
            }
            func_001CC900_inl4(this, lnWheel);
        }
    }
    if (lnNumConstraints > 0) {
        field_130 += lConstrain * (1.0f / (float)lnNumConstraints);
    }
    if (lnNumImpulses > 0) {
        field_110 -= field_204->mUp * DotProduct(field_110, field_204->mUp);
    }
    if (lnNumImpulses > 0) {
        float lrRecip = 1.0f / (float)lnNumImpulses;
        for (lnWheel = 0; lnWheel < 4; lnWheel++) {
            if (field_820[lnWheel].field_B4 != 0) {
                laImpulse[lnWheel] = laImpulse[lnWheel] * lrRecip;
                ApplyPositionedImpulse(laImpulse[lnWheel], field_820[lnWheel].field_0);
            }
        }
    }
    float x = func_001CC900_inl1(-field_1164);
    float lrSinSteerAngle = func_001CC900_inl2(x);
    float lrCosSteerAngle = sqrtf(GtMath::Max(0.0f, 1.0f - lrSinSteerAngle * lrSinSteerAngle));
    float lrLooseRadians = func_001CC900_inl1(lrLooseAngle);
    for (lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        if (field_CC4->field_4AC[lnWheel] == 3) continue;
        bool b2 = func_001CC900_inl3(field_215);
        if (field_210 != 0 || !b2) {
            field_820[lnWheel].field_5C *= 0.99f;
            if (field_820[lnWheel].field_B3 != 0) field_820[lnWheel].field_5C *= 0.8f;
        }
        field_820[lnWheel].field_58 += field_820[lnWheel].field_5C * lrTimeStep;
        if (field_820[lnWheel].field_58 > 628.31854f) {
            field_820[lnWheel].field_58 = field_820[lnWheel].field_58 - 628.31854f;
        } else if (field_820[lnWheel].field_58 < -628.31854f) {
            field_820[lnWheel].field_58 += 628.31854f;
        }
        float lrAngle = field_820[lnWheel].field_58 - 6.2831855f * (float)(int)(0.15915494f * field_820[lnWheel].field_58);
        if (lrAngle > 3.1415927f) lrAngle -= 6.2831855f;
        float sn = func_001CC900_inl2(lrAngle);
        float cs = sqrtf(GtMath::Max(0.0f, 1.0f - sn * sn));
        if (fabsf(lrAngle) > 1.5707964f) cs *= -1.0f;
        float s, c;
        if (lnWheel < 2) {
            s = lrSinSteerAngle;
            c = lrCosSteerAngle;
        } else {
            s = 0.0f;
            c = 1.0f;
        }
        CGtMatrix3x4 *m = field_CC8[lnWheel];
        CGtV3d lScale;
        if (lnWheel & 1) {
            lScale.Set(field_820[lnWheel].field_70, field_820[lnWheel].field_6C, -field_820[lnWheel].field_6C);
        } else {
            lScale.Set(field_820[lnWheel].field_70, field_820[lnWheel].field_6C, field_820[lnWheel].field_6C);
        }
        m->mRight.Set(c, 0.0f, s);
        m->mUp.Set(-s * sn, cs, sn * c);
        m->mAt.Set(-s * cs, -sn, cs * c);
        m->mPos.SetY(field_820[lnWheel].field_60);
        if (field_CC4->field_4AC[lnWheel] == 2) {
            *m = CreateRotationMatrix3x4(lAxis, lrLooseRadians) * *m;
        }
        CGtMatrix3x4 lScalingMat;
        lScalingMat.SetIdentity();
        lScalingMat.mRight.SetX(lScale.X());
        lScalingMat.mUp.SetY(lScale.Y());
        lScalingMat.mAt.SetZ(lScale.Z());
        *m = lScalingMat * *m;
        field_CC4->field_4E8[lnWheel] = field_820[lnWheel].field_5C;
    }
}
