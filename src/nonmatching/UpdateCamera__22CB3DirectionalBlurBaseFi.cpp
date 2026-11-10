// NONMATCHING: UpdateCamera__22CB3DirectionalBlurBaseFi -- retail 604 / ours 626 instructions, 336 in changed runs
// ghvu22: first full draft (604 vs 630 instrs, 187 off with registers+sp masked). Logic/calls right: CGtQuatPos::ConvertToMatrix of the viewport camera, centre = mPos + mAt*10, crash-pulse branch (header CosFast4 * D_004D1550), motion-blur branch (ghvu21's proven orthonormal-invert inline, header TransformPoint/GetLength, Max). Header gaps: (1) retail's two N239 byte-loop copies come out of the header CGtQuatPos::ConvertToMatrix only with explicit intermediate matrices (stand-in), which adds ~26 NRV lq/sq instrs (N246); (2) retail calls __ct__Q29GtMathPs26CGtV4dF1 out of line inside CGtQuat::operator*(float) (inline depth) -- the plain header call does too, the stand-in loses it; (3) Y/Z/W lane reads (header copy-ctor asm) come out as addiu+lwc1 0(reg) in this big function where retail folds lwc1 K(sp) (also in hdr17's GetMatrix draft). Frame 0xA10 vs 0x7E0. | N262: scoped #pragma inline_depth [G] (gapF)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// UpdateCamera__22CB3DirectionalBlurBaseFi -- hand-written (ghvu22) from the Ghidra draft and the retail asm.
// Types/fields [G] (instruction widths; field_20 is a float here). Shape: the viewport camera matrix from the camera's
// CGtQuatPos (header CGtQuatPos::ConvertToMatrix, N241), the blur centre pushed 10 along mAt; then either the crash-start
// pulse (CosFast4, header GtMathPs2Trig.h) or the motion blur from the old centre's camera-space velocity.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
#pragma inline_depth(6)

