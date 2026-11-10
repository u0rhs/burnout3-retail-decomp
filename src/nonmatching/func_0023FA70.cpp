// NONMATCHING: func_0023FA70 -- retail 762 / ours 786 instructions, 664 in changed runs
// draftAF C-first: = func_0023D410's blend set-up as a standalone helper of CB3NetworkCarPhysics::Update: inverse(current)*target, per-step delta, Slerp(identity, ., 1/n) with func_0023D410's QueryRotate/Slerp stand-ins. 786/762; calls identical (atan2f); VU op counts equal except vmove.xyzw 12/6 (header operator copies); lq/lqc2 class; frame 0x9B0 vs 0x11B0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] retail 0x23FA70..0x240654 has the structure of the block func_0023D410 inlines (0x23D7B0..0x23E364: same inverse/multiply, 1/n step, identity, 2.0-degree test, SinCos constants, three row Normalises; not compared line by line); op counts per kind equal except copies; Slerp body [L] per draftAE (RW 3.1 bamatrix.c)

// func_0023FA70 -- draftAF (0x23FA70, 0xBE8). Unnamed in every table, so the asm label with C linkage. Called three times by
// CB3NetworkCarPhysics::Update (0x268DCC: n = field_1A80 = 10, the body's current matrix field_204, a target matrix +0x19B0,
// out +0x1A40, a delta vector). [L] the blend set-up func_0023D410 inlines for traffic records (same code, retail 0x23D7B0 ..
// 0x23E364 vs 0x23FA70 .. 0x240654): the offset inverse(current) * target, the per-step position delta (target - current) / n,
// and the per-step rotation interpolated from the identity over n steps (GtMathPs2::Slerp, inlined).
// The Slerp / QueryRotate / QueryRotateDegenerateUnitAxis stand-ins are func_0023D410's archive's (header gap already queued
// by draftAE), renamed. Types [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
#pragma inline_depth(10)   // [G] N262/N182 (as func_0023D410)

extern "C" float func_0011E358(float, float);
// [G] GtMathPs2::operator -(XAxisType, float) (B3O0PCH 0x131C90, 0x50; header gap already queued, ApplyDrivingForces): the scalar
// moved into a VU register, `vsubx.x D, a, Sx` (retail 0x23D908)
static inline XAxisType func_0023FA70_subxf(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }   // [L] libm atan2f (E_B3DEBUG wf_atan2.o at the same address)

static inline void func_0023FA70_qrd(const CGtMatrix3x4 & m, CGtV3d * lpUnitAxis)
{
    CGtV3d lTwoSinThetaAxis;
    if (m.mRight.X() > m.mUp.Y()) {
        if (m.mRight.X() > m.mAt.Z()) {
            lTwoSinThetaAxis.SetX(m.mRight.X() + 1.0f);
            lTwoSinThetaAxis.SetX(lTwoSinThetaAxis.X() + lTwoSinThetaAxis.X());
            lTwoSinThetaAxis.SetY(m.mRight.Y() + m.mUp.X());
            lTwoSinThetaAxis.SetZ(m.mRight.Z() + m.mAt.X());
        } else {
            lTwoSinThetaAxis.SetZ(m.mAt.Z() + 1.0f);
            lTwoSinThetaAxis.SetZ(lTwoSinThetaAxis.Z() + lTwoSinThetaAxis.Z());
            lTwoSinThetaAxis.SetX(m.mAt.X() + m.mRight.Z());
            lTwoSinThetaAxis.SetY(m.mAt.Y() + m.mUp.Z());
        }
    } else {
        if (m.mUp.Y() > m.mAt.Z()) {
            lTwoSinThetaAxis.SetY(m.mUp.Y() + 1.0f);
            lTwoSinThetaAxis.SetY(lTwoSinThetaAxis.Y() + lTwoSinThetaAxis.Y());
            lTwoSinThetaAxis.SetZ(m.mUp.Z() + m.mAt.Y());
            lTwoSinThetaAxis.SetX(m.mUp.X() + m.mRight.Y());
        } else {
            lTwoSinThetaAxis.SetZ(m.mAt.Z() + 1.0f);
            lTwoSinThetaAxis.SetZ(lTwoSinThetaAxis.Z() + lTwoSinThetaAxis.Z());
            lTwoSinThetaAxis.SetX(m.mAt.X() + m.mRight.Z());
            lTwoSinThetaAxis.SetY(m.mAt.Y() + m.mUp.Z());
        }
    }
    lTwoSinThetaAxis.Normalise();
    *lpUnitAxis = lTwoSinThetaAxis;
}

