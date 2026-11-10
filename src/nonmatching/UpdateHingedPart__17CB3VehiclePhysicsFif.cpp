// NONMATCHING: UpdateHingedPart__17CB3VehiclePhysicsFif -- retail 2350 / ours 2308 instructions, 2635 in changed runs
// draft3 first full draft: 2339/2350, frame 0x16F0 vs 0x1EC0. Op counts agree (15 vrsqrt, 13 cross products, 28 vmulax, 66 trig ctc2 = 6 CreateRotationMatrix3x4 copies, 16 FP compares, 9 clamps); call order identical (UpdatePhysics, acosf x2, DetachBodyPart, acosf: axis-0 branch out of line as in retail). Left: stack-slot layout and the matrix temporaries' sq/lqc2 traffic (sq 168 vs 156, sqc2 32 vs 56). Stand-ins: CreateRotationMatrix3x4, hinge clamp, rotate-back (local inlines); opt_classresults on: 2315 / 3829 | N259: CreateRotationMatrix3x4 + lane ops via the header
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra as reading aid), every branch, call, store and constant accounted for; Revenge STABS locals; the unused axis-scale check kept as computed (assert remnant [G])

// draft3: CB3VehiclePhysics::UpdateHingedPart(int, float) (0x1C8870, 2350 instructions), written from the retail asm
// (Ghidra 12.1.4 as reading aid). [L] locals: Revenge STABS (UpdateHingedPart__17CB4VehiclePhysicsif, 0x205758): names,
// declaration order and types (lRotate, lInvBodyPartSpace, lHingeAxis, lMeasureAxis, lWindingAxis, lZeroDegreeAxis,
// lrMinAngle, lrMaxAngle, lrAngle, the three axis scales, lnAxis, lPart, lbReverse); lInvBodyPartSpace and
// lrAngularVelocity are not used by the retail code (Revenge's body differs there) [L].
// [L] a hinged body part (bonnet, boot, door) swings about one local axis of its matrix under gravity, the car body's
// point velocity and drag; past its hinge limits it is rotated back, its angular momentum reflected (x -0.7), and the
// crash sound manager may detach it.
// Types and field meanings [G] (instruction widths, use); the hinged part layout is Revenge's CB4HingedPartPhysics (0xD0)
// without its 0x70 mLastPosition (retail stride 0xC0) [L]. Local stand-ins for inlines the headers lack:
//   inl1 = [L] GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float) (E map; draft1's decode, the same lanes here).
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct UnkStruct_001C8870_part {    // [L] Revenge CB4HingedPartPhysics
    unsigned char pad_0[0x60];      // [L] mInverseInertiaTensorLocal / World
    CGtV3d field_60;                // [L] mPrevVelocity
    CGtV3d field_70;                // [L] mTotalTorque
    CGtV3d field_80;                // [L] mTotalImpulseAngular
    CGtV3d field_90;                // [L] mAngularMomentum
    CGtV3d field_A0;                // [L] mAngularVelocity
    float field_B0;                 // [L] mrMaxHingeAngle (degrees, signed)
    float field_B4;                 // [L] mrMass
    CGtMatrix3x4 *field_B8;         // [L] mpMatrix
    unsigned char pad_BC[4];
};
struct UnkStruct_001C8870_hinge { CGtV3d field_0; CGtV3d field_10; };   // [G] the part's two hinge points (local)
struct UnkStruct_001C8870_q {
    unsigned char pad_0[0xADC];
    unsigned char field_ADC[0x3C4];         // [L] per part: hinge axis 0 = x, 1 = y, 2 = z (lnAxis)
    UnkStruct_001C8870_hinge field_EA0[1];
};
struct UnkStruct_001C8870_p { unsigned char pad_0[0x40]; UnkStruct_001C8870_q *field_40; };

class CB3VehiclePhysics {
public:
    void UpdateHingedPart(int i, float dt);

    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;          // [G] world -> body orientation (only its rows are read)
    CGtV3d field_B0;                // [G] linear velocity
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                // [G] angular velocity
    unsigned char pad_E0[0x124];
    CGtMatrix3x4 *field_204;        // [G] body matrix
    unsigned char pad_208[0xD];
    signed char field_215;          // [G] 1: hinge hits are reported to the crash sound manager
    unsigned char pad_216[0xAAA];
    UnkStruct_001C8870_p *field_CC0;
    unsigned char pad_CC4[0x1C];
    UnkStruct_001C8870_part field_CE0[1];
};

