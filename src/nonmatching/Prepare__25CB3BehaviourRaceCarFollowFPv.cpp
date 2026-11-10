// NONMATCHING: Prepare__25CB3BehaviourRaceCarFollowFPv -- retail 1233 / ours 1232 instructions, 1040 in changed runs
// draftS: 1233/1232, calls + branch sequence (CFG) identical; residue: CreateRotationMatrix3x4 SinCos constants kept in s-regs/stack slots across the 3 copies in retail (ori 7 vs ours 14), SetFromMatrix stand-in VU register choice/schedule, mPos store order, frame 0x2890 vs 0x1750 (N254/N255)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm with Revenge STABS locals: every call (asinf, acosf), branch, store and VU op accounted for (yaw reset, pitch ASinDeg, 3 CreateRotationMatrix3x4, XZ angle via in-place Normalise + clamped ACosDeg, 2x SetFromMatrix, FOV 90, return true)

// Prepare__25CB3BehaviourRaceCarFollowFPv -- draftS (0x2E4A40, 0x1344) -- CB3BehaviourRaceCarFollow::Prepare(void*)
// Written from the retail asm with Revenge STABS (B4BehaviourRaceCarFollow.cpp, CB4BehaviourRaceCarFollow::Prepare locals) as [L]
// structure; class layout, .sdata constants and SetFromMatrix stand-in from the archived sibling Update (draftL). Prepare = Update
// without springs/FOV interpolation: yaw reset, pitch = ASinDeg(car at.y), three inlined CreateRotationMatrix3x4 (X by -pitch,
// Y by the XZ angle, X by the attrib tilt), SetFromMatrix into the camera twice [C: two identical inlined copies at 0x2E57D0 and
// 0x2E5A6C], FOV = D_004E1C90 (90), return true. lpData is the camera (same +0x4 FOV / +0x10 CGtQuatPos as Update) [L].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_002E3440_attr { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; float field_30; };
struct UnkStruct_002E3440_body { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x144]; CGtMatrix3x4 * field_204; };
struct UnkStruct_002E3440_row { UnkStruct_002E3440_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_002E3440_cam { unsigned char pad_0[0x4]; float field_4; unsigned char pad_8[0x8]; CGtQuatPos field_10; void * field_30; };
struct UnkStruct_002E3440 {
    unsigned char pad_0[0x8];
    UnkStruct_002E3440_attr * field_8;
    unsigned char pad_C[0xC];
    float field_18;
    float field_1C;
    int field_20;
    bool field_24;
    unsigned char field_25;
    bool field_26;
};
extern UnkStruct_002E3440_row D_0055EFEC[];
extern float D_004E1C90;   // 90 (base FOV)
extern CGtV3d kAxisX;
extern CGtV3d kAxisY;



// [L] N185 stand-ins (as the Update__18CB3BehaviourRotate archive): compiler-chosen CGtV4d scalar setters.
static inline void func_002E4A40_sx(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E4A40_sy(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E4A40_sz(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E4A40_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// [L] N185: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with compiler-chosen SetX/Y/Z(float) and the vmulx.w SetW(float).
static inline void func_002E4A40_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        float w = 0.5f * s;
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_002E4A40_sw(q.mRot, w);
    } else {
        int i;
        if (m.mUp.Y() > m.mRight.X()) {
            if (m.mAt.Z() > m.mUp.Y()) i = 2; else i = 1;
        } else {
            if (m.mAt.Z() > m.mRight.X()) i = 2; else i = 0;
        }
        switch (i) {
        case 0: {
            float s = GtMath::Sqrt(m.mRight.X() - (m.mUp.Y() + m.mAt.Z()) + 1.0f);
            func_002E4A40_sx(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002E4A40_sy(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002E4A40_sz(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
static inline void func_002E4A40_sfmp(CGtQuatPos &qp, const CGtMatrix3x4& m)
{
    func_002E4A40_sfm(qp.mQuat, m);
    qp.mPos = m.mPos;
}

// 0x002E4A40
extern "C" bool Prepare__25CB3BehaviourRaceCarFollowFPv(UnkStruct_002E3440 * self, void * lpData)
{
    CGtMatrix3x4 lCameraMatrix;
    CGtMatrix3x4 lCarMatrix;
    CGtMatrix3x4 lRotMatrix;
    CGtV3d lCarAtXZ;
    CGtV3d lCamAtXZ;
    UnkStruct_002E3440_cam * cam = (UnkStruct_002E3440_cam *)lpData;
    self->field_24 = true;
    lCarMatrix = *D_0055EFEC[self->field_20].field_0->field_204;
    if (self->field_26) {
        lCarMatrix.mAt = lCarMatrix.mAt * -1.0f;
        lCarMatrix.mRight = lCarMatrix.mRight * -1.0f;
    }
    CGtV3d lTarget = TransformPoint(lCarMatrix, self->field_8->field_10);
    lCameraMatrix.SetIdentity();
    lCameraMatrix.mPos = self->field_8->field_0;

    float lrPitch = GtMath::ASinDeg(lCarMatrix.mAt.Y());
    self->field_18 = 0.0f;
    self->field_1C = lrPitch;
    lCameraMatrix = lCameraMatrix * CreateRotationMatrix3x4(kAxisX, 0.017453292f * -self->field_1C);
    lCarAtXZ.SetX(lCarMatrix.mAt.X());
    lCarAtXZ.SetY(0.0f);
    lCarAtXZ.SetZ(lCarMatrix.mAt.Z());
    lCamAtXZ.SetX(lCameraMatrix.mAt.X());
    lCamAtXZ.SetY(0.0f);
    lCamAtXZ.SetZ(lCameraMatrix.mAt.Z());
    func_002EBED0_inl1(lCarAtXZ);
    func_002EBED0_inl1(lCamAtXZ);
    float lrClamped = GtMath::Min(GtMath::Max(DotProduct(lCarAtXZ, lCamAtXZ), -1.0f), 1.0f);
    float lrAngle = GtMath::ACosDeg(lrClamped);
    if (DotProduct(lCarMatrix.mAt, lCameraMatrix.mRight) < 0.0f)
        lrAngle *= -1.0f;
    if (self->field_24)
        self->field_18 += lrAngle;
    lRotMatrix = CreateRotationMatrix3x4(kAxisY, 0.017453292f * lrAngle);
    lCameraMatrix = lCameraMatrix * lRotMatrix;
    lCameraMatrix.mPos += lTarget;
    lRotMatrix = CreateRotationMatrix3x4(kAxisX, 0.017453292f * self->field_8->field_30);
    lCameraMatrix = lRotMatrix * lCameraMatrix;
    func_002E4A40_sfmp(cam->field_10, lCameraMatrix);
    func_002E4A40_sfmp(cam->field_10, lCameraMatrix);
    cam->field_4 = D_004E1C90;
    return true;
}


