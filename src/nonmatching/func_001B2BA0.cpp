// NONMATCHING: func_001B2BA0 -- retail 997 / ours 1015 instructions, 998 in changed runs
// draftAD C-first: crash-breaker blast (type-4 id list, radius/strength choice, traffic crash loop, race-car air ram + i%6 damage flag + detach + special-id wreck + keep-4-nearest, two body-part impulse pools, ExplodeVehicle, 4-nearest sphere reset); calls identical, all arithmetic/VU op counts equal; residue = lqc2/sqc2 vs GPR moves (+32 qmtc2/qmfc2), frame 0x1F0 vs 0x240
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm read end to end, Ghidra as aid); call sequence identical incl. the 7-way i%6 jump table; per-mnemonic counts equal for all ALU/FPU/VU arithmetic

// func_001B2BA0 -- hand-written C-first draft (draftAD, 2026-10-31); not in the lifter's candidates. Unnamed (research/nahelam_check.csv
// rejects CB3PhysicsManager::DoCrashBreaker for it), so a C-linkage placeholder; callers: func_001BE990 (&D_0055EF70, vehicle, 0, p0) and
// 0x1ADAD4. File B3PhysicsManager.cpp by its neighbours [G].
// What it does [L]: a vehicle explodes (crash breaker): with a type-4 vehicle (field_215) the id (field_2429) goes into a 4-slot list
// at this+0xE9228 (already there: return). Radius / strength: p2 ? (30, 3) : p3 ? (20, 2) : the car's own values (func_003EAD60 /
// func_003EADD0 of a 64-bit id at car+0x1960). Every active traffic vehicle (flags bit 0 set, bit 1 clear) inside the radius is
// crashed; every race car in the list at this+0xE6100 inside it gets an air ram away from the blast (falling off to 0 at the edge),
// a damage flag picked by i % 6, its bits detached; a car with one special id close in is wrecked outright, other type-1 cars go into
// a keep-4-nearest list. The two body-part pools (64 x 0x4E0 at +0xD2900, 32 x 0x780 at +0xC3900, live masks D_00648188 / D_00648190)
// get an outward impulse at a random point; then ExplodeVehicle, and the 4 nearest cars get their sphere at +0x1000 of field_CC4
// reset to their position with radius D_00522680 and flags set.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

// [G] body-part / debris object (both pools): pose, mass, a bounding sphere (w = radius), impulse accumulators
struct UnkStruct_001B2BA0_body {
    unsigned char pad_0[0x110];
    CGtV3d field_110;           // impulse accumulator [G]
    CGtV3d field_120;           // angular impulse accumulator [G]
    unsigned char pad_130[0x90];
    CGtV4d field_1C0;           // w = radius [G]
    unsigned char pad_1D0[0x20];
    float field_1F0;            // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[6];
    unsigned char field_20E;
    unsigned char pad_20F[1];
};
struct UnkStruct_001B2BA0_b4e0 { UnkStruct_001B2BA0_body b; unsigned char pad[0x4E0 - sizeof(UnkStruct_001B2BA0_body)]; };
struct UnkStruct_001B2BA0_b780 { UnkStruct_001B2BA0_body b; unsigned char pad[0x780 - sizeof(UnkStruct_001B2BA0_body)]; };

class CB3TrafficVehicle {       // [G] 0x180 bytes, the pool at D_00522660 + 0x175B0
public:
    unsigned char pad_0[0xA0];
    CGtV3d field_A0;            // position [G]
    unsigned char pad_B0[0xC4];
    unsigned char field_174;    // flags: 1 active, 2 crashed [G]
    unsigned char pad_175[0xB];
};
struct UnkStruct_001B2BA0_cc4 {
    unsigned char pad_0[0x1000];
    CGtV3dPlus field_1000;      // [G] a sphere: centre, radius
    unsigned char pad_1010[5];
    unsigned char field_1015;
    unsigned char field_1016;
};
struct UnkStruct_001B2BA0_car { unsigned char pad_0[0x1960]; unsigned long field_1960; };
class CB3VehiclePhysics {
public:
    void FireAirRamWithDirection(unsigned int, float, CGtV3d, bool);
    void DetachAll(bool);

    unsigned char pad_0[0x1F0];
    float field_1F0;            // mass [G]
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xD];
    signed char field_215;      // vehicle type [G]
    unsigned char pad_216[0xCC4 - 0x216];
    UnkStruct_001B2BA0_cc4 * field_CC4;
    unsigned char pad_CC8[0x13F4 - 0xCC8];
    UnkStruct_001B2BA0_car * field_13F4;
    unsigned char pad_13F8[0x2429 - 0x13F8];
    unsigned char field_2429;   // id [G]
    unsigned char field_242A;   // index into D_00522660's 64-bit id table [G]
};
class CB3PhysicsManager {
public:
    void InduceTrafficVehicleCrash(CB3TrafficVehicle *, CB3VehiclePhysics *, bool);

