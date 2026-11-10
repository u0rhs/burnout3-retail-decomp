// NONMATCHING: Update__18CB3BehaviourRotateFP9CGtCameraf -- retail 557 / ours 556 instructions, 278 in changed runs
// ghvu22: 557/557 instrs, 46 off with registers+sp masked. Logic/calls right; look-at basis as an inline returning a matrix built in place (m.mAt normalised through its reference gives retail's materialised sp+0x330 store), then t = m; cm = t (N239 byte loops exact); SinCosFast via BarUpdate's int-constant stand-in (VU region exact); local SetFromMatrix copy with compiler-chosen CGtV4d SetX/Y/Z(float) + vmulx.w SetW. Left: retail stores m.mUp through a materialised address (sp+0x320) and reloads it, s-register rotation (retail s3=self s2=cam s1=body s4=mat), VU/GPR numbering, frame 0xE60 vs 0x8F0 (~85 dead slots). | N266-N268 header APIs (gapH)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Update__18CB3BehaviourRotateFP9CGtCameraf -- hand-written (ghvu22) from the Ghidra draft and the retail asm.
// Types/fields [G] (instruction widths). Shape: the camera matrix is built from the rotated offset (SinCosFast, header
// GtMathPs2Trig.h), dropped onto the floor (func_002F5F40, [L] DNAT CB3CameraUtils::GetPositionOnFloor), aimed at the
// body (look-at basis with kAxisY), then written into the camera's CGtQuatPos (SetFromMatrix).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_002E5E40_body { unsigned char pad_0[0x1C0]; CGtV4d field_1C0; unsigned char pad_1D0[0x34]; CGtMatrix3x4 * field_204; };
struct UnkStruct_002E5E40_row { UnkStruct_002E5E40_body * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_002E5E40_cam { unsigned char pad_0[0x4]; float field_4; unsigned char pad_8[0x8]; CGtQuatPos field_10; void * field_30; };
struct UnkStruct_002E5E40 {
    unsigned char pad_0[0x10];
    CGtMatrix3x4 field_10;
    float field_50;
    unsigned char pad_54[0x4];
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    float field_68;
    int field_6C;
    int field_70;
};
extern UnkStruct_002E5E40_row D_0055EFEC[];
extern CGtV3d kAxisY;

extern "C" void GetRigPosition__14CB3CameraUtilsFPQ29GtMathPs26CGtV3dP16CB3CollidingBody(CGtV3d *, UnkStruct_002E5E40_body *);
extern "C" CGtV3d func_002F5F40(const CGtV3d *, int);   // [L] DNAT CB3CameraUtils::GetPositionOnFloor(CGtV3d, int) (dnat_align 0.496); by-value point passed by address [G]
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *, UnkStruct_002E5E40_cam *, float, int);

