// NONMATCHING: func_00429BE0 -- retail 574 / ours 573 instructions, 439 in changed runs
// ghvu22: first full draft, 574/574 instrs, 95 off with registers+sp masked. Logic/calls right: angle wrap, axis-angle rotation matrix stand-in ([L] E map CreateRotationMatrix3x4(CGtV3d,float), decoded lane by lane), pushed back along mAt, look-at onto field_60 (same look-at inline as Update__18CB3BehaviourRotate), local SetFromMatrix copy, viewport attach. Left: rotation-row/SetFromMatrix lane-op register numbering, CSE of the D_004D1590 loads (volatile pun used), matrix copy chain slots, frame 0xF70 vs 0x4C0 (dead slots), GPR numbering. | N266-N268 header APIs (gapH)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00429BE0 -- hand-written (ghvu22) from the Ghidra draft and the retail asm. [G] by its neighbours (func_0042A4E0 =
// CB3CarViewComponent::UpdateLoadState, new_names.csv medium; field_9E the vehicle index as in func_0042AFC0) this is a car-view
// orbit camera update (the E map's CB3CarViewComponent::UpdateCamera(float) would fit) -- placeholder, not renamed. Types [G].
// Shape: angle += 20*dt (wrapped at 360); a rotation about D_004D1590 by that angle (the E map's CreateRotationMatrix3x4(CGtV3d,
// float) would fit; local stand-in), pushed back along its at row, then a look-at onto field_60, written into the camera's
// CGtQuatPos (SetFromMatrix) and attached to viewport 1.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_00429BE0_vt { unsigned char pad_0[0x18]; void (*vfunc_18)(void *, float); };
struct UnkStruct_00429BE0 {
    unsigned char pad_0[0x20];
    UnkStruct_00429BE0_vt * field_20;     // camera object at +0x20 (vptr first) [G]
    float field_24;
    unsigned char pad_28[0x8];
    CGtQuatPos field_30;
    unsigned char pad_50[0x10];
    CGtV3d field_60;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    unsigned char field_80;
    unsigned char pad_81[0x1D];
    signed char field_9E;
};
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F509C D_004F509C;
extern CGtV3d D_004D1590;
extern unsigned char D_00665EC0[];
extern "C" void AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(void *, int, void *);
extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);

// [L] N185 stand-ins: compiler-chosen lane ops the header has only in hard-coded or other forms.
static inline void func_00429BE0_sx(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_00429BE0_sy(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_00429BE0_sz(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
static inline void func_00429BE0_sw(CGtV4d &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(d.mData) : "j"(s)); }
// in-place compiler-chosen normalise (the 1.0 parked in a GPR)
static inline void func_00429BE0_nrm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" "\n\t" "qmfc2.i %0, %2" : "=r"(r) : "r"(l.lVector), "j"(v.mData));
    asm(".set reorder");
    v.mData = r;
}
// the same, the result written back through the vector's address [G] (retail: addiu + sq 0(reg), then reloaded)
// cross product with the result on the first operand's register
static inline CGtV3d func_00429BE0_crs(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(t);
}
// CrossProduct (header operand order, result on the second operand's register) moved out with a .i qmfc2 [L] N185
static inline CGtV3d func_00429BE0_crs2(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: CGtQuat::SetFromMatrix (GtMathPs2Quat.h body) with compiler-chosen SetX/Y/Z(float) and the vmulx.w SetW(float).
static inline void func_00429BE0_sfm(CGtQuat &q, const CGtMatrix3x4& m)
{
    float trace = m.mRight.X() + m.mUp.Y() + m.mAt.Z();
    if (trace > 0.0f) {
        float s = GtMath::Sqrt(trace + 1.0f);
        q.mRot.SetX(m.mUp.Z() - m.mAt.Y());
        q.mRot.SetY(m.mAt.X() - m.mRight.Z());
        float w = 0.5f * s;
        q.mRot.SetZ(m.mRight.Y() - m.mUp.X());
        q.mRot *= 0.5f / s;
        func_00429BE0_sw(q.mRot, w);
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
            func_00429BE0_sx(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mUp.Z() - m.mAt.Y()) * s);
            q.mRot.SetY((m.mRight.Y() + m.mUp.X()) * s);
            q.mRot.SetZ((m.mRight.Z() + m.mAt.X()) * s);
            break;
        }
        case 1: {
            float s = GtMath::Sqrt(m.mUp.Y() - (m.mAt.Z() + m.mRight.X()) + 1.0f);
            func_00429BE0_sy(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mAt.X() - m.mRight.Z()) * s);
            q.mRot.SetZ((m.mUp.Z() + m.mAt.Y()) * s);
            q.mRot.SetX((m.mUp.X() + m.mRight.Y()) * s);
            break;
        }
        case 2: {
            float s = GtMath::Sqrt(m.mAt.Z() - (m.mRight.X() + m.mUp.Y()) + 1.0f);
            func_00429BE0_sz(q.mRot, 0.5f * s);
            s = 0.5f / s;
            q.mRot.SetW((m.mRight.Y() - m.mUp.X()) * s);
            q.mRot.SetX((m.mAt.X() + m.mRight.Z()) * s);
            q.mRot.SetY((m.mAt.Y() + m.mUp.Z()) * s);
            break;
        }
        }
    }
}
static inline void func_00429BE0_sfmp(CGtQuatPos &qp, const CGtMatrix3x4& m)
{
    func_00429BE0_sfm(qp.mQuat, m);
    qp.mPos = m.mPos;
}


