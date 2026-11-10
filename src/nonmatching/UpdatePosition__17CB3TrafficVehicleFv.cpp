// NONMATCHING: UpdatePosition__17CB3TrafficVehicleFv -- retail 706 / ours 711 instructions, 327 in changed runs
// draftAD C-first: interpolator pull (speed modifier, clamped move), amortised direction, rate-limited steering sine + cos rotation of mAt, axle moves, cat 8/9 segment centring, matrix rebuild with zero fallbacks (IsEffectivelyZero/NormaliseGetLength/CrossProduct), wheel spin wrap, roll/pitch springs; calls identical, all VU/FPU arithmetic op counts equal; residue = branch layout (beq/bc1t/bc1f), one swc1, frame 0x2E0 vs 0x450
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm read end to end; Revenge STABS locals); call sequence identical; per-mnemonic counts equal for all VU and FPU arithmetic

// CB3TrafficVehicle::UpdatePosition() -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. Local names [L]: Revenge STABS UpdatePosition__17CB4TrafficVehicle (lpParamPos,
// lDiff, lNewDirection, lAmortizedInterpolatorDirection, lrDistanceFromInterpolator, lrDistanceToMove, lrSinTheta, lrSteeringDiff,
// lrSpeedModifier, lrDirectionChange, lrDP, lrAcrossSpeed, lrTimeStep; tools/stabs_lookup.py). Layout as the InitalisePosition
// archive and the proven CB3TrafficVehicle sources; field names placeholders, types [G].
// [L] reading: the interpolator point (lane param position + up * height) pulls the front axle: speed modified by how far ahead it is,
// the move clamped to the distance; the heading turns toward it through a rate-limited steering sine (field_130), the front axle
// moves along the turned heading, the rear one follows; special categories 8/9 snap both axles to the segment centre; the matrix
// is rebuilt from the axles (zero-length fallbacks); wheel spin (field_128, wrapped at +-200 pi) and the body roll/pitch springs
// (field_BC/field_C0, field_B4/field_B8) are updated.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3TrafficLane;
class CB3TrafficVehicle;
class CB3TrafficAxle {
public:
    int AdjustAxleHeight(CB3TrafficLane *, int);
    void MoveToSegmentCentre(CGtV3d p);
    CGtV3dPlus field_0;     // position
    CGtV3d field_10;        // ground normal [G]
    unsigned char pad_20[0x10];
};
struct UnkStruct_00172E40_rec { CGtMatrix3x4 field_0; CGtV3d field_40; };   // [G] the lane param position record (0x50)
struct UnkStruct_00172E40_d {   // [G] per-type data
    unsigned char pad_0[0x18];
    float field_18;
    unsigned char pad_1C[0xC];
    float field_28;
    unsigned char pad_2C[0x1D];
    unsigned char field_49;
};
struct UnkStruct_00172E40_b0 { unsigned char pad_0[0xD]; signed char field_D; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x34210]; UnkStruct_00172E40_rec field_34210[1]; };
extern UnkStruct_D_00522660 D_00522660;
extern float D_0052267C[];   // [L] lrTimeStep
extern float D_004E0978;     // 0.95
extern float D_004E0B18;     // 0.03
extern float D_004E1038;     // 0.1
extern float D_004E1170;     // 0.01
extern float D_004E125C;     // -0.03
extern float D_004E1260;     // -0.01
extern float D_004E1264;     // 628.31854 (200 pi)
extern float D_004E1268;     // -628.31854
extern float D_004E126C;     // -0.05
extern float D_004E1270;     // 0.9

class CB3TrafficVehicle {
public:
    void UpdatePosition();

