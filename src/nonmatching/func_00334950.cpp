// NONMATCHING: func_00334950 -- retail 337 / ours 341 instructions, 306 in changed runs
// ghvu18: logic complete from Ghidra+asm (DNAT CGtCameraFrustum::InitialisePerspective; ConstructPerspective call, near/far corner loop with b119p-hoisted scalars, kx/ky screen-edge offsets, 8 adjusted points, 4 planes = Normalise(Cross) + SetDistance(Dot) transposed into rows +0x60..0x90). 341 vs 337 instrs, 306 in changed runs. Left: frame 0x270 vs 0x4E0 (~39 dead 16-byte slots, no pad yet); self in s0 vs retail s3 (params rotated); VU numbering of the post-loop block (retail loads low vf1..vf6, differences vf8..vf13; retail re-loads p[2]/p[6] = rematerialisation); Normalise: retail creates the 1.0 before the square (vaddw.x vf2 then vmul vf3) -- the header GetSquaredLength order parks the square through a GPR here; on/of copies of m.mPos at 0x90/0x80 reproduced via two named copies + N129 reads
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00334950 -- hand-written (ghvu18): Ghidra draft + retail asm.
// [L] DNAT: CGtCameraFrustum::InitialisePerspective(const CGtMatrix3x4&, const CGtV2d&, const CGtV2d&, const CGtV2d&, float, float)
//     (research/proto/new_names.csv, high; B3INTERN map 0x544 bytes = retail's size). Sibling: CGtCameraFrustum::Initialise
//     (the four planes transposed into the rows at +0x60).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtCameraFrustum {
public:
    unsigned char pad_0[0x60];
    CGtV4d field_60[4];
};
extern "C" void ConstructPerspective__17CGtFrustumBuilderFP10CGtFrustumRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff(void *, const CGtMatrix3x4 &, const CGtV2d &, const CGtV2d &, float, float);

