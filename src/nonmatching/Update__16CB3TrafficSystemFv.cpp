// NONMATCHING: Update__16CB3TrafficSystemFv -- retail 785 / ours 769 instructions, 614 in changed runs
// draftAK C-first: dead-vehicle delay queue -> free list, leading player's race position/lap (vfunc_20, field_1348) arming the traffic trigger, per-race-car CB3TrafficRaceCarInfo in the scratchpad (replay: CGtQuatPos::ConvertToMatrix of gGame+0x29010, its position also stored at +0x50 as retail), live param/vehicle bitsets -> scratchpad lists, CalcSpeed/Update/UpdateNodes, vehicle Update/UpdateTrailerPosition, stop junctions, lights, valves or hulls; 769/785, call multiset identical (scoped inline_depth(7) [G] gives retail's out-of-line CGtV4d(u_long128) ctor call); left: frame 0x3A0 vs 0x370, block placement
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every branch sense, store order per arm and call argument traced (bool fields passed unconverted; the 2-player race position/lap are left unset by retail when no car has field_1348 > 0, kept uninitialised)

// CB3TrafficSystem::Update() -- draftAK (C-first draft). 0x166160, 0xC44.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid). Layout from
// the proven Prepare__16CB3TrafficSystemFv (B3TrafficSystem_00166F50.cpp) and func_00163E90 (the dead-vehicle queues).
// What it does [L], only while field_363BB is set:
//  1. the delayed dead-vehicle queue (field_36370..74, per-slot frame countdowns field_36378[32], read index field_36398):
//     expired vehicles move to the free list (field_36364..68) and the live count field_363AC drops;
//  2. the leading player's race position (vfunc_20 of each player car, the 2-player case keeps the one with the larger
//     field_1348) and lap (field_10D4 + 1), which arm the next traffic trigger (field_363A4/A6) or, in a timed mode
//     (field_363B7), field_363A0; with a trigger pending, UseNextTriggerData;
//  3. one CB3TrafficRaceCarInfo (0x70 bytes) per race car in the scratchpad (0x70000000): matrix, velocity, half size,
//     flags; in replay (gWorld+0x143840) the matrix comes from the replay camera's CGtQuatPos instead;
//  4. the live params (bitset field_36300) and vehicles (bitset field_362E0) collected into scratchpad lists, then
//     CalcSpeed / Update / UpdateNodes per param, Update / UpdateTrailerPosition per vehicle, the stop junctions, lights,
//     and the valves (generating modes) or the hulls (per player).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern float D_00522680;   // [L] game time
extern int D_0064D37C;     // [G] race car count (gWorld+0x12AD1C)
extern int D_0064517C;     // [G] the int CalcSpeed takes (its vehicle-table count, gWorld+0x122B1C)

struct UnkStruct_00166160_dim { unsigned char pad_0[0xE80]; CGtV3d field_E80; };   // [G] vehicle dimensions (x half width, z half length)

struct UnkStruct_00166160_car {             // [G] a race car (CB3RaceCar-like, 0x27D0 bytes at gWorld+0x12AD50)
    CGtV3d field_0;                         // matrix rows
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    UnkStruct_00166160_dim *field_40;
    unsigned char pad_44[0x10C4 - 0x44];
    unsigned char pad_10C4[0x10];
    int field_10D4;                         // [G] lap
    unsigned char pad_10D8[0x1348 - 0x10D8];
    float field_1348;                       // [G] race distance
    unsigned char pad_134C[0x18ED - 0x134C];
    unsigned char field_18ED;
    unsigned char pad_18EE[0x1910 - 0x18EE];
    // vptr at +0x1910: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual CGtV3d vfunc_1C();              // [C] returns 16 bytes through a0 (this in a1): [G] velocity
    virtual unsigned short vfunc_20();      // [G] race position
    int field_1914;                         // [G] control mode (0 = player driven)
    unsigned char pad_1918[0x27D0 - 0x1918];
};

struct UnkStruct_00166160_body { unsigned char pad_0[0xB0]; CGtV3d field_B0; };   // [G] a physics body (velocity at B0)
struct UnkStruct_00166160_pe { UnkStruct_00166160_body *field_0; unsigned char pad_4[0x2C]; };   // 0x30-byte entries

