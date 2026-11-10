// NONMATCHING: func_00250350 -- retail 871 / ours 855 instructions, 434 in changed runs
// draftN: [L] CB3TrafficPhysics::Update(float) (E dnat file order); logic complete, same calls (order differs by block layout), VU op counts equal, FPU equal; residue = block layout: b119p defers the hitch-impulse block, the first unhitch's speed set and the trailing VehiclePhysics::Update call out of line where retail keeps them in source order (if/else, ==false, empty-then, wrapping and return forms all negative); retail's stack copies (frame 0xF10 vs 0x410), constant 2^-32 kept in f20 | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every branch, call, store and VU op accounted for; the fabsf(impulse) result is unused in retail too

// func_00250350 -- [L] CB3TrafficPhysics::Update(float): E dnat map B3TrafficPhysics.cpp lists StopCrashing, Destruct, Release,
// Update(float), Prepare(CB3TrafficVehicle*,int), Prepare(), Construct in that order, and retail has StopCrashing 0x2502D0,
// Destruct 0x250300, Release 0x250310, this function, Prepare(..) 0x2510F0, Prepare() 0x2513F0, Construct 0x251460. No name at
// this address in the tables, so the symbol stays func_00250350 (a free function taking the object). Hand-written by draftN
// from the retail asm + Ghidra draft; locals after Revenge's CB4TrafficPhysics::Update STABS where the role is clear [L].
// Field names are placeholders and every type is [G] (instruction widths).
// A trailer (field_2428 == 1) hitched to its cab (field_2424): both hitch points to world space, a vertical spring when the
// params' flag is 1, a separating push of half the hitch gap into each body's field_130, a 5.0 speed floor for a trailer
// whose cab moves, the angular-momentum corrections when the two bodies' At (cos 100 deg) or Up (cos 10 deg) axes diverge,
// and the unhitch when the bodies fold past -0.5 or the gap / spring length grow too large. Then the vehicle update.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);
extern "C" void *memset(void *, int, unsigned int);

class CB3TrafficPhysics;
extern "C" void func_001AB010(CB3TrafficPhysics *);
extern "C" void Update__17CB3VehiclePhysicsFf(CB3TrafficPhysics *, float);   // CB3VehiclePhysics::Update(float)

struct UnkStruct_00250350_params {     // [G] the vehicle params (field_13A0)
    unsigned char pad_0[0x16A4];
    CGtV3d *field_16A4;                // [G] hitch point, flag 1
    CGtV3d *field_16A8;                // [G] hitch point (the cab's own, and the trailer's otherwise)
    unsigned char pad_16AC[0x10];
    unsigned char field_16BC;
};
struct UnkStruct_00250350_160 {        // [G] 0x60 bytes, cleared by memset then field by field
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x10];
    short field_30;
    unsigned char pad_32[2];
    int field_34;
    int field_38;
    unsigned char pad_3C[0x24];
};

class CB3TrafficPhysics {
public:
    unsigned char pad_0[0x40];
    CGtMatrix3x4 field_40;            // [G] inverse inertia (rows 0x40/0x50/0x60 used)
    unsigned char pad_80[0x30];
    CGtV3dPlus field_B0;              // [G] linear velocity, w = speed
    CGtV3d field_C0;                  // [G] velocity direction
    CGtV3d field_D0;                  // [G] angular velocity
    CGtV3d field_E0;                  // [G] angular momentum
    CGtV3d field_F0;                  // [G] force accumulator
    CGtV3d field_100;                 // [G] torque accumulator
    unsigned char pad_110[0x20];
    CGtV3d field_130;                 // [G] position correction (as UpdateSuspension's constraint push)
    unsigned char pad_140[0x20];
    UnkStruct_00250350_160 field_160;
    unsigned char pad_1C0[0x30];
    float field_1F0;                  // [G] mass
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F;
    unsigned char field_210;
    unsigned char pad_211;
    unsigned char field_212;
    unsigned char pad_213[3];
    signed char field_216;
    unsigned char pad_217[0x1353 - 0x217];
    unsigned char field_1353;
    unsigned char pad_1354[0x13A0 - 0x1354];
    UnkStruct_00250350_params *field_13A0;
    unsigned char pad_13A4[0x2424 - 0x13A4];
    CB3TrafficPhysics *field_2424;    // [L] the cab (Revenge lpCabPhysics)
    unsigned char field_2428;         // [G] 1 = trailer
    unsigned char pad_2429[3];
    unsigned char field_242C;

