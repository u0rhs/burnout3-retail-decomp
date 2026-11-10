// NONMATCHING: Update__21CB3BehaviourTrackSideFP9CGtCameraf -- retail 1632 / ours 1688 instructions, 1912 in changed runs
// fix3 (2026-11-01): deg->rad constant 0.0174533f (0x3C8EFA39) -> 0.017453292f = retail's 0x3C8EFA35 [C] retail D_004E0D60 / D_004E0F74 | Before: draftA: 1632/1695; calls identical (incl. retail's out-of-line __ct__CGtV4dF1), every branch sense and VU/FPU op count equal. Left: ConvertToMatrix lane-product slots (N255 stride 48 vs 16: retail hoists 6 slot addresses, ~30 instrs), header CRM row scheduling (x3), OrthoNormalise X<=0/Y<=0 blocks inline (retail: at the end), lq/sq vs lqc2/sqc2 folding, frame 0x1DC0 vs 0x2D60. Shares the Prepare archive's stand-ins; adds GtMath::IsEffectivelyZero(float) [G]; inline_depth 3-7 all worse | N266-N268 header APIs (gapH) | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every call, argument, store and branch condition decoded from retail asm (calls identical, op counts equal); dt unused as in retail


// draftA: Update__21CB3BehaviourTrackSideFP9CGtCameraf (0x2FD2C0, 0x1980) -- CB3BehaviourTrackSide::Update(CGtCamera*, float)
// [C] name: retail symbol table. Decoded from retail asm (build/vt/draftA/u_cfg.txt); sibling of the Prepare archive (same stand-ins).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

// [G] lane segment record, 10 bytes (retail 0x2FED80: index * 10); field_4 / field_5 = 0xFF on a missing side link
struct UnkStruct_002FEC40_seg { unsigned char pad_0[4]; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
class CB3AILaneStruct { public: unsigned char pad_0[8]; UnkStruct_002FEC40_seg *field_8; };
class CB3AILane { public: unsigned char pad_0[4]; CB3AILaneStruct *field_4; };
// [G] per-player record behind D_0064D388 (AI / race-car data): +0 a direction, +0x30 position, +0x54 speed, +0x18B4 lane, +0x18B8 segment
struct UnkStruct_002FEC40_ai {
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
    unsigned char pad_40[0x14];
    float field_54;
    unsigned char pad_58[0x185C];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
};
struct UnkStruct_002FEC40_vp { unsigned char pad_0[0x74]; float field_74; };
// [G] camera fields as Prepare's camera data: +4 FOV, +0x10 rotation + position (CGtQuatPos), +0x30 viewport
class CGtCamera {
public:
    unsigned char pad_0[4];
    float field_4;
    unsigned char pad_8[8];
    CGtQuatPos field_10;
    UnkStruct_002FEC40_vp *field_30;
};

class CB3BehaviourTrackSide {
public:
    void Update(CGtCamera *cam, float dt);
    unsigned char pad_0[8];
    CB3AILane *field_8;
    float field_C;
    int field_10;           // [G] index into D_0064D388 here (the header types +0x10 as CB3AttribsTrackSide*)
    int field_14;
    unsigned short field_18;
    int field_1C;           // [L] EAISegmentLinkType (StepForward / GetOppositeSide argument)
    int field_20;           // [L] EB3BehaviourType (SetParameters p0)
};

extern UnkStruct_002FEC40_ai *D_0064D388[];
extern CGtV3d kAxisY;
extern float krSafeFOVVert;
extern float krSafeFOVHoriz;
extern "C" float func_00148DF0(CB3AILane *, const CGtV3d &, unsigned short);
extern "C" CB3AILane *FindNoGo__9CB3AILaneFPUs18EAISegmentLinkType(CB3AILane *, unsigned short *, int);
extern "C" void StepForward__21CB3BehaviourTrackSideFf(float *frac, CB3AILane **lane, unsigned short *idx, int dir, float amt);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(CB3AILaneStruct *, unsigned short, float, int);
extern "C" int GetOppositeSide__14CB3CameraUtilsF18EAISegmentLinkType(int);
extern "C" void GetLeftwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
extern "C" void GetRightwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short, CGtV3d *);
extern "C" bool func_00147FC0(CB3AILane *, unsigned short, CGtV3d *);
extern "C" float func_0011E340(float);          // [L] libm asinf (E_B3DEBUG wf_asin.o at the same address)
extern "C" float func_0011E358(float, float);   // [L] libm atan2f (E_B3DEBUG wf_atan2.o)
extern float D_004E1CFC;   // [L] 25.0 (minimum FOV; a variable: retail loads it, a lui-able literal would be built)
extern float D_004E1D00;   // [L] 60.0 (maximum FOV)
extern "C" float atanf(float);

