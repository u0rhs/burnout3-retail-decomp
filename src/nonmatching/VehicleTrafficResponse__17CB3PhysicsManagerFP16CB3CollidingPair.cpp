// NONMATCHING: VehicleTrafficResponse__17CB3PhysicsManagerFP16CB3CollidingPair -- retail 566 / ours 536 instructions, 449 in changed runs
// draftAG: logic complete; retail 566 / ours 536; calls identical; every VU op count identical (header Invert / DotProduct / GetLength / lane ops; stand-ins CGtV3d*WAxisType and XAxisType*float, queued); layouts and the hull fetch from the BodyTrafficResponse / RaceCarRaceCarResponse drafts; left: retail re-reads the matrix / box for every lane (lqc2 54 vs 37), the hull-type test as a bit mask (sllv), frame 0xD40 vs 0x8F0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm read end to end); call sequence identical (calls.sh); per-mnemonic VU and FPU arithmetic equal

// CB3PhysicsManager::VehicleTrafficResponse(CB3CollidingPair*) -- draftAG (C-first draft; the lifter refused it).
// [C] name: retail symbol table. Written from the retail asm. Struct layouts and the hull-params / inverse / hull-fetch inlines from
// the archived siblings BodyTrafficResponse (0x1B5730) and RaceCarRaceCarResponse (0x1B6380). Revenge's VehicleTrafficResponse
// (121 instrs, CB4HullCollideParams lCollideParams) was reworked; only the local name is taken [L].
// What it does [L]: a vehicle (pair body A, field_24) against a traffic body (B, field_28). Race cars flagged 2 are skipped; a
// vehicle not yet crashing ignores traffic more than 2 m above or below it. Hull collision; a fatal pair (kaabCanFatal) of a
// non-crashing vehicle may still be downgraded unless its closing speed beats the crash threshold. Not fatal: the two
// boxes' length segments are compared in 2D (x/z); on overlap the vehicle is pushed out along the 2D normal, gets a
// mass-capped bounce force at the contact and the race logic is told (vtable +0x5C). Fatal (or a pinned vehicle): the vehicle
// starts crashing (StartRaceCarCrashing for race cars with a crash-start info naming the traffic, else StartTrafficCrashing),
// the traffic body is crashed and the pair handed to BodyBodyResponse.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;