struct UnkStruct_D_00522660 {               // gWorld (CB3World)
    unsigned char pad_0[0x12AD28];
    UnkStruct_00166160_car *field_12AD28[6];   // [G] race cars
    unsigned char pad_12AD40[0x10];
    UnkStruct_00166160_car field_12AD50[2];    // the player cars
};
// The physics manager entries and the replay flag lie past the race cars; addressed as offsets from gWorld like retail.
struct UnkStruct_D_00522660_b {
    unsigned char pad_0[0x3C98C];
    UnkStruct_00166160_pe field_3C98C[6];   // [G] CB3PhysicsManager (gWorld+0x3C910) +0x7C: the race car bodies
    unsigned char pad_3CAAC[0x143840 - 0x3CAAC];
    unsigned char field_143840;             // [G] replay playing
};
struct UnkStruct_D_004EE040 {               // [L] gGame
    unsigned char pad_0[0x29010];
    CGtQuatPos field_29010;                 // [G] the replay camera's rotation and position
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_004EE040 D_004EE040;

class CB3TrafficRaceCarInfo {               // [C] class name from Update__17CB3TrafficVehicleFP21CB3TrafficRaceCarInfoi; 0x70 bytes
public:
    CGtV3d field_0;                         // matrix rows
    CGtV3d field_10;
    CGtV3d field_20;
    CGtV3d field_30;
    CGtV3d field_40;                        // velocity
    CGtV3d field_50;                        // [G] velocity from vfunc_1C (the replay position in replay)
    float field_60;                         // half width
    float field_64;                         // half length
    unsigned char field_68;                 // [G] player controlled
    unsigned char field_69;
    unsigned char pad_6A[0x6];
};

class CB3TrafficParam {
public:
    void CalcSpeed(int, bool, bool);
    void Update(bool);
    void UpdateNodes();
    unsigned char pad_0[0x4B];
    unsigned char field_4B;                 // flags (1: nodes need updating)
    unsigned char pad_4C[0x4];
};
class CB3TrafficVehicle {
public:
    void Update(CB3TrafficRaceCarInfo *, int);
    void UpdateTrailerPosition();
    unsigned char pad_0[0x108];
    CB3TrafficVehicle *field_108;           // next in a list
    void *field_10C;                        // trailer
    unsigned char pad_110[0x70];
};
class CB3TrafficValve {
public:
    void Update(int, unsigned short, float, bool, bool);
    unsigned char pad_0[0x118];
};
class CB3StopJunction {
public:
    void Update(bool, float);
    unsigned char pad_0[0x20];
};
class CB3TrafficLight {
public:
    void Update(float);
    unsigned char pad_0[0x18];
};

struct UnkStruct_00166160_spr {             // [G] scratchpad layout (0x70000000)
    CB3TrafficRaceCarInfo field_0[6];
    CB3TrafficParam *field_2A0[254];
    CB3TrafficVehicle *field_698[254];
};

class CB3TrafficSystem {
public:
    void Update();
    void UseNextTriggerData(float);
    void UpdateHulls(int, float, int);

