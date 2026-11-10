// NONMATCHING: CollideAndRespondPair__17CB3PhysicsManagerFP16CB3CollidingPair -- retail 631 / ours 623 instructions, 505 in changed runs
// draftAD: pair reset, type-8 out, vehicle/traffic, car-car (field_210), vehicle/prop (box test, prop hit, dynamise), vehicle/vehicle dispatch; then both deform Impacts (dir, -dir), traffic bookkeeping inline per arm (func_003CD380 other/0, func_001CBCE0 own+trailer), damage deltas to func_003CCC60 when logic vfunc_B0, crash director; calls identical as a multiset (car-car block placed later), all ALU/VU op counts equal except lb reloads (13 vs 18) and branch layout
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm + Ghidra; Ghidra's either/or traffic branch corrected from the asm); call multiset identical; the only mnemonic differences are branch layout, lb reloads and lw/addiu address forms

// CB3PhysicsManager::CollideAndRespondPair(CB3CollidingPair*) -- hand-written draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: retail symbol table. Layouts as the BodyBodyResponse / RaceCarRaceCarResponse archives; Impact's declaration as the
// Update__17CB3PhysicsManager / func_001C8120 archives. [L] reading: the pair result cleared; type-8 bodies never collide; a
// vehicle against type 3 (traffic) -> VehicleTrafficResponse (car/traffic first) or BodyTrafficResponse; two race cars -> the
// car-car response unless one is detached (field_210) -> BodyBodyResponse; a vehicle against type 5 (prop) -> the box test
// (func_002F0440), a prop hit for a race car, the prop dynamised and a body-body response; two vehicles -> BodyBodyResponse.
// Then, for a colliding pair of two cars/traffic vehicles both flagged field_210, both get a deform Impact (the second with the
// direction reversed), traffic vehicles their crash bookkeeping (func_003CD380 / func_001CBCE0), and the damage deltas reported
// (func_003CCC60) when the logic's vfunc_B0 asks for it; finally the crash director's vehicle-vehicle handler.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001B7220_params {   // [G] CB3VehicleParams (field_CC4)
    unsigned char pad_0[0x300];
    unsigned char field_300[0x70];   // the CB3VehicleDeform (Impact's this)
    float field_370;                 // damage [G]
    unsigned char pad_374[0x1023 - 0x374];
    unsigned char field_1023;
    void * field_1024;
};
struct UnkStruct_001B7220_car { unsigned char pad_0[0x10C0]; unsigned char field_10C0[0x8A0]; unsigned long field_1960; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x160];
    unsigned char field_210;         // [G] detached / free body
    unsigned char pad_211[0xAAF];
    void * field_CC0;                // CB3VehicleEssentialParams*
    UnkStruct_001B7220_params * field_CC4;
    unsigned char pad_CC8[0x13B8 - 0xCC8];
    unsigned char field_13B8;
    unsigned char pad_13B9[0x13F4 - 0x13B9];
    UnkStruct_001B7220_car * field_13F4;
    unsigned char pad_13F8[0x2420 - 0x13F8];
    int field_2420;                  // traffic category [G]
    CB3VehiclePhysics * field_2424;  // linked trailer [G]
    unsigned char pad_2428[2];
    unsigned char field_242A;        // id table index
    unsigned char pad_242B;
    unsigned char field_242C;
};
class CB3ActiveBody {
public:
    signed char field_0;             // body type
    unsigned char pad_1[3];
    CGtMatrix3x4 * field_4;
    void * field_8;                  // box [G]
    CB3VehiclePhysics * field_C;
};
class CB3CollidingPair {
public:
    CGtV3d field_0;          // contact point
    CGtV3d field_10;         // contact normal
    float field_20;          // impulse
    CB3ActiveBody * field_24;
    CB3ActiveBody * field_28;
    unsigned char field_2C;  // colliding
    unsigned char field_2D;
    unsigned char pad_2E[2];
};
class CB3Score { public: void HandlePropHit(); };
class UnkStruct_001B7220_logic {   // [G] the race logic (D_0051BA88->field_1B4); slot +0xB0 unnamed
public:
    virtual void vfunc_8();  virtual void vfunc_C();  virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC();
    virtual bool vfunc_B0();
};
struct UnkStruct_D_0051BA88 {
    struct { unsigned char pad_0[0x1B4]; UnkStruct_001B7220_logic * field_1B4; } * field_0;
    unsigned char pad_4[0xC];
};
class CB3PhysicsManager {
public:
    void CollideAndRespondPair(CB3CollidingPair * p0);
    void VehicleTrafficResponse(CB3CollidingPair *);
    void BodyTrafficResponse(CB3CollidingPair *);
    void RaceCarRaceCarResponse(CB3CollidingPair *);
    void BodyBodyResponse(CB3CollidingPair *);
    bool DynamisePropBody(CB3ActiveBody *);
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned long D_0055B7D0[];   // [G] 64-bit vehicle ids by index
extern unsigned char D_0055E948[];   // [L] the CB3CrashActionDirector
extern unsigned char D_0064CE40[];
extern "C" bool func_00131E40(void *);   // [G] bool: retail andi 0xFF
extern "C" bool func_002F0440(void *, const CGtMatrix3x4 *, void *, const CGtMatrix3x4 *, const CGtMatrix3x4 *, void *, void *, void *);
extern "C" void func_001CBCE0(CB3VehiclePhysics *);
extern "C" void func_003CD380(void *, CB3VehiclePhysics *, CB3VehiclePhysics *);
extern "C" void func_003CCC60(void *, CB3VehiclePhysics *, CB3VehiclePhysics *, float, float);
extern "C" void HandleCrashingVehicleVehicleCollision__22CB3CrashActionDirectorFP16CB3CollidingPair(void *, CB3CollidingPair *);
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    void *, void *, void *, void *, unsigned long, int, int, int, const CGtV3d &, const CGtV3d &, int, float);

