// NONMATCHING: RaceCarRaceCarResponse__17CB3PhysicsManagerFP16CB3CollidingPair -- retail 936 / ours 945 instructions, 484 in changed runs
// draftAD C-first: hull collide, mass-split ground-plane separation, contact lift/flatten, front-back params, restitution impulse, bounce forces, fatal crashes both ways, shunt/slam OnRaceCarCollision (vtable +0x6C [C]); calls identical (acosf = header name of func_0011E328); residue: 0-x folded to neg.s (2), branch/bool materialisation, frame 0x8F0 vs 0xE70
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm read end to end); call sequence identical; per-mnemonic counts equal for all VU and FPU arithmetic except 2 sub.s->neg.s folds of 0.0f - x

// CB3PhysicsManager::RaceCarRaceCarResponse(CB3CollidingPair*) -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: retail symbol table. Written from the retail asm (Ghidra draft as a reading aid). Struct layouts shared with the
// archived sibling BodyBodyResponse (0x1B4BF0). Local names [L]: Revenge STABS RaceCarRaceCarResponse__17CB4PhysicsManager
// (lHullColParams, lrImpulse, lrClosingSpeed, lrParamA, lrParamB, lPair; tools/stabs_lookup.py).
// What it does [L]: hull collision; position separation by mass on the ground plane (y cleared), unless one car is pinned
// (field_212); the contact point lifted to the cars' height, the normal flattened; each contact's parameter along its car's
// length (0 = front of the box, 1 = back); restitution impulse; a mass-capped bounce force on both cars; above
// krRaceCarRaceCarCrashSpeed fatal crashes both ways (kaabCanFatal), otherwise the logic's OnRaceCarCollision(1);
// then shunt (back-to-front contact, the faster car behind; paint trade below krPaintTradeThreshold) and slam (side
// contact, closing speed against the heading angle) callbacks into the race logic (vtable +0x6C), which mark the
// victim's side (field_153C) from the side dot product.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);

// [G] the 32-byte box at body+0x1D0 (min/max; z = the car's length axis)
struct UnkStruct_001B4BF0_box { CGtV3d field_0; CGtV3d field_10; };
// [G] per-body block of the hull-collide parameters (0xF0 bytes) -- as BodyBodyResponse's archive
struct UnkStruct_001B5730_hb {
    void * field_0;
    unsigned char pad_4[0x2C];
    CGtMatrix3x4 field_30;   // separated pose [G]: mPos at +0x60
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x40];
};
struct CB3HullCollideParams {
    UnkStruct_001B5730_hb field_0;
    UnkStruct_001B5730_hb field_F0;
    int field_1E0;
    int field_1E4;          // set when the separation in field_0/field_F0 .field_30.mPos is valid
    unsigned char pad_1E8[8];
    CGtV3d field_1F0;       // contact normal
    CGtV3d field_200;       // contact point
};
struct UnkStruct_001B6380_car {   // [G] race-car object at body+0x13F4
    unsigned char pad_0[0x19AC];
    signed char field_19AC;  // player/car index [G] (StartRaceCarCrashing's int)
};
class CB3RaceCarPhysics {
public:
    void ApplyNonSpinoutPositionedForce(CGtV3d p0, CGtV3d p1);

