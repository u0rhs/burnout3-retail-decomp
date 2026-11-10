// NONMATCHING: Prepare__19CB3BehaviourClusterFPv -- retail 258 / ours 261 instructions, 129 in changed runs
// fix2 (2026-11-01): CollisionResolveCameraWorld called through its link name with the camera (Prepare's argument) in a1 (the draft passed field_D4 there); layout pad_E4[0xEC] -> pad_F0[0xE0] (field_1D0/1E0/1E1 were 0x10 high) [C] retail 0x35864C..0x358694 | Before: beh8: 261/258, 135 changed (header SetFromMatrix as-is: 264/258, 206). Body = CGtQuatPos::SetFromMatrix(rig matrix 2) + field_4 = rig B8 + if (!rig CC) {field_1D0.Zero(); 1E1=0; 1E0 = CollisionResolveCameraWorld(vp, Dot(m2.At, m1.Pos - m2.Pos), rig C4)}. [L] header finding: retail's SetFromMatrix sets mRot with the SCALAR on a hard-coded $vf1 and mRot in place on a compiler-chosen reg (qmtc2.ni v0,$vf1; vaddx.x $vf6,$vf0,$vf1x; same for SetW(float) vmulx.w and *=(float) vmulx.xyzw) -- local stand-ins here. Left: VU numbering (trace lane adds accumulate over the first operand: vaddy.x $vf2,$vf2,$vf3y; header +(X,Y) is =j), frame 0x210 vs 0x5F0 (N221 dead lane slots), compare-block U/A staging
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix2: written from the asm; the tail (0x3585B0..0x358694: stores, CollisionResolveCameraWorld's 4 args and bool) re-checked against retail; behaviour_audit quiet


// CB3BehaviourCluster::Prepare(void*) -- hand-written (beh8).
// [C] name: the mangled symbol in retail's tables. Fields placeholders, types [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
class CB3Viewport;
// [C] retail 0x358684..0x35868C passes the camera (Prepare's argument) in a1 as well and reads the bool result (sb v0); the
// mangled name lists three parameters (as Update__19CB3BehaviourClusterFP9CGtCameraf's archive)
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *, void *, float, int);
// [G] the camera state Prepare fills (as CB3BehaviourInterpolate::Prepare's block): +4 float, +0x10 quat/pos, +0x30 viewport
struct UnkStruct_003582A0_cam {
    unsigned char pad_0[0x4];
    float field_4;
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;
    CB3Viewport *field_30;
};
// [G] CB3ClusterRig (SetRig 0x358780) seen as two matrices
struct UnkStruct_003582A0_rig {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    int field_80;
    int field_84;
    CGtV3d field_90;
    CGtV3d field_A0;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
};
class CB3BehaviourCluster {
public:
    int Prepare(void *p0);
    unsigned char pad_0[0x10];
    UnkStruct_003582A0_rig field_10;
    unsigned char pad_F0[0xE0];
    CGtV4d field_1D0;                       // [C] retail 0x35864C sqc2 0x1D0 (the rig ends at 0xF0)
    bool field_1E0;
    bool field_1E1;
};

// [L] N185 stand-ins: CGtV4d::SetX/Y/Z/W(float) and operator*=(float) with the scalar on a hard-coded $vf1, the vector in place
// (retail Prepare__19CB3BehaviourClusterFPv 0x3583D8: `qmtc2.ni v0,$vf1; vaddx.x $vf6,$vf0,$vf1x`)
static inline void func_003582A0_setX(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_003582A0_setY(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_003582A0_setZ(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_003582A0_setW(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_003582A0_mul(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.xyzw %0, %0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_003582A0_inl1(CGtV4d& mRot, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        mRot.SetX(m.mUp.Z() - m.mAt.Y());
        mRot.SetY(m.mAt.X() - m.mRight.Z());
        mRot.SetZ(m.mRight.Y() - m.mUp.X());
        func_003582A0_mul(mRot, 0.5f / s);
        func_003582A0_setW(mRot, 0.5f * s);
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
            func_003582A0_setX(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_003582A0_setY(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_003582A0_setZ(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
// 0x003582A0
int CB3BehaviourCluster::Prepare(void *p0)
{
    UnkStruct_003582A0_cam *c = (UnkStruct_003582A0_cam *)p0;
    func_003582A0_inl1(c->field_10.mQuat.mRot, field_10.field_40);
    c->field_10.mPos = field_10.field_40.mPos;
    c->field_4 = field_10.field_B8;
    if (field_10.field_CC == 0) {
        field_1D0.Zero();
        field_1E1 = false;
        field_1E0 = CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(c->field_30, c, DotProduct(field_10.field_40.mAt, field_10.field_0.mPos - field_10.field_40.mPos), field_10.field_C4);
    }
    return 1;
}