// [L] N185 stand-ins: compiler-chosen lane ops the header has only in hard-coded or other forms.
static inline void func_002E5E40_inl1(CGtV3d &d, YAxisType y) { asm("vaddy.z %0, $vf0, %1y" : "+j"(d.mData) : "j"(y.lVector)); }
static inline void func_002E5E40_sx(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E5E40_sy(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E5E40_sz(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_002E5E40_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// in-place compiler-chosen normalise (the 1.0 parked in a GPR)
static inline void func_002E5E40_nrm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" "\n\t" "qmfc2.i %0, %2" : "=r"(r) : "r"(l.lVector), "j"(v.mData));
    asm(".set reorder");
    v.mData = r;
}
// the same, the result written back through the vector's address [G] (retail: addiu + sq 0(reg), then reloaded)
static inline void func_002E5E40_nrm2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" "\n\t" "qmfc2.i %0, %2" : "=r"(r) : "r"(l.lVector), "j"(v.mData));
    asm(".set reorder");
    asm("sq %1, 0(%2)" : "=m"(v.mData) : "r"(r), "r"(&v));
}
// cross product with the result on the first operand's register
static inline CGtV3d func_002E5E40_crs(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(t);
}
// CrossProduct (header operand order, result on the second operand's register) moved out with a .i qmfc2 [L] N185
static inline CGtV3d func_002E5E40_crs2(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
static inline void func_002E5E40_crs3(CGtV3d &o, CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    o.mData = t;
}
// [L] N185: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with compiler-chosen SetX/Y/Z(float) and the vmulx.w SetW(float).
static inline void func_002E5E40_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        float w = 0.5f * s;
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_002E5E40_sw(q.mRot, w);
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
            func_002E5E40_sx(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_002E5E40_sy(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_002E5E40_sz(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
static inline void func_002E5E40_sfmp(CGtQuatPos &qp, const CGtMatrix3x4& m)
{
    func_002E5E40_sfm(qp.mQuat, m);
    qp.mPos = m.mPos;
}

static inline CGtMatrix3x4 func_002E5E40_mk(const CGtV3d &r, const CGtV3d &u, const CGtV3d &a, const CGtV3d &p)
{
    CGtMatrix3x4 m;
    m.mRight = r;
    m.mUp = u;
    m.mAt = a;
    m.mPos = p;
    return m;
}

// [L] N185 stand-in for GtMathPs2::SinCosFast(float) (GtMathPs2Trig.h body; the trig I-constants as int locals where retail's
// scheduler lets them rise, as the archived BarUpdate__14CB3HUDBoostBarFf's copy, pass3c).
static inline u_long128 func_002E5E40_sc(float a)
{
    int k0 = 0x3FC90FDB;
    CGtV4d v;
    u_long128 w;
    u_long128 x, one, f, y, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v.mData));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(k0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xz %0, %1, $I" : "=j"(w) : "j"(v.mData));
    asm(".set reorder");
    int k3 = 0x3F000000;
    int k1 = 0xBE22F983;
    asm("vabs.xyzw %0, %1" : "=j"(x) : "j"(w));
    int k2 = 0x4B400000;
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I\n\tvmaddai.xyzw $ACC, %0, $I" : : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k3));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm("vabs.xyzw %0, %1" : "=j"(y) : "j"(f));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(y));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %1" : "=j"(t2) : "j"(t));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t4) : "j"(t2));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t8) : "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2992661));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(c1) : "j"(t));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %2" : "=j"(c3) : "j"(c1), "j"(t2));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2255DE0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(ca) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x42A33457));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cb) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x421ED7B7));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cc) : "j"(t));
    asm(".set reorder");
    int k4 = 0x40C90FDA;
    asm("vmula.xyzw $ACC, %0, %1" : : "j"(ca), "j"(t2));
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(c3), "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21" : : "r"(k4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(cb), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaddai.xyzw $ACC, %0, $I" : : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadd.xyzw %0, %1, %2" : "=j"(r) : "j"(cc), "j"(t8));
    asm(".set reorder");
    return r;
}

// [L] look-at basis (the E map's GtMathPs2::Matrix3x4SetLookAt(CGtV3d, CGtV3d) would fit; body [G]); mPos unwritten
static inline CGtMatrix3x4 func_002E5E40_la(CGtV3d at, const CGtV3d &up)
{
    CGtMatrix3x4 m;
    m.mAt = at;
    func_002E5E40_nrm(m.mAt);
    m.mRight = func_002E5E40_crs(up, m.mAt);
    func_002E5E40_nrm(m.mRight);
    m.mUp = CrossProduct(m.mAt, m.mRight);
    return m;
}

// 0x002E5E40
extern "C" void Update__18CB3BehaviourRotateFP9CGtCameraf(UnkStruct_002E5E40 * self, UnkStruct_002E5E40_cam * cam, float dt)
{
    self->field_50 += self->field_58 * (self->field_5C * dt);
    UnkStruct_002E5E40_body * body = D_0055EFEC[self->field_6C].field_0;
    CGtMatrix3x4 * bm = body->field_204;
    CGtV3d rig;
    GetRigPosition__14CB3CameraUtilsFPQ29GtMathPs26CGtV3dP16CB3CollidingBody(&rig, body);
    float d = bm->mPos.Y() - rig.Y();
    float h = GtMath::Min(d, 5.5f - self->field_60);
    self->field_10.mPos = bm->mPos;
    self->field_10.mPos.SetY(rig.Y() + h);
    CGtV3d r = CGtV3d(func_002E5E40_sc(0.01745329238f * self->field_50)) * self->field_64;
    CGtV3d off;
    off.SetX(r.X());
    off.SetY(self->field_60);
    func_002E5E40_inl1(off, r.Y());
    CGtMatrix3x4 cm;
    cm.mPos = TransformPoint(self->field_10, off);
    cm.mPos.SetY(cm.mPos.Y() - 1.0f);
    cm.mPos = func_002F5F40(&cm.mPos, self->field_70);
    cm.mPos.SetY(cm.mPos.Y() + 1.0f);
    CGtV3d at = bm->mPos;
    at.SetY(at.Y() + self->field_68);
    at -= cm.mPos;
    func_002E5E40_nrm(at);
    CGtMatrix3x4 m = Matrix3x4SetLookAt(at, kAxisY);
    m.mPos = cm.mPos;
    CGtMatrix3x4 t;
    t = m;
    cm = t;
    func_002E5E40_sfmp(cam->field_10, cm);
    cam->field_4 = 60.0f;
    float len = off.GetLength();
    CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(cam->field_30, cam, len - (float)body->field_1C0.W(), self->field_70);
}