    unsigned char pad_0[0x40];
    CGtV3d field_40[3];     // inverse inertia rows [G]
    unsigned char pad_70[0x40];
    CGtV3d field_B0;        // velocity; w = speed [G]
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;        // angular velocity [G]
    unsigned char pad_E0[0x10];
    CGtV3d field_F0;        // force accumulator [G]
    CGtV3d field_100;
    CGtV3d field_110;       // impulse accumulator [G]
    CGtV3d field_120;
    CGtV3d field_130;       // position correction [G]
    CGtV3d field_140;
    CGtV3d field_150;       // last contact point [G]
    unsigned char pad_160[0x70];
    UnkStruct_001B4BF0_box field_1D0;
    float field_1F0;        // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[9];
    unsigned char field_211;
    unsigned char field_212; // pinned [G]: takes the whole separation on the other car
    unsigned char pad_213[0x13F4 - 0x213];
    UnkStruct_001B6380_car * field_13F4;
    unsigned char pad_13F8[0x10];
    float field_1408;
    unsigned char pad_140C[0x153C - 0x140C];
    unsigned char field_153C;  // hit side [G]
};
class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[0xB];
    CB3RaceCarPhysics * field_C;
    int GetNetworkCollBodyType() const;
};
class CB3CollidingPair {
public:
    CGtV3d field_0;          // contact point
    CGtV3d field_10;         // contact normal
    float field_20;          // impulse
    CB3ActiveBody * field_24;
    CB3ActiveBody * field_28;
    unsigned char field_2C;  // colliding
    unsigned char field_2D;  // 1 slam, 2 shunt [G]
    unsigned char pad_2E[2];
};
class CB3CrashStartInfo;
enum ERaceCarCollisionType {};   // [C] type name: the mangled OnRaceCarCollision symbols; values [G] 1, 3, 4, 5, 6
// [C] the race-logic object: vtable slot +0x6C holds OnRaceCarCollision (__vt__23CB3OfflineRoadRageLogic 0x4DEE6C =
// 0x38C6B0 OnRaceCarCollision__23CB3OfflineRoadRageLogic); the base class is unnamed, so placeholder slots before it.
class UnkStruct_001B6380_logic {
public:
    virtual void vfunc_8();  virtual void vfunc_C();  virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68();
    virtual bool OnRaceCarCollision(ERaceCarCollisionType, CB3RaceCarPhysics *, CB3RaceCarPhysics *, float);
};
struct UnkStruct_D_0051BA88 {
    struct { unsigned char pad_0[0x1B4]; UnkStruct_001B6380_logic * field_1B4; } * field_0;
    unsigned char pad_4[0xC];   // [G] size: absolute addressing needs > 8 bytes (N50)
};
class CB3HUDSoundManager {
public:
    void OnRaceCarCollision(ERaceCarCollisionType, CB3RaceCarPhysics *, CB3RaceCarPhysics *, float);
    unsigned char pad_0[0x10];
};
class CB3PhysicsManager {
public:
    void RaceCarRaceCarResponse(CB3CollidingPair * p0);
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern CB3HUDSoundManager D_01E7A800;
extern unsigned char kaabCanFatal[7][7];
extern unsigned char D_0055E948[];
// [C] names from the data tables (research/retail_data_names.csv, medium): the values do not all fit them -- 0x4E162C (0.1)
// is used as the restitution, 0x4E1630 (0.1) as the contact-point lift [G].
extern float _gnHullHullCollisionPCID, krRaceCarSlamShuntRestitution;
extern float krImpulseBodgeEffectsFactor, krRaceCarRaceCarCrashSpeed, krMaxBounceMass;
extern float krRaceCarShuntSpeed, krRaceCarShuntRange, krRaceCarSlamSpeed, krRaceCarSlamRange, krPaintTradeThreshold;
extern float D_004E0D6C;   // 2.2369363 (m/s -> mph)
extern float D_004E1688;   // 20.0 (bounce force scale)
extern float D_004E168C;   // 40.0 (slam angle)
extern float D_004E1690;   // 20.0 (slam speed at 0 degrees)
extern float D_004E1694;   // 35.0 (slam speed at the full angle)
extern float D_004E1698;   // 17.8816 (40 mph in m/s: speed advantage that makes the slower car the slammer)
extern "C" unsigned char CollideBodyHulls__20CB3ConvexHullCollideFP20CB3HullCollideParamsP16CB3CollidingBodyP16CB3CollidingBodyb(
    CB3HullCollideParams *, CB3RaceCarPhysics *, CB3RaceCarPhysics *, bool);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
    void *, CB3RaceCarPhysics *, int, CB3CollidingPair *, CB3CrashStartInfo *);

