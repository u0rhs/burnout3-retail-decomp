// Hand-written; the lifter refused it (v257: CollideWithWorld [L DNAT]; inlined rotate + orthonormal invert (per-row transpose asm, header operator+ for x+y, += z, unary -), N140 pad 0x100 per inline copy).

// Hand-written (v257); the lifter refused it.
// [L] DNAT: CB3BodyPartPhysics::CollideWithWorld() (research/proto/new_names.csv, medium). Types/fields placeholders [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00333740_sp { int field_0; void * field_4; void * field_8; };
struct UnkStruct_00333740 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x150];
    UnkStruct_00333740_sp * field_200;
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F[0x51];
    CGtV3d field_260;
    unsigned char pad_270[0x4A];
    unsigned char field_2BA;
};
extern "C" void CacheWorldTriangles__16CB3CollidingBodyFv(void *);
extern "C" void CollideWithWorld__16CB3CollidingBodyFv(void *);
extern "C" void CollideWheelWithWorld__18CB3BodyPartPhysicsFv(void *);
// [L] N185 stand-ins for GtMathPs2 inlines missing from the header (compiler-chosen VU registers): a 3-row rotate
// (TransformPoint without the translation row, retail vmulax/vmadday/vmaddz), operator+= (vadd.xyz d,d,s), lane-scaled
// products by another vector's x/y/z lane, and the per-row lane copies of an in-place 3x3 transpose. The inlined body
// (twice, retail order) rotates field_260 into the matrix position, copies the matrix to field_70 and inverts it in
// place (orthonormal: transpose, pos = -(r0*p.x + r1*p.y + r2*p.z)); the API name is not in our tables (placeholder).
static inline CGtV3d func_00333740_inl1(const CGtMatrix3x4 &m, CGtV3d v)
{
    u_long128 t;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %2y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %2z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(m.mRight.mData), "j"(v.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}
static inline void func_00333740_inl2(CGtV3d &a, const CGtV3d &b) { asm("vadd.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }
static inline CGtV3d func_00333740_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00333740_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00333740_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00333740_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00333740_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00333740_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
// [G] N140 pad: retail's frame is 0x200 larger with no stack access at all (dead slots of the inlined matrix code, 16 per copy)
struct UnkStruct_00333740_pad { int x[64]; UnkStruct_00333740_pad() {} ~UnkStruct_00333740_pad() {} };
static inline void func_00333740_inl0(UnkStruct_00333740 * self)
{
    UnkStruct_00333740_pad pad;
    CGtMatrix3x4 * m = self->field_204;
    func_00333740_inl2(m->mPos, func_00333740_inl1(*m, self->field_260));
    self->field_70 = *self->field_204;
    CGtMatrix3x4 &r = self->field_70;
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_00333740_r0(r.mRight, b, c);
    func_00333740_r1(r.mUp, a, c);
    func_00333740_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_00333740_inl5(r.mAt, p);
    CGtV3d x = func_00333740_inl3(r.mRight, p);
    CGtV3d t = x + func_00333740_inl4(r.mUp, p);
    func_00333740_inl2(t, z);
    r.mPos = -t;
}

// 0x00333740
extern "C" void func_00333740(UnkStruct_00333740 * self)
{
    UnkStruct_00333740_sp * saved = self->field_200;
    if (self->field_20E != 0) {
        if (self->field_2BA == 1)
            func_00333740_inl0(self);
        return;
    }
    self->field_200 = (UnkStruct_00333740_sp *)0x70002000;
    UnkStruct_00333740_sp * s = self->field_200;
    s->field_0 = 0;
    s->field_4 = (char *)s + 0x10;
    s->field_8 = (char *)s + 0x1810;
    if (self->field_2BA == 0) {
        CacheWorldTriangles__16CB3CollidingBodyFv(self);
        CollideWheelWithWorld__18CB3BodyPartPhysicsFv(self);
    } else {
        if (self->field_2BA == 1)
            func_00333740_inl0(self);
        CacheWorldTriangles__16CB3CollidingBodyFv(self);
        CollideWithWorld__16CB3CollidingBodyFv(self);
    }
    self->field_200 = saved;
}