    CB3TrafficAxle field_0;
    CB3TrafficAxle field_30;
    CGtV3d field_60;           // interpolator point
    CGtMatrix3x4 field_70;
    UnkStruct_00172E40_b0 * field_B0;
    float field_B4;            // pitch spring sine [G]
    float field_B8;
    float field_BC;            // roll spring sine [G]
    float field_C0;
    float field_C4;            // speed
    unsigned char pad_C8[0x4C];
    UnkStruct_00172E40_d * field_114;
    unsigned char pad_118[0x8];
    float field_120;           // wheel radius / height [G]
    float field_124;
    float field_128;           // wheel spin
    unsigned char pad_12C[0x4];
    float field_130;           // steering sine
    unsigned char pad_134[0x18];
    float field_14C;
    float field_150;           // axle offsets
    float field_154;
    float field_158;
    float field_15C;           // spring limit
    unsigned char pad_160[0x13];
    signed char field_173;     // category
    unsigned char field_174;   // flags
};

// [G] a zero-safe in-place normalise with a fallback lane (inlined 5 times, as InitalisePosition's)
static inline void func_00172E40_inl1(CGtV3d & v)
{
    if (v.IsEffectivelyZero()) {
        v.SetZ(1.0f);
    } else if (v.NormaliseGetLength() == 0.0f) {
        v.SetZ(1.0f);
    }
}