// [G] effective-mass term of one car: (I^-1 (r x n)) x r
static inline CGtV3d func_001B6380_inl2(const CB3RaceCarPhysics *o, CGtV3d p, const CGtV3d &n)
{
    CGtV3d r = p - o->field_204->mPos;
    return CrossProduct(TransformVector(*(const CGtMatrix3x3*)o->field_40, CrossProduct(r, n)), r);
}
// [G] the contact's parameter along the car's length: 0 at the box front (max z), 1 at the back (min z), clamped
static inline float func_001B6380_inl3(const CB3RaceCarPhysics *o, const CGtV3d &p)
{
    CGtMatrix3x4 * m = o->field_204;
    CGtV3d lFront = m->mPos + m->mAt * o->field_1D0.field_10.Z();
    CGtV3d lAxis = m->mAt * (o->field_1D0.field_0.Z() - o->field_1D0.field_10.Z());
    float sq = lAxis.GetSquaredLength();
    float t = DotProduct(p - lFront, lAxis) / sq;
    return GtMath::Min(GtMath::Max(t, 0.0f), 1.0f);
}
// [G] shunt/slam strength: (speed - base) / range capped at 1; a paint trade below krPaintTradeThreshold (rescaled to 0..1)
static inline float func_001B6380_inl4(float lrSpeed, float lrBase, float lrRange, bool & lbPaint)
{
    float s = (lrSpeed - lrBase) / lrRange;
    if (!(s <= 1.0f)) s = 1.0f;
    if (s <= krPaintTradeThreshold) {
        lbPaint = true;
        if (!(s <= 0.0f)) s = s / krPaintTradeThreshold;
    }
    return s;
}