static inline void func_0023FA70_qr(const CGtMatrix3x4 & m, CGtV3d * lpUnitAxis, float * lpAngle, CGtV3d * lpCentre)
{
    float lrTwoCosTheta = func_0023FA70_subxf(m.mRight.X() + m.mUp.Y() + m.mAt.Z(), 1.0f);
    CGtV3d lTwoSinThetaAxis;
    lTwoSinThetaAxis.SetX(m.mUp.Z() - m.mAt.Y());
    lTwoSinThetaAxis.SetY(m.mAt.X() - m.mRight.Z());
    lTwoSinThetaAxis.SetZ(m.mRight.Y() - m.mUp.X());
    float lrTwoSinTheta = lTwoSinThetaAxis.GetLength();
    if (lrTwoSinTheta > 0.0f) {
        *lpUnitAxis = lTwoSinThetaAxis * (1.0f / lrTwoSinTheta);
    } else {
        lpUnitAxis->Zero();
    }
    *lpAngle = 57.29578f * func_0011E358(lrTwoSinTheta, lrTwoCosTheta);
    if (lrTwoSinTheta <= 0.01f && lrTwoCosTheta <= 0.0f) {
        func_0023FA70_qrd(m, lpUnitAxis);
    }
    CGtMatrix3x4 lISubMat;
    lISubMat.SetIdentity();
    lISubMat.mRight -= m.mRight;
    lISubMat.mUp -= m.mUp;
    lISubMat.mAt -= m.mAt;
    CGtMatrix3x4 lISubMatInverse = lISubMat;
    lISubMatInverse.Invert();
    *lpCentre = lISubMatInverse.mPos;
    *lpCentre += lISubMatInverse.mRight * m.mPos.X();
    *lpCentre += lISubMatInverse.mUp * m.mPos.Y();
    *lpCentre += lISubMatInverse.mAt * m.mPos.Z();
}

static inline CGtMatrix3x4 func_0023FA70_slrp(const CGtMatrix3x4 & a, const CGtMatrix3x4 & b, float t, float * lpAngle)
{
    CGtMatrix3x4 lResult;
    if (t <= 0.0f) {
        lResult = a;
    } else if (t >= 1.0f) {
        lResult = b;
    } else {
        CGtMatrix3x4 lInv = a;
        lInv.Invert();
        CGtMatrix3x4 lDelta;
        lDelta = lInv * b;
        CGtV3d lAxis;
        CGtV3d lCentre;
        func_0023FA70_qr(lDelta, &lAxis, lpAngle, &lCentre);
        if (*lpAngle < 2.0f) {
            lResult.mRight = a.mRight + (b.mRight - a.mRight) * t;
            lResult.mUp = a.mUp + (b.mUp - a.mUp) * t;
            lResult.mAt = a.mAt + (b.mAt - a.mAt) * t;
            lResult.mPos = a.mPos + (b.mPos - a.mPos) * t;
            lResult.mRight.Normalise();
            lResult.mUp.Normalise();
            lResult.mAt.Normalise();
        } else {
            lResult = a;
            lResult.mPos.Set(0.0f, 0.0f, 0.0f);
            lResult = lResult * CreateRotationMatrix3x4(lAxis, 0.017453292f * (*lpAngle * t));
            lResult.mPos = (b.mPos - a.mPos) * t + a.mPos;
        }
    }
    return lResult;
}

// 0x0023FA70
extern "C" void func_0023FA70(int n, const CGtMatrix3x4 * lpCurrent, const CGtMatrix3x4 * lpTarget, CGtMatrix3x4 * lpRot, CGtV3d * lpDelta)
{
    CGtMatrix3x4 lInv = *lpCurrent;
    lInv.Invert();
    *lpRot = lInv * *lpTarget;
    float lrStep = 1.0f / (float)n;
    CGtMatrix3x4 lIdentity;
    lIdentity.SetIdentity();
    *lpDelta = (lpTarget->mPos - lpCurrent->mPos) * lrStep;
    float lrAngle;
    *lpRot = func_0023FA70_slrp(lIdentity, *lpRot, lrStep, &lrAngle);
}