    unsigned char pad_0[0xC3900];
    UnkStruct_001B2BA0_b780 field_C3900[32];
    UnkStruct_001B2BA0_b4e0 field_D2900[64];
    CB3VehiclePhysics * field_E6100[67];
    int field_E620C;            // race cars in field_E6100
    unsigned char pad_E6210[0xE9228 - 0xE6210];
    unsigned char field_E9228[4];   // exploded type-4 vehicle ids [G]
    unsigned char pad_E922C[4];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x175B0];
    CB3TrafficVehicle field_175B0[254];
    unsigned char pad_2F2B0[0x39170 - 0x2F2B0];
    unsigned long field_39170[1];   // [G] 64-bit vehicle ids
};
struct UnkStruct_D_0055E948 {    // [L] CB3CrashActionDirector (ExplodeVehicle's this): a CGtRandom first
    CGtRandom field_0;
    unsigned char pad_8[0x8];
};
extern UnkStruct_D_00522660 D_00522660;
extern float D_00522680[];         // [G] the 4-nearest sphere radius (inside D_00522660, addressed on its own)
extern CB3PhysicsManager D_0055EF70;
extern UnkStruct_D_0055E948 D_0055E948;
extern unsigned long D_00648188[];   // live masks of the two body-part pools [G]
extern unsigned long D_00648190[];
extern float D_004E09BC;   // 0.65 (body-part blast direction y)
extern float D_004E0D68;   // 0.7 (race-car blast direction y)
extern float D_004E166C;   // 20.0
extern float D_004E1670;   // 30.0
extern float D_004E1674;   // 2.0
extern float D_004E1678;   // 3.0
extern int D_004E167C;     // 6 (damage-flag cycle)
extern float D_004E1680;   // 35.0 (body-part impulse per kg)
extern float D_004E1684;   // 0.35 (impulse point offset, x radius)

extern "C" float func_003EAD60(unsigned long);
extern "C" float func_003EADD0(unsigned long);
extern "C" void func_001C7970(CB3VehiclePhysics *);
extern "C" void func_001CC4C0(CB3VehiclePhysics *, int, int, float);
extern "C" void func_003E0FC0(UnkStruct_001B2BA0_cc4 *);
extern "C" void func_001AE360(UnkStruct_D_0055E948 *, CB3VehiclePhysics *);
extern "C" void ExplodeVehicle__22CB3CrashActionDirectorFQ29GtMathPs26CGtV3dP17CB3VehiclePhysics(UnkStruct_D_0055E948 *, const CGtV3d &, CB3VehiclePhysics *);

// [G] the director's CGtRandom as a 0..1 real
static inline float func_001B2BA0_inl2()
{
    return 2.3283064e-10f * (float)D_0055E948.field_0.Random();
}
// [G] blast falloff: 1 inside half the radius, 0 at the edge
static inline float func_001B2BA0_inl3(float lrDist, float lrRadius)
{
    return GtMath::Min(GtMath::Max((1.0f - lrDist / lrRadius) * 2.0f, 0.0f), 1.0f);
}
// [G] inlined twice (both body-part pools): an outward, upward impulse at a random point of the body's sphere
static inline void func_001B2BA0_inl4(UnkStruct_001B2BA0_body * o, const CGtV3d & lPos, float lrRadius)
{
    CGtV3d d = o->field_204->mPos - lPos;
    float lrDist = d.GetLength();
    if (lrDist < lrRadius) {
        if (d.IsEffectivelyZero()) {
            d.SetX(0.0f);
            d.SetY(1.0f);
            d.SetZ(0.0f);
        } else {
            d.Normalise();
        }
        d.SetY(D_004E09BC);
        d.Normalise();
        float s = func_001B2BA0_inl3(lrDist, lrRadius);
        d = d * (o->field_1F0 * (s * D_004E1680));
        CGtV3d r;
        r.SetX(func_001B2BA0_inl2() - 0.5f);
        r.SetY(0.5f * func_001B2BA0_inl2());
        r.SetZ(func_001B2BA0_inl2() - 0.5f);
        r.Normalise();
        r = (r * (o->field_1C0.W() * func_001B2BA0_inl2() * D_004E1684));
        o->field_110 += d;
        o->field_120 += CrossProduct((o->field_204->mPos + r) - o->field_204->mPos, d);
        o->field_20E = 0;
    }
}
static inline UnkStruct_001B2BA0_body * func_001B2BA0_inl5(int i)
{
    return (D_00648188[0] & (1UL << (long)i)) ? &D_0055EF70.field_D2900[i].b : 0;
}
static inline UnkStruct_001B2BA0_body * func_001B2BA0_inl6(int i)
{
    return (D_00648190[0] & (1UL << (long)i)) ? &D_0055EF70.field_C3900[i].b : 0;
}

