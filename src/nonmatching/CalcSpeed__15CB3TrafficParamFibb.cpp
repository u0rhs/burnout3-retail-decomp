// NONMATCHING: CalcSpeed__15CB3TrafficParamFibb -- retail 1060 / ours 1057 instructions, 534 in changed runs
// draftAJ C-first: own-vehicle crashed shortcut, state reset, two proximity sweeps (vehicle table / race cars: state 4 + random speed offset, induced traffic crash), next-param and vehicle-ahead braking (states 3/5), 8-way state switch; 1057/1060, calls identical; left: retail keeps the dead GetLane(field_41) 0xFF test, sweep-2 loop layout, d spilled through the stack (sqc2/lqc2) vs ours lq/sq, field_4 reload, frame 0x320 vs 0x230
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every compare sense, threshold constant (values read from the ELF), store and call argument traced; header GetLength/DotProduct/lane ops incl. operator-(XAxisType, float) (gapN)

// CB3TrafficParam::CalcSpeed(int, bool, bool) -- draftAJ (C-first draft; the lifter refused it). 0x161B50, 0x1090.
// [C] name: the mangled symbol in retail's tables (config/symbol_addrs_b3names.txt). Written from the retail asm (Ghidra's
// draft as a reading aid). What it does [L]: the traffic param's speed controller for one frame.
//  - own vehicle (traffic vehicle record field_4A) crashed-ish (flag 4, field_173 != 8): accelerate toward the limit, return;
//  - unless a hold state (2, 6, 7) is active, reset to state 1 and field_10 (stop distance) = -1;
//  - two proximity sweeps (the field_122A10 vehicle table, count = the int argument; then the race cars at
//    gWorld+0x12AD28): a car closer than 35 (30 in the D_0055D7F8 mode) and ahead (dot with the param's at-row > 0) whose
//    gap minus its half length is short for our speed puts us into state 4 with a randomised speed offset (field_1C),
//    unless one of the bool arguments is set; when it is also inside the lateral band (|dot right| < 10 / 4), almost
//    level (|d.y| < 2) and we go faster than 10, the physics manager induces a traffic crash and the sweep stops;
//  - the next param in the lane (field_44) and the vehicle ahead (field_40) each give a braking target (states 3 / 5)
//    when their distance is under field_14 (look-ahead) and the scaled speed is below ours;
//  - the state switch sets field_18 (acceleration), and field_2C (speed) += field_18, floored at 0.
// Revenge member names for the fields ([L], research/names/class_layouts.tsv) are in comments only.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CB3TrafficParam;
class CB3VehiclePhysics;

struct UnkStruct_00161B50_dim { unsigned char pad_0[0xE80]; CGtV3d field_E80; };   // [G] vehicle dimensions (z = half length)
struct UnkStruct_00161B50_car {             // [G] entries of the gWorld+0x122A10 table (passed on as CB3VehiclePhysics*)
    unsigned char pad_0[0x1390];
    CGtV3d field_1390;                      // position
    UnkStruct_00161B50_dim *field_13A0;
};
struct UnkStruct_00161B50_rc {              // [G] race cars (gWorld+0x12AD28, as CB3World::RenderTwoPlayer)
    unsigned char pad_0[0x30];
    CGtV3d field_30;                        // position
    UnkStruct_00161B50_dim *field_40;
    unsigned char pad_44[0x18A6];
    unsigned char field_18EA;               // [G] active
};
struct UnkStruct_00161B50_rec {             // [C] 0x50-byte records at gWorld+0x34210 (CalculateTargetParamMatrix's matrix)
    CGtMatrix3x4 field_0;                   // mRight = lateral, mAt = forward, mPos = position
    CGtV3d field_40;
};
struct CB3TrafficVehicle {                  // [G] 0x180-byte records at gWorld+0x175B0
    unsigned char pad_0[0x30];
    CGtV3d field_30;                        // position
    unsigned char pad_40[0x1E];
    unsigned char field_5E;                 // lane index
    unsigned char pad_5F[0x65];
    float field_C4;                         // speed
    unsigned char pad_C8[0x4C];
    CB3TrafficParam *field_114;             // its param
    unsigned char pad_118[0x5B];
    signed char field_173;
    unsigned char field_174;                // flags (4: [G] crashed/stopped, 2: [G] no proximity checks)
    unsigned char pad_175[0x5];
    unsigned char field_17A;
    unsigned char pad_17B[0x5];
};
struct UnkStruct_00161B50_world {           // D_00522660 (CB3World, as RenderTwoPlayer__8CB3WorldFv)
    unsigned char pad_0[0x175B0];
    CB3TrafficVehicle field_175B0[1];       // [G] count unknown
    unsigned char pad_17730[0x2F2B0 - 0x17730];
    unsigned char field_2F2B0[1];           // CB3TrafficParam records, 0x50 each (GetParam)
    unsigned char pad_2F2B1[0x34210 - 0x2F2B1];
    UnkStruct_00161B50_rec field_34210[1];
    unsigned char pad_34260[0x3B128 - 0x34260];
    CGtRandom field_3B128;
    unsigned char pad_3B130[0x122A10 - 0x3B130];
    UnkStruct_00161B50_car *field_122A10[1];
    unsigned char pad_122A14[0x12AD1C - 0x122A14];
    int field_12AD1C;                       // race car count
    unsigned char pad_12AD20[0x8];
    UnkStruct_00161B50_rc *field_12AD28[1];
};
extern UnkStruct_00161B50_world D_00522660;

