// NONMATCHING: Update__17CB3VehiclePhysicsFf -- retail 613 / ours 606 instructions, 216 in changed runs
// draftAE C-first: 606/613, call sequence identical, op counts agree except one hoisted constant (0.98 kept in f23 by retail: lwc1/swc1 +1 saved FPR), lui 2 and a few branch forms; 22 mnemonic hunks (59). Left: frame 0x160 vs 0x2F0 (dead lane slots), the wheel level loop's dot-product body out of line, PlayCarAlarm call inline (retail out of line), range-test early-return branch shape
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (cfgmap, Ghidra as reading aid); every branch, call, store and constant accounted for; header APIs DotProduct/GetSquaredLength/SetX-Y-Z(lane)/operator*(lane,float)/SetGtV3d; CGtV3dPlus GtV3d/Plus/SetPlus(WAxisType) stand-ins (gap queued)

// Update__17CB3VehiclePhysicsFf -- draftAE (0x1CE470, 0x994) -- CB3VehiclePhysics::Update(float)
// Written from the retail asm (cfgmap, Ghidra as reading aid). Local names after Revenge's CB4VehiclePhysics::Update STABS
// (lrAirResistance, lnWheel, lbAllWheelsOff, lbAllWheelsOnGround, lb30HzCrash, lnNumSteps, lrLinearSpeed, lbLevelWithWorld,
// lrAbs) [L]; Revenge's body is smaller (0x7A8), so the mapping of each name to a B3 value is [G].
// [L] per frame: wheel ground/detach summary, air resistance, detaching hinged parts and wheels past their damage limits
// (CB3PhysicsManager::AddBodyPart + CB3BodyPartPhysics::Detach + CB3SoundCrashManager::DetachBodyPart), crash steering,
// then one or two physics sub-steps (two at half the step when the game runs a 30 Hz crash camera [G]): angular and linear
// damping while airborne / nearly stopped, a resting test (the car comes to rest -> wheel spin 0, car alarm, field_20E set),
// UpdateSuspension unless resting, CB3CollidingBody::Update; finally the hinged parts still attached are updated.
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [G] the grounded-wheel / body test range (retail lbu + bltz + slti 0x21: an int parameter tested 0..32)
static inline bool func_001CE470_inl1(int v, int lo, int hi) { if (v < lo) return false; if (v > hi) return false; return true; }
// [G] |a . b| above the threshold (the level-with-world test, three rows)
static inline bool func_001CE470_inl2(CGtV3d a, CGtV3d b) { return GtMath::Abs(DotProduct(a, b)) > 0.99f; }

