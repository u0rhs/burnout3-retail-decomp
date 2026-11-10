// NONMATCHING: Prepare__20CB3BehaviourKeyFrameFPv -- retail 301 / ours 302 instructions, 95 in changed runs
// beh8: 302/301, 95 changed (hdr17 draft as-is 304/301, 174). Changes: local SetFromMatrix with CGtV4d::SetX/Y/Z/W(float) and *=(float) taking the scalar on a hard-coded $vf1, vector in place ("+j") [L]; CGtMatrix3x4::operator* stand-in with mUp/mAt via qmtc2.i (retail lq+qmtc2) and qmfc2.i outputs under opt_classresults. Left: frame 0x370 vs 0x770 (dead lane slots, N221) -> every stack offset; trace-compare staging (retail sqc2 from VU, ours sq from GPR); VU numbering in the switch
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
// [L] N185 stand-in for CGtMatrix3x4::operator*(const CGtMatrix3x4&) const (B3O0PCH map, 340)
#pragma opt_classresults on
static inline CGtMatrix3x4 func_00374DA0_inl1(const CGtMatrix3x4& a, const CGtMatrix3x4& m)
{
    CGtMatrix3x4 r;
    asm("qmtc2.ni %1, $vf4" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %3, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.i %4, $vf2" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mRight.mData) : "r"(m.mRight.mData), "r"(a.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "r"(a.mUp.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "r"(a.mAt.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t"
        "qmtc2.ni %2, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mPos.mData) : "r"(a.mPos.mData), "r"(m.mPos.mData));
    return r;
}
#pragma opt_classresults reset

// [L] N185 stand-ins: CGtV4d::SetX/Y/Z/W(float) and operator*=(float) with the scalar on a hard-coded $vf1, the vector in place
// (retail Prepare__19CB3BehaviourClusterFPv 0x3583D8: `qmtc2.ni v0,$vf1; vaddx.x $vf6,$vf0,$vf1x`)
static inline void func_00374DA0_setX(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00374DA0_setY(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00374DA0_setZ(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00374DA0_setW(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00374DA0_mul(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.xyzw %0, %0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00374DA0_inl1b(CGtV4d& mRot, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        mRot.SetX(m.mUp.Z() - m.mAt.Y());
        mRot.SetY(m.mAt.X() - m.mRight.Z());
        mRot.SetZ(m.mRight.Y() - m.mUp.X());
        func_00374DA0_mul(mRot, 0.5f / s);
        func_00374DA0_setW(mRot, 0.5f * s);
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
            func_00374DA0_setX(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_00374DA0_setY(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_00374DA0_setZ(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
class CB3CameraKeyFrame {
public:
    int GetRaceCarIndex();
    int GetTypeBehaviour();
    CGtMatrix3x4 GetMatrix();
    float GetFOV();
};
struct UnkStruct_00374DA0_obj { CGtMatrix3x4 field_0; };
struct UnkStruct_00374DA0_car { unsigned char pad_0[0x204]; UnkStruct_00374DA0_obj * field_204; };
struct UnkStruct_00374DA0_slot { UnkStruct_00374DA0_car * field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_00374DA0_slot D_0055EFEC[];
struct UnkStruct_00374DA0_cam { unsigned char pad_0[4]; float field_4; unsigned char pad_8[8]; CGtQuatPos field_10; };

class CB3BehaviourKeyFrame {
public:
    bool Prepare(void * p);
    unsigned char pad_0[8];
    CB3CameraKeyFrame * field_8;
};

// 0x00374DA0
bool CB3BehaviourKeyFrame::Prepare(void * p)
{
    UnkStruct_00374DA0_cam * cam = (UnkStruct_00374DA0_cam *)p;
    UnkStruct_00374DA0_car * car = D_0055EFEC[field_8->GetRaceCarIndex()].field_0;
    CGtMatrix3x4 m;
    switch (field_8->GetTypeBehaviour()) {
    case 0:
        m = field_8->GetMatrix();
        break;
    case 1:
        m = field_8->GetMatrix();
        m.mPos += car->field_204->field_0.mPos;
        break;
    case 2:
        m = func_00374DA0_inl1(field_8->GetMatrix(), car->field_204->field_0);
        break;
    }
    cam->field_4 = field_8->GetFOV();
    func_00374DA0_inl1b(cam->field_10.mQuat.mRot, m);
    cam->field_10.mPos = m.mPos;
    return true;
}