    // [L] E map names (B3O0PCH: CB3CollidingBody::ApplyPositionedForce(CGtV3d, CGtV3d), GetPointVelocity(CGtV3d),
    // LocalPointToWorldPoint(CGtV3d)); parameter order (lPoint, lForce) from Revenge STABS; bodies [G] from retail's inlined copies.
    void ApplyPositionedForce(CGtV3d lPoint, CGtV3d lForce) {
        field_F0 += lForce;
        field_100 += CrossProduct(lPoint - field_204->mPos, lForce);
    }
    CGtV3d LocalPointToWorldPoint(CGtV3d p) { return TransformPoint(*field_204, p); }
    CGtV3d GetPointVelocity(CGtV3d pos) {
        CGtV3d v = CrossProduct(field_D0, pos - field_204->mPos) + field_B0Vec();
        // [C] w = field_D0.w at both calls here (0x250560 / 0x250590 lqc2 vf1, 0xD0; 0x250570 / 0x2505A4 vopmsub.xyz vf1, vf2, vf1 into its
        // register; 0x250588 / 0x2505B4 vadd.xyz; 0x250594 / 0x2505BC sqc2 0xEB0 / 0xEC0(sp)) -- `a + b` took field_B0's w
        ((float *)&v)[3] = ((const float *)&field_D0)[3];
        return v;
    }
    CGtV3d field_B0Vec() { return CGtV3d(field_B0.mData); }
};

// [G] CGtV3d::IsEffectivelyZero() (E map name, 0x68): squared length below 2^-32 (header gap)
static inline bool func_00250350_inl1(CGtV3d v) { return v.GetSquaredLength() < 2.3283064e-10f; }

// [G] the speed: w of the linear velocity read through a stack copy (Revenge `UGtVectorAsTypes lRet`)
static inline float func_00250350_inl2(CB3TrafficPhysics *b)
{
    CGtV3dPlus v = b->field_B0;
    return ((float *)&v)[3];
}

// [G] set the linear velocity: xyz, then direction + speed (zero -> direction = the body's At row)
static inline void func_00250350_inl3(CB3TrafficPhysics *b, CGtV3d v)
{
    b->field_B0.SetGtV3d(v);
    if (v.IsEffectivelyZero()) {
        b->field_B0.SetPlus(0.0f);
        b->field_C0 = b->field_204->mAt;
    } else {
        b->field_C0 = v;
        float lrLen = b->field_C0.NormaliseGetLength();
        b->field_B0.SetPlus(lrLen);
    }
}

// [G] reset when not hitched: three flag bits, the 0x60 block at +0x160 cleared
static inline void func_00250350_inl4(CB3TrafficPhysics *b)
{
    if (b->field_242C == 0) {
        b->field_1353 |= 1;
        b->field_1353 |= 2;
        b->field_1353 |= 4;
        b->field_212 = 0;
        memset(&b->field_160, 0, 0x60);
        b->field_160.field_0.Zero();
        b->field_160.field_10.Zero();
        b->field_160.field_30 = 0;
        b->field_160.field_34 = 0;
        b->field_160.field_38 = 0;
    }
}

// [G] unhitch: a trailer slower than a quarter of its cab's speed takes that speed along its own direction
static inline void func_00250350_inl5(CB3TrafficPhysics *b)
{
    b->field_2428 = 0;
    if (b->field_2424 != 0) {
        if (!(func_00250350_inl2(b) < 0.25f * func_00250350_inl2(b->field_2424))) {
        } else {
            func_00250350_inl3(b, b->field_C0 * (0.25f * func_00250350_inl2(b->field_2424)));
        }
        b->field_2424->field_2424 = 0;
        b->field_2424 = 0;
    }
}

// [G] remove k times the axis component of the angular momentum
static inline void func_00250350_inl6(CB3TrafficPhysics *b, const CGtV3d &lAxis, float k)
{
    b->field_E0 -= lAxis * DotProduct(lAxis, b->field_E0) * k;
}