class CB3VehiclePhysics;
struct UnkStruct_001CE470_cc4 {     // [G]
    unsigned char pad_0[0x4AC];
    signed char field_4AC[4];       // [G] per-wheel part state (2 damaged, 3 detached)
    unsigned char pad_4B0[0x2];
    signed char field_4B2[8];       // [G] per hinged part state (2 damaged, 3 detached)
    unsigned char pad_4BA[0x16];
    float field_4D0[4];             // [G] per-wheel damage amount
    unsigned char pad_4E0[0xF78 - 0x4E0];
    float field_F78[4];             // [G] per-wheel damage
    unsigned char pad_F88[0x8];
    float field_F90[8];             // [G] per hinged part damage
    unsigned char pad_FB0[0x10];
    float field_FC0[8];             // [G] per hinged part damage threshold
    unsigned char pad_FE0[0x10];
    CGtV4d field_FF0;               // [G] w read
};
struct UnkStruct_001CE470_cc0_40 { unsigned char pad_0[0xC]; signed char field_C; };   // [G] hinged part count
struct UnkStruct_001CE470_cc0 { unsigned char pad_0[0x40]; UnkStruct_001CE470_cc0_40 * field_40; };
struct UnkStruct_001CE470_wheel {   // [G] 0xC0 stride, base veh+0x820
    unsigned char pad_0[0x20];
    CGtV3d field_20;                // [G] wheel axis / normal
    unsigned char pad_30[0x2C];
    float field_5C;                 // [G] wheel spin rate
    unsigned char pad_60[0x50];
    unsigned char field_B0;
    unsigned char pad_B1[0x2];
    unsigned char field_B3;         // [G] on the ground
    unsigned char pad_B4[0xC];
};
struct UnkStruct_001CE470_part { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };   // [L] CB3BodyPartPhysics
struct UnkStruct_001CE470_cam { unsigned char pad_0[0x1B4]; void * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_001CE470_cam * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
class CB3PhysicsManager;
class CB3SoundCrashManager {
public:
    void PlayCarAlarm(CB3VehiclePhysics * p0);
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;   // [G] bool
extern UnkStruct_D_00522680 D_00522680;
extern unsigned char D_0051B714[];         // [G] two objects compared by address with D_0051BA88->field_1B4
extern unsigned char D_0051B788[];
extern signed char D_004E1700;              // [G] resting frame count (5)
extern CB3PhysicsManager D_0055EF70;
extern CB3SoundCrashManager D_01E78510;
// [C] names research/retail_names.csv: 0x1B86A0 CB3PhysicsManager::AddBodyPart(CB3VehiclePhysics*, int, EBodyPartType);
// 0x333990 CB3BodyPartPhysics::Detach(); 0x27D240 CB3SoundCrashManager::DetachBodyPart(CGtV3d, float, EVehicleFlyingBit)
// (the CGtV3d passed by address in retail: the queued by-value gap, so const& here [G]).
extern "C" UnkStruct_001CE470_part * func_001B86A0(CB3PhysicsManager *, CB3VehiclePhysics *, int, int);
extern "C" void func_00333990(UnkStruct_001CE470_part *);
extern "C" void func_0027D240(CB3SoundCrashManager *, const CGtV3d &, float, int);

class CB3CollidingBody {
public:
    void Update(float lrTimeStep);

    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;            // [G] linear velocity, w = speed
    CGtV3d field_C0;                // [G] velocity direction
    CGtV3d field_D0;                // [G] angular velocity
    CGtV3d field_E0;                // [G] angular momentum
    CGtV3d field_F0;                // [G] force accumulator
    unsigned char pad_100[0x70];
    CGtV3d field_170;               // [G] a body axis tested against the world matrix rows
    unsigned char pad_180[0x10];
    unsigned char field_190;
    unsigned char pad_191[0x73];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0x6];
    unsigned char field_20E;        // [G] at rest
    unsigned char pad_20F[0x2];
    unsigned char field_211;
    unsigned char field_212;
    unsigned char pad_213[0x2];
    signed char field_215;
    unsigned char pad_216[0xA];
};

class CB3VehiclePhysics : public CB3CollidingBody {
public:
    void Update(float lrTimeStep);
    void UpdateCrashSteering(float lrTimeStep);
    void UpdateSuspension(float lrTimeStep);
    void UpdateHingedPart(int lnPart, float lrTimeStep);

