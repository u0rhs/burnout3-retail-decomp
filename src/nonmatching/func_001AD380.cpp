// NONMATCHING: func_001AD380 -- retail 305 / ours 306 instructions, 362 in changed runs
// draftAG: logic complete; retail 305 / ours 306; calls identical (4 memset); VU lane/zero/identity ops agree; tensor stand-ins copied from the archived Update__16CB3CollidingBodyFf draft; left: schedule, lq/sq vs byte-loop copy split (13/17 vs 9/15), a float constant through mtc1/mfc1, frame 0x1C0 vs 0x200
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every store, call and VU op decoded from retail asm; header SetIdentity / Zero / SetX..Z / CGtSphere SetPosition+SetRadius; call sequence identical (calls.sh)

// func_001AD380 -- draftAG (C-first draft). [L] CB3CollidingBody::Prepare / reset (callers B3BodyPartPhysics_003342D0,
// B3VehiclePhysics_001CFC00 call it on their CB3CollidingBody base and test the bool); placeholder name. Layout as the archived
// Update__16CB3CollidingBodyFf draft (tensors at +0x10/+0x40, inverse matrix +0x70, velocity +0xB0 ...).
// Resets the body: identity orientation, zero inverse-inertia tensors (world = R^T * local * R, recomputed), identity inverse
// matrix, zero velocities / momenta / accumulators, default mass 1 and coefficients, and empties a global pool.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" void *memset(void *, int, unsigned int);