// [G] per-body block of the hull-collide parameters (0xF0 bytes): hull, world matrix, inverse matrix
struct UnkStruct_001B5730_hb {
    void * field_0;
    unsigned char pad_4[0x2C];
    CGtMatrix3x4 field_30;
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x40];
};
struct CB3HullCollideParams {
    UnkStruct_001B5730_hb field_0;
    UnkStruct_001B5730_hb field_F0;
    int field_1E0;
    int field_1E4;
    unsigned char pad_1E8[8];
    CGtV3d field_1F0;
    CGtV3d field_200;
};
struct UnkStruct_001B5AA0_car {   // [G] race-car object at body+0x13F4
    unsigned char pad_0[0x19AC];
    signed char field_19AC;        // player/car index [G] (StartRaceCarCrashing's int)
};
class CB3RaceCarPhysics {          // the vehicle (body A's object) [G]
public:
    void ApplyNonSpinoutPositionedForce(CGtV3d p0, CGtV3d p1);

    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;         // inverse world matrix
    CGtV4d field_B0;               // velocity, w = speed [G]
    unsigned char pad_C0[0x70];
    CGtV3d field_130;              // position correction [G]
    unsigned char pad_140[0x90];
    CGtV3d field_1D0;              // [C] x = half width, z = back of the box
    CGtV3d field_1E0;              // [C] z = front of the box
    float field_1F0;               // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[8];
    unsigned char field_210;       // crashing [G]
    unsigned char field_211;
    unsigned char field_212;       // pinned [G]
    unsigned char pad_213[2];
    signed char field_215;
    unsigned char pad_216[2];
    signed char field_218;
    unsigned char pad_219[7];
    unsigned char field_220[0x1133];   // [C] its convex hull (&field_220 into the hull params) [G size]
    unsigned char field_1353;      // [C] flags: 2 = ignore traffic (race cars), 0x10
    unsigned char pad_1354[0xA0];
    UnkStruct_001B5AA0_car * field_13F4;
    unsigned char pad_13F8[0x134];
    float field_152C;
    unsigned char pad_1530[4];
    float field_1534;              // [C] crash-speed scale
};
struct UnkStruct_001B5AA0_tv {     // the traffic body's object [G]
    unsigned char pad_0[0x90];
    CGtV3d field_90;               // [C] heading (scaled by field_C4 = speed)
    unsigned char pad_A0[0x10];
    unsigned char * field_B0;      // [C] deform data: hull at +0x1060 (BodyTrafficResponse draft)
    unsigned char pad_B4[0x10];
    float field_C4;                // [C] speed
    unsigned char pad_C8[0xAC];
    unsigned char field_174;       // [C] flags: 8 = never fatal
    unsigned char pad_175[0x93];
    void * field_208;              // [C] hull
    unsigned char pad_20C[5];
    unsigned char field_211;
};
class CB3ActiveBody {
public:
    signed char field_0;           // body type
    unsigned char pad_1[3];
    CGtMatrix3x4 * field_4;        // world matrix
    CGtV3d * field_8;              // [C] box: [0].x half width, [0].z back, [1].z front
    void * field_C;
    int GetNetworkCollBodyType() const;
};
class CB3CollidingPair {
public:
    CGtV3d field_0;                // contact point
    CGtV3d field_10;               // contact normal
    float field_20;                // impulse
    CB3ActiveBody * field_24;
    CB3ActiveBody * field_28;
    unsigned char field_2C;        // colliding
};
class CB3CrashStartInfo {          // as the BodyBodyResponse draft
public:
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[6];
    void * field_8;                // [C] here the traffic object
    void * field_C;
};
class UnkStruct_001B5AA0_logic {   // [C] the race-logic object (D_0051BA88->field_1B4); slot +0x5C called with (vehicle, traffic)
public:
    virtual void vfunc_8();  virtual void vfunc_C();  virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C(CB3RaceCarPhysics *, UnkStruct_001B5AA0_tv *);
};
struct UnkStruct_D_0051BA88 {
    struct { unsigned char pad_0[0x1B4]; UnkStruct_001B5AA0_logic * field_1B4; } * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064ED5C { signed char field_0; unsigned char pad_1[0xF]; };
class CB3PhysicsManager {
public:
    void VehicleTrafficResponse(CB3CollidingPair * p0);
    void BodyBodyResponse(CB3CollidingPair * p0);
    void CrashTrafficBody(CB3ActiveBody * p0, int p1, int p2, bool p3, bool p4, bool p5);
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064ED5C D_0064ED5C;
extern unsigned char kaabCanFatal[7][7];
extern unsigned char D_0055E948[];
extern unsigned char D_004EE040[];
// [C] names: research/retail_data_names.csv (medium/high); as RaceCarRaceCarResponse's draft notes, not every value fits its name
// (krRaceCarSlamShuntRestitution 0.1 is used as the contact-point lift here too) [G]
extern float krRaceCarSlamShuntRestitution, krRaceCarCollisionHeight, krRaceCarTrafficCrashSpeed;
extern float krNonFatalBounce, krMaxBounceMass, krImpulseBodgeEffectsFactor;
extern float D_004E0D6C;   // 2.2369363 (m/s -> mph)
extern "C" int CollideHulls__20CB3ConvexHullCollideFP20CB3HullCollideParams(CB3HullCollideParams *);
extern "C" void StartTrafficCrashing__22CB3CrashActionDirectorFP17CB3TrafficPhysicsi(void *, CB3RaceCarPhysics *, int);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
    void *, CB3RaceCarPhysics *, int, CB3CollidingPair *, CB3CrashStartInfo *);
extern "C" int func_00131E40(void *);   // [G] a game-mode test on gGame (as its other callers)
// [L] _ShortestVectorBetween2DLines (archived func_001BA4C0): distance between two 2D segments, closest points, parameters
extern "C" float func_001BA4C0(const CGtV2d &, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV2d *, CGtV2d *, float *, float *);

// [G] orthonormal inverse of src into dst (BodyTrafficResponse's func_001B5730_inv: the header Invert on a copy)
static inline void func_001B5AA0_inl1(CGtMatrix3x4 &r, const CGtMatrix3x4 &m)
{
    r = m;
    r.Invert();
}
// [L] the body's hull for the hull collision (BodyTrafficResponse's fetch): traffic deform hull, or the object's own
static inline void *func_001B5AA0_inl2(const CB3ActiveBody *b)
{
    void * h = 0;
    if (b->field_0 == 3) {
        unsigned char * x = ((UnkStruct_001B5AA0_tv *)b->field_C)->field_B0;
        if (x != 0) h = x + 0x1060;
    } else if ((unsigned int)b->field_0 <= 2 || b->field_0 == 4 || b->field_0 == 6 || b->field_0 == 7) {
        h = ((UnkStruct_001B5AA0_tv *)b->field_C)->field_208;
    }
    return h;
}
// [G] the ends of a box's length segment in the ground plane (x and z lanes): pos + at * (front z + half width) and
// pos + at * (back z - half width); retail evaluates the offset once per lane
static inline CGtV2d func_001B5AA0_inl3(const CGtMatrix3x4 *m, const CGtV3d &lo, const CGtV3d &hi)
{
    CGtV2d p;
    p.marValues[0] = m->mPos.X() + m->mAt.X() * (hi.Z() + lo.X());
    p.marValues[1] = m->mPos.Z() + m->mAt.Z() * (hi.Z() + lo.X());
    return p;
}
static inline CGtV2d func_001B5AA0_inl6(const CGtMatrix3x4 *m, const CGtV3d &lo)
{
    CGtV2d p;
    p.marValues[0] = m->mPos.X() + m->mAt.X() * (lo.Z() - lo.X());
    p.marValues[1] = m->mPos.Z() + m->mAt.Z() * (lo.Z() - lo.X());
    return p;
}

// 0x001B5AA0
void CB3PhysicsManager::VehicleTrafficResponse(CB3CollidingPair * lpPair)
{
    CB3HullCollideParams lCollideParams;
    CB3ActiveBody * b = lpPair->field_28;
    UnkStruct_001B5AA0_tv * lpTraffic = (UnkStruct_001B5AA0_tv *)b->field_C;
    CB3RaceCarPhysics * lpCar = (CB3RaceCarPhysics *)lpPair->field_24->field_C;
    UnkStruct_001B5AA0_logic * logic = D_0051BA88.field_0->field_1B4;
    bool lbRespond = false;
    if ((unsigned int)lpPair->field_24->field_0 < 3 && (lpCar->field_1353 & 2) == 2)
        return;
    if (lpCar->field_210 == 0)
        lbRespond = true;
    if (lbRespond) {
        float dy = lpPair->field_24->field_4->mPos.Y() - lpPair->field_28->field_4->mPos.Y();
        if (!(GtMath::Abs(dy) <= 2.0f))
            return;
    }
    lpPair->field_20 = 0.0f;
    lCollideParams.field_0.field_0 = lpCar->field_220;
    lCollideParams.field_0.field_30 = *lpCar->field_204;
    lCollideParams.field_0.field_70 = lpCar->field_70;
    lCollideParams.field_F0.field_30 = *lpPair->field_28->field_4;
    func_001B5AA0_inl1(lCollideParams.field_F0.field_70, *lpPair->field_28->field_4);
    lCollideParams.field_F0.field_0 = func_001B5AA0_inl2(lpPair->field_28);
    lCollideParams.field_1E0 = 1;
    bool lbFatal = false;
    if (CollideHulls__20CB3ConvexHullCollideFP20CB3HullCollideParams(&lCollideParams)) {
        if (kaabCanFatal[b->GetNetworkCollBodyType()][lpPair->field_24->GetNetworkCollBodyType()])
            lbFatal = true;
    }
    if (lpPair->field_28->field_0 == 3 && (((UnkStruct_001B5AA0_tv *)lpPair->field_28->field_C)->field_174 & 8))
        lbFatal = false;
    if (lbRespond) {
        // the two boxes' length segments in the ground plane, each lengthened by its half width
        CGtV2d lFrontA = func_001B5AA0_inl3(lpCar->field_204, lpCar->field_1D0, lpCar->field_1E0);
        CGtV2d lBackA = func_001B5AA0_inl6(lpCar->field_204, lpCar->field_1D0);
        CGtV2d lFrontB = func_001B5AA0_inl3(b->field_4, b->field_8[0], b->field_8[1]);
        CGtV2d lBackB = func_001B5AA0_inl6(b->field_4, b->field_8[0]);
        CGtV2d lPointA, lPointB;
        float lrParam1, lrParam2;
        float lrDist = func_001BA4C0(lFrontA, lBackA, lFrontB, lBackB, &lPointA, &lPointB, &lrParam1, &lrParam2);
        float lrGap = lrDist - (float)(lpCar->field_1D0.X() + b->field_8[0].X());
        if (!(lrGap <= 0.0f))
            return;
        CGtV2d n = lPointA - lPointB;
        n *= GtMath::InvSqrt(0.0f + n.marValues[1] * n.marValues[1] + n.marValues[0] * n.marValues[0]);
        float lrNz = n.marValues[1];
        CGtV3d lNormal;
        lNormal.SetX(n.marValues[0]);
        lNormal.SetY(0.0f);
        lNormal.SetZ(lrNz);
        lpPair->field_2C = 1;
        lpPair->field_10 = lNormal;
        if (lbFatal) {
            bool lbTest = (lpCar->field_1353 & 0x10) != 0x10;
            if (lbTest)
                lbTest = lpCar->field_152C < 0.0f;
            if (lbTest == true) {
                // the closing speed decides whether the fatal crash stands
                CGtV3d lRel = lpTraffic->field_90 * lpTraffic->field_C4 - (lpCar->field_204->mAt * lpCar->field_B0.W());
                float lrMph = D_004E0D6C;
                float lrSpeed = GtMath::Abs(lrMph * (float)DotProduct(lRel, lpPair->field_10));
                lpPair->field_20 = krImpulseBodgeEffectsFactor * (0.5f * (lrSpeed * (lpCar->field_1F0 + lpCar->field_1F0)));
                float lrLimit;
                if (func_00131E40(D_004EE040)) {
                    lrSpeed = (lRel.GetLength() * lrMph);
                    lrLimit = lpCar->field_1534 * krRaceCarTrafficCrashSpeed;
                } else {
                    lrLimit = lpCar->field_1534 * krRaceCarCollisionHeight;
                }
                if (!(lrSpeed <= lrLimit))
                    lbRespond = false;
            }
        }
        if (lpCar->field_212 && lpCar->field_215 != 3) {
            lbRespond = false;
            lbFatal = true;
        }
        if (lbRespond) {
            lpCar->field_130 += lNormal * -lrGap;
            CGtV3d lContact;
            lContact.SetX(lPointA.marValues[0] - (lpCar->field_1D0.X() * n.marValues[0]));
            lContact.SetY(lpCar->field_204->mPos.Y() + krRaceCarSlamShuntRestitution);
            lContact.SetZ(lPointA.marValues[1] - (lpCar->field_1D0.X() * lrNz));
            lNormal = lNormal * (krNonFatalBounce * GtMath::Min(lpCar->field_1F0, krMaxBounceMass));
            lpCar->ApplyNonSpinoutPositionedForce(lContact, lNormal);
            logic->vfunc_5C(lpCar, lpTraffic);
            lpPair->field_0 = lContact;
            return;
        }
    }
    if (!lbFatal)
        return;
    lpPair->field_2C = 1;
    lpCar->field_211 = 1;
    int lnPlayer = D_0064ED5C.field_0;
    if ((unsigned int)lpPair->field_24->field_0 < 3) {
        CB3CrashStartInfo info;
        info.field_1 = 1;
        info.field_8 = lpTraffic;
        info.field_0 = 0;
        info.field_C = 0;
        StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(
            D_0055E948, lpCar, lpCar->field_13F4->field_19AC, lpPair, &info);
    } else {
        StartTrafficCrashing__22CB3CrashActionDirectorFP17CB3TrafficPhysicsi(D_0055E948, lpCar, lpCar->field_218);
    }
    CrashTrafficBody(b, lnPlayer, lpCar->field_218, true, true, true);
    ((UnkStruct_001B5AA0_tv *)b->field_C)->field_211 = 1;
    BodyBodyResponse(lpPair);
}
