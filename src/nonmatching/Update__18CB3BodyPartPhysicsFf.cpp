// NONMATCHING: Update__18CB3BodyPartPhysicsFf -- retail 173 / ours 171 instructions, 26 in changed runs
// near24 (167/173 28 off -> 171/173 26 off, frame exact): projection inline = header DotProduct(axis, v) + qmtc2 of the dot + vmulx.xyz with the axis read as *(volatile u_long128*)&axis.mData (gives retail's addiu+lqc2 0(reg) reload); pad2 0x40. Left: retail loads E0 before the axis for the dot (vf2/vf3), holds &E0 (addiu v0,s0,0xE0) for the second dot's lqc2 0(v0) -- 2 instrs short
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// v279: hand-written (lifter refused), 167/173, 28 off. Exact: prologue, W() drag (s = -1.0f; s *= w*w; t = C0 * s; F0 += t), the 0.98 damping arm, nested field_212 tests (DotProduct + GtMath::Abs, D_004C9CD0 zero), frame 0x230 (N140 pads 0x110 in the invert inline + 0x30 per projection inline), the rotate + orthonormal-invert block (func_00333740's inline with -=). Left: the two E0 -= axis * DotProduct(axis, E0) projections -- retail reloads the axis for the multiply through a held address (addiu v1,a0,0x20) and reads E0 for the second dot through addiu v0,s0,0xE0; ours CSEs both loads (6 instrs short). By-value/pointer/ref inline params, named XAxisType/float d, local by-ref dot/mul stand-ins all CSE
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// Hand-written (v279); the lifter refused it.
// CB3BodyPartPhysics::Update(float) [C name: config/symbol_addrs_b3names.txt]. Defined through its link name with a
// local layout (the consolidated class header has only padding there). Types/fields placeholders [G].
// Drag on field_F0 by field_B0.w^2, damping/zeroing of field_E0 against the matrix axes, the base Update, then (state 1)
// the rotate + orthonormal-invert block also inlined in func_00333740 (here with -=).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
struct UnkStruct_00334010 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    CGtV4d field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x10];
    CGtV3d field_E0;
    CGtV3d field_F0;
    unsigned char pad_100[0x70];
    CGtV3d field_170;
    unsigned char pad_180[0x84];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xA];
    unsigned char field_212;
    unsigned char pad_213[3];
    signed char field_216;
    unsigned char pad_217[0x49];
    CGtV3d field_260;
    unsigned char pad_270[0x44];
    float field_2B4;
    unsigned char pad_2B8[2];
    unsigned char field_2BA;
    unsigned char pad_2BB[0x215];
    unsigned char field_4D0;
};
extern "C" void Update__16CB3CollidingBodyFf(void *, float);
extern const CGtV3d D_004C9CD0;
// [L] N185 stand-ins (as func_00333740's): a 3-row rotate (TransformPoint without the translation row), lane-scaled
// products by another vector's x/y/z lane, and the per-row lane copies of an in-place 3x3 transpose.
static inline CGtV3d func_00334010_inl1(const CGtMatrix3x4 &m, CGtV3d v)
{
    u_long128 t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %2y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %2z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(m.mRight.mData), "j"(v.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}
static inline void func_00334010_inl2(CGtV3d &a, const CGtV3d &b) { asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
static inline CGtV3d func_00334010_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00334010_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00334010_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00334010_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00334010_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00334010_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
// [G] N140 pad: dead slots of the inlined matrix code (as func_00333740's, one per inline copy)
struct UnkStruct_00334010_pad { int x[68]; UnkStruct_00334010_pad() {} ~UnkStruct_00334010_pad() {} };
struct UnkStruct_00334010_pad2 { int x[16]; UnkStruct_00334010_pad2() {} ~UnkStruct_00334010_pad2() {} };
static inline void func_00334010_inl0(UnkStruct_00334010 * self)
{
    UnkStruct_00334010_pad pad;
    CGtMatrix3x4 * m = self->field_204;
    m->mPos -= func_00334010_inl1(*m, self->field_260);
    self->field_70 = *self->field_204;
    CGtMatrix3x4 &r = self->field_70;
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_00334010_r0(r.mRight, b, c);
    func_00334010_r1(r.mUp, a, c);
    func_00334010_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_00334010_inl5(r.mAt, p);
    CGtV3d x = func_00334010_inl3(r.mRight, p);
    CGtV3d t = x + func_00334010_inl4(r.mUp, p);
    func_00334010_inl2(t, z);
    r.mPos = -t;
}
// [L] N185 stand-in: v -= axis * DotProduct(axis, v) with both vectors read through their addresses (retail 0x3340FC:
// `addiu v1,a0,0x20` held, the axis reloaded `lqc2 $vf2,0(v1)` for the multiply; the second copy reads E0 through the
// first copy's `addiu v0,s0,0xE0`)
static inline void func_00334010_inl6(CGtV3d &v, const CGtV3d &axis)
{
    UnkStruct_00334010_pad2 pad;
    XAxisType dd = DotProduct(axis, v);
    u_long128 a2, sc, r;
    asm("qmtc2 %1, %0" : "=j"(sc) : "r"(dd.lVector));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(*(volatile u_long128 *)&axis.mData), "j"(sc));
    v -= CGtV3d(r);
}
// 0x00334010
extern "C" void Update__18CB3BodyPartPhysicsFf(UnkStruct_00334010 * self, float dt)
{
    if (self->field_4D0 != 0) {
        self->field_4D0 = 0;
        return;
    }
    if (self->field_216 == -1) return;
    float w = self->field_B0.W();
    float s = -1.0f;
    s *= w * w;
    CGtV3d t = self->field_C0 * s;
    self->field_F0 += t;
    if (self->field_2BA != 0) {
        self->field_E0 = self->field_E0 * 0.98f;
    } else {
        if (self->field_212 != 0) {
            float a = GtMath::Abs(DotProduct(self->field_204->mRight, self->field_170));
            if (w < 0.1f && a < 0.1f) self->field_E0 = D_004C9CD0;
            if (self->field_212 != 0 && a < 0.1f) {
                func_00334010_inl6(self->field_E0, self->field_204->mAt);
                func_00334010_inl6(self->field_E0, self->field_204->mUp);
            }
        }
    }
    Update__16CB3CollidingBodyFf(self, dt);
    if (self->field_2BA == 1) func_00334010_inl0(self);
    self->field_2B4 += dt;
}



