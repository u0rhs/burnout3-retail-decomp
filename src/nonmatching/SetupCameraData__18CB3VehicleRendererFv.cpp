// NONMATCHING: SetupCameraData__18CB3VehicleRendererFv -- retail 148 / ours 144 instructions, 56 in changed runs
// 144/148, 56 off. Logic believed right: field_B0 = camera 0 matrix (D_00666330+0xA0); fwd = pos - zero, -at if squared length < 2^-32 (goto out-of-line), header Normalise; right = up x fwd (result on first operand, .i) + compiler-chosen Normalise; up = fwd x right (.i); field_70 = {right, up, fwd, zero} then the func_00333740 orthonormal invert; _rwDMAOpenVIFPkt(0, 15) + 3 GIF quads + 10 quads from D_00666450. Left: retail addresses fwd/zero through pointer registers (addiu v1,sp,0x170 / v0,sp,0x180 held), right/up dead-stored to their slots (0x150/0x160), camera base in a2 (ours re-lui's), N140 pad 0xE0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleRenderer::SetupCameraData() -- hand-matched (ghvu8). Builds a look-at camera matrix from the current
// render camera (gGraphicsManager camera 0), inverts it in place (orthonormal: the func_00333740 stand-ins) and opens
// a VIF packet with a GIF tag + the camera's 10 quads [G].
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

// [G] camera 0 of the graphics manager (D_00665EC0 + 0x470)
struct UnkStruct_D_00666330 {
    unsigned char pad_0[0xA0];
    CGtMatrix3x4 field_A0;
};
struct UnkStruct_farFogPlane { u_long128 *field_0; };

class CB3VehicleRenderer {
public:
    void SetupCameraData();
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    CGtMatrix3x4 field_B0;
};

extern UnkStruct_D_00666330 D_00666330;
extern u_long128 D_00666450[10];   // [G] camera 0's quads (D_00666330 + 0x120), as retail addresses them
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// [L] N185 stand-ins (as func_00333740's, compiler-chosen VU registers)
static inline void SetupCameraData_inl2(CGtV3d &a, const CGtV3d &b) { asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
static inline CGtV3d SetupCameraData_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d SetupCameraData_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d SetupCameraData_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void SetupCameraData_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void SetupCameraData_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void SetupCameraData_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
// [L] N185: zero vector, compiler-chosen (the header's Zero() hard-codes $vf1)
static inline void SetupCameraData_inl6(CGtV3d &v) { u_long128 t; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t)); v.mData = t; }
// [L] N185: CGtV3d - CGtV3d / unary minus on compiler-chosen registers
static inline CGtV3d SetupCameraData_inl7(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d SetupCameraData_inl8(const CGtV3d &a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a.mData)); return CGtV3d(r); }
// [L] N185: a x b with the result on a's register, out .i (retail's vopmula/vopmsub operand order)
static inline CGtV3d SetupCameraData_inl9(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: Normalise on the vector's own (compiler-chosen) register, result out through a GPR
static inline void SetupCameraData_inl10(CGtV3d &v) {
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(r) : "j"(v.mData));
    v.mData = r;
}

// [L] N185: CrossProduct (header operand order) with the result moved out .i (the fixup restores .ni; retail keeps qmfc2 + sq)
static inline CGtV3d SetupCameraData_inl11(CGtV3d a, CGtV3d b) {
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
// [G] N140: dead 16-byte frame slots (inline temporaries) below the named vectors
struct UnkStruct_002208E0_pad { int x[56]; UnkStruct_002208E0_pad() {} ~UnkStruct_002208E0_pad() {} };

// 0x002208E0
void CB3VehicleRenderer::SetupCameraData()
{
    CGtV3d zero;
    CGtV3d fwd;
    CGtV3d up;
    CGtV3d right;
    UnkStruct_002208E0_pad pad;
    const void *pf = &fwd;
    UnkStruct_D_00666330 * const cam = &D_00666330;
    SetupCameraData_inl6(zero);
    field_B0 = cam->field_A0;
    fwd = SetupCameraData_inl7(field_B0.mPos, zero);
    if (fwd.GetSquaredLength() < 2.3283064e-10f) goto degen;
back:
    fwd.Normalise();
    right = SetupCameraData_inl9(field_B0.mUp, fwd);
    SetupCameraData_inl10(right);
    const void *pr = &right;
    const void *pu = &up;
    up = SetupCameraData_inl11(fwd, right);
    field_70.mRight = *(const CGtV3d *)pr;
    field_70.mUp = *(const CGtV3d *)pu;
    field_70.mAt = fwd;
    field_70.mPos = zero;
    {
        CGtMatrix3x4 &r = field_70;
        CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
        SetupCameraData_r0(r.mRight, b, c);
        SetupCameraData_r1(r.mUp, a, c);
        SetupCameraData_r2(r.mAt, a, b);
        CGtV3d p = r.mPos;
        CGtV3d z = SetupCameraData_inl5(r.mAt, p);
        CGtV3d x = SetupCameraData_inl3(r.mRight, p);
        CGtV3d t = x + SetupCameraData_inl4(r.mUp, p);
        SetupCameraData_inl2(t, z);
        r.mPos = -t;
    }
    _rwDMAOpenVIFPkt(0, 0xF);
    u_long128 *q = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x10000001UL), "r"(0UL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x11000000UL), "r"(0x11000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x1000000AUL), "r"(0x6C0A03F601000404UL));
    for (int i = 0; i < 10; i++) {
        *q++ = D_00666450[i];
    }
    farFogPlane.field_0 = q;
    return;
degen:
    fwd = SetupCameraData_inl8(field_B0.mAt);
    ((float *)&fwd)[3] = ((const float *)&field_B0.mAt)[3]; // [C] 0x220B14 lqc2 vf1, 0xD0(a0) (field_B0.mAt); 0x220B18 vsub.xyz vf1,
    // vf0, vf1 keeps its w; 0x220B20 sqc2 vf1 -- inl8's "=j" output leaves w undefined (the port's asm translator takes it from vf0)
    goto back;
}