extern CGtV3d kGravity;
extern CGtV3d kAtVector;
extern CGtV3d D_004B7DA0;           // [G] the local x axis (zero in the ELF: built by a static initializer)
extern CGtV3d D_004B7DB0;           // [G] the local y axis (likewise)
extern float D_004E16E4;            // [G] tuning (sdata): restitution, 0.7
extern float D_004E16E8;            // [G] drag, 3.0
extern float D_004E16EC;            // [G] inertia from the body's acceleration, 40.0
extern float D_004E16F0;            // [G] angular momentum damping, 0.98
extern char D_01E78510[];           // [L] the CB3SoundCrashManager instance
extern "C" void func_001CFE40(UnkStruct_001C8870_part *, float);   // [L] CB4HingedPartPhysics::UpdatePhysics (Revenge method list)
extern "C" float func_0011E328(float);                            // [L] libm acosf (E_B3DEBUG wf_acos.o)
// [L] CB3SoundCrashManager::DetachBodyPart(GtMathPs2::CGtV3d, float, EVehicleFlyingBit) (E map; placeholder in our tables)
extern "C" void func_0027D240(void *, CGtV3d, float, int);

static inline CGtMatrix3x4 func_001C8870_inl1_unused(CGtV3d axis, float angle)
{
    axis.Normalise();
    CGtV4d sc = SinCosFast(angle);
    float s = sc.f[0];
    float c = sc.f[1];
    float k = 1.0f - c;
    float x = axis.X(), y = axis.Y(), z = axis.Z();
    CGtMatrix3x4 m;
    m.mRight = CGtV3d(1.0f - (1.0f - x * x) * k, x * y * k + z * s, z * x * k - y * s);
    m.mUp = CGtV3d(x * y * k - z * s, 1.0f - (1.0f - y * y) * k, y * z * k + x * s);
    m.mAt = CGtV3d(z * x * k + y * s, y * z * k - x * s, 1.0f - (1.0f - z * z) * k);
    m.mPos.Zero();
    return m;
}

// [G] rotate the part back by lrDelta degrees about lAxis; the axis-scale check after it is computed but unused in
// retail (an assert remnant [G]: |(|R|^2, |U|^2, |A|^2) - 1|^2)
static inline void func_001C8870_inl2(CGtMatrix3x4 &m, CGtV3d lAxis, float lrDelta)
{
    CGtMatrix3x4 lRotate;
    lRotate = CreateRotationMatrix3x4(lAxis, 0.01745329238f * lrDelta);
    m = m * lRotate;
    float lrRightAxisScale = m.mRight.GetSquaredLength();
    float lrUpAxisScale = m.mUp.GetSquaredLength();
    float lrAtAxisScale = m.mAt.GetSquaredLength();
    CGtV3d s;
    s.SetX(lrRightAxisScale);
    s.SetY(lrUpAxisScale);
    s.SetZ(lrAtAxisScale);
    s = s - CGtV3d(1.0f, 1.0f, 1.0f);
    float e = s.GetSquaredLength();
    (void)e;
}

// [G] the hinge angle of lMeasureAxis from lZeroDegreeAxis, signed by the winding against lRef (degrees, -180..180);
// past a limit the part is rotated back about lAxis (retail: one inlined copy per axis)
static inline void func_001C8870_inl3(CGtMatrix3x4 &m, CGtV3d lMeasureAxis, CGtV3d lZeroDegreeAxis, CGtV3d &lWindingAxis,
                                      CGtV3d lRef, CGtV3d lAxis, float lrMinAngle, float lrMaxAngle, bool &lbReverse)
{
    float lrAngle = 57.29578018f * func_0011E328(CosAngleBetweenNormalisedVectors(lMeasureAxis, lZeroDegreeAxis));
    lWindingAxis = CrossProduct(lMeasureAxis, lZeroDegreeAxis);
    if (DotProduct(lWindingAxis, lRef) < 0.0f)
        lrAngle = 360.0f - lrAngle;
    if (lrAngle > 180.0f)
        lrAngle -= 360.0f;
    if (lrAngle > lrMaxAngle) {
        func_001C8870_inl2(m, lAxis, lrAngle - lrMaxAngle);
        lbReverse = true;
    } else if (lrAngle < lrMinAngle) {
        func_001C8870_inl2(m, lAxis, lrAngle - lrMinAngle);
        lbReverse = true;
    }
}

