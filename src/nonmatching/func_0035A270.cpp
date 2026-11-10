// NONMATCHING: func_0035A270 -- retail 290 / ours 288 instructions, 166 in changed runs
// draftAI: logic complete; retail 290 / ours 288; calls identical (6); header SinCosFast, CGtSphere::SetPosition/Radius/Position, CGtMatrix3x4::Invert, TransformPoint x3, lane SetX/SetY/SetZ, Y()+Y(), Y()-Y(), Y()+float, GtMath::Min; one CGtV3d*WAxisType stand-in (queued); VU op counts identical except one vmove (retail's Invert copies mUp and mAt, the header's one); left: lq/sq -1, frame 0x4D0 vs 0x380
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op; the type-0 tail is PrepareOffset's proven one (B3BehaviourCluster_0035BC10.cpp); the cylinder point as the E-map GetPositionOnCylinder signature

// func_0035A270 -- draftAI (C-first draft, 0x35A270, 0x488). Unnamed in every table, so the asm label with C linkage.
// [L] a CB3ClusterRig method (this = CB3BehaviourCluster + 0x10; Update__19CB3BehaviourCluster calls it while its rig mode
// field_DC < 2, before UpdateFocus); [G] CB3ClusterRig::UpdatePosition() (B3O0PCH map, between ResetRotatePosition and
// UpdateFocus; Revenge's UpdatePosition locals lNewPos, lMatrix, lrB, lrMin) with ResetRotatePosition-style rig-inverse code.
// Body [C asm]: the rig matrix position (and the sphere centre) from the target body (CB3CameraUtils::GetRigPosition for rig
// type 0, else the body's matrix position), the camera position on the cylinder around it (angle field_B0 degrees, height
// field_B4, radius = the sphere's), its offset in rig space, then the ground clamp: type 0 = the offset height above the
// lane / track point under the camera (as PrepareOffset's tail), type 1 = at most 25 (45 in crash stage 99) above it.
// Layout: the UpdateFocus / PrepareOffset archives' CB3ClusterRig fields; names [L] from research/names/class_layouts.tsv.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3CollidingBody;
struct UnkStruct_0035A270_m { unsigned char pad_0[0x30]; CGtV3d field_30; };        // [L] the body's matrix (mPos at +0x30)
struct UnkStruct_0035A270_b {                                                        // [L] CB3CollidingBody (the child's body)
    unsigned char pad_0[0x204];
    UnkStruct_0035A270_m *field_204;
    unsigned char pad_208[0x13F4 - 0x208];
    void *field_13F4;                                                                // [C] func_002F5DC0's first argument
};
struct UnkStruct_0035A270_c { unsigned char pad_0[0x40]; UnkStruct_0035A270_b *field_40; };   // [L] CB3ChildBody
class CB3ClusterRig {
public:
    CGtMatrix3x4 field_0;          // [L] mRigMatrix
    CGtMatrix3x4 field_40;         // [L] mCameraMatrix
    unsigned char pad_80[0x4];
    UnkStruct_0035A270_c *field_84; // [L] mpChild
    unsigned char pad_88[0x8];
    CGtSphere field_90;            // [L] mSphere
    CGtV3d field_A0;               // [L] mRigOffset
    float field_B0;                // [L] mrAngleY (degrees)
    float field_B4;                // [L] mrHeight
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;                  // [C] the car index (D_00522660 entry / func_002F6040)
    int field_C8;                  // [L] EB3FocusType
    int field_CC;                  // [L] EB3RigType
    unsigned char field_D0;        // [C] use the car's lane (func_002F5DC0) rather than func_002F6040
};
class CB3CameraUtils { public: static void GetRigPosition(CGtV3d *, CB3CollidingBody *); };
class CB3HardCodedCrashStageList { public: static int FindCrashStage(unsigned long); };
struct UnkStruct_D_01E901F0 { unsigned long field_0; };   // [C] the current crash stage id (as func_0030F620)
extern UnkStruct_D_01E901F0 D_01E901F0;
struct UnkStruct_0035A270_e0 { unsigned char pad_0[0x1050]; };
struct UnkStruct_D_00522660 { UnkStruct_0035A270_e0 field_0[1]; };   // [G] element count unknown (as PrepareOffset)
extern UnkStruct_D_00522660 D_00522660;
extern float D_004E1E1C;           // [C] 25.0: the type-1 clamp
extern float D_004E1E20;           // [C] 45.0: the type-1 clamp in crash stage 99
extern "C" UnkStruct_0035A270_c *func_00353960(void *p);
extern "C" CGtV3d func_002F5DC0(void *p, const void *pos);
extern "C" CGtV3d func_002F6040(const void *pos, int i);

// [L] CB3ClusterRig::GetPositionOnCylinder(CGtV3d*, CGtSphere, const CGtMatrix3x4&, float, float) by its E-map signature
// (B3O0PCH, 0x150 bytes): the point at angle / height on the sphere's cylinder, in the matrix's frame about the sphere centre
static inline void func_0035A270_inl2(CGtV3d *lpOut, CGtSphere lSphere, const CGtMatrix3x4 &lRig, float lrAngle, float lrHeight)
{
    CGtV4d lSinCos = SinCosFast(lrAngle);
    CGtV3d lSC = (CGtV3d(lSinCos.mData) * lSphere.Radius());
    CGtMatrix3x4 lMatrix = lRig;
    lMatrix.mPos = lSphere.Position();
    CGtV3d lNewPos;
    lNewPos.SetX(lSC.X());
    lNewPos.SetY(lrHeight);
    lNewPos.SetZ(lSC.Y());
    *lpOut = TransformPoint(lMatrix, lNewPos);
}

// 0x0035A270
extern "C" void func_0035A270(CB3ClusterRig *self)
{
    CGtV3d lRigPos;
    if (self->field_CC == 0)
        CB3CameraUtils::GetRigPosition(&lRigPos, (CB3CollidingBody *)self->field_84->field_40);
    else
        lRigPos = self->field_84->field_40->field_204->field_30;
    self->field_0.mPos = lRigPos;
    self->field_90.SetPosition(lRigPos);
    CGtMatrix3x4 lRigMatrixInverse = self->field_0;
    lRigMatrixInverse.Invert();
    func_0035A270_inl2(&self->field_40.mPos, self->field_90, self->field_0, 0.017453292f * self->field_B0, self->field_B4);
    self->field_A0 = TransformPoint(lRigMatrixInverse, self->field_40.mPos);
    self->field_40.mPos = TransformPoint(self->field_0, self->field_A0);
    if (self->field_CC == 0) {
        CGtV3d v;
        if (self->field_D0) {
            UnkStruct_0035A270_c *car = func_00353960((char *)&D_00522660.field_0[self->field_C4] + 0x128290);
            v = func_002F5DC0(car->field_40->field_13F4, &self->field_40.mPos);
        } else {
            v = func_002F6040(&self->field_40.mPos, self->field_C4);
        }
        self->field_40.mPos.SetY(v.Y() + self->field_A0.Y());
    } else if (self->field_CC == 1) {
        int lnStage = CB3HardCodedCrashStageList::FindCrashStage(D_01E901F0.field_0) + 1;
        CGtV3d v = func_002F5DC0(self->field_84->field_40->field_13F4, &self->field_40.mPos);
        float lrB = self->field_40.mPos.Y() - v.Y();
        float lrMin;
        if (lnStage == 100)
            lrMin = GtMath::Min(lrB, D_004E1E20);
        else
            lrMin = GtMath::Min(lrB, D_004E1E1C);
        self->field_40.mPos.SetY(v.Y() + lrMin);
    }
}