    unsigned char pad_220[0x820 - 0x220];
    UnkStruct_001CE470_wheel field_820[4];
    unsigned char pad_B20[0xCC0 - 0xB20];
    UnkStruct_001CE470_cc0 * field_CC0;
    UnkStruct_001CE470_cc4 * field_CC4;
    unsigned char pad_CC8[0x1168 - 0xCC8];
    unsigned char field_1168;       // [G] all wheels off the ground
    signed char field_1169;         // [G] wheel count
    unsigned char pad_116A;
    unsigned char field_116B;       // [G] crash steering active
    unsigned char pad_116C[0x1354 - 0x116C];
    signed char field_1354;         // [G] frames at rest
};

// [G] a wheel (or the body, field_212) touching within range
static inline bool func_001CE470_inl3(CB3VehiclePhysics * v)
{
    if (v->field_212 && func_001CE470_inl1(v->field_190, 0, 32)) {
        return true;
    }
    int i = v->field_1169;
    while (i-- != 0) {
        if (v->field_820[i].field_B3 && v->field_CC4->field_4AC[i] != 3 && func_001CE470_inl1(v->field_820[i].field_B0, 0, 32)) {
            return true;
        }
    }
    return false;
}

void CB3VehiclePhysics::Update(float lrTimeStep)
{
    bool lb30HzCrash = false;
    if (D_01E65499.field_0) {
        void * p = D_0051BA88.field_0->field_1B4;
        if (p != 0 && (p == D_0051B714 || p == D_0051B788)) {
            lb30HzCrash = true;
        }
    }

    bool lbAllWheelsOnGround = true;
    field_1168 = true;
    bool lbAllWheelsOff = true;
    for (int lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        if (field_CC4->field_4AC[lnWheel] != 3) {
            lbAllWheelsOff = false;
            if (field_820[lnWheel].field_B3) {
                field_1168 = false;
            } else {
                lbAllWheelsOnGround = false;
            }
        }
    }
    if (lbAllWheelsOff) {
        lbAllWheelsOnGround = false;
    }

    float lrLinearSpeed = field_B0.Plus();
    float lrAirResistance = -1.0f * (lrLinearSpeed * lrLinearSpeed);
    field_F0 += field_C0 * lrAirResistance;

    for (int lnIndex = 0; lnIndex < field_CC0->field_40->field_C; lnIndex++) {
        if (field_CC4->field_F90[lnIndex] > field_CC4->field_FC0[lnIndex] && (unsigned int)field_CC4->field_4B2[lnIndex] < 2) {
            field_CC4->field_4B2[lnIndex] = 2;
        }
        if (field_CC4->field_F90[lnIndex] > 999 && field_CC4->field_4B2[lnIndex] == 2) {
            field_CC4->field_4B2[lnIndex] = 3;
            UnkStruct_001CE470_part * lpPart = func_001B86A0(&D_0055EF70, this, lnIndex, 1);
            if (lpPart != 0) {
                func_00333990(lpPart);
                func_0027D240(&D_01E78510, lpPart->field_204->mPos, 100.0f, lnIndex);
            } else {
                field_CC4->field_4B2[lnIndex] = 2;
            }
        }
    }

    for (int lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        if (field_CC4->field_F78[lnWheel] > 0.3f && (unsigned int)field_CC4->field_4AC[lnWheel] < 2) {
            field_CC4->field_4AC[lnWheel] = 2;
        }
        if (field_CC4->field_F78[lnWheel] > 0.5f && field_CC4->field_4AC[lnWheel] == 2 && field_CC4->field_4D0[lnWheel] > 0.05f) {
            field_CC4->field_4AC[lnWheel] = 3;
            UnkStruct_001CE470_part * lpPart = func_001B86A0(&D_0055EF70, this, lnWheel, 0);
            if (lpPart != 0) {
                func_00333990(lpPart);
            } else {
                field_CC4->field_4AC[lnWheel] = 2;
            }
        }
    }

    if (field_116B) {
        if (field_CC4->field_4AC[0] == 0 && field_CC4->field_4AC[1] == 0 && lrLinearSpeed > 5.0f) {
            UpdateCrashSteering(lrTimeStep);
        } else {
            field_116B = false;
        }
    }

    int lnNumSteps;
    if (lb30HzCrash) {
        lnNumSteps = 2;
        lrTimeStep *= 0.5f;
    } else {
        lnNumSteps = 1;
    }
    while (lnNumSteps-- != 0) {
        if (field_211 == 0 && lbAllWheelsOnGround && lrLinearSpeed < 1.0f) {
            field_E0.SetY(field_E0.Y() * 0.95f);
            field_B0.SetGtV3d(field_B0.GtV3d() * 0.95f);
            field_B0.SetPlus(field_B0.Plus() * 0.95f);
        } else if (field_1168) {
            field_E0.SetX(field_E0.X() * 0.99f);
            field_E0.SetY(field_E0.Y() * 0.99f);
            field_E0.SetZ(field_E0.Z() * 0.97f);
        }
        if (lrLinearSpeed < 1.0f && (func_001CE470_inl3(this) || field_20E)) {
            field_E0 = field_E0 * 0.9f;
            field_B0.SetGtV3d(field_B0.GtV3d() * 0.95f);
            field_B0.SetPlus(field_B0.Plus() * 0.95f);
            field_1354++;
            bool lbLevelWithWorld = true;
            if (field_212) {
                CGtV3d lAxis = field_170;
                CGtMatrix3x4 * m = field_204;
                lbLevelWithWorld = func_001CE470_inl2(lAxis, m->mUp) || func_001CE470_inl2(lAxis, m->mAt) || func_001CE470_inl2(lAxis, m->mRight);
            } else {
                for (int lnWheel = 0; lnWheel < field_1169; lnWheel++) {
                    if (field_820[lnWheel].field_B3 && DotProduct(field_204->mUp, field_820[lnWheel].field_20) < 0.98f) {
                        lbLevelWithWorld = false;
                        break;
                    }
                }
            }
            if (lrLinearSpeed < 0.5f && field_D0.GetSquaredLength() < 0.25f && D_00522680.field_0 > field_CC4->field_FF0.W()
                && (lbLevelWithWorld || lbAllWheelsOnGround) && field_1354 > D_004E1700) {
                for (int lnWheel = 0; lnWheel < field_1169; lnWheel++) {
                    field_820[lnWheel].field_5C = 0.0f;
                }
                if (field_215 != 1) {
                    D_01E78510.PlayCarAlarm(this);
                }
                field_20E = true;
            }
        } else {
            field_20E = false;
            field_1354 = 0;
        }
        if (!field_20E) {
            UpdateSuspension(lrTimeStep);
        }
        CB3CollidingBody::Update(lrTimeStep);
    }
    if (lb30HzCrash) {
        lrTimeStep *= 2.0f;
    }
    for (int lnPart = 0; lnPart < field_CC0->field_40->field_C; lnPart++) {
        if (field_CC4->field_4B2[lnPart] == 2) {
            UpdateHingedPart(lnPart, lrTimeStep);
        }
    }
}