// 0x001C8870
void CB3VehiclePhysics::UpdateHingedPart(int i, float dt)
{
    CGtV3d lHingeAxis;
    CGtV3d lMeasureAxis;
    CGtV3d lWindingAxis;
    CGtV3d lZeroDegreeAxis;
    float lrMinAngle;
    float lrMaxAngle;
    UnkStruct_001C8870_part &lPart = field_CE0[i];
    UnkStruct_001C8870_q *q = field_CC0->field_40;
    int lnAxis = q->field_ADC[i];

    // forces on the part, as torques about its matrix position
    CGtV3d lPivot = (q->field_EA0[i].field_0 + q->field_EA0[i].field_10) * 0.5f;
    CGtV3d lWorldPivot = TransformPoint(*lPart.field_B8, lPivot);
    CGtV3d lGravity = TransformVector(field_70, kGravity * lPart.field_B4);
    lPart.field_70 += CrossProduct(lWorldPivot - lPart.field_B8->mPos, lGravity);
    CGtV3d lBodyPoint = TransformPoint(*field_204, lWorldPivot);
    CGtV3d lVelocity = TransformVector(field_70, CrossProduct(field_D0, lBodyPoint - field_204->mPos) + field_B0);
    CGtV3d lAccel = lVelocity - lPart.field_60;
    lPart.field_60 = lVelocity;
    lPart.field_70 += CrossProduct(lWorldPivot - lPart.field_B8->mPos, lAccel * (-lPart.field_B4 * D_004E16EC));
    float lrSpeed = lVelocity.GetLength();
    lPart.field_70 += CrossProduct(lWorldPivot - lPart.field_B8->mPos, (lVelocity * -lrSpeed) * D_004E16E8);

    // only the hinge axis' component of the torque is kept
    if (lnAxis == 0) {
        lPart.field_70.SetY(0.0f);
        lPart.field_70.SetZ(0.0f);
        lHingeAxis = lPart.field_B8->mRight;
    } else if (lnAxis == 1) {
        lPart.field_70.SetX(0.0f);
        lPart.field_70.SetZ(0.0f);
        lHingeAxis = lPart.field_B8->mUp;
    } else {
        lPart.field_70.SetX(0.0f);
        lPart.field_70.SetY(0.0f);
        lHingeAxis = lPart.field_B8->mAt;
    }
    lPart.field_90 = lPart.field_90 * D_004E16F0;
    func_001CFE40(&lPart, dt);

    lrMaxAngle = lPart.field_B0;
    lrMinAngle = 0.0f;
    if (lrMaxAngle < 0.0f) {
        lrMinAngle = lrMaxAngle;
        lrMaxAngle = 0.0f;
    }
    CGtMatrix3x4 &m = *lPart.field_B8;
    CGtV3d lPos = m.mPos;
    bool lbReverse = false;     // [L] Revenge's name; set when a hinge limit was hit
    if (lnAxis == 0) {
        lMeasureAxis = m.mAt;
        lMeasureAxis.SetX(0.0f);
        if (!(lMeasureAxis.GetSquaredLength() < 2.3283064e-10f)) {
            CGtV3d lRef = D_004B7DA0;
            lMeasureAxis.Normalise();
            lZeroDegreeAxis = kAtVector;
            lZeroDegreeAxis.Normalise();
            func_001C8870_inl3(m, lMeasureAxis, lZeroDegreeAxis, lWindingAxis, lRef, D_004B7DA0, lrMinAngle, lrMaxAngle,
                               lbReverse);
        }
    } else if (lnAxis == 1) {
        lMeasureAxis = m.mAt;
        lMeasureAxis.SetY(0.0f);
        if (!(lMeasureAxis.GetSquaredLength() < 2.3283064e-10f)) {
            CGtV3d lRef = D_004B7DB0;
            lMeasureAxis.Normalise();
            lZeroDegreeAxis = kAtVector;
            lZeroDegreeAxis.Normalise();
            func_001C8870_inl3(m, lMeasureAxis, lZeroDegreeAxis, lWindingAxis, lRef, D_004B7DB0, lrMinAngle, lrMaxAngle,
                               lbReverse);
        }
    } else {
        lZeroDegreeAxis = m.mRight;
        lZeroDegreeAxis.SetY(0.0f);
        if (!(lZeroDegreeAxis.GetSquaredLength() < 2.3283064e-10f)) {
            lMeasureAxis = m.mRight;
            CGtV3d lRef = m.mAt;
            lMeasureAxis.Normalise();
            lZeroDegreeAxis.Normalise();
            func_001C8870_inl3(m, lMeasureAxis, lZeroDegreeAxis, lWindingAxis, lRef, m.mAt, lrMinAngle, lrMaxAngle,
                               lbReverse);
        }
    }
    m.mPos = lPos;

    // rebuild the matrix orthonormal around the hinge axis as it was before the update
    if (lnAxis == 0) {
        CGtV3d a = CrossProduct(lHingeAxis, m.mUp);
        a.Normalise();
        CGtV3d u = CrossProduct(a, lHingeAxis);
        CGtMatrix3x4 t;
        t.mRight = lHingeAxis; t.mUp = u; t.mAt = a; t.mPos = m.mPos;
        m = t;
    } else if (lnAxis == 1) {
        CGtV3d r = CrossProduct(lHingeAxis, m.mAt);
        r.Normalise();
        CGtV3d a = CrossProduct(r, lHingeAxis);
        CGtMatrix3x4 t;
        t.mRight = r; t.mUp = lHingeAxis; t.mAt = a; t.mPos = m.mPos;
        m = t;
    } else {
        CGtV3d r = CrossProduct(m.mUp, lHingeAxis);
        r.Normalise();
        CGtV3d u = CrossProduct(lHingeAxis, r);
        CGtMatrix3x4 t;
        t.mRight = r; t.mUp = u; t.mAt = lHingeAxis; t.mPos = m.mPos;
        m = t;
    }

    if (lbReverse) {
        lPart.field_90 = lPart.field_90 * -D_004E16E4;
        if (field_215 == 1)
            func_0027D240(D_01E78510, lPart.field_B8->mPos, 100.0f, 0);
    }
}