struct UnkStruct_004256C0 {
    CGtV3d field_0;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
};
struct UnkStruct_004256C0_cam { unsigned char pad_0[0x10]; CGtQuatPos field_10; };
struct UnkStruct_004256C0_vp { unsigned char pad_0[0x68]; UnkStruct_004256C0_cam * field_68; };
struct UnkStruct_004256C0_car { unsigned char pad_0[0x3534]; float field_3534; };
struct UnkStruct_004256C0_fx { unsigned char pad_0[0x52]; unsigned char field_52; };
struct UnkStruct_004256C0_e3 { unsigned long field_0; unsigned char pad_8[0xBA8]; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_004256C0_vp * D_00666270[4];
extern UnkStruct_004256C0_e3 D_005179C0[];
extern unsigned char D_004EE040[];
extern unsigned char D_00522660[];
extern CGtV4d D_004D1540;
extern CGtV4d D_004D1550;
extern "C" float func_0030A990(UnkStruct_004256C0_fx *);

// [L] N185 stand-ins (copied from func_00356FB0): orthonormal invert of a 3x4 matrix in place.
static inline void func_004256C0_inl1(CGtV3d &d, const CGtV3d &s) { asm("vadd.xyz %0, %0, %1" : "+j"(d.mData) : "j"(s.mData)); }
static inline CGtV3d func_004256C0_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_004256C0_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_004256C0_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_004256C0_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_004256C0_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_004256C0_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline void func_004256C0_inl0(CGtMatrix3x4 &r)
{
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_004256C0_r0(r.mRight, b, c);
    func_004256C0_r1(r.mUp, a, c);
    func_004256C0_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_004256C0_inl5(r.mAt, p);
    CGtV3d x = func_004256C0_inl3(r.mRight, p);
    CGtV3d t = x + func_004256C0_inl4(r.mUp, p);
    func_004256C0_inl1(t, z);
    r.mPos = -t;
}

// [L] N185: ZAxisType - float (the header has the YAxisType form only): the scalar by its own qmtc2.ni, then vsubx.z.
static inline ZAxisType func_004256C0_zsub(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }

// [L] N185 stand-in for CGtQuatPos::ConvertToMatrix (header body, N241) with explicit intermediate matrices: b119p gives the
// N239 byte-loop copy only into a matrix that is merely copied on (retail: m -> bytes -> lq -> +pos -> bytes -> lq; the
// header's `m = mQuat.ConvertToMatrix()` copies with lq/sq here, cf. N246).
static inline CGtMatrix3x4 func_004256C0_ctm(const CGtQuatPos &qp)
{
    CGtMatrix3x4 q = ((CGtQuat &)qp.mQuat).ConvertToMatrix();
    CGtMatrix3x4 x;
    x = q;
    CGtMatrix3x4 m;
    m = x;
    m.mPos = qp.mPos;
    return m;
}
// 0x004256C0
extern "C" int UpdateCamera__22CB3DirectionalBlurBaseFi(UnkStruct_004256C0 * self, int idx)
{
    float now = D_004F50A0.field_0;
    CGtV3d old = self->field_0;
    float last = self->field_24;
    CGtMatrix3x4 r = func_004256C0_ctm(D_00666270[0]->field_68->field_10);
    CGtMatrix3x4 z;
    z = r;
    CGtMatrix3x4 cm;
    cm = z;
    self->field_0 = cm.mPos + cm.mAt * 10.0f;
    self->field_24 = now;
    self->field_20 = 0.0f;
    unsigned char * base = D_00522660 + idx * 0x27D0;
    UnkStruct_004256C0_fx * fx = (UnkStruct_004256C0_fx *)(base + 0x12BEDC);
    UnkStruct_004256C0_car * car = *(UnkStruct_004256C0_car **)(base + 0x12D180);
    if (car == 0)
        return 0;
    float t;
    if (car->field_3534 > 0.0f && (D_005179C0[idx].field_0 & 0x2000) == 0 && (t = D_00522680.field_0 - car->field_3534) < 0.3f) {
        CGtV4d c = CosFast4(D_004D1540 * t) * D_004D1550;
        float k = 3.333333254f * t;
        k = 1.0f - k * k;
        self->field_10 = c.X() + c.Y();
        self->field_14 = c.Z() + c.W();
        float len = GtMath::Sqrt(self->field_14 * self->field_14 + self->field_10 * self->field_10);
        self->field_10 += 0.5f;
        float s = 1.0f - 0.0120000001f * (0.1000000015f + 0.8999999762f * k) / (0.5f + len);
        self->field_14 += 0.5f;
        self->field_20 = k;
        self->field_18 = s;
        self->field_1C = s;
        return 1;
    }
    if ((D_005179C0[idx].field_0 & 0x400) == 0) {
        if (fx->field_52 == 0)
            return 0;
        if (!(func_0030A990(fx) > 0.0f))
            return 0;
    }
    CGtMatrix3x4 inv = cm;
    func_004256C0_inl0(inv);
    CGtV3d p = TransformPoint(inv, old);
    float dt = now - last;
    if (dt <= 0.0f)
        return 1;
    p.SetZ(func_004256C0_zsub(p.Z(), 10.0f));
    CGtV3d vel = p * (1.0f / dt);
    float a = 0.02040816285f * ((float)vel.GetLength() - 1.0f);
    if (a < 0.007843137719f)
        return 1;
    if (a > 1.0f)
        a = 1.0f;
    if (vel.Z() < 0.0f)
        vel = -vel;
    CGtV3d dir = vel * (0.9980000257f / GtMath::Max(vel.Z(), 0.009999999776f));
    float ox, oy;
    if (dir.X() > 0.0f) ox = 0.0f; else ox = 1.0f;
    if (dir.Y() > 0.0f) oy = 0.0f; else oy = 1.0f;
    self->field_10 = dir.X() + 0.5f;
    self->field_14 = dir.Y() + 0.5f;
    CGtV2d d(self->field_10 - ox, self->field_14 - oy);
    CGtV2d e = d;
    float s = 1.0f - 0.0120000001f * (0.5f + 0.5f * a) / GtMath::Sqrt(e.X() * e.X() + e.Y() * e.Y());
    self->field_18 = s;
    self->field_1C = s;
    self->field_20 = a;
    if (fx->field_52 != 0) {
        unsigned long f = *(unsigned long *)((unsigned int)idx * 0xBB0 + ((unsigned int)D_004EE040 + 0x29980));
        if ((f & 4) != 0 || (f & 0x20) != 0)
            self->field_20 *= func_0030A990(fx);
    }
    return 1;
}

