// NONMATCHING: CalculateCollisionImpulseWithTraffic__16CB3CollidingBodyFP17CB3TrafficVehicleQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dfPQ29GtMathPs26CGtV3d -- retail 313 / ours 259 instructions, 367 in changed runs
// draftAD C-first: half-extents (Max of min/-max per lane), box inverse inertia diag with traffic mass, Rt D R via two 3x3 products (local stand-ins), restitution impulse (two TransformVector + cross terms), n*-|j| out, returns j; calls identical; VU/FPU arithmetic equal except -Z (header vmulx.z vs retail vsub.z); residue = retail's CGtMatrix3x3 op= byte-copy loops (4) and frame
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm; Revenge STABS locals); call identical; per-mnemonic VU/FPU arithmetic equal except the Z negation form

// CB3CollidingBody::CalculateCollisionImpulseWithTraffic(CB3TrafficVehicle*, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d*) -- hand-written
// C-first draft (draftAD, 2026-10-31); the lifter refused it. [C] name: retail symbol table. Parameter / local names [L]: Revenge STABS
// CalculateCollisionImpulseWithTraffic__16CB4CollidingBody (lpTraffic, lPoint, lImpactVel, lCollisionNormal, lrRestitution,
// lpImpulseOut; lInvTrafficTensor, lrInertiaX/Y/Z, lrX/Y/ZPlaneSquared, lOrient, lOrientInv, lLocalTensor, lOutMatrix, lrImpVal).
// [L] reading: the traffic vehicle's inverse inertia tensor from this body's box half-extents (the larger of each min/max magnitude)
// and the traffic mass (field_168), rotated into the world by this body's orientation (Rt D R); then the restitution impulse of
// the pair along the normal (as BodyBodyResponse's), written out as n * -|j|; returns j.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);

struct UnkStruct_001AB120_box { CGtV3d field_0; CGtV3d field_10; };
class CB3TrafficVehicle {
public:
    unsigned char pad_0[0xA0];
    CGtV3d field_A0;            // position [G]
    unsigned char pad_B0[0xB8];
    float field_168;            // mass [G]
};
class CB3CollidingBody {
public:
    float CalculateCollisionImpulseWithTraffic(CB3TrafficVehicle * lpTraffic, CGtV3d lPoint, CGtV3d lImpactVel, CGtV3d lCollisionNormal,
                                               float lrRestitution, CGtV3d * lpImpulseOut);
    unsigned char pad_0[0x40];
    CGtV3d field_40[3];         // inverse inertia rows [G]
    unsigned char pad_70[0x160];
    UnkStruct_001AB120_box field_1D0;
    float field_1F0;            // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
};

// [L] N185 stand-in (header gap: CGtMatrix3x3::operator*(const CGtMatrix3x3&), queued): each row of a through b's rows (b in $vf4/$vf3/$vf2)
static inline CGtMatrix3x3 func_001AB120_inl2(const CGtMatrix3x3 & a, const CGtMatrix3x3 & b)
{
    CGtMatrix3x3 r;
    asm("qmtc2.ni %1, $vf4" "\n\t" "qmtc2.ni %4, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.ni %2, $vf3" "\n\t"
        "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.ni %3, $vf2" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1"
        : "=r"(r.mRight.mData) : "r"(b.mRight.mData), "r"(b.mUp.mData), "r"(b.mAt.mData), "r"(a.mRight.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t"
        "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(r.mUp.mData) : "r"(a.mUp.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t"
        "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(r.mAt.mData) : "r"(a.mAt.mData));
    return r;
}

// 0x001AB120
float CB3CollidingBody::CalculateCollisionImpulseWithTraffic(CB3TrafficVehicle * lpTraffic, CGtV3d lPoint, CGtV3d lImpactVel,
                                                             CGtV3d lCollisionNormal, float lrRestitution, CGtV3d * lpImpulseOut)
{
    // half-extents
    float lrX = GtMath::Max(field_1D0.field_0.X(), -field_1D0.field_10.X());
    float lrY = GtMath::Max(field_1D0.field_0.Y(), -field_1D0.field_10.Y());
    float lrZ = GtMath::Max(field_1D0.field_0.Z(), -field_1D0.field_10.Z());
    float lrZPlaneSquared = lrZ * lrZ;
    float lrYPlaneSquared = lrY * lrY;
    float lrXPlaneSquared = lrX * lrX;
    float lrInertiaX = 1.0f / (0.5f * (lpTraffic->field_168 * (lrYPlaneSquared + lrZPlaneSquared)));
    float lrInertiaY = 1.0f / (0.5f * (lpTraffic->field_168 * (lrXPlaneSquared + lrZPlaneSquared)));
    float lrInertiaZ = 1.0f / (0.5f * (lpTraffic->field_168 * (lrXPlaneSquared + lrYPlaneSquared)));

    CGtMatrix3x3 lLocalTensor;
    lLocalTensor.mRight.SetX(lrInertiaX);
    lLocalTensor.mRight.SetY(0.0f);
    lLocalTensor.mRight.SetZ(0.0f);
    lLocalTensor.mUp.SetX(0.0f);
    lLocalTensor.mUp.SetY(lrInertiaY);
    lLocalTensor.mUp.SetZ(0.0f);
    lLocalTensor.mAt.SetX(0.0f);
    lLocalTensor.mAt.SetY(0.0f);
    lLocalTensor.mAt.SetZ(lrInertiaZ);
    CGtMatrix3x3 lOrient;
    lOrient.mRight = field_204->mRight;
    lOrient.mUp = field_204->mUp;
    lOrient.mAt = field_204->mAt;
    CGtMatrix3x3 lOrientInv = lOrient;   // the transpose
    lOrientInv.mRight.SetY(lOrient.mUp.X());
    lOrientInv.mRight.SetZ(lOrient.mAt.X());
    lOrientInv.mUp.SetX(lOrient.mRight.Y());
    lOrientInv.mUp.SetZ(lOrient.mAt.Y());
    lOrientInv.mAt.SetX(lOrient.mRight.Z());
    lOrientInv.mAt.SetY(lOrient.mUp.Z());
    CGtMatrix3x3 lOutMatrix;
    lOutMatrix = func_001AB120_inl2(lOrientInv, lLocalTensor);
    lOutMatrix = func_001AB120_inl2(lOutMatrix, lOrient);
    CGtMatrix3x3 lInvTrafficTensor = lOutMatrix;

    // the impulse (as BodyBodyResponse)
    XAxisType lNum = DotProduct(lCollisionNormal, lImpactVel) * -(1.0f + lrRestitution);
    CGtV3d rT = lPoint - lpTraffic->field_A0;
    CGtV3d rB = lPoint - field_204->mPos;
    CGtV3d kB = CrossProduct(TransformVector(*(const CGtMatrix3x3*)(field_40), CrossProduct(rB, lCollisionNormal)), rB);
    CGtV3d kT = CrossProduct(TransformVector(*(const CGtMatrix3x3*)(&lInvTrafficTensor.mRight), CrossProduct(rT, lCollisionNormal)), rT);
    XAxisType lDen = DotProduct(kB + kT, lCollisionNormal) + (1.0f / field_1F0 + 1.0f / lpTraffic->field_168);
    float lrImpVal = (float)lNum / (float)lDen;
    *lpImpulseOut = lCollisionNormal * -fabsf(lrImpVal);
    return lrImpVal;
}