// 0x001B2BA0
extern "C" void func_001B2BA0(CB3PhysicsManager * self, CB3VehiclePhysics * veh, int p2, int p3)
{
    int lnNearest = 0;
    CGtV3d lPos = veh->field_204->mPos;
    CB3VehiclePhysics * lNearCar[4];
    float lNearDist[4];

    if (veh->field_215 == 4) {
        unsigned char id = veh->field_2429;
        int i;
        for (i = 0; i < 4; i++) {
            unsigned char * e = &self->field_E9228[i];
            if (*e == 0xFF) {
                *e = id;
                break;
            }
            if (*e == id) return;
        }
    }

    float lrRadius;
    float lrStrength;
    if (p2 != 0) {
        lrStrength = D_004E1678;
        lrRadius = D_004E1670;
    } else if (p3 != 0) {
        lrRadius = D_004E166C;
        lrStrength = D_004E1674;
    } else {
        lrRadius = func_003EAD60(veh->field_13F4->field_1960);
        lrStrength = func_003EADD0(veh->field_13F4->field_1960);
    }
    float lrNearLimit = lrRadius;
    if (p2 != 0) func_001C7970(veh);

    // traffic
    int i;
    for (i = 0; i < 254; i++) {
        CB3TrafficVehicle * tv = &D_00522660.field_175B0[i];
        if ((tv->field_174 & 1) && !(tv->field_174 & 2)) {
            CGtV3d d = tv->field_A0 - lPos;
            if (d.GetLength() < lrRadius) {
                self->InduceTrafficVehicleCrash(tv, veh, true);
            }
        }
    }

    // race cars
    float lrHalf = 0.5f * lrRadius;
    for (i = 0; i < self->field_E620C; i++) {
        CB3VehiclePhysics * car = self->field_E6100[i];
        CGtV3d d = car->field_204->mPos - lPos;
        float lrDist = d.GetLength();
        if (!(lrDist < lrRadius)) continue;
        if (d.IsEffectivelyZero()) {
            d.SetX(0.0f);
            d.SetY(1.0f);
            d.SetZ(0.0f);
        } else {
            d.Normalise();
        }
        d.SetY(D_004E0D68);
        d.Normalise();
        float lrForce = (1600.0f * (lrStrength * func_001B2BA0_inl3(lrDist, lrRadius))) / car->field_1F0;
        car->FireAirRamWithDirection(0x10, lrForce, d, true);
        switch (i % D_004E167C) {
        case 0: func_001CC4C0(car, 1, 1, lrForce); break;
        case 1: func_001CC4C0(car, 8, 1, lrForce); break;
        case 2: func_001CC4C0(car, 0x20, 1, lrForce); break;
        case 3: func_001CC4C0(car, 0x40, 1, lrForce); break;
        case 4: func_001CC4C0(car, 4, 1, lrForce); break;
        case 5: func_001CC4C0(car, 0x40, 1, lrForce); break;
        default: func_001CC4C0(car, 2, 1, lrForce); break;
        }
        func_003E0FC0(car->field_CC4);
        car->DetachAll(true);
        if (D_00522660.field_39170[car->field_242A] == 0x77042838671E0800UL && lrDist < lrHalf) {
            func_001AE360(&D_0055E948, car);
            func_001C7970(car);
        } else if (((1 << car->field_215) & 2) && lrDist < lrNearLimit) {
            // keep the 4 nearest, sorted [G: as retail, the test reads slot j, not j - 1]
            if (lnNearest < 4) lnNearest++;
            int j = lnNearest - 1;
            while (j > 0 && !(lNearDist[j] <= lrDist)) {
                lNearCar[j] = lNearCar[j - 1];
                lNearDist[j] = lNearDist[j - 1];
                j--;
            }
            lNearCar[j] = car;
            lNearDist[j] = lrDist;
            if (lnNearest == 4) lrNearLimit = lNearDist[3];
        }
    }

    // body parts
    for (i = 0; i < 64; i++) {
        UnkStruct_001B2BA0_body * o = func_001B2BA0_inl5(i);
        if (o != 0) func_001B2BA0_inl4(o, lPos, lrRadius);
    }
    for (i = 0; i < 32; i++) {
        UnkStruct_001B2BA0_body * o = func_001B2BA0_inl6(i);
        if (o != 0) func_001B2BA0_inl4(o, lPos, lrRadius);
    }

    ExplodeVehicle__22CB3CrashActionDirectorFQ29GtMathPs26CGtV3dP17CB3VehiclePhysics(&D_0055E948, veh->field_204->mPos, veh);

    while (lnNearest != 0) {
        lnNearest--;
        CB3VehiclePhysics * car = lNearCar[lnNearest];
        car->field_CC4->field_1016 |= 0xF0;
        car->field_CC4->field_1015 |= 0x10;
        car->field_CC4->field_1000.SetGtV3d(car->field_204->mPos);
        car->field_CC4->field_1000.SetPlus(D_00522680[0]);
    }
}
