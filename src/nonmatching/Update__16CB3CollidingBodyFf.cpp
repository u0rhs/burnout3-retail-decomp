// NONMATCHING: Update__16CB3CollidingBodyFf -- retail 964 / ours 963 instructions, 621 in changed runs
// fix1 (2026-11-01): defined w lanes as retail (port6 checker): field_40 rows keep field_10.mAt's w through the two row products (inl12 takes the madd destination's start value; inl14 = the second product), field_70.mPos keeps mUp's w (vmove.w). F0/100/110/120/130 w stay stale-register lanes (Zero = vadd.xyz on a stale register, class 7) | Before: draftC: 964/966; no calls; every branch sense and the out-of-line if-blocks (field_211, positioned force, StopImmediately, speed clamp, angular-velocity clamp) as retail. Left: OrthoNormalise X<=0/Y<=0 blocks inline (retail: function end -- also when the body is pasted in-line, and with inverted/early-return forms, so not an inlining effect), frame 0x790 vs 0xCA0, Invert's at*z product order, GetSquaredLength(D0) through GPR vs retail's store+lqc2. Stand-ins [G]: CGtMatrix3x3 with assigning copy ctor, TransformVector(3x3) (header 3x4 form), op* row product with compiler-chosen rows, Set(X,X,X)/(Y,Y,Y)/(Z,Z,Z), GetTranspose, Invert, V3d*Y/*Z, InvSqrt (rsqrt.s)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix1 (2026-11-01): Burn3 checker on 24 port6 live captures (with the port's sqrt.s fix): 7 pass; every remaining difference is a w lane retail fills from a stale VU register (Zero() = vadd.xyz $vfN,$vf0,$vf0 at this+0xFC/0x12C/0x13C: port class 7, not reproducible from source); every defined value matches
// W lanes (port lane vu0, 2026-11-07, unit_001AC470.s): +0x12C = field_B0.w, fixed in the source [C]. +0x13C (field_130
//   zero at 0x1ACCAC/0x1ACCB8) = the w of the row the inlined OrthoNormalise touched last: mAt via 0x1AC9A4 / 0x1AD370,
//   mUp via 0x1ACA58 / 0x1ACBDC / the fall-through, mRight via 0x1ACB30 / 0x1AD2BC [C]; fixable once OrthoNormalise's
//   branch structure is visible here. +0xFC (field_F0 zero, 0x1AC524) = field_204->mUp.w on the field_210 ||
//   field_215 == 6 path (0x1AD0BC) [C], else the caller's $vf3 (CB3RaceCarPhysics::Update, ra 0x1C4B74): cross-function.
//   +0x10C / +0x11C keep their own w, as Zero() does [C].