// [G] body type 4, 6 or 7 (sltiu 4 + 0xD mask)
static inline bool func_001B7220_inl1(int t) { return t == 4 || t == 6 || t == 7; }
// [G] a vehicle body: type 0..2 or 4/6/7
static inline bool func_001B7220_inl2(CB3ActiveBody * b)
{
    bool r = true;
    if (!((unsigned int)b->field_0 < 3)) {
        if (!func_001B7220_inl1(b->field_0)) r = false;
    }
    return r;
}
// [G] a car or traffic body: type 0..2 or 4
static inline bool func_001B7220_inl3(CB3ActiveBody * b)
{
    bool r = true;
    if (!((unsigned int)b->field_0 < 3) && b->field_0 != 4) r = false;
    return r;
}
static inline void func_001B7220_inl4(CB3CollidingPair * p)
{
    CB3ActiveBody * t = p->field_24;
    p->field_24 = p->field_28;
    p->field_28 = t;
}
// [G] traffic crash bookkeeping for one vehicle of the pair (the other race car or none), and its trailer
static inline void func_001B7220_inl6(CB3VehiclePhysics * v, CB3VehiclePhysics * other, bool lbReport)
{
    if (lbReport) func_003CD380(D_0064CE40, v, other);
    v->field_13B8 = 0;
    if (v->field_242C && !v->field_CC4->field_1023 && v->field_CC4->field_1024) func_001CBCE0(v);
    CB3VehiclePhysics * t = v->field_2424;
    if (t != 0) {
        t->field_13B8 = 0;
        if (t->field_242C && !t->field_CC4->field_1023 && t->field_CC4->field_1024) func_001CBCE0(t);
    }
}
static inline void func_001B7220_inl5(CB3VehiclePhysics * v, CB3ActiveBody * other, bool lbReport)
{
    if ((unsigned int)other->field_0 < 3) func_001B7220_inl6(v, other->field_C, lbReport);
    else func_001B7220_inl6(v, 0, lbReport);
}