struct UnkStruct_00161B50_pm { CB3VehiclePhysics *field_0; unsigned char pad_4[0x2C]; };
class CB3PhysicsManager {
public:
    void InduceTrafficVehicleCrash(CB3TrafficVehicle *, CB3VehiclePhysics *, bool);
    unsigned char pad_0[0x7C];
    UnkStruct_00161B50_pm field_7C[1];      // per race car (D_0055EFEC)
};
extern CB3PhysicsManager D_0055EF70;

struct UnkStruct_D_0055D7F7 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0055D7F7 D_0055D7F7;     // [G] a traffic mode flag (param-to-param distances)
extern UnkStruct_D_0055D7F7 D_0055D7F8;     // [G] a traffic mode flag (shorter look range)

class CB3TrafficParam {
public:
    void CalcSpeed(int, bool, bool);
    float CalcFormationSpeedChange();

    float field_0;                          // [L] mrLastValveSpeed (mph: x 0.44704 = m/s)
    float field_4;                          // distance to the next param
    float field_8;                          // [L] mrNextCarDist
    float field_C;                          // [L] mrFrontDist
    float field_10;                         // [L] mrBackDist; stop distance, < 0 = none
    float field_14;                         // [L] mrStopDist; look-ahead distance
    float field_18;                         // [L] mrSpeedDiff; acceleration this frame
    float field_1C;                         // random speed offset (state 4)
    unsigned char pad_20[0xC];
    float field_2C;                         // [L] mrSpeed
    unsigned char pad_30[0x8];
    void *field_38;                         // [L] mpCurrentBehaviour
    unsigned char pad_3C[0x4];
    unsigned char field_40;                 // [L] mu8ChangeLaneVehicleAhead
    unsigned char field_41;                 // [L] mu8LaneIndex
    unsigned char pad_42[0x2];
    unsigned char field_44;                 // [L] mu8NextTrafficParam
    unsigned char pad_45;
    unsigned char field_46;                 // [L] meState
    unsigned char field_47;                 // [L] mu8BehaviourIndex
    unsigned char pad_48;
    unsigned char field_49;                 // [L] mu8ParamIndex
    unsigned char field_4A;                 // [L] mu8TrafficIndex
    unsigned char field_4B;                 // [L] mx8Flags
    unsigned char pad_4C;
    unsigned char field_4D;                 // [L] meOwnerClass
};

// [G] the lane getter (GetLane, as Update__15CB3TrafficParamFb); retail keeps only its 0xFF test, the result is unused.
static inline void *func_00161B50_inl0(unsigned char i)
{
    if (i == 0xFF) return 0;
    return (char *)&D_00522660 + i * 76 + 0x22C;
}

static inline CB3TrafficVehicle *func_00161B50_inl1(unsigned char i)
{
    if (i == 0xFF) return 0;
    return &D_00522660.field_175B0[i];
}

static inline CB3TrafficParam *func_00161B50_inl2(unsigned char i)
{
    if (i == 0xFF) return 0;
    return (CB3TrafficParam *)&D_00522660.field_2F2B0[i * 0x50];
}

