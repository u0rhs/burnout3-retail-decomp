// NONMATCHING: Prepare__18CB3BehaviourRotateFPv -- retail 365 / ours 365 instructions, 176 in changed runs
// beh8: 365/365, 176 changed (hdr19 draft with the header SetFromMatrix: 296). Change: local SetFromMatrix whose CGtV4d::SetX/Y/Z/W(float) and *=(float) take the scalar on a hard-coded $vf1, vector in place [L] (same finding as Cluster/KeyFrame Prepare). Left: frame 0x4C0 vs 0x940 (dead lane slots, N221), look-at stand-in [G] (Matrix3x4SetLookAt), byte-loop staging, VU numbering
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// hdr19 rough draft: Prepare__18CB3BehaviourRotateFPv (0x2E6700), to measure CGtQuat(Pos)::SetFromMatrix in context.
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3RaceCarPhysics;
struct UnkStruct_002E6700_car { unsigned char pad_0[0x204]; CGtMatrix3x4 *field_204; };
struct UnkStruct_002E6700_slot { UnkStruct_002E6700_car *field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_002E6700_slot D_0055EFEC[];
extern CGtV3d kAxisY;
struct UnkStruct_002E6700_p { unsigned char pad_0[4]; float field_4; unsigned char pad_8[8]; CGtQuatPos field_10; };
namespace CB3CameraUtils { void GetTrackMatrix(CGtMatrix3x4 *, CB3RaceCarPhysics *); }

// [L] N185: lane Y(Y) - Y (header operator-(YAxisType, YAxisType)) and Y + float (GtMathPs2Quat.h) are header; this stands in for the
// in-place Normalise on a compiler-chosen register (hperm normalise H1Q0N2V1R-, not in the header).
static inline void func_002E6700_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder");
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
// [L] N185: cross product a x b on compiler-chosen registers, result over a's register (retail 0x2E6888 vopmula/vopmsub)
static inline CGtV3d func_002E6700_inl2(CGtV3d a, CGtV3d b)
{
    asm("vopmula.xyz $ACC, %0, %1" "\n\t" "vopmsub.xyz %0, %1, %0" : "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(a.mData);
}
// [G] a look-at matrix (the E map's Matrix3x4SetLookAt(CGtV3d, CGtV3d), 432 bytes, would fit): at normalised, right = Y x at
// normalised, up = at x right, mPos = pos.
static inline CGtMatrix3x4 func_002E6700_inl3(CGtV3d at, CGtV3d pos)
{
    CGtMatrix3x4 m;
    func_002E6700_inl1(at);
    CGtV3d right = func_002E6700_inl2(kAxisY, at);
    func_002E6700_inl1(right);
    m.mRight = right;
    m.mUp = func_002E6700_inl2(at, right);
    m.mAt = at;
    m.mPos = pos;
    return m;
}

// [L] N185 stand-ins: CGtV4d::SetX/Y/Z/W(float) and operator*=(float) with the scalar on a hard-coded $vf1, the vector in place
// (retail Prepare__19CB3BehaviourClusterFPv 0x3583D8: `qmtc2.ni v0,$vf1; vaddx.x $vf6,$vf0,$vf1x`)
static inline void func_002E6700_setX(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002E6700_setY(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002E6700_setZ(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002E6700_setW(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002E6700_mul(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.xyzw %0, %0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002E6700_inl9(CGtV4d& mRot, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        mRot.SetX(m.mUp.Z() - m.mAt.Y());
        mRot.SetY(m.mAt.X() - m.mRight.Z());
        mRot.SetZ(m.mRight.Y() - m.mUp.X());
        func_002E6700_mul(mRot, 0.5f / s);
        func_002E6700_setW(mRot, 0.5f * s);
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
            func_002E6700_setX(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002E6700_setY(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002E6700_setZ(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
class CB3BehaviourRotate {
public:
    int Prepare(void *pv);
    unsigned char pad_0[0x10];
    CGtMatrix3x4 field_10;
    float field_50;
    float field_54;
    unsigned char pad_58[8];
    float field_60;
    float field_64;
    float field_68;
    int field_6C;
};

int CB3BehaviourRotate::Prepare(void *pv)
{
    UnkStruct_002E6700_p *p = (UnkStruct_002E6700_p *)pv;
    UnkStruct_002E6700_car *car = D_0055EFEC[field_6C].field_0;
    CGtMatrix3x4 *cm = car->field_204;
    p->field_4 = 60.0f;
    field_50 = field_54;
    CB3CameraUtils::GetTrackMatrix(&field_10, (CB3RaceCarPhysics *)car);
    CGtV3d cp = cm->mPos;
    float h = GtMath::Min(cp.Y() - field_10.mPos.Y(), 5.5f - field_60);
    field_10.mPos = cp;
    field_10.mPos.SetY(cp.Y() + h);
    CGtV3d off;
    off.Set(0.0f, field_60, field_64);
    CGtV3d eye = TransformPoint(field_10, off);
    CGtV3d tgt = cm->mPos;
    tgt.SetY(tgt.Y() + field_68);
    tgt -= eye;
    CGtMatrix3x4 m;
    m = func_002E6700_inl3(tgt, eye);
    CGtMatrix3x4 t = m;
    func_002E6700_inl9(p->field_10.mQuat.mRot, t);
    p->field_10.mPos = t.mPos;
    return 1;
}