// 0x00250350
extern "C" void func_00250350(CB3TrafficPhysics *self, float lrTimeStep)
{
    if (self->field_210 == 0) return;
    unsigned char lbHitched = self->field_242C;
    if (lbHitched != 0 && self->field_216 == -1) {
        self->field_242C = 0;
        func_00250350_inl4(self);
    } else if (lbHitched == 0 && self->field_216 != -1) {
        self->field_242C = 1;
        func_001AB010(self);
        func_00250350_inl4(self);
    }
    func_00250350_inl4(self);
    if (self->field_242C == 0) return;
    if (self->field_2424 != 0) {
        if (self->field_216 != -1 && self->field_2424->field_216 != -1) {
            self->field_20E = 0;
            self->field_2424->field_20E = 0;
        } else {
            self->field_20E = 1;
            self->field_2424->field_20E = 1;
        }
        if (self->field_20E == 0 || self->field_2424->field_20E == 0) {
            self->field_20E = 0;
            self->field_2424->field_20E = 0;
        }
    } else if (self->field_216 == -1) {
        self->field_20E = 1;
    } else {
        self->field_20E = 0;
    }
    if (self->field_2428 == 1) {
        CGtV3d lImpulse(0.0f, 0.0f, 0.0f);
        UnkStruct_00250350_params *p = self->field_13A0;
        bool lbNoSpring;
        CGtV3d lHitch;
        if (p->field_16BC == 1) {
            lbNoSpring = false;
            lHitch = *p->field_16A4;
        } else {
            lbNoSpring = true;
            lHitch = *p->field_16A8;
        }
        CB3TrafficPhysics *lpCabPhysics = self->field_2424;
        CGtV3d lCabHitch = lpCabPhysics->LocalPointToWorldPoint(*lpCabPhysics->field_13A0->field_16A8);
        CGtV3d lTrailerHitch = self->LocalPointToWorldPoint(lHitch);
        CGtV3d lTrailerVel = self->GetPointVelocity(lTrailerHitch);
        CGtV3d lCabVel = lpCabPhysics->GetPointVelocity(lCabHitch);
        float lrSpringLength;
        if (!lbNoSpring) {
            lrSpringLength = lTrailerHitch.Y() - operator+(lCabHitch.Y(), 0.5f);
            float lrSpringForce = -80000.0f * (lrSpringLength - 0.3f);
            lrSpringForce += (float)operator*(-lTrailerVel.Y(), 1000.0f) / lrTimeStep;
            lImpulse.SetY(lrSpringForce);
            self->ApplyPositionedForce(lTrailerHitch, lImpulse);
        } else {
            lrSpringLength = lTrailerHitch.Y() - lCabHitch.Y();
        }
        CGtV3d lTranslate = lTrailerHitch - lCabHitch;
        if (lTranslate.IsEffectivelyZero() == false) {
            CGtV3d n = lTranslate;
            n.Normalise();
            float num = DotProduct(n, lCabVel - lTrailerVel) * -1.0f;
            CGtV3d rB = lTrailerHitch - self->field_204->mPos;
            CGtV3d rA = lCabHitch - lpCabPhysics->field_204->mPos;
            float den = DotProduct(CrossProduct(TransformVector(self->field_40, CrossProduct(rB, n)), rB)
                                   + CrossProduct(TransformVector(lpCabPhysics->field_40, CrossProduct(rA, n)), rA), n)
                        + (1.0f / self->field_1F0 + 1.0f / lpCabPhysics->field_1F0);
            float lrImp = fabsf(num / den);   // [C] retail calls fabsf and never reads the result
            lTranslate = lTranslate * 0.5f;
            lTranslate.SetY(0.0f);
            lpCabPhysics->field_130 += lTranslate;
            lTranslate = -lTranslate;
            self->field_130 += lTranslate;
            if (func_00250350_inl2(self) < 5.0f && !(func_00250350_inl2(self->field_2424) <= 5.0f)) {
                func_00250350_inl3(self, self->field_C0 * 5.0f);
            }
        }
        float lrJackknifeAt = DotProduct(self->field_204->mAt, lpCabPhysics->field_204->mAt);
        if (lrJackknifeAt < -0.1736f) {
            func_00250350_inl6(self, self->field_204->mUp, 2.0f);
            func_00250350_inl6(lpCabPhysics, lpCabPhysics->field_204->mUp, 2.0f);
        }
        if (!lbNoSpring && lrJackknifeAt < -0.5f) {
            func_00250350_inl5(self);
        }
        float lrJackknifeUp = DotProduct(self->field_204->mUp, lpCabPhysics->field_204->mUp);
        if (lrJackknifeUp < 0.9848f) {
            func_00250350_inl6(self, self->field_204->mRight, 1.5f);
            func_00250350_inl6(lpCabPhysics, lpCabPhysics->field_204->mRight, 1.5f);
            func_00250350_inl6(self, self->field_204->mAt, 1.5f);
            func_00250350_inl6(lpCabPhysics, lpCabPhysics->field_204->mAt, 1.5f);
        }
        if (lTranslate.GetSquaredLength() > 1.44f || GtMath::Abs(lrSpringLength) > 1.0f) {
            func_00250350_inl5(self);
        }
    }
    Update__17CB3VehiclePhysicsFf(self, lrTimeStep);
}