// 0x001B7220
void CB3PhysicsManager::CollideAndRespondPair(CB3CollidingPair * p0)
{
    p0->field_2C = 0;
    p0->field_0.Zero();
    p0->field_10.Zero();
    p0->field_20 = 0.0f;
    p0->field_2D = 0;
    CB3ActiveBody * a = p0->field_24;
    CB3ActiveBody * b = p0->field_28;
    int ta = a->field_0;
    int tb = b->field_0;
    if (ta == 8) return;
    if (tb == 8) return;

    if ((func_001B7220_inl2(a) && tb == 3) || (func_001B7220_inl2(b) && ta == 3)) {
        if (ta == 3) func_001B7220_inl4(p0);
        if (func_001B7220_inl3(p0->field_24)) VehicleTrafficResponse(p0);
        else BodyTrafficResponse(p0);
    } else if ((unsigned int)a->field_0 < 3 && (unsigned int)b->field_0 < 3) {
        if (a->field_C->field_210 == 0 && b->field_C->field_210 == 0) {
            RaceCarRaceCarResponse(p0);
        } else {
            if (b->field_C->field_210 == 0) func_001B7220_inl4(p0);
            BodyBodyResponse(p0);
        }
    } else if ((func_001B7220_inl2(a) && tb == 5) || (func_001B7220_inl2(b) && ta == 5)) {
        if (ta == 5) func_001B7220_inl4(p0);
        CB3VehiclePhysics * v = p0->field_24->field_C;
        if (func_002F0440(p0->field_28->field_8, p0->field_28->field_4, p0->field_24->field_8, p0->field_24->field_4, &v->field_70, 0, 0, 0)) {
            if ((unsigned int)p0->field_24->field_0 < 3) ((CB3Score *)v->field_13F4->field_10C0)->HandlePropHit();
            if (DynamisePropBody(p0->field_28) && p0->field_24->field_0 < 8) BodyBodyResponse(p0);
        }
    } else if (func_001B7220_inl2(a) && func_001B7220_inl2(b)) {
        if ((unsigned int)b->field_0 < 3) func_001B7220_inl4(p0);
        BodyBodyResponse(p0);
    }

    if (p0->field_2C && func_001B7220_inl3(p0->field_24) && func_001B7220_inl3(p0->field_28)
        && p0->field_24->field_C->field_210 && p0->field_28->field_C->field_210) {
        bool lbReport = func_00131E40(&D_004EE040);
        bool lbDamage;
        if (lbReport) lbDamage = D_0051BA88.field_0->field_1B4->vfunc_B0();
        else lbDamage = false;
        CGtV3d lDir = p0->field_24->field_4->mPos - p0->field_28->field_4->mPos;
        lDir.Normalise();
        float lrBefore;
        float lrDamageA;
        float lrDamageB;

        CB3VehiclePhysics * va = p0->field_24->field_C;
        void * ess = va->field_CC0;
        UnkStruct_001B7220_params * prm = va->field_CC4;
        unsigned long id;
        int cat;
        if (p0->field_24->field_0 == 4) {
            id = D_0055B7D0[va->field_242A];
            cat = va->field_2420;
            func_001B7220_inl5(va, p0->field_28, lbReport);
        } else {
            cat = 1;
            id = va->field_13F4->field_1960;
        }
        if (lbDamage) lrBefore = prm->field_370;
        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
            prm->field_300, va, ess, prm, id, cat, p0->field_24->field_0, 0, p0->field_0, lDir, 0, p0->field_20);
        if (lbDamage) {
            lrDamageA = prm->field_370 - lrBefore;
            if (lrDamageA < 0.0f) lrDamageA = 0.0f;
        }

        CB3VehiclePhysics * vb = p0->field_28->field_C;
        ess = vb->field_CC0;
        prm = vb->field_CC4;
        if (p0->field_28->field_0 == 4) {
            id = D_0055B7D0[vb->field_242A];
            cat = vb->field_2420;
            func_001B7220_inl5(vb, p0->field_24, lbReport);
        } else {
            cat = 1;
            id = vb->field_13F4->field_1960;
        }
        if (lbDamage) lrBefore = prm->field_370;
        CGtV3d lRev = -lDir;
        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
            prm->field_300, vb, ess, prm, id, cat, p0->field_28->field_0, 0, p0->field_0, lRev, 0, p0->field_20);
        if (lbDamage) {
            lrDamageB = prm->field_370 - lrBefore;
            if (lrDamageB < 0.0f) lrDamageB = 0.0f;
            func_003CCC60(D_0064CE40, va, vb, lrDamageA, lrDamageB);
        }
        HandleCrashingVehicleVehicleCollision__22CB3CrashActionDirectorFP16CB3CollidingPair(D_0055E948, p0);
    }
}