// [G] a param's matrix position (gWorld+0x34240 + index * 0x50)
static inline CGtV3d &func_00161B50_inl3(unsigned char i)
{
    return D_00522660.field_34210[i].field_0.mPos;
}

// [G] the state-4 entry: a new random speed offset in [-0.15, 0.12] unless the old one is already outside [-0.1, 0.1]
static inline void func_00161B50_inl5(CB3TrafficParam *p)
{
    p->field_46 = 4;
    float v = p->field_1C;
    if (!(v < -0.1f) && v <= 0.1f) {
        float r = 2.3283064e-10f * (float)D_00522660.field_3B128.Random();
        v = GtMath::Min(GtMath::Max(r * 5.0f - 2.0f, -0.15f), 0.12f);
    }
    p->field_1C = v;
}

// 0x00161B50
void CB3TrafficParam::CalcSpeed(int numCars, bool p1, bool p2)
{
    if (field_46 == 0) return;
    func_00161B50_inl0(field_41);
    CB3TrafficVehicle *veh = &D_00522660.field_175B0[field_4A];
    if ((veh->field_174 & 4) && veh->field_173 != 8) {
        field_18 = 0.44704f * field_0 - field_2C;
        field_2C = GtMath::Max(field_2C + field_18, 0.0f);
        return;
    }
    UnkStruct_00161B50_rec *rec = &D_00522660.field_34210[field_49];
    if (field_46 != 2 && field_46 != 6 && field_46 != 7) {
        field_46 = 1;
        field_10 = -1.0f;
    }
    float range, lat;
    if (D_0055D7F8.field_0 == 0) {
        range = 35.0f;
        lat = 10.0f;
    } else {
        range = 30.0f;
        lat = 4.0f;
    }
    if (!(veh->field_174 & 4) && !(veh->field_174 & 2)) {
        for (int i = 0; i < numCars; i++) {
            UnkStruct_00161B50_car *car = D_00522660.field_122A10[i];
            bool hit = false;
            CGtV3d d = car->field_1390 - rec->field_0.mPos;
            float dist = d.GetLength();
            if (dist < range && !(DotProduct(d, rec->field_0.mAt) <= 0.0f)) {
                float len = car->field_13A0->field_E80.Z() + field_8 + 2.0f;
                float gap = dist - len;
                if (0.5f * GtMath::Max(gap, 0.0f) < field_2C) {
                    if (field_46 == 1) {
                        if (!p1 && !p2) func_00161B50_inl5(this);
                        hit = true;
                    } else if (!(0.5f <= field_10)) {
                        if (!p1 && !p2) func_00161B50_inl5(this);
                        hit = true;
                    }
                }
                if (hit) {
                    float side = DotProduct(d, rec->field_0.mRight);
                    if (!(side <= -lat) && side < lat && GtMath::Abs(d.Y()) < 2.0f && !(field_2C <= 10.0f)) {
                        D_0055EF70.InduceTrafficVehicleCrash(veh, (CB3VehiclePhysics *)car, true);
                        break;
                    }
                }
            }
        }
        if (!(veh->field_174 & 2)) {
            for (int i = 0; i < D_00522660.field_12AD1C; i++) {
                UnkStruct_00161B50_rc *car = D_00522660.field_12AD28[i];
                if (car == 0 || car->field_18EA == 0) continue;
                bool hit = false;
                CGtV3d d = car->field_30 - rec->field_0.mPos;
                float dist = d.GetLength();
                if (dist < range && !(DotProduct(d, rec->field_0.mAt) <= 0.0f)) {
                    float len = car->field_40->field_E80.Z() + field_8 + 2.0f;
                    float gap = dist - len;
                    if (0.5f * GtMath::Max(gap, 0.0f) < field_2C) {
                        if (field_46 == 1) {
                            if (!p1 && !p2) func_00161B50_inl5(this);
                            hit = true;
                        } else if (!(0.5f <= field_10)) {
                            if (!p1 && !p2) func_00161B50_inl5(this);
                            hit = true;
                        }
                    }
                    if (hit) {
                        float side = DotProduct(d, rec->field_0.mRight);
                        if (!(side <= -lat) && side < lat && GtMath::Abs(d.Y()) < 2.0f && !(field_2C <= 10.0f)) {
                            D_0055EF70.InduceTrafficVehicleCrash(veh, D_0055EF70.field_7C[i].field_0, true);
                            break;
                        }
                    }
                }
            }
        }
    }
    // the next param in the lane: brake to its speed (state 3)
    if (field_44 != 0xFF && !(veh->field_174 & 4)) {
        CB3TrafficParam *next = func_00161B50_inl2(field_44);
        field_4 = (func_00161B50_inl3(field_44) - rec->field_0.mPos).GetLength() + (next->field_C - field_8);
        field_4 = GtMath::Max(field_4 - 2.5f, 0.0f);
        float d = field_4;
        if (d < field_14) {
            float t = GtMath::Max(GtMath::Max(next->field_2C * (d / field_14), 0.8f * d), 0.0f);
            if (!(field_2C <= t) && (field_10 < 0.0f || d < field_10)) {
                field_10 = d;
                field_46 = 3;
                field_18 = 0.15384616f * (t - field_2C);
            }
        }
    }
    // the vehicle ahead (lane change): drop it when out of reach
    if (field_40 != 0xFF && !(veh->field_174 & 4)) {
        veh = func_00161B50_inl1(field_40);
        if (D_0055D7F7.field_0 != 0) {
            CB3TrafficParam *op = veh->field_114;
            if (op == 0) {
                field_40 = 0xFF;
            } else {
                float d = (func_00161B50_inl3(op->field_49) - func_00161B50_inl3(field_49)).GetLength() + (op->field_C - field_8);
                if (d < 0.0f) d = 0.0f;
                if (op->field_4D == 3 || op->field_4D == 5) {
                    d -= 1.5f;
                } else if (op->field_4D == 4) {
                    d -= 3.5f;
                }
                if (!(d <= 15.0f)) field_40 = 0xFF;
            }
        } else {
            if (veh->field_5E != field_41) {
                float s = DotProduct(veh->field_30 - rec->field_0.mPos, rec->field_0.mRight);
                if (s < -3.5f || !(s <= 3.5f)) field_40 = 0xFF;
            }
            if (veh->field_17A & 1) field_40 = 0;
        }
    }
    // ... and brake to its speed (state 5); veh is the vehicle ahead here when the block above ran
    if (field_40 != 0xFF && !(veh->field_174 & 4)) {
        float d;
        if (D_0055D7F7.field_0 != 0) {
            CB3TrafficParam *op = veh->field_114;
            d = (func_00161B50_inl3(op->field_49) - func_00161B50_inl3(field_49)).GetLength() + (op->field_C - field_8);
            if (d < 0.0f) d = 0.0f;
            if (op->field_4D == 3 || op->field_4D == 5) {
                d -= 1.5f;
            } else if (op->field_4D == 4) {
                d -= 3.5f;
            }
        } else {
            d = (veh->field_30 - rec->field_0.mPos).GetLength() - 2.5f;
        }
        d = GtMath::Max(d, 0.0f);
        if (d < field_14) {
            float t = GtMath::Max(GtMath::Max(veh->field_C4 * (d / field_14), 0.8f * d), 0.0f);
            if (!(field_2C <= t) && (field_10 < 0.0f || d < field_10)) {
                field_10 = d;
                field_46 = 5;
                field_18 = 0.15384616f * (t - field_2C);
            }
        }
    }
    switch (field_46) {
    default:
    case 0:
    case 1:
        field_18 = 0.44704f * field_0 - field_2C;
        if (D_0055D7F7.field_0 == 0 && field_47 != 0xFF && field_38 != 0) {
            field_18 = field_18 + CalcFormationSpeedChange();
        }
        field_18 = GtMath::Min(GtMath::Max(field_18, -0.1f), 0.08f);
        break;
    case 2:
        field_18 = GtMath::Min(0.8f * field_10 - field_2C, 0.0f);
        break;
    case 3:
    case 5:
        break;
    case 4:
        field_18 = field_1C;
        break;
    case 6:
        field_18 = 0.15384616f * (0.55f * (0.44704f * field_0) - field_2C);
        break;
    case 7: {
        float target = 1.45f * (0.44704f * field_0);
        if (field_4B & 4) {
            field_18 = 0.2857143f * (target - field_2C);
        } else {
            field_18 = 0.15384616f * (target - field_2C);
        }
        break;
    }
    }
    field_2C = GtMath::Max(field_2C + field_18, 0.0f);
}
