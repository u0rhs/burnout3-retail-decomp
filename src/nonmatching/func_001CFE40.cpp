// NONMATCHING: func_001CFE40 -- retail 699 / ours 693 instructions, 399 in changed runs
// draftC: 699/693; no calls; [L] CB3HingedPart::UpdatePhysics(float) (B3O0PCH 0x1D5AA0), the angular half of CB3CollidingBody::Update (sibling archive, same stand-ins). OrthoNormalise's Z/Y/X rebuild blocks land at the function end as retail. Left: v -= v x w -- retail computes the product over v ("=j" result, N256 open) and re-reads the row through its address for the subtraction (stand-in for that is locally right but scores worse: 425 vs 399), rows of the TransformVector read through GPRs, transpose/product scheduling, frame 0x540 vs 0x780
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every load/store, VU op and branch condition decoded from retail asm (no calls; op counts within 6, all from copy moves); same shape as CB3CollidingBody::Update's angular part

// draftC: func_001CFE40 (0x1CFE40, 0xAEC) -- [L] CB3HingedPart::UpdatePhysics(float) (B3O0PCH map name, 0x1D5AA0; Revenge
// CB4HingedPartPhysics::UpdatePhysics); the only caller is CB3VehiclePhysics::UpdateHingedPart (archive). Same integration step as
// CB3CollidingBody::Update (sibling archive): stand-ins copied from it.
// [C] name: retail symbol table. Decoded from retail asm (no calls: every helper inlined). Helper set [C map / L use]: the
// B3O0PCH emission queue after CB3CollidingBody::Update (SetLinearVelocity, CB3Tensor::Set(CGtV3d x3), TransformVector/
// TransformPoint(CGtMatrix3x3), ...) and before it (CGtMatrix3x3 op= / Multiply / op* / copy ctor, CB3Tensor::GetTranspose,
// CGtV3d::Set(X,X,X)/(Y,Y,Y)/(Z,Z,Z)). Revenge's Update (55 instrs) was refactored: not used.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] GtMathPs2::CGtMatrix3x3 with the B3O0PCH map's default ctor / copy ctor (the header's is a plain struct): the copy
// constructor assigns, as N263's CGtMatrix3x4 (implicit op= = retail's row-0-from-register + byte-loop row copies) [G body].
struct UnkStruct_001AC470_m33 {
    CGtV3d mRight, mUp, mAt;
    UnkStruct_001AC470_m33() {}
    UnkStruct_001AC470_m33(const UnkStruct_001AC470_m33& m) { UnkStruct_001AC470_m33& r = (*this = m); }
};
// [G] stand-in for GtMathPs2::TransformVector(const CGtMatrix3x3&, CGtV3d) (B3O0PCH 0x1A6130): the 3x4 header body.
static inline CGtV3d func_001AC470_inl1(const UnkStruct_001AC470_m33& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %1z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}
// [G] the row product inside CGtMatrix3x3::operator* (its own body: op* is emitted before TransformVector(3x3) in the map, so
// it does not call it): rows as compiler-chosen VU operands (retail keeps the second product's rows in $vf4/$vf3/$vf2).
static inline CGtV3d func_001AC470_inl12(const UnkStruct_001AC470_m33& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz $vf1, %1, %2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
// [G] stand-in for CGtMatrix3x3::operator*(const CGtMatrix3x3&) (B3O0PCH 0x1A50B0): each row of this through m.
static inline UnkStruct_001AC470_m33 func_001AC470_inl2(const UnkStruct_001AC470_m33& a, const UnkStruct_001AC470_m33& b) {
    UnkStruct_001AC470_m33 r;
    r.mRight = func_001AC470_inl12(b, a.mRight);
    r.mUp = func_001AC470_inl12(b, a.mUp);
    r.mAt = func_001AC470_inl12(b, a.mAt);
    return r;
}
// [G] stand-ins for CGtV3d::Set(XAxisType,XAxisType,XAxisType) / (Y,Y,Y) / (Z,Z,Z) (B3O0PCH 0x1A54C0 / 0x1A5430 / 0x1A53A0).
static inline void func_001AC470_inl3(CGtV3d& d, XAxisType a, XAxisType b, XAxisType c) {
    asm("vaddx.x %0, $vf0, %1x" "\n\t" "vaddx.y %0, $vf0, %2x" "\n\t" "vaddx.z %0, $vf0, %3x" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001AC470_inl4(CGtV3d& d, YAxisType a, YAxisType b, YAxisType c) {
    asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.y %0, $vf0, %2y" "\n\t" "vaddy.z %0, $vf0, %3y" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001AC470_inl5(CGtV3d& d, ZAxisType a, ZAxisType b, ZAxisType c) {
    asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" "\n\t" "vaddz.z %0, $vf0, %3z" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
// [G] stand-in for CB3Tensor::GetTranspose() (B3O0PCH 0x1A5230)
static inline UnkStruct_001AC470_m33 func_001AC470_inl6(const UnkStruct_001AC470_m33& m) {
    UnkStruct_001AC470_m33 t;
    func_001AC470_inl3(t.mRight, m.mRight.X(), m.mUp.X(), m.mAt.X());
    func_001AC470_inl4(t.mUp, m.mRight.Y(), m.mUp.Y(), m.mAt.Y());
    func_001AC470_inl5(t.mAt, m.mRight.Z(), m.mUp.Z(), m.mAt.Z());
    return t;
}

struct UnkStruct_001CFE40 {             // [L] Revenge CB4HingedPartPhysics (field roles from the caller's archive)
    UnkStruct_001AC470_m33 field_0;      // [L] inverse inertia tensor, local
    UnkStruct_001AC470_m33 field_30;     // [L] inverse inertia tensor, world
    CGtV3d field_60;                     // [L] previous velocity
    CGtV3d field_70;                     // [L] total torque
    CGtV3d field_80;                     // [L] total angular impulse
    CGtV3d field_90;                     // [L] angular momentum
    CGtV3d field_A0;                     // [L] angular velocity
    float field_B0;
    float field_B4;
    CGtMatrix3x4 *field_B8;              // [L] matrix
};

// [G] v -= v x w through a reference (retail forms the row address with addiu and reads it again for the subtraction)
static inline void func_001CFE40_inl1(CGtV3d& v, CGtV3d w) { v -= CrossProduct(v, w); }
// 0x001CFE40
extern "C" void func_001CFE40(UnkStruct_001CFE40 *self, float dt)
{
    self->field_80 += self->field_70 * dt;
    self->field_90 += self->field_80;
    self->field_A0 = func_001AC470_inl1(self->field_30, self->field_90);
    CGtV3d w = self->field_A0 * dt;
    func_001CFE40_inl1(self->field_B8->mAt, w);
    func_001CFE40_inl1(self->field_B8->mUp, w);
    func_001CFE40_inl1(self->field_B8->mRight, w);
    self->field_B8->OrthoNormalise();
    CGtMatrix3x4 *m = self->field_B8;
    UnkStruct_001AC470_m33 lRot;
    lRot.mRight = m->mRight;
    lRot.mUp = m->mUp;
    lRot.mAt = m->mAt;
    self->field_30 = func_001AC470_inl2(func_001AC470_inl6(lRot), self->field_0);
    self->field_30 = func_001AC470_inl2(self->field_30, lRot);
    self->field_70.Zero();
    self->field_80.Zero();
}