// [L] N185 stand-in for GtMathPs2::SinCosFast(float) (GtMathPs2Trig.h body; the trig I-constants as int locals where retail's
// scheduler lets them rise, as the archived BarUpdate__14CB3HUDBoostBarFf's copy, pass3c).
static inline u_long128 func_00429BE0_sc(float a)
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
static inline CGtMatrix3x4 func_00429BE0_la(CGtV3d at, const CGtV3d &up)
{
    CGtMatrix3x4 m;
    m.mAt = at;
    func_00429BE0_nrm(m.mAt);
    m.mRight = func_00429BE0_crs(CGtV3d(*(volatile const u_long128 *)&up.mData), m.mAt);
    func_00429BE0_nrm(m.mRight);
    m.mUp = CrossProduct(m.mAt, m.mRight);
    return m;
}

// [L] N185 lane-op stand-ins (compiler-chosen registers) for the rotation-matrix inline below.
#define OPN(name, text) static inline u_long128 name(u_long128 a, u_long128 b) { u_long128 r; asm(text : "=j"(r) : "j"(a), "j"(b)); return r; }
#define OPI(name, text) static inline void name(u_long128 &d, u_long128 a) { asm(text : "+j"(d) : "j"(a)); }
OPN(func_00429BE0_subyx, "vsuby.x %0, %1, %2y")
OPN(func_00429BE0_subxx, "vsubx.x %0, %1, %2x")
OPN(func_00429BE0_subyy, "vsuby.y %0, %1, %2y")
OPN(func_00429BE0_subzz, "vsubz.z %0, %1, %2z")
OPN(func_00429BE0_subzx, "vsubz.x %0, %1, %2z")
OPN(func_00429BE0_addzz, "vaddz.z %0, %1, %2z")
OPN(func_00429BE0_addxx, "vaddx.x %0, %1, %2x")
OPN(func_00429BE0_addyy, "vaddy.y %0, %1, %2y")
OPN(func_00429BE0_mul, "vmul.xyz %0, %1, %2")
OPN(func_00429BE0_mulzy, "vmulz.y %0, %1, %2z")
OPN(func_00429BE0_mulxz, "vmulx.z %0, %1, %2x")
OPN(func_00429BE0_mulyx, "vmuly.x %0, %1, %2y")
OPN(func_00429BE0_mulx, "vmulx.xyz %0, %1, %2x")
OPI(func_00429BE0_setzx, "vaddx.z %0, $vf0, %1x")
OPI(func_00429BE0_setxy, "vaddy.x %0, $vf0, %1y")
OPI(func_00429BE0_setyz, "vaddz.y %0, $vf0, %1z")
OPI(func_00429BE0_setxx, "vaddx.x %0, $vf0, %1x")
OPI(func_00429BE0_setyy, "vaddy.y %0, $vf0, %1y")
OPI(func_00429BE0_setxz, "vaddz.x %0, $vf0, %1z")
OPI(func_00429BE0_setyx, "vaddx.y %0, $vf0, %1x")
OPI(func_00429BE0_setzy, "vaddy.z %0, $vf0, %1y")
OPI(func_00429BE0_addbx, "vaddx.xyz %0, %0, %1x")
OPI(func_00429BE0_mulbz, "vmulz.xyz %0, %0, %1z")
static inline u_long128 func_00429BE0_neg(u_long128 a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_00429BE0_zero() { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); return r; }

