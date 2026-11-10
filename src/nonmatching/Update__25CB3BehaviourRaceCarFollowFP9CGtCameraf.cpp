// NONMATCHING: Update__25CB3BehaviourRaceCarFollowFP9CGtCameraf -- retail 1405 / ours 1412 instructions, 1508 in changed runs
// draftL: 1405/1397, calls + block layout + VU/FPU op counts identical (mnemonic hunks 207/420); residue: CreateRotationMatrix3x4 rows built in memory (lqc2/sqc2) and its SinCos constants CSE'd into sq stack slots across the 4 copies (retail ori 7, ours 14), in-place VU Normalise of lCarAtXZ/lCamAtXZ (ours via GPR), RoundToNearest's 0.5 bits folded (retail sw/lw), frame 0x2BE0 vs 0x1B00 (N254/N255 dead slots) | N275 header APIs (gapK) | header operator* at 4 sites (gapL)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm with Revenge STABS locals: every call, branch, store and VU op accounted for (springs, frame-count rounding, pitch smoothing via ASinDeg, 4 CreateRotationMatrix3x4, yaw by AngleBetweenVectors, FOV interpolation, SetFromMatrix, <50 mph collision resolve; the length before it is dead in retail too)

// Update__25CB3BehaviourRaceCarFollowFP9CGtCameraf -- draftL (0x2E3440, 0x15F4) -- CB3BehaviourRaceCarFollow::Update(CGtCamera*, float)
// Written from the retail asm with Revenge STABS (B4BehaviourRaceCarFollow.cpp, CB4BehaviourRaceCarFollow::Update locals) as [L]
// structure: lCameraMatrix / lCarMatrix / lRotMatrix, lCarAtXZ / lCamAtXZ, speed factor, per-frame spring factors, ASinDeg, four
// inlined CreateRotationMatrix3x4, the FOV interpolation, SetFromMatrix into the camera. Types/fields [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_002E3440_attr { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; float field_30; };
struct UnkStruct_002E3440_body { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x144]; CGtMatrix3x4 * field_204; };
struct UnkStruct_002E3440_row { UnkStruct_002E3440_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_002E3440_gd { unsigned char pad_0[0x118C]; unsigned char field_118C[0x1634]; int field_27C0; };
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
extern UnkStruct_002E3440_gd * D_0064D388[];
extern signed char D_004E2910;
extern float D_004E1C88;   // 60 (frames per second)
extern float D_004E1C8C;   // 110 (FOV at full boost)
extern float D_004E1C90;   // 90 (base FOV)
extern float D_004E1C94;   // 2.3
extern float D_004E1C98;   // 50 (mph)
extern CGtV3d kAxisX;
extern CGtV3d kAxisY;

extern "C" float func_0011E340(float);          // [L] libm asinf (E_B3DEBUG wf_asin.o at the same address)
extern "C" float func_0011E388(float, float);   // [L] libm powf
extern "C" float tanf(float);
extern "C" float func_0030A970(void *);         // [L] DNAT call tree: CB3BoostEffectParams::GetCameraFOVInterpAmount() const
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *, UnkStruct_002E3440_cam *, float, int);