// [L] GtMathPs2::CGtMatrix3x3 with the B3O0PCH map's default ctor / copy ctor (the header's is a plain struct): the copy
// constructor assigns, as N263's CGtMatrix3x4 (implicit op= = retail's row-0-from-register + byte-loop row copies) [G body].
struct UnkStruct_001AD380_m33 {
    CGtV3d mRight, mUp, mAt;
    UnkStruct_001AD380_m33() {}
    UnkStruct_001AD380_m33(const UnkStruct_001AD380_m33& m) { UnkStruct_001AD380_m33& r = (*this = m); }
};
// [G] stand-in for GtMathPs2::TransformVector(const CGtMatrix3x3&, CGtV3d) (B3O0PCH 0x1A6130): the 3x4 header body.
static inline CGtV3d func_001AD380_inl1(const UnkStruct_001AD380_m33& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddz.xyz $vf1, $vf1, %1z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    return CGtV3d(t);
}
// [G] the row product inside CGtMatrix3x3::operator* (its own body: op* is emitted before TransformVector(3x3) in the map, so
// it does not call it): rows as compiler-chosen VU operands (retail keeps the second product's rows in $vf4/$vf3/$vf2).
static inline CGtV3d func_001AD380_inl12(const UnkStruct_001AD380_m33& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz $vf1, %1, %2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
// [G] stand-in for CGtMatrix3x3::operator*(const CGtMatrix3x3&) (B3O0PCH 0x1A50B0): each row of this through m.
static inline UnkStruct_001AD380_m33 func_001AD380_inl2(const UnkStruct_001AD380_m33& a, const UnkStruct_001AD380_m33& b) {
    UnkStruct_001AD380_m33 r;
    r.mRight = func_001AD380_inl12(b, a.mRight);
    r.mUp = func_001AD380_inl12(b, a.mUp);
    r.mAt = func_001AD380_inl12(b, a.mAt);
    return r;
}
// [G] stand-ins for CGtV3d::Set(XAxisType,XAxisType,XAxisType) / (Y,Y,Y) / (Z,Z,Z) (B3O0PCH 0x1A54C0 / 0x1A5430 / 0x1A53A0).
static inline void func_001AD380_inl3(CGtV3d& d, XAxisType a, XAxisType b, XAxisType c) {
    asm("vaddx.x %0, $vf0, %1x" "\n\t" "vaddx.y %0, $vf0, %2x" "\n\t" "vaddx.z %0, $vf0, %3x" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001AD380_inl4(CGtV3d& d, YAxisType a, YAxisType b, YAxisType c) {
    asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.y %0, $vf0, %2y" "\n\t" "vaddy.z %0, $vf0, %3y" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001AD380_inl5(CGtV3d& d, ZAxisType a, ZAxisType b, ZAxisType c) {
    asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" "\n\t" "vaddz.z %0, $vf0, %3z" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
// [L] a float into a VU register's x lane (retail 0x1AD67C lui v0, 1.0 / 0x1AD6D0 qmtc2.ni v0, $vf5; 0x1AD678 / 0x1AD680 for 0.0 in $vf6)
static inline XAxisType func_001AD380_inl13(float f) {
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    return XAxisType(s);
}
// [G] stand-in for CB3Tensor::GetTranspose() (B3O0PCH 0x1A5230)
static inline UnkStruct_001AD380_m33 func_001AD380_inl6(const UnkStruct_001AD380_m33& m) {
    UnkStruct_001AD380_m33 t;
    func_001AD380_inl3(t.mRight, m.mRight.X(), m.mUp.X(), m.mAt.X());
    func_001AD380_inl4(t.mUp, m.mRight.Y(), m.mUp.Y(), m.mAt.Y());
    func_001AD380_inl5(t.mAt, m.mRight.Z(), m.mUp.Z(), m.mAt.Z());
    return t;
}
struct UnkStruct_001AD380_200 { int field_0; };
struct UnkStruct_001AD380_160 {          // [G] a 0x60-byte block cleared by memset, then field by field
    CGtV3d field_0;                       // +0x160
    CGtV3d field_10;                      // +0x170
    unsigned char pad_20[0x10];
    short field_30;                       // +0x190
    unsigned char pad_32[2];
    int field_34;                         // +0x194
    int field_38;                         // +0x198
    unsigned char pad_3C[0x24];
};
struct UnkStruct_001AD380 {               // CB3CollidingBody [L]
    unsigned char pad_0[0x10];
    UnkStruct_001AD380_m33 field_10;      // [L] CB3Tensor (local inverse inertia)
    UnkStruct_001AD380_m33 field_40;      // [L] CB3Tensor (world inverse inertia)
    CGtMatrix3x4 field_70;                // [L] inverse matrix
    CGtV4d field_B0;                      // [L] linear velocity, speed in w
    CGtV3d field_C0;                      // [L] velocity direction
    CGtV3d field_D0;                      // [L] angular velocity
    CGtV3d field_E0;                      // [L] angular momentum
    CGtV3d field_F0;                      // [L] accumulated force
    CGtV3d field_100;                     // [L] accumulated torque
    CGtV3d field_110;
    CGtV3d field_120;
    CGtV3d field_130;
    CGtV3d field_140;
    CGtV3d field_150;
    UnkStruct_001AD380_160 field_160;
    CGtSphere field_1C0;                  // [G] SetPosition + SetRadius shape
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;                      // [L] mass
    float field_1F4;
    float field_1F8;
    float field_1FC;
    UnkStruct_001AD380_200 *field_200;
    void *field_204;
    int field_208;
    unsigned char field_20C;
    unsigned char field_20D;
    unsigned char field_20E;
    unsigned char field_20F;
    unsigned char field_210;
    unsigned char field_211;
    unsigned char field_212;
    unsigned char field_213;
    unsigned char field_214;
    unsigned char pad_215;
    unsigned char field_216;
    unsigned char field_217;
    signed char field_218;
};
// [C] a global pool header: count, current and end pointers into the 0x1800-byte buffer D_0066C590..D_0066DD90 [L]
struct UnkStruct_D_0066C580 { int field_0; void *field_4; void *field_8; };
extern UnkStruct_D_0066C580 D_0066C580;
extern unsigned char D_0066C590[];
extern unsigned char D_0066DD90[];

// 0x001AD380
extern "C" bool func_001AD380(UnkStruct_001AD380 *self)
{
    UnkStruct_001AD380_m33 lRot;
    memset(&lRot, 0, sizeof(lRot));
    // [C] retail sets the identity rows in VU registers, one read-modify-write per row (w kept): 0x1AD3B0 / 0x1AD3CC /
    // 0x1AD3D4 lqc2 rows, 0x1AD3D8..0x1AD3F8 vaddx.x/.y/.z from vf5 = 1.0 / vf4 = 0.0, 0x1AD3FC..0x1AD408 sqc2 (port lane vu0)
    func_001AD380_inl3(lRot.mRight, func_001AD380_inl13(1.0f), func_001AD380_inl13(0.0f), func_001AD380_inl13(0.0f));
    func_001AD380_inl3(lRot.mUp, func_001AD380_inl13(0.0f), func_001AD380_inl13(1.0f), func_001AD380_inl13(0.0f));
    func_001AD380_inl3(lRot.mAt, func_001AD380_inl13(0.0f), func_001AD380_inl13(0.0f), func_001AD380_inl13(1.0f));
    memset(&self->field_10, 0, sizeof(self->field_10));
    memset(&self->field_40, 0, sizeof(self->field_40));
    self->field_40 = func_001AD380_inl2(func_001AD380_inl6(lRot), self->field_10);
    self->field_40 = func_001AD380_inl2(self->field_40, lRot);
    self->field_200->field_0 = 0;
    self->field_70.SetIdentity();
    self->field_B0.Zero();
    // [C] retail 0x1AD6F0 lqc2 $vf4, 0xC0(s0); 0x1AD6F8 vaddx.x / 0x1AD6FC vaddx.y $vf4, $vf0, $vf6x (0.0); 0x1AD700 vaddx.z $vf4, $vf0,
    // $vf5x (1.0); 0x1AD704 sqc2 $vf4, 0xC0(s0): one register read-modify-write, so field_C0.w stays (port VU binding)
    func_001AD380_inl3(self->field_C0, func_001AD380_inl13(0.0f), func_001AD380_inl13(0.0f), func_001AD380_inl13(1.0f));
    self->field_D0.Zero();
    self->field_E0.Zero();
    self->field_F0.Zero();
    self->field_100.Zero();
    self->field_110.Zero();
    self->field_120.Zero();
    self->field_130.Zero();
    // [C] retail 0x1AD738 lqc2 $vf1, 0x140(s0); 0x1AD73C vaddx.x $vf1, $vf0, $vf5x (1.0) / 0x1AD740 vaddx.y and 0x1AD744 vaddx.z
    // $vf1, $vf0, $vf6x (0.0); 0x1AD748 sqc2 $vf1, 0x140(s0): one register read-modify-write, so field_140.w stays (port VU binding)
    func_001AD380_inl3(self->field_140, func_001AD380_inl13(1.0f), func_001AD380_inl13(0.0f), func_001AD380_inl13(0.0f));
    self->field_204 = 0;
    memset(&self->field_160, 0, sizeof(self->field_160));
    self->field_160.field_0.Zero();
    self->field_160.field_10.Zero();
    self->field_160.field_30 = 0;
    self->field_160.field_34 = 0;
    self->field_160.field_38 = 0;
    self->field_150.Zero();
    self->field_20C = 0;
    self->field_208 = 0;
    self->field_1C0.SetPosition(CGtV3d(0.0f, 0.0f, 0.0f));
    self->field_1C0.SetRadius(0.0f);
    self->field_1E0.Zero();
    self->field_1D0.Zero();
    self->field_20D = 0;
    self->field_20E = 0;
    self->field_20F = 0;
    self->field_210 = 0;
    self->field_211 = 0;
    self->field_212 = 0;
    self->field_213 = 0;
    self->field_214 = 0;
    self->field_1F0 = 1.0f;
    self->field_1F4 = 0.0f;
    self->field_1F8 = 0.1f;
    self->field_1FC = -0.75f;
    self->field_216 = 0;
    self->field_217 = 0;
    self->field_218 = -1;
    D_0066C580.field_4 = D_0066C590;
    D_0066C580.field_8 = D_0066DD90;
    D_0066C580.field_0 = 0;
    return true;
}