// [L] N185: the header Normalise's body as a value-returning helper reading its operand in place (retail loads the
// constant axis twice, lqc2 for the square and lq for the scale: the [G] volatile re-read pun of the proven
// B3VehiclePhysics_001CB780.cpp inl3)
static inline CGtV3d func_00429BE0_nrmd(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "qmtc2 %1, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" : "=r"(r.mData) : "r"(*(volatile const u_long128 *)&v.mData));
    asm(".set reorder");
    return r;
}
// [L] a rotation matrix about a unit axis (the E map's GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float), 1372 bytes, would fit;
// body [G] decoded from retail 0x429E70..0x429EE8): s/c from SinCosFast, k = 1 - c,
// rows R = (1 - (1-xx)k, xy k + z s, zx k - y s), U = (xy k - z s, 1 - (1-yy)k, yz k + x s), A = (zx k + y s, yz k - x s, 1 - (1-zz)k).
static inline void func_00429BE0_rot(CGtMatrix3x4 &m, const CGtV3d &ax, float angle)
{
    CGtV3d one;
    one.SetX(1.0f);
    CGtV3d axis = func_00429BE0_nrmd(ax);
    u_long128 sc = func_00429BE0_sc(angle);
    func_00429BE0_setzx(sc, func_00429BE0_subyx(one.mData, sc));
    u_long128 n = func_00429BE0_neg(func_00429BE0_mul(axis.mData, axis.mData));
    CGtV3d t;
    func_00429BE0_setxy(t.mData, func_00429BE0_mulzy(axis.mData, axis.mData));
    func_00429BE0_setyz(t.mData, func_00429BE0_mulxz(axis.mData, axis.mData));
    func_00429BE0_addbx(n, one.mData);
    func_00429BE0_setzx(t.mData, func_00429BE0_mulyx(axis.mData, axis.mData));
    func_00429BE0_mulbz(n, sc);
    u_long128 as = func_00429BE0_mulx(axis.mData, sc);
    func_00429BE0_mulbz(t.mData, sc);
    func_00429BE0_setxx(m.mRight.mData, func_00429BE0_subxx(one.mData, n));
    func_00429BE0_setyz(m.mRight.mData, func_00429BE0_addzz(t.mData, as));
    func_00429BE0_setzy(m.mRight.mData, func_00429BE0_subyy(t.mData, as));
    func_00429BE0_setxz(m.mUp.mData, func_00429BE0_subzz(t.mData, as));
    func_00429BE0_setyx(m.mUp.mData, func_00429BE0_subyx(one.mData, n));
    func_00429BE0_setzx(m.mUp.mData, func_00429BE0_addxx(t.mData, as));
    func_00429BE0_setxy(m.mAt.mData, func_00429BE0_addyy(t.mData, as));
    func_00429BE0_setyx(m.mAt.mData, func_00429BE0_subxx(t.mData, as));
    m.mPos.mData = func_00429BE0_zero();
    func_00429BE0_setzx(m.mAt.mData, func_00429BE0_subzx(one.mData, n));
}

// 0x00429BE0
extern "C" void func_00429BE0(UnkStruct_00429BE0 * self, float dt)
{
    self->field_24 = 45.0f / self->field_7C;
    float a = self->field_78 + 20.0f * dt;
    self->field_78 = a;
    if (a > 360.0f)
        self->field_78 = a - 360.0f;
    CGtMatrix3x4 cm;
    {
        CGtMatrix3x4 r;
        func_00429BE0_rot(r, D_004D1590, 0.01745329238f * self->field_78);
        CGtMatrix3x4 t;
        t = r;
        cm = t;
    }
    cm.mPos = cm.mAt * -self->field_74;
    cm.mPos.SetY(self->field_70);
    if (self->field_9E > -1)
        cm.mPos.SetX(cm.mPos.X() + 0.0f);
    CGtV3d at = self->field_60 - cm.mPos;
    func_00429BE0_nrm(at);
    CGtMatrix3x4 m = Matrix3x4SetLookAt(at, D_004D1590);
    m.mPos = cm.mPos;
    CGtMatrix3x4 t;
    t = m;
    cm = t;
    if (self->field_80 != 0)
        cm.mPos -= cm.mRight * -1.0f;
    func_00429BE0_sfmp(self->field_30, cm);
    AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(D_00665EC0, 1, &self->field_20);
    self->field_20->vfunc_18(&self->field_20, D_004F509C.field_0);
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(D_00665EC0, 1);
}