    void *field_0;
    CB3TrafficValve field_4[255];
    CB3StopJunction field_116EC[7];
    CB3TrafficLight field_117CC[128];
    unsigned char pad_123CC[0x404];
    CB3TrafficVehicle field_127D0[254];
    CB3TrafficParam field_2A4D0[254];
    unsigned char pad_2F430[0x362E0 - 0x2F430];
    unsigned int field_362E0[8];            // live vehicles
    unsigned int field_36300[8];            // live params
    unsigned char pad_36320[0x20];
    int field_36340;                        // [G] trigger position window
    unsigned char pad_36344[0xC];
    unsigned char field_36350[6];
    unsigned char field_36356[6];
    unsigned char field_3635C[6];
    unsigned char pad_36362[2];
    CB3TrafficVehicle *field_36364;         // free list head
    CB3TrafficVehicle *field_36368;         // free list tail
    void *field_3636C;
    CB3TrafficVehicle *field_36370;         // dead-vehicle queue head
    CB3TrafficVehicle *field_36374;         // dead-vehicle queue tail
    unsigned char field_36378[32];          // per-slot frame countdowns
    unsigned char field_36398;              // read index
    unsigned char field_36399;              // write index
    unsigned char pad_3639A[0x6];
    float field_363A0;                      // [G] trigger time
    unsigned short field_363A4;             // [G] trigger race position
    unsigned char field_363A6;              // [G] trigger lap
    unsigned char pad_363A7[0x4];
    unsigned char field_363AB;              // vehicle count
    unsigned char field_363AC;              // live vehicle count
    unsigned char field_363AD;              // valves
    unsigned char field_363AE;              // splitters
    unsigned char field_363AF;              // lights
    unsigned char field_363B0;              // stop junctions
    unsigned char pad_363B1[0x6];
    bool field_363B7;              // [G] timed generation mode
    bool field_363B8;
    unsigned char field_363B9;              // [G] two players
    bool field_363BA;
    unsigned char field_363BB;              // [G] active
    unsigned char pad_363BC;
    unsigned char field_363BD;              // trigger data pending
};

// [L] the free-list append of func_00163E90 (its non-delayed arm), inlined.
static inline void func_00166160_inl1(CB3TrafficSystem *s, CB3TrafficVehicle *v)
{
    if (s->field_36364 == 0) {
        s->field_36364 = v;
        s->field_36368 = v;
        v->field_108 = 0;
    } else {
        s->field_36368->field_108 = v;
        v->field_108 = 0;
        s->field_36368 = v;
    }
}

#pragma push
#pragma inline_depth(7)
void CB3TrafficSystem::Update()
{
    UnkStruct_00166160_spr * const spr = (UnkStruct_00166160_spr *)0x70000000;
    if (field_363BB == 0)
        return;

    if (field_36370 != 0) {
        unsigned int slot = field_36398;
        CB3TrafficVehicle *v = field_36370;
        for (;;) {
            bool removed = false;
            if (--field_36378[slot] == 0) {
                if (field_36370->field_108 == 0) {
                    field_36370 = 0;
                    field_36374 = 0;
                } else {
                    field_36370 = field_36370->field_108;
                }
                v->field_108 = 0;
                field_36398++;
                if (field_36398 >= 32)
                    field_36398 = 0;
                func_00166160_inl1(this, v);
                removed = true;
                field_363AC--;
            }
            if (field_36370 == 0 || v == field_36374)
                break;
            if (removed) {
                slot = field_36398;
                v = field_36370;
            } else {
                slot++;
                v = v->field_108;
                if (slot >= 32)
                    slot = 0;
            }
        }
    }

    int nPlayers;
    unsigned short position;                // [C] retail leaves it unset in the 2-player case when no car has
    unsigned char lap;                      //     field_1348 > 0 (s5/s7 keep the caller's values): read below as is
    unsigned short positions[2];
    if (field_363B9 == 0) {
        nPlayers = 1;
        UnkStruct_00166160_car *car = &D_00522660.field_12AD50[0];
        positions[0] = car->vfunc_20();
        position = positions[0];
        lap = car->field_10D4 + 1;
    } else {
        float best = 0.0f;
        nPlayers = 2;
        UnkStruct_00166160_car *cars[2];
        for (int i = 0; i < 2; i++) {
            UnkStruct_00166160_car *car = &D_00522660.field_12AD50[i];
            cars[i] = car;
            positions[i] = car->vfunc_20();
            float d = car->field_1348;
            if (d > best) {
                position = positions[i];
                lap = cars[i]->field_10D4 + 1;
                best = d;
            }
        }
    }

    float t = D_00522680;
    if (field_363BD != 0) {
        UseNextTriggerData(t);
    } else if (field_363B7 != 0) {
        if (!(field_363A0 <= 0.0f) && !(t <= field_363A0))
            field_363BD = 1;
    } else {
        if (field_363A4 + field_363A6 > 0 && position >= field_363A4 && position <= field_363A4 + field_36340
            && lap == field_363A6)
            field_363BD = 1;
    }

    UnkStruct_D_00522660_b *w = (UnkStruct_D_00522660_b *)&D_00522660;
    int nCars = D_0064D37C;
    for (int i = 0; i < nCars; i++) {
        UnkStruct_00166160_car *car = D_00522660.field_12AD28[i];
        UnkStruct_00166160_body *body = w->field_3C98C[i].field_0;
        CB3TrafficRaceCarInfo *info = &spr->field_0[i];
        if (car->field_1914 == 0) {
            info->field_69 = car->field_18ED;
            info->field_40 = body->field_B0;
            info->field_68 = 1;
            info->field_60 = car->field_40->field_E80.X();
            info->field_64 = car->field_40->field_E80.Z();
            if (w->field_143840 != 0) {
                CGtMatrix3x4 m = D_004EE040.field_29010.ConvertToMatrix();
                info->field_0 = m.mRight;
                info->field_10 = m.mUp;
                info->field_20 = m.mAt;
                info->field_30 = m.mPos;
                info->field_50 = D_004EE040.field_29010.mPos;   // [C] retail stores the replay position here too
            } else {
                info->field_0 = car->field_0;
                info->field_10 = car->field_10;
                info->field_20 = car->field_20;
                info->field_30 = car->field_30;
                info->field_50 = car->vfunc_1C();
            }
        } else {
            info->field_68 = 0;
            info->field_40 = body->field_B0;
            info->field_60 = car->field_40->field_E80.X();
            info->field_64 = car->field_40->field_E80.Z();
            info->field_69 = 0;
            info->field_0 = car->field_0;
            info->field_10 = car->field_10;
            info->field_20 = car->field_20;
            info->field_30 = car->field_30;
            info->field_50 = car->vfunc_1C();
        }
    }
    for (int i = 0; i < nCars; i++) {
        field_36350[i] = 0;
        field_36356[i] = 0;
        field_3635C[i] = 0;
    }

    int nParams = 0;
    {
        CB3TrafficParam *p = &field_2A4D0[0];
        unsigned short word = 0;
        int base = 0;
        do {
            unsigned int bits = field_36300[word];
            signed char n = 32;
            if (base >= 0xDE)
                n = 31;
            unsigned int mask = 1;
            for (signed char b = 0; b < n; b++) {
                if (bits & mask)
                    spr->field_2A0[nParams++] = p;
                mask <<= 1;
                p++;
            }
            word++;
            base += 32;
        } while (base < 0xFE);
    }
    int count = D_0064517C;
    for (int i = 0; i < nParams; i++)
        spr->field_2A0[i]->CalcSpeed(count, field_363B7, field_363B8);
    for (int i = 0; i < nParams; i++)
        spr->field_2A0[i]->Update(field_363B8);
    for (int i = 0; i < nParams; i++)
        if (spr->field_2A0[i]->field_4B & 1)
            spr->field_2A0[i]->UpdateNodes();

    int nVehicles = 0;
    {
        unsigned int bits = field_362E0[0];
        CB3TrafficVehicle *v = &field_127D0[0];
        unsigned short word = 0;
        for (int base = 0; base < field_363AB; base += 32) {
            signed char n = 32;
            if (base >= 0xDE)
                n = 31;
            unsigned int mask = 1;
            for (signed char b = 0; b < n; b++) {
                if (bits & mask)
                    spr->field_698[nVehicles++] = v;
                mask <<= 1;
                v++;
            }
            word++;
            bits = field_362E0[word];
        }
    }
    for (int i = 0; i < nVehicles; i++)
        spr->field_698[i]->Update(spr->field_0, nCars);
    for (int i = 0; i < nVehicles; i++)
        if (spr->field_698[i]->field_10C != 0)
            spr->field_698[i]->UpdateTrailerPosition();

    for (int i = 0; i < field_363B0; i++)
        field_116EC[i].Update(field_363BA, t);
    for (int i = 0; i < field_363AF; i++)
        field_117CC[i].Update(t);

    if (field_363BD == 0) {
        if (field_363B8 != 0 || field_363B7 != 0) {
            for (int i = 0; i < field_363AD; i++)
                for (int j = 0; j < nPlayers; j++)
                    field_4[i].Update(j, 0, t, field_363B7, field_363B8);
        } else {
            for (int j = 0; j < nPlayers; j++)
                UpdateHulls(positions[j], t, j);
        }
    }
}
#pragma pop