// 0x00172E40
void CB3TrafficVehicle::UpdatePosition()
{
    UnkStruct_00172E40_rec * lpParamPos = &D_00522660.field_34210[field_114->field_49];
    CGtV3d lOldPos = CGtV3d(field_0.field_0.mData);
    field_60 = lpParamPos->field_40;
    field_60 += field_70.mUp * field_120;
    CGtV3d lDiff = field_60 - lOldPos;
    ((float *)&lDiff)[3] = ((const float *)&lOldPos)[3]; // [C] 0x172EC0 qmtc2 a2, vf3 (lOldPos); 0x172EC4 vsub.xyz vf3, vf2, vf3 keeps
    // its w; 0x172ED4 sqc2 vf3, 0x420(sp) -- `a - b` took field_60's w
    float lrDistanceFromInterpolator = lDiff.GetLength();
    float lrAcrossSpeed = DotProduct(lDiff, lpParamPos->field_0.mRight) * field_114->field_28;
    float lrDP = DotProduct(lDiff, lpParamPos->field_0.mAt);
    float lrSpeedModifier;
    if (lrDP < 0.0f) {
        lDiff = lpParamPos->field_0.mAt * -lrDP;
        lrSpeedModifier = D_004E1038 * (lrDP - 1.0f) + 2.0f * lrDP;
    } else {
        lrSpeedModifier = D_004E1038 * (lrDP - 1.0f);
    }
    float lrTimeStep = D_0052267C[0];
    float lrDistanceToMove = (field_C4 + lrSpeedModifier) * lrTimeStep;
    if (!(lrDistanceToMove <= lrDistanceFromInterpolator)) lrDistanceToMove = lrDistanceFromInterpolator;
    if (lrDistanceToMove < 0.0f) lrDistanceToMove = 0.0f;

    float k;
    if (lrAcrossSpeed <= 0.0f) k = 1.0f / (2.0f * field_124);
    else k = 2.0f;
    CGtV3d lNewDirection;
    if (lrDistanceToMove * field_C4 < 225.0f * lrTimeStep)
        lNewDirection = lpParamPos->field_0.mAt * (k * (10.0f * (225.0f * lrTimeStep)));
    else
        lNewDirection = lpParamPos->field_0.mAt * (k * (10.0f * (lrDistanceToMove * field_C4)));
    CGtV3d lAmortizedInterpolatorDirection = lDiff + lNewDirection;
    func_00172E40_inl1(lAmortizedInterpolatorDirection);

    // steering: the sine of the angle to the target, rate-limited
    CGtV3d lCross = CrossProduct(lAmortizedInterpolatorDirection, field_70.mAt);
    float lrSinTheta;
    if (lCross.Y() > 0.0f) lrSinTheta = lCross.GetLength();
    else lrSinTheta = -lCross.GetLength();
    float s = field_130;
    float lrSteeringDiff = lrSinTheta - s;
    if (s > 0.0f) {
        if (!(lrSteeringDiff <= D_004E1170)) lrSinTheta = D_004E1170 + s;
        if (lrSteeringDiff < D_004E125C) lrSinTheta = s - D_004E0B18;
    } else {
        if (!(lrSteeringDiff <= D_004E0B18)) lrSinTheta = D_004E0B18 + s;
        if (lrSteeringDiff < D_004E1260) lrSinTheta = s - D_004E1170;
    }
    field_130 = lrSinTheta;
    float c = 1.0f;
    c -= lrSinTheta * lrSinTheta;
    float lrCos = GtMath::Sqrt(c);
    lAmortizedInterpolatorDirection.SetX(field_70.mAt.X() * lrCos - field_70.mAt.Z() * lrSinTheta);
    lAmortizedInterpolatorDirection.SetZ(field_70.mAt.X() * lrSinTheta + field_70.mAt.Z() * lrCos);
    field_0.field_0.SetGtV3d(lOldPos + lAmortizedInterpolatorDirection * lrDistanceToMove);
    field_30.field_0.SetGtV3d(field_70.mPos + field_70.mAt * field_14C);
    if ((unsigned int)(field_173 - 8) < 2) {
        field_0.MoveToSegmentCentre(field_60);
        field_30.MoveToSegmentCentre(CGtV3d(field_0.field_0.mData));
    }

    // the matrix from the axles
    field_70.mAt = CGtV3d(field_0.field_0.mData) - CGtV3d(field_30.field_0.mData);
    func_00172E40_inl1(field_70.mAt);
    field_70.mPos = CGtV3d(field_0.field_0.mData) - field_70.mAt * field_150;
    if (!field_0.AdjustAxleHeight(0, -1)) field_0.field_10 = lpParamPos->field_0.mUp;
    if (!field_30.AdjustAxleHeight(0, -1)) field_30.field_10 = field_0.field_10;
    field_70.mAt = CGtV3d(field_0.field_0.mData) - CGtV3d(field_30.field_0.mData);
    func_00172E40_inl1(field_70.mAt);
    float lrDirectionChange = DotProduct(field_70.mAt, field_70.mRight);
    field_70.mPos = CGtV3d(field_0.field_0.mData) - field_70.mAt * field_150;
    field_70.mUp = field_0.field_10 + field_30.field_10;
    if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);
    field_70.mRight = CrossProduct(field_70.mUp, field_70.mAt);
    if (field_70.mRight.NormaliseGetLength() == 0.0f) field_70.mRight.SetX(1.0f);
    field_70.mUp = CrossProduct(field_70.mAt, field_70.mRight);
    if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);

    // wheel spin
    if (field_B0->field_D > 0) {
        field_128 = field_128 + lrDistanceToMove / field_120;
        if (!(field_128 <= D_004E1264)) field_128 = field_128 - D_004E1264;
        else if (field_128 < D_004E1268) field_128 = field_128 + D_004E1264;
    }
    if (field_174 & 4) return;

    // body roll and pitch springs
    field_BC = field_BC * D_004E0978;
    field_BC = field_BC + field_158 * (D_004E126C * field_114->field_18);
    field_BC = GtMath::Min(GtMath::Max(field_BC, -field_15C), field_15C);
    float r = 1.0f;
    r -= field_BC * field_BC;
    field_C0 = GtMath::Sqrt(r);
    float lrTurn = D_004E1038 * lrDirectionChange;
    field_B4 = field_B4 * D_004E1270;
    field_B4 = field_B4 + field_C4 * (field_C4 * (field_154 * lrTurn));
    field_B4 = GtMath::Min(GtMath::Max(field_B4, -field_15C), field_15C);
    float p = 1.0f;
    p -= field_B4 * field_B4;
    field_B8 = GtMath::Sqrt(p);
}