// draftC: Update__16CB3CollidingBodyFf (0x1AC470, 0xF10) -- CB3CollidingBody::Update(float)
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
// fix1: the result's w is the w of the register the last madd writes into, which retail fills with a defined row: m.mAt in
// the first product (0x1ACD3C `qmtc2.ni $t1,$vf1; vmaddz.xyz $vf1,$vf1,$vf5z`), v in the second (0x1ACE68 `lqc2 $vf1,0x40($a0);
// ...; vmaddz.xyz $vf1,$vf2,$vf1z`) [C]; passed in as w (the old form kept a stale $vf1 w: port6 checker, field_40 w lanes).
static inline CGtV3d func_001AC470_inl12(const UnkStruct_001AC470_m33& m, CGtV3d v, u_long128 w) {
    u_long128 t = w;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz %0, %1, %2z" : "+j"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
// [G] stand-in for CGtMatrix3x3::operator*(const CGtMatrix3x3&) (B3O0PCH 0x1A50B0): each row of this through m.
// first product: each result row keeps b.mAt's w [C] (inl12)
static inline UnkStruct_001AC470_m33 func_001AC470_inl2(const UnkStruct_001AC470_m33& a, const UnkStruct_001AC470_m33& b) {
    UnkStruct_001AC470_m33 r;
    r.mRight = func_001AC470_inl12(b, a.mRight, b.mAt.mData);
    r.mUp = func_001AC470_inl12(b, a.mUp, b.mAt.mData);
    r.mAt = func_001AC470_inl12(b, a.mAt, b.mAt.mData);
    return r;
}
// fix1: the second product (the same op*): each result row keeps a's row w [C] (inl12)
static inline UnkStruct_001AC470_m33 func_001AC470_inl14(const UnkStruct_001AC470_m33& a, const UnkStruct_001AC470_m33& b) {
    UnkStruct_001AC470_m33 r;
    r.mRight = func_001AC470_inl12(b, a.mRight, a.mRight.mData);
    r.mUp = func_001AC470_inl12(b, a.mUp, a.mUp.mData);
    r.mAt = func_001AC470_inl12(b, a.mAt, a.mAt.mData);
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
// [G] CGtV3d * YAxisType / * ZAxisType (B3O0PCH map names; header gap queued by draftA)
static inline CGtV3d func_001AC470_inl7(CGtV3d v, YAxisType a) { u_long128 r; asm("vmuly.xyz %0, %1, %2y" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
static inline CGtV3d func_001AC470_inl8(CGtV3d v, ZAxisType a) { u_long128 r; asm("vmulz.xyz %0, %1, %2z" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
// [L] stand-in for GtMath::InvSqrt(float) (B3O0PCH map name): rsqrt.s with 1.0 (as proven GtWideLine_0041D910).
static inline float func_001AC470_inl10(float x) { float r, one = 1.0f; asm("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(one), "f"(x)); return r; }
// [G] stand-in for CGtMatrix3x4::Invert() (B3O0PCH 0x1539B0; queued by draftA): orthonormal inverse in place.
static inline void func_001AC470_inl9(CGtMatrix3x4& m) {
    CGtV3d r = m.mRight, u = m.mUp, a = m.mAt;
    m.mRight.SetY(u.X()); m.mRight.SetZ(a.X());
    m.mUp.SetX(r.Y()); m.mUp.SetZ(a.Y());
    m.mAt.SetX(r.Z()); m.mAt.SetY(u.Z());
    m.mPos = -(m.mRight * m.mPos.X() + func_001AC470_inl7(m.mUp, m.mPos.Y()) + func_001AC470_inl8(m.mAt, m.mPos.Z()));
    // fix1: retail's sum and negation run in the register holding mUp * y, so mPos keeps mUp's w [C] 0x1ACFA0..0x1ACFB4
    asm("vmove.w %0, %1" : "+j"(m.mPos.mData) : "j"(m.mUp.mData));
}

class CB3CollidingBody {
public:
    void Update(float dt);
    unsigned char pad_0[0x10];
    UnkStruct_001AC470_m33 field_10;     // [L] CB3Tensor (local inverse inertia)
    UnkStruct_001AC470_m33 field_40;     // [L] CB3Tensor (world inverse inertia)
    CGtMatrix3x4 field_70;               // [L] inverse matrix (GetInverseMatrix)
    CGtV3dPlus field_B0;                 // [L] linear velocity, speed in w
    CGtV3d field_C0;                     // [L] velocity direction
    CGtV3d field_D0;                     // [L] angular velocity
    CGtV3d field_E0;                     // [L] angular momentum
    CGtV3d field_F0;                     // [L] accumulated force
    CGtV3d field_100;                    // [L] accumulated torque
    CGtV3d field_110;                    // [G] accumulated linear impulse
    CGtV3d field_120;                    // [G] accumulated angular impulse
    CGtV3d field_130;                    // [G] accumulated translation
    unsigned char pad_140[0x54];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x54];
    float field_1F0;                     // [L] mass
    float field_1F4;
    unsigned char pad_1F8[0xC];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F;
    unsigned char field_210;
    unsigned char field_211;
    unsigned char field_212;
    unsigned char field_213;
    unsigned char pad_214;
    signed char field_215;
};

extern CGtV3d kGravity;
extern "C" float sqrtf(float);

// 0x001AC470
void CB3CollidingBody::Update(float dt)
{
    CGtV3d grav = kGravity;
    CGtV3d dtv(dt, dt, dt);
    if (field_211) field_20E = 0;
    CGtV3d g = grav * CGtV3d(1.0f, field_1F0, 1.0f);
    if (field_210 || field_215 == 6) {
        field_F0 += g;
        CGtV3d p = field_204->mUp * field_1F4 + field_204->mPos;
        field_100 += CrossProduct(p - field_204->mPos, g);
    } else {
        field_F0 += g;
    }
    if (field_20E) {
        field_D0.Zero();
        field_E0.Zero();
        ((CGtV4d *)&field_B0)->Zero();
        field_C0 = field_204->mAt;
        field_F0.Zero();
        field_100.Zero();
        field_110.Zero();
        field_120.Zero();
        field_130.Zero();
        field_194 = 0;
        field_198 = 0;
        field_212 = 0;
        field_213 = 0;
    }
    field_110 += field_F0 * dtv;
    field_F0.Zero();
    if (field_210 || field_215 == 6) // [C] on this path retail's vf3 is field_204->mUp (0x1AD0BC lqc2 vf3, 0x10(v1)), so
        ((float *)&field_F0)[3] = ((const float *)&field_204->mUp)[3]; // the 0x1AC524 vadd.xyz / 0x1AC528 sqc2 zero leaves mUp.w (vu0)
    field_120 += field_100 * dtv;
    field_100.Zero();
    field_B0.SetGtV3d(CGtV3d(field_B0.mData) + field_110 * (1.0f / field_1F0));
    field_110.Zero();
    CGtV3d v(field_B0.mData);
    if (v.Y() > 120.0f) {
        v.SetY(120.0f);
        field_B0.SetGtV3d(v);
    }
    field_E0 += field_120;
    field_120.Zero();
    ((float *)&field_120)[3] = ((const float *)&field_B0)[3]; // [C] retail keeps field_B0's w here: 0x1AC550 lqc2 $vf1, 0xB0($a0); 0x1AC570 / 0x1AC5A0 vadd.xyz (w untouched); 0x1AC5AC sqc2 $vf1, 0x120($a0) -- so this Zero() stores field_B0.w into field_120.w (port lane vu0: the hybrid restore's first main-hash difference, poll 3001)
    field_D0 = func_001AC470_inl1(field_40, field_E0);
    float sq = field_D0.GetSquaredLength();
    if (sq > 10000) {
        field_D0.Normalise();
        field_D0 = field_D0 * (100.0f * func_001AC470_inl10(sq));
        field_E0 = field_E0 * 0.95f;
    }
    field_204->mPos += CGtV3d(field_B0.mData) * dtv;
    CGtMatrix3x4 *m = field_204;
    CGtV3d w = field_D0 * dtv;
    m->mAt -= CrossProduct(m->mAt, w);
    m->mUp -= CrossProduct(m->mUp, w);
    m->mRight -= CrossProduct(m->mRight, w);
    m->OrthoNormalise();
    m->mPos += field_130;
    field_130.Zero();
    UnkStruct_001AC470_m33 lRot;
    lRot.mRight = m->mRight;
    lRot.mUp = m->mUp;
    lRot.mAt = m->mAt;
    field_40 = func_001AC470_inl2(func_001AC470_inl6(lRot), field_10);
    field_40 = func_001AC470_inl14(field_40, lRot);
    field_70 = *field_204;
    func_001AC470_inl9(field_70);
    CGtV3d lv(field_B0.mData);
    field_B0.SetGtV3d(lv);
    if (lv.GetSquaredLength() < 2.3283064e-10f) {
        field_B0.SetPlus(0.0f);
        field_C0 = field_204->mAt;
    } else {
        field_C0 = lv;
        field_B0.SetPlus(field_C0.NormaliseGetLength());
    }
}