// [G] header gap: the E map's GtMath::IsEffectivelyZero(float) (0x28) -- exponent below 2^-16 (retail 0x2FDE34: and 0x7F800000,
// sltu 0x37800001 on the float's bits)
static inline bool func_002FD2C0_inl1(float f)
{
    return (*(unsigned int *)&f & 0x7F800000) < 0x37800001;
}

extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *, void *, float, int);

// [G] header gap: the E map's GtMathPs2::Matrix3x4SetLookAt(CGtV3d, CGtV3d) (432 bytes) would fit -- at normalised,
// right = Y x at normalised, up = at x right, mPos = pos (retail 0x2FEF0C..0x2FEFE8)
static inline CGtMatrix3x4 func_002FEC40_inl3(CGtV3d at, CGtV3d pos)
{
    CGtMatrix3x4 m;
    at.Normalise();
    CGtV3d right = CrossProduct(kAxisY, at);
    right.Normalise();
    m.mRight = right;
    m.mUp = CrossProduct(at, right);
    m.mAt = at;
    m.mPos = pos;
    return m;
}

// [L] header gap: the E map's CGtV3d::operator*(YAxisType) / operator*(ZAxisType) (0x44 each, emitted right after
// CGtMatrix3x4::Invert); bodies as the header operator*(XAxisType)
static inline CGtV3d func_002FEC40_inl4(const CGtV3d &v, YAxisType a) { u_long128 r; asm("vmuly.xyz %0, %1, %2y" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
static inline CGtV3d func_002FEC40_inl5(const CGtV3d &v, ZAxisType a) { u_long128 r; asm("vmulz.xyz %0, %1, %2z" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }

// [G] header gap: the E map's GtMathPs2::CGtMatrix3x4::Invert() (0x20C) -- orthonormal inverse in place: rows transposed,
// pos = -(R^T pos) (retail 0x2FF644..0x2FF698)
static inline void func_002FEC40_inl1(CGtMatrix3x4 &m)
{
    CGtV3d r = m.mRight;
    CGtV3d u = m.mUp;
    CGtV3d a = m.mAt;
    r.SetY(m.mUp.X());
    u.SetX(m.mRight.Y());
    r.SetZ(m.mAt.X());
    u.SetZ(m.mAt.Y());
    a.SetX(m.mRight.Z());
    a.SetY(m.mUp.Z());
    m.mRight = r;
    m.mUp = u;
    m.mAt = a;
    CGtV3d tz = func_002FEC40_inl5(a, m.mPos.Z());
    CGtV3d ty = func_002FEC40_inl4(u, m.mPos.Y());
    CGtV3d tx = r * m.mPos.X();
    m.mPos = -(tx + ty + tz);
}

// [G] header gap: the E map's GtMath::Sign(float) (0x48) -- copysign(1.0f, x) through a stack word (retail 0x3009C0)
static inline float func_002FEC40_inl2(float x)
{
    volatile union { float f; unsigned int i; } u;
    u.f = x;
    u.i = (u.i & 0x80000000) | 0x3F800000;
    return u.f;
}

// [L] N185 stand-ins: CGtV4d::SetX/Y/Z/W(float) and operator*=(float) with the scalar on a hard-coded $vf1, the vector in place
// (as the CB3BehaviourRotate::Prepare archive; retail Prepare__19CB3BehaviourClusterFPv 0x3583D8: `qmtc2.ni v0,$vf1; vaddx.x $vf6,$vf0,$vf1x`)
static inline void func_002FEC40_qsetX(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002FEC40_qsetY(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002FEC40_qsetZ(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002FEC40_qsetW(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002FEC40_qmul(CGtV4d& v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.xyzw %0, %0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_002FEC40_inl9(CGtV4d& mRot, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        mRot.SetX(m.mUp.Z() - m.mAt.Y());
        mRot.SetY(m.mAt.X() - m.mRight.Z());
        mRot.SetZ(m.mRight.Y() - m.mUp.X());
        func_002FEC40_qmul(mRot, 0.5f / s);
        func_002FEC40_qsetW(mRot, 0.5f * s);
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
            func_002FEC40_qsetX(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002FEC40_qsetY(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002FEC40_qsetZ(mRot, 0.5f * s);
            s = 0.5f / s;
            mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
// CGtQuatPos::SetFromMatrix through the stand-ins above
static inline void func_002FEC40_inl10(CGtQuatPos &q, const CGtMatrix3x4 &m)
{
    func_002FEC40_inl9(q.mQuat.mRot, m);
    q.mPos = m.mPos;
}

// [L] header Interpolate(CGtV3d, CGtV3d, float) with b moved in by qmtc2.i and the result out by qmfc2.i (unfolded lq + qmtc2 /
// qmfc2 + sq, as retail 0x2FEE58..0x2FEE88; the header's .ni forms fold into lqc2/sqc2; the .i bits are cleared after assembly)
static inline CGtV3d func_002FEC40_inl7(CGtV3d a, CGtV3d b, float t)
{
    u_long128 r;
    asm volatile("vaddax.xyz $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %3, $vf2" "\n\t" "vmsubax.xyz $ACC, %1, $vf2x" "\n\t"
        "qmtc2.i %2, %1" "\n\t" "vmaddx.xyz %1, %1, $vf2x" "\n\t" "qmfc2.i %0, %1"
        : "=r"(r), "+j"(a.mData) : "r"(b.mData), "r"(t));
    return CGtV3d(r);
}

void CB3BehaviourTrackSide::Update(CGtCamera *cam, float dt)
{
    UnkStruct_002FEC40_ai *ai = D_0064D388[field_10];
    if (field_20 == 0) {
        CGtV3d d(0.0f, 0.0f, 0.0f);
        CGtMatrix3x4 m;
        m = cam->field_10.ConvertToMatrix();
        CGtMatrix3x4 inv = m;
        inv.Invert();
        CGtV3d local = TransformPoint(inv, ai->field_30);
        float len = local.GetLength();
        float lz = local.Z();
        float yaw = 57.29578f * func_0011E358(local.X(), lz);
        float pitch = -(GtMath::ASinDeg(local.Y() / len));
        float limH = cam->field_4 * krSafeFOVHoriz;
        float limV = krSafeFOVVert * (cam->field_4 / cam->field_30->field_74);
        if (GtMath::Abs(yaw) > limH) {
            yaw = yaw - limH * GtMath::Sign(yaw);
        } else {
            yaw = 0.0f;
        }
        if (GtMath::Abs(pitch) > limV) {
            pitch = pitch - limV * GtMath::Sign(pitch);
        } else {
            float a = GtMath::ASinDeg(m.mAt.Y());
            pitch = pitch + limV * GtMath::Sign(a);
            if (GtMath::Abs(pitch) < GtMath::Abs(a)) {
            } else {
                pitch = a;
            }
        }
        float fov = GtMath::Min(GtMath::Max(0.5f * (57.29578f * atanf(10.0f / (float)(ai->field_30 - m.mPos).GetLength())), D_004E1CFC), D_004E1D00);  // [C] retail FPU form, not a VU lane op: 0x2FD6FC div.s (the cast keeps the port's PS2 float model)
        d.SetX(pitch);
        d.SetY(yaw);
        d.SetZ(fov - cam->field_4);
        CGtV3d saved = m.mPos;
        cam->field_4 += d.Z();
        m.mPos.Zero();
        m = m * CreateRotationMatrix3x4(m.mUp, 0.017453292f * (float)d.Y());
        CGtMatrix3x4 r;
        r = CreateRotationMatrix3x4(m.mRight, 0.017453292f * (float)d.X());
        m = m * r;
        float roll;
        if (GtMath::IsEffectivelyZero(m.mRight.Y())) {
            roll = 0.0f;
            if (DotProduct(m.mUp, kAxisY) < 0.0f) {
                roll = 180.0f;
            }
        } else {
            roll = -(GtMath::ASinDeg(m.mRight.Y()));
        }
        r = CreateRotationMatrix3x4(m.mAt, 0.017453292f * roll);
        m = m * r;
        m.mPos = saved;
        m.OrthoNormalise();
        func_002FEC40_inl10(cam->field_10, m);
    }
}