// [L] N185: CGtV3d * float with the scalar moved into $vf1 (the older hard-coded body), vector and result compiler-chosen
static inline CGtV3d func_00334950_inl0(const CGtV3d &v, float s) { u_long128 r; asm("qmtc2.ni %2, $vf1\n\tvmulx.xyz %0, %1, $vf1x" : "=j"(r) : "j"(v.mData), "r"(s)); return CGtV3d(r); }
// [L] N185: compiler-chosen CGtV3d::operator+(CGtV3d) / operator-(CGtV3d) (map: by value)
static inline CGtV3d func_00334950_inl1(const CGtV3d &a, CGtV3d b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00334950_inl2(const CGtV3d &a, CGtV3d b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185/N129: operator+(CGtV3d) with its by-value argument read through its address (the copy's slot stays)
static inline CGtV3d func_00334950_inl23(const CGtV3d &a, CGtV3d b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(*(const u_long128 *)&b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00334950_inl25(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(*(const u_long128 *)&b.mData)); return CGtV3d(r); }
// [L] N185: operator+ with the result moved out through a GPR (.i, fixup restores .ni)
static inline CGtV3d func_00334950_inl24(const CGtV3d &a, CGtV3d b) { u_long128 r, t; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); asm("qmfc2.i %0, %1" : "=r"(t) : "j"(r)); return CGtV3d(t); }
// [L] N185: CGtV3d::operator*=(float) (map 0x4C) on compiler-chosen registers
static inline void func_00334950_inl3(CGtV3d &v, float s) { u_long128 sv; asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s)); asm("vmulx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(sv)); }
// [L] N185: CrossProduct on compiler-chosen registers, the result out through a GPR (.i move, fixup restores .ni)
static inline CGtV3d func_00334950_inl4(CGtV3d a, CGtV3d b) { u_long128 r, t; asm("vopmula.xyz $ACC, %0, %1" : : "j"(a.mData), "j"(b.mData)); asm("vopmsub.xyz %0, %1, %2" : "=j"(r) : "j"(b.mData), "j"(a.mData)); asm("qmfc2.i %0, %1" : "=r"(t) : "j"(r)); return CGtV3d(t); }
// [L] N185: in-place Normalise on compiler-chosen registers (no 1.0*Q tail)
static inline void func_00334950_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r = v.mData;
    asm(".set noreorder");
    asm("vrsqrt $Q, $vf0w, %1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(r) : "j"(l.lVector));
    asm(".set reorder");
    v.mData = r;
}
// [L] N185: CGtPlane::SetDistance(XAxisType) on compiler-chosen registers
static inline void func_00334950_inl6(CGtPlane &p, XAxisType d) { asm("vmulx.w %0, $vf0, %1x" : "+j"(p.mData) : "j"(d.lVector)); }
// [L] N185: one lane of a plane into one lane of a row (as CGtCameraFrustumBase::Initialise)
static inline void func_00334950_inl7(CGtV4d &r, const CGtPlane &p) { asm("vaddx.x %0, $vf0, %1x" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl8(CGtV4d &r, const CGtPlane &p) { asm("vaddx.y %0, $vf0, %1x" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl9(CGtV4d &r, const CGtPlane &p) { asm("vaddx.z %0, $vf0, %1x" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl10(CGtV4d &r, const CGtPlane &p) { asm("vmulx.w %0, $vf0, %1x" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl11(CGtV4d &r, const CGtPlane &p) { asm("vaddy.x %0, $vf0, %1y" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl12(CGtV4d &r, const CGtPlane &p) { asm("vaddy.y %0, $vf0, %1y" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl13(CGtV4d &r, const CGtPlane &p) { asm("vaddy.z %0, $vf0, %1y" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl14(CGtV4d &r, const CGtPlane &p) { asm("vmuly.w %0, $vf0, %1y" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl15(CGtV4d &r, const CGtPlane &p) { asm("vaddz.x %0, $vf0, %1z" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl16(CGtV4d &r, const CGtPlane &p) { asm("vaddz.y %0, $vf0, %1z" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl17(CGtV4d &r, const CGtPlane &p) { asm("vaddz.z %0, $vf0, %1z" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl18(CGtV4d &r, const CGtPlane &p) { asm("vmulz.w %0, $vf0, %1z" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl19(CGtV4d &r, const CGtPlane &p) { asm("vaddw.x %0, $vf0, %1w" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl20(CGtV4d &r, const CGtPlane &p) { asm("vaddw.y %0, $vf0, %1w" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl21(CGtV4d &r, const CGtPlane &p) { asm("vaddw.z %0, $vf0, %1w" : "+j"(r.mData) : "j"(p.mData)); }
static inline void func_00334950_inl22(CGtV4d &r, const CGtPlane &p) { asm("vmulw.w %0, $vf0, %1w" : "+j"(r.mData) : "j"(p.mData)); }

// 0x00334950
extern "C" void func_00334950(CGtCameraFrustum *self, const CGtMatrix3x4 &m, const CGtV2d &size, const CGtV2d &a, const CGtV2d &b, float n, float f)
{
    CGtV3d p[8];
    CGtV3d q[8];
    CGtPlane pl[4];
    ConstructPerspective__17CGtFrustumBuilderFP10CGtFrustumRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff(self, m, a, b, n, f);
    CGtV3d d = func_00334950_inl0(m.mRight, -b.marValues[0]);
    CGtV3d d1 = func_00334950_inl0(m.mUp, b.marValues[1]);
    d = func_00334950_inl24(d, d1);
    CGtV3d x = func_00334950_inl0(m.mRight, a.marValues[0]);
    CGtV3d c = func_00334950_inl1(m.mAt, x);
    CGtV3d y = func_00334950_inl0(m.mUp, a.marValues[1]);
    p[0] = func_00334950_inl1(c, y);
    func_00334950_inl3(x, 2.0f);
    func_00334950_inl3(y, 2.0f);
    p[1] = func_00334950_inl2(p[0], x);
    p[2] = func_00334950_inl2(p[1], y);
    p[3] = func_00334950_inl1(p[2], x);
    CGtV3d pos0 = m.mPos;
    CGtV3d pos1 = m.mPos;
    for (int i = 0; i < 4; i++) {
        CGtV3d v = func_00334950_inl2(p[i], d);
        CGtV3d pn = func_00334950_inl23(d, pos0);
        pn += v * n;
        CGtV3d pf = func_00334950_inl23(d, pos1);
        pf += v * f;
        p[i] = pn;
        p[i + 4] = pf;
    }
    float hy = 0.5f * size.marValues[1];
    float hx = 0.5f * size.marValues[0];
    float ky = ((2047.937378f - hy) / hy - 1.0f) * 0.5f;
    float kx = ((2047.937378f - hx) / hx - 1.0f) * 0.5f;
    CGtV3d dyn = func_00334950_inl2(p[1], p[2]);
    CGtV3d dxn = func_00334950_inl2(p[3], p[2]);
    CGtV3d dyf = func_00334950_inl2(p[5], p[6]);
    CGtV3d dxf = func_00334950_inl2(p[7], p[6]);
    dyn = dyn * ky;
    dxn = dxn * kx;
    dyf = dyf * ky;
    dxf = dxf * kx;
    CGtV3d s = func_00334950_inl1(dyn, dxn);
    q[0] = func_00334950_inl1(p[0], s);
    q[2] = func_00334950_inl2(p[2], s);
    CGtV3d t = func_00334950_inl2(dyn, dxn);
    q[1] = func_00334950_inl1(p[1], t);
    q[3] = func_00334950_inl2(p[3], t);
    CGtV3d sf = func_00334950_inl1(dyf, dxf);
    q[4] = func_00334950_inl1(p[4], sf);
    q[6] = func_00334950_inl2(p[6], sf);
    CGtV3d tf = func_00334950_inl2(dyf, dxf);
    q[5] = func_00334950_inl1(p[5], tf);
    q[7] = func_00334950_inl2(p[7], tf);
    CGtV3d e1 = func_00334950_inl2(q[1], q[5]);
    CGtV3d n0 = func_00334950_inl4(e1, func_00334950_inl2(q[6], q[5]));
    func_00334950_inl5(n0);
    pl[0].SetNormal(n0);
    func_00334950_inl6(pl[0], DotProduct(q[1], n0));
    CGtV3d n1 = func_00334950_inl4(func_00334950_inl2(q[4], q[5]), e1);
    func_00334950_inl5(n1);
    pl[1].SetNormal(n1);
    func_00334950_inl6(pl[1], DotProduct(q[1], n1));
    CGtV3d e2 = func_00334950_inl2(q[3], q[7]);
    CGtV3d n2 = func_00334950_inl4(e2, func_00334950_inl2(q[4], q[7]));
    func_00334950_inl5(n2);
    pl[2].SetNormal(n2);
    func_00334950_inl6(pl[2], DotProduct(q[3], n2));
    CGtV3d n3 = func_00334950_inl4(func_00334950_inl2(q[6], q[7]), e2);
    func_00334950_inl5(n3);
    pl[3].SetNormal(n3);
    func_00334950_inl6(pl[3], DotProduct(q[3], n3));
    func_00334950_inl7(self->field_60[0], pl[0]);
    func_00334950_inl8(self->field_60[0], pl[1]);
    func_00334950_inl9(self->field_60[0], pl[2]);
    func_00334950_inl10(self->field_60[0], pl[3]);
    func_00334950_inl11(self->field_60[1], pl[0]);
    func_00334950_inl12(self->field_60[1], pl[1]);
    func_00334950_inl13(self->field_60[1], pl[2]);
    func_00334950_inl14(self->field_60[1], pl[3]);
    func_00334950_inl15(self->field_60[2], pl[0]);
    func_00334950_inl16(self->field_60[2], pl[1]);
    func_00334950_inl17(self->field_60[2], pl[2]);
    func_00334950_inl18(self->field_60[2], pl[3]);
    func_00334950_inl19(self->field_60[3], pl[0]);
    func_00334950_inl20(self->field_60[3], pl[1]);
    func_00334950_inl21(self->field_60[3], pl[2]);
    func_00334950_inl22(self->field_60[3], pl[3]);
}