// 0x001B6380
void CB3PhysicsManager::RaceCarRaceCarResponse(CB3CollidingPair * p0)
{
    CB3HullCollideParams lHullColParams;
    CB3RaceCarPhysics * a = p0->field_24->field_C;
    CB3RaceCarPhysics * b = p0->field_28->field_C;
    UnkStruct_001B6380_logic * logic = D_0051BA88.field_0->field_1B4;
    p0->field_2C = CollideBodyHulls__20CB3ConvexHullCollideFP20CB3HullCollideParamsP16CB3CollidingBodyP16CB3CollidingBodyb(
        &lHullColParams, a, b, false);
    if (p0->field_2C == 0)
        return;
    a->field_211 = 1;
    b->field_211 = 1;

    // separation on the ground plane, split by mass
    if (lHullColParams.field_1E4 != 0) {
        float f = a->field_1F0 / (a->field_1F0 + b->field_1F0);
        CGtV3d da = lHullColParams.field_0.field_30.mPos - a->field_204->mPos;
        da.SetY(0.0f);
        CGtV3d db = lHullColParams.field_F0.field_30.mPos - b->field_204->mPos;
        db.SetY(0.0f);
        CGtV3d d = da - db;
        if (b->field_212 != 0) {
            a->field_130 += d;
        } else if (a->field_212 != 0) {
            b->field_130 += -d;
        } else {
            a->field_130 += d * (1.0f - f);
            b->field_130 += d * -f;
        }
    }

    // contact point at the cars' height, normal flattened
    p0->field_0 = lHullColParams.field_200;
    // [G] a's height twice (retail reads only a->field_204: vaddy.y of the same register), plus the lift constant
    p0->field_0.SetY((a->field_204->mPos.Y() + a->field_204->mPos.Y()) * 0.5f + krRaceCarSlamShuntRestitution);
    p0->field_10 = lHullColParams.field_1F0;
    p0->field_10.SetY(0.0f);
    a->field_150 = p0->field_0;
    b->field_150 = p0->field_0;

    float lrParamA = func_001B6380_inl3(a, p0->field_0);
    float lrParamB = func_001B6380_inl3(b, p0->field_0);

    // closing speed and the restitution impulse
    CGtV3d lPoint = p0->field_0;
    CGtV3d lRel = (CrossProduct(b->field_D0, lPoint - b->field_204->mPos) + b->field_B0)
                - (CrossProduct(a->field_D0, lPoint - a->field_204->mPos) + a->field_B0);
    CGtV3d lNormal = p0->field_10;
    float lrClosing = DotProduct(lRel, lNormal);
    float lrClosingSpeed = GtMath::Abs(D_004E0D6C * lrClosing);
    XAxisType lNum = DotProduct(lNormal, lRel) * -(1.0f + _gnHullHullCollisionPCID);
    CGtV3d ka = func_001B6380_inl2(a, lPoint, lNormal);
    CGtV3d kb = func_001B6380_inl2(b, lPoint, lNormal);
    XAxisType lDen = DotProduct(ka + kb, lNormal) + (1.0f / a->field_1F0 + 1.0f / b->field_1F0);
    float lrImpulse = (float)lNum / (float)lDen;
    CGtV3d lImp = lNormal * -fabsf(lrImpulse);
    if (lrImpulse > 0.0f) {
        a->field_110 += lImp;
        b->field_110 += -lImp;
        // bounce: each car pushed by the other's (capped) mass
        CGtV3d lForce = p0->field_10 * GtMath::Min(b->field_1F0, krMaxBounceMass) * -D_004E1688
                      * (1.0f + GtMath::Abs(b->field_1408));
        a->field_F0 += lForce;
        a->ApplyNonSpinoutPositionedForce(p0->field_0, lForce);
        lForce = p0->field_10 * GtMath::Min(a->field_1F0, krMaxBounceMass) * D_004E1688
               * (1.0f + GtMath::Abs(a->field_1408));
        b->field_F0 += lForce;
        b->ApplyNonSpinoutPositionedForce(p0->field_0, lForce);
    }
    float lrB = lrClosingSpeed * (a->field_1F0 + b->field_1F0);
    p0->field_20 = krImpulseBodgeEffectsFactor * (0.5f * lrB);

    // fatal crashes
    if (lrClosingSpeed > krRaceCarRaceCarCrashSpeed) {
        int lnIndex;
        if (kaabCanFatal[p0->field_24->GetNetworkCollBodyType()][p0->field_28->GetNetworkCollBodyType()]) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
                D_0055E948, a, a->field_13F4->field_19AC, p0, 0);
            lnIndex = a->field_13F4->field_19AC;
        } else {
            lnIndex = b->field_13F4->field_19AC;
        }
        if (kaabCanFatal[p0->field_28->GetNetworkCollBodyType()][p0->field_24->GetNetworkCollBodyType()]) {
            CB3CollidingPair lPair;
            lPair.field_2C = p0->field_2C;
            lPair.field_10 = -p0->field_10;
            lPair.field_24 = p0->field_28;
            lPair.field_28 = p0->field_24;
            lPair.field_0 = p0->field_0;
            lPair.field_20 = GtMath::Max(0.0f, lrImpulse);
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
                D_0055E948, b, lnIndex, &lPair, 0);
        }
    } else {
        logic->OnRaceCarCollision((ERaceCarCollisionType)1, a, b, 1.0f);
    }

    // side of b that a is on; both speeds
    float lrSide = DotProduct(b->field_204->mRight, b->field_204->mPos - a->field_204->mPos);
    float lrSpeedA = ((CGtV4d *)&a->field_B0)->W();
    float lrSpeedB = ((CGtV4d *)&b->field_B0)->W();
    bool lbPaint;
    bool r;

    if (GtMath::IsEffectivelyZero(1.0f - lrParamA) && GtMath::IsEffectivelyZero(0.0f - lrParamB)) {
        // a's back against b's front, a faster: a shunts b
        if (lrClosingSpeed <= krRaceCarShuntSpeed) return;
        if (lrSpeedA <= lrSpeedB) return;
        lbPaint = false;
        float s = func_001B6380_inl4(lrClosingSpeed, krRaceCarShuntSpeed, krRaceCarShuntRange, lbPaint);
        if (lbPaint) {
            r = logic->OnRaceCarCollision((ERaceCarCollisionType)4, a, b, s);
        } else {
            r = logic->OnRaceCarCollision((ERaceCarCollisionType)6, a, b, s);
            D_01E7A800.OnRaceCarCollision((ERaceCarCollisionType)6, a, b, s);
        }
        if (!r) return;
        p0->field_2D = 2;
        b->field_153C = lrSide < 0.0f;
        if (!lbPaint) return;
        a->field_153C = b->field_153C != 1;
    } else if (GtMath::IsEffectivelyZero(1.0f - lrParamB) && GtMath::IsEffectivelyZero(0.0f - lrParamA)) {
        // b's back against a's front, b faster: b shunts a
        if (lrClosingSpeed <= krRaceCarShuntSpeed) return;
        if (lrSpeedB <= lrSpeedA) return;
        lbPaint = false;
        float s = func_001B6380_inl4(lrClosingSpeed, krRaceCarShuntSpeed, krRaceCarShuntRange, lbPaint);
        if (lbPaint) {
            r = logic->OnRaceCarCollision((ERaceCarCollisionType)4, b, a, s);
        } else {
            r = logic->OnRaceCarCollision((ERaceCarCollisionType)6, b, a, s);
            D_01E7A800.OnRaceCarCollision((ERaceCarCollisionType)6, a, b, s);
        }
        if (!r) return;
        p0->field_2D = 2;
        a->field_153C = lrSide > 0.0f;
        if (!lbPaint) return;
        b->field_153C = a->field_153C != 1;
    } else {
        // slam: closing speed against the angle between the headings (on the ground plane)
        CGtV3d lAtA = a->field_204->mAt;
        CGtV3d lAtB = b->field_204->mAt;
        lAtA.SetY(0.0f);
        lAtB.SetY(0.0f);
        float lrAngle = AngleBetweenVectors(lAtA, lAtB);
        bool lbSlam = false;
        if (lrClosingSpeed > D_004E1694) lbSlam = true;
        if (lrClosingSpeed > D_004E1690 && GtMath::Abs(lrAngle) > D_004E168C) lbSlam = true;
        if (lrClosingSpeed > D_004E1690 + (lrAngle / D_004E168C) * (D_004E1694 - D_004E1690)) lbSlam = true;
        if (!lbSlam) return;
        lbPaint = false;
        float s = func_001B6380_inl4(lrClosingSpeed, krRaceCarSlamSpeed, krRaceCarSlamRange, lbPaint);
        // the car further back along its length slams, unless the other is much faster
        bool lbA = lrParamA > lrParamB;
        bool lbB = !lbA;
        if (lbA) {
            if (lrSpeedB - lrSpeedA > D_004E1698) { lbA = false; lbB = true; }
        } else if (lbB) {
            if (lrSpeedA - lrSpeedB > D_004E1698) { lbA = true; lbB = false; }
        }
        if (lbA) {
            if (lbPaint) r = logic->OnRaceCarCollision((ERaceCarCollisionType)3, a, b, s);
            else r = logic->OnRaceCarCollision((ERaceCarCollisionType)5, a, b, s);
            if (!r) return;
            p0->field_2D = 1;
            b->field_153C = lrSide < 0.0f;
            if (!lbPaint) return;
            a->field_153C = b->field_153C != 1;
        } else if (lbB) {
            if (lbPaint) r = logic->OnRaceCarCollision((ERaceCarCollisionType)3, b, a, s);
            else r = logic->OnRaceCarCollision((ERaceCarCollisionType)5, b, a, s);
            if (!r) return;
            p0->field_2D = 1;
            a->field_153C = lrSide > 0.0f;
            if (!lbPaint) return;
            b->field_153C = a->field_153C != 1;
        }
    }
}