// [L] E map GtMath::ASinDeg(float) (B3O0PCH 0x312210, 0x38, emitted after CB3BehaviourRaceCarFollow::Prepare), as ACosDeg [G body].
static inline float func_002E3440_inl1(float x) { float r = 57.29578f * func_0011E340(x); return r; }
// [L] E map GtMath::RoundToNearest(float) (B3O0PCH 0x220290, 0x7C); Revenge STABS lSplitValue / lSplitHalf (USplitBits) [L].
static inline float func_002E3440_inl2(float x)
{
    GtMath::USplitBits lSplitValue(x);
    GtMath::USplitBits lSplitHalf(0.5f);
    lSplitHalf.mxBits |= lSplitValue.mxBits & 0x80000000;
    return (float)(int)(x + lSplitHalf.mrReal);
}
// [L] E map CB3CollidingBody::GetSpeedMPH() (0x155450): m/s (field_B0's w) * 2.236936 (as B3Score_001566F0).
static inline float func_002E3440_inl3(UnkStruct_002E3440_body * b) { float w = b->field_B0.W(); return 2.236936331f * w; }
// [G] stand-in: operator-(float, YAxisType) -> XAxisType (vsuby.x; the header has the X/W forms only).
static inline XAxisType func_002E3440_inl4(float f, YAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsuby.x %0, %1, %2y" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }

// [L] N185 stand-ins (as the Update__18CB3BehaviourRotate archive): compiler-chosen CGtV4d scalar setters.
static inline void func_002E3440_sx(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E3440_sy(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E3440_sz(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E3440_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.i %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// [L] N185: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with compiler-chosen SetX/Y/Z(float) and the vmulx.w SetW(float).
static inline void func_002E3440_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        float w = 0.5f * s;
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_002E3440_sw(q.mRot, w);
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
            func_002E3440_sx(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002E3440_sy(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002E3440_sz(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
static inline void func_002E3440_sfmp(CGtQuatPos &qp, const CGtMatrix3x4& m)
{
    func_002E3440_sfm(qp.mQuat, m);
    qp.mPos = m.mPos;
}

// [G] stand-in for CGtMatrix3x4::operator* (header body, N253): retail here keeps the basis R row (m.mRight) and this's row 0 on
// compiler-chosen VU registers (vf8/vf6), U/A in $vf3/$vf2 via qmtc2, rows 1-3 of this through $vf1 (0x2E3820.., 0x2E3A38.., 0x2E41A0..).
static inline CGtMatrix3x4 func_002E3440_inl5(const CGtMatrix3x4& a, const CGtMatrix3x4& m)
{
    CGtMatrix3x4 r;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.i %3, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, %2y" "\n\t" "qmtc2.i %4, $vf2" "\n\t" "vmaddz.xyz $vf1, $vf2, %2z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r.mRight.mData) : "j"(m.mRight.mData), "j"(a.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    asm("qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, %1, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "j"(m.mRight.mData), "r"(a.mUp.mData));
    asm("qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, %1, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "j"(m.mRight.mData), "r"(a.mAt.mData));
    asm("qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, %1, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r.mPos.mData) : "j"(m.mRight.mData), "r"(a.mPos.mData), "r"(m.mPos.mData));
    return r;
}
// 0x002E3440
extern "C" void Update__25CB3BehaviourRaceCarFollowFP9CGtCameraf(UnkStruct_002E3440 * self, UnkStruct_002E3440_cam * cam, float dt)
{
    CGtMatrix3x4 lCameraMatrix;
    CGtMatrix3x4 lCarMatrix;
    CGtMatrix3x4 lRotMatrix;
    CGtV3d lCarAtXZ;
    CGtV3d lCamAtXZ;
    UnkStruct_002E3440_gd * gd = D_0064D388[self->field_20];
    UnkStruct_002E3440_body * lpPhysics = D_0055EFEC[self->field_20].field_0;
    float lrSpeedFactor = 0.02f * func_002E3440_inl3(lpPhysics);
    lCarMatrix = *lpPhysics->field_204;
    if (lrSpeedFactor > 1.0f)
        lrSpeedFactor = 1.0f;
    float lrSpringX = (1.0f - self->field_8->field_20.X()) * lrSpeedFactor;
    float lrSpringY = (1.0f - self->field_8->field_20.Y());
    int lnNumFrames = (int)GtMath::RoundToNearest(D_004E1C88 * dt);
    if (D_004E2910) {
        lrSpringX = func_0011E388(lrSpringX, 1.2f);
        lrSpringY = func_0011E388(lrSpringY, 1.2f);
    }
    float lrSingleFrameX = 1.0f;
    float lrSingleFrameY = 1.0f;
    for (int i = 0; i < lnNumFrames; i++) {
        lrSingleFrameX *= lrSpringX;
        lrSingleFrameY *= lrSpringY;
    }
    lrSingleFrameX = 1.0f - lrSingleFrameX;
    lrSingleFrameY = 1.0f - lrSingleFrameY;
    if (self->field_26) {
        lCarMatrix.mAt = lCarMatrix.mAt * -1.0f;
        lCarMatrix.mRight = lCarMatrix.mRight * -1.0f;
    }
    CGtV3d lTarget = TransformPoint(lCarMatrix, self->field_8->field_10);
    lCameraMatrix.SetIdentity();
    lCameraMatrix.mPos = self->field_8->field_0;
    self->field_1C += lrSingleFrameX * (GtMath::ASinDeg(lCarMatrix.mAt.Y()) - self->field_1C);
    lCameraMatrix = lCameraMatrix * CreateRotationMatrix3x4(kAxisX, 0.017453292f * -self->field_1C);
    lRotMatrix = CreateRotationMatrix3x4(kAxisY, 0.017453292f * self->field_18);
    lCameraMatrix = lCameraMatrix * lRotMatrix;
    lCarAtXZ.SetX(lCarMatrix.mAt.X());
    lCarAtXZ.SetY(0.0f);
    lCarAtXZ.SetZ(lCarMatrix.mAt.Z());
    lCamAtXZ.SetX(lCameraMatrix.mAt.X());
    lCamAtXZ.SetY(0.0f);
    lCamAtXZ.SetZ(lCameraMatrix.mAt.Z());
    lCarAtXZ.Normalise();
    lCamAtXZ.Normalise();
    float lrClamped = GtMath::Min(GtMath::Max(DotProduct(lCarAtXZ, lCamAtXZ), -1.0f), 1.0f);
    float lrAngle = GtMath::ACosDeg(lrClamped);
    if (DotProduct(lCarMatrix.mAt, lCameraMatrix.mRight) < 0.0f)
        lrAngle *= -1.0f;
    lrAngle *= lrSingleFrameY;
    if (self->field_24)
        self->field_18 += lrAngle;
    lRotMatrix = CreateRotationMatrix3x4(kAxisY, 0.017453292f * lrAngle);
    lCameraMatrix = lCameraMatrix * lRotMatrix;
    lCameraMatrix.mPos += lTarget;
    lRotMatrix = CreateRotationMatrix3x4(kAxisX, 0.017453292f * self->field_8->field_30);
    lCameraMatrix = lRotMatrix * lCameraMatrix;
    float lrA = func_0030A970(gd->field_118C);
    float lrInterpolated = D_004E1C90 + lrA * (D_004E1C8C - D_004E1C90);
    cam->field_4 = lrInterpolated;
    float lrNewDistance = D_004E1C94 * (1.0f / tanf(0.017453292f * (lrInterpolated / 2.0f)));
    lrNewDistance = D_004E1C94 - lrNewDistance;
    lCameraMatrix.mPos += lCameraMatrix.mAt * lrNewDistance;
    func_002E3440_sfmp(cam->field_10, lCameraMatrix);
    if (func_002E3440_inl3(lpPhysics) < D_004E1C98) {
        (cam->field_10.mPos - lpPhysics->field_204->mPos).GetLength();
        CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(cam->field_30, cam, 5.0f, gd->field_27C0);
    }
}
