// NONMATCHING: GetDrivingControls__17CB3RaceCarPhysicsFv -- retail 776 / ours 775 instructions, 104 in changed runs
// draftAK C-first: slam/trade-paint steer limits, pre-race launch/boost-start, gear buttons, steer rate limit, transmission call (two call sites, max(9FC,ABC) as f13), drift state; 775/776, calls identical; left: frame 0x130 vs 0x160 (speed W temps), the top-gear bool inline folds to bne, block order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid; it drops f13 of the first func_001C6F90 call); every branch sense, store and call argument traced; NaN-exact compare senses where retail uses !(a<=b)

// CB3RaceCarPhysics::GetDrivingControls() -- draftAK (C-first draft). 0x1C0F00, 0xC20.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid; it lost
// f13 of the first func_001C6F90 call and shows 0x1388 as 5000). What it does [L]: the player car's per-frame control
// filter: the steer/throttle limits after a slam or trade-paint (field_137C/1384/13C0 from the attribs at field_13F8 or
// the slam overrides at 13E8/13EC/13F0), the boost-start / launch logic before the race (attribs+0x178C != 1), manual
// gear shift buttons (field_13FC bits 0/1), steering rate limiting (field_1388 per frame), the transmission update
// (func_001C6F90 on the object at +0x1448, result field_1520) and the brake/handbrake drift state (field_1524).
// Revenge member names ([L], research/names/class_layouts.tsv) are in comments only.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
using namespace GtMath;

extern float D_0052267C;   // [L] frame time
extern float D_00522680;   // [L] game time

class CB3Score {
public:
    bool WasSlammedWithinTime(float);
    bool WasTradingPaintWithinTime(float);
    void HandleBoostStart();
};

struct UnkStruct_001C0F00_attr {            // field_13F4 ([L] Revenge mpAttribs)
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;                    // [C] the score object passed to WasSlammedWithinTime etc.
    unsigned char pad_10C1[0xB];
    float field_10CC;                       // [G] a time
    unsigned char pad_10D0[0x26C];
    int field_133C;                         // [G] race mode (3 = no auto drift)
    float field_1340;                       // [G] race start time
    unsigned char pad_1344[0x244];
    float field_1588;                       // [G] slam recovery time
    unsigned char pad_158C[0xF4];
    float field_1680;                       // [G] trade-paint recovery time
    unsigned char pad_1684[0x108];
    int field_178C;                         // [G] race state (1 = racing, 0 = pre-start)
};

struct UnkStruct_001C0F00_lim {             // field_13F8 ([G] handling attribs)
    unsigned char pad_0[0x14C];
    float field_14C;
    unsigned char pad_150[0x4];
    float field_154;
    unsigned char pad_158[0x38];
    float field_190;
};

struct UnkStruct_001C0F00_trans {           // +0x1448 ([L] Revenge mTransmission, CB4Transmission)
    unsigned char pad_0[0x4];
};

class CB3RaceCarPhysics {
public:
    void GetDrivingControls();

    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;                    // [L] Revenge mLinearVelocityAndSpeed (w = speed)
    CGtV3d field_C0;                        // [G] angular velocity
    unsigned char pad_D0[0x134];
    CGtMatrix3x4 *field_204;                // [L] Revenge mpMatrix
    unsigned char pad_208[0xA];
    unsigned char field_212;                // [G] world collision this frame
    unsigned char pad_213[0x2];
    signed char field_215;                  // [G] car state (3 = AI / replay controlled)
    unsigned char pad_216[0x7E6];
    float field_9FC;
    unsigned char pad_A00[0xBC];
    float field_ABC;
    unsigned char pad_AC0[0x6A4];
    float field_1164;                       // [G] steering output
    unsigned char pad_1168[0x210];
    float field_1378;                       // [G] steer limit floor
    float field_137C;                       // [G] steer limit
    float field_1380;
    float field_1384;
    float field_1388;                       // [G] max steer change per frame
    unsigned char pad_138C[0x4];
    float field_1390;
    float field_1394;
    unsigned char pad_1398[0x8];
    float field_13A0;
    unsigned char pad_13A4[0x1C];
    float field_13C0;
    float field_13C4;
    float field_13C8;
    unsigned char pad_13CC[0x4];
    float field_13D0;
    float field_13D4;
    unsigned char pad_13D8[0x8];
    float field_13E0;                       // [G] trade-paint window
    float field_13E4;                       // [G] slam window
    float field_13E8;
    float field_13EC;
    float field_13F0;
    UnkStruct_001C0F00_attr *field_13F4;    // [L] Revenge mpAttribs
    UnkStruct_001C0F00_lim *field_13F8;
    unsigned char field_13FC;               // [G] buttons (1 gear up, 2 gear down, 4 boost)
    unsigned char pad_13FD[0x3];
    float field_1400;                       // [G] throttle
    float field_1404;                       // [G] brake
    float field_1408;                       // [G] steer
    unsigned char pad_140C[0x8];
    float field_1414;
    unsigned char pad_1418[0x4];
    float field_141C;
    float field_1420;
    float field_1424;
    unsigned char pad_1428[0x4];
    float field_142C;
    float field_1430;
    unsigned char pad_1434[0x4];
    float field_1438;
    unsigned char pad_143C[0x4];
    float field_1440;
    unsigned char field_1444;               // [L] Revenge mControlStuff.mu8BoostingState
    unsigned char pad_1445;
    unsigned char field_1446;               // [L] Revenge mControlStuff.mbBoostStart
    unsigned char pad_1447;
    UnkStruct_001C0F00_trans field_1448;    // [L] Revenge mTransmission
    unsigned char pad_144C[0x54];
    float field_14A0;
    int field_14A4;
    int field_14A8;                         // [L] Revenge mDrivingControls.mbSiren (B3 meaning unknown)
    unsigned char pad_14AC[0xC];
    int field_14B8;                         // [G] manual gears
    unsigned char pad_14BC[0x4];
    int field_14C0;                         // [G] gear-up button latch
    int field_14C4;                         // [G] gear-down button latch
    int field_14C8;                         // [G] gear (-1 reverse)
    int field_14CC;                         // [G] top gear
    unsigned char pad_14D0[0x50];
    float field_1520;                       // [G] transmission output
    int field_1524;                         // [G] drift state (1, 2; 3 = world collision)
    unsigned char field_1528;
    unsigned char field_1529;
    unsigned char field_152A;
    unsigned char field_152B;
    unsigned char pad_152C[0x10];
    unsigned char field_153C;               // [L] Revenge mbAIAfterTouchRight
};

// [C] a0 = the object at +0x1448, f12 = throttle - brake, f13 = max(field_9FC, field_ABC), a1 = field_13FC & 4 (not
// converted to bool), a2 = (attribs->field_178C == 0); returns a float (f0). Float/int parameter interleaving unknown.
extern "C" float func_001C6F90(UnkStruct_001C0F00_trans *, float, float, int, bool);

// [G] retail tests the gear against the top gear through a materialised bool (xor/sltiu/beqz): an inline.
static inline bool func_001C0F00_inl1(const CB3RaceCarPhysics *p) { return p->field_14C8 == p->field_14CC; }


void CB3RaceCarPhysics::GetDrivingControls()
{
    float slamTime = field_13E4;
    float paintTime = field_13E0;
    float steerLimit = field_13E8;
    bool slammed = false;                   // s1
    bool second = false;                    // s2
    bool paint = false;                     // s0
    bool drift = false;                     // s3
    float speed = field_B0.Plus();
    float speedMph = field_B0.Plus() * 2.2374146f;   // [C] 0x400F31CD

    if (field_215 == 3) {
        field_137C = field_13F8->field_14C;
        field_1384 = field_13F8->field_154;
        field_13C0 = field_13F8->field_190;
    } else {
        slammed = field_13F4->field_10C0.WasSlammedWithinTime(slamTime);
        if (!slammed) {
            slamTime = slamTime * 0.6f;
            paintTime = paintTime * 0.6f;
            slammed = field_13F4->field_10C0.WasTradingPaintWithinTime(slamTime);
            if (slammed) {
                paint = true;
                steerLimit = steerLimit * 0.8f;
            }
        }
        if (field_212 == 0) {
            if (!paint)
                second = field_13F4->field_10C0.WasSlammedWithinTime(paintTime);
            else
                second = field_13F4->field_10C0.WasTradingPaintWithinTime(paintTime);
        }
        if (slammed && field_212 == 0) {
            if (second) {
                field_137C = field_13E8;
            } else {
                float t;
                if (!paint)
                    t = 1.0f - (field_13F4->field_10CC - (field_13F4->field_1588 + paintTime)) / (slamTime - paintTime);
                else
                    t = 1.0f - (field_13F4->field_10CC - (field_13F4->field_1680 + paintTime)) / (slamTime - paintTime);
                float base = field_13F8->field_14C;
                field_137C = 0.0f + base + t * (steerLimit - base);
            }
            field_1384 = field_13EC;
            field_13C0 = field_13F0;
        } else {
            field_137C = field_13F8->field_14C;
            field_1384 = field_13F8->field_154;
            field_13C0 = field_13F8->field_190;
        }
    }

    if (field_13F4->field_178C == 1) {
        if (field_1446 != 0) {
            field_1404 = 0.0f;
            field_1400 = 1.0f;
            field_1414 = 1.0f;
            float since = D_00522680 - field_13F4->field_1340;
            if (field_215 != 3 && since > 3.0f)
                field_1446 = 0;
        }
        int gear = field_14C8;
        if (gear < 2 && field_14A4 == 0) {
            float d = DotProduct(field_B0.GtV3d(), field_204->mAt);   // [G] forward velocity
            if (gear != -1 && field_1404 > field_1400 && field_1404 > 0.1f && d < 0.5f && field_1446 == 0) {
                field_14C8 = -1;
                field_14A4 = 1;
                field_14A0 = 0.35f;
            } else if (gear != 1 && field_1400 > field_1404 && field_1400 > 0.1f && d > -10.5f) {
                field_14C8 = 1;
                field_14A4 = 1;
                field_14A0 = 0.35f;
            } else if (gear == 0 && field_B0.Plus() > 0.1f) {
                field_1404 = 1.0f;
            }
        }
        if (field_14B8 != 0) {
            if (field_13FC & 1) {
                if (field_14C0 == 0) {
                    int g = field_14C8;
                    if (g >= 0 && g < field_14CC) {
                        field_14C8 = g + 1;
                        field_14A4 = 1;
                        field_14A0 = 0.35f;
                    }
                    field_14C0 = 1;
                }
            } else {
                field_14C0 = 0;
            }
            if (field_13FC & 2) {
                if (field_14C4 == 0) {
                    if (field_14C8 >= 2) {
                        field_14C8 = field_14C8 - 1;
                        field_14A4 = 1;
                        field_14A0 = 0.35f;
                    }
                    field_14C4 = 1;
                }
            } else {
                field_14C4 = 0;
            }
        }
    } else if (field_215 != 3) {
        float left = field_13F4->field_1340 - D_00522680;   // [G] time to the start
        if (field_1404 > 0.5f)
            field_1528 = 1;
        if (field_1528 != 0 && field_1400 < 0.5f && !(field_141C <= field_1400))
            field_1528 = 0;
        if (left <= 1.0f && !(left < 0.5f)) {
            if (field_1528 == 0)
                field_152A = 0;
            else if (field_1529 == 0)
                field_152A = 0;
            else
                field_152A = 1;
        }
        if (left < 0.5f) {
            if (field_152A != 0 && field_152B == 0) {
                if (field_1400 < 0.2f)
                    field_152B = 1;
            } else if (field_152A != 0 && field_152B != 0 && field_1400 > 0.8f) {
                if (field_1446 == 0)
                    field_13F4->field_10C0.HandleBoostStart();
                field_1446 = 1;
            }
        }
        if (field_1528 != 0)
            field_14C8 = 1;
        else
            field_14C8 = 0;
        field_B0.Zero();
        field_14A8 = 1;
    }

    if (field_14C8 < 0) {
        float t = field_1404;
        field_1404 = field_1400;
        field_1400 = t;
    }

    float lim = 0.0f + field_1384 - 1.4f * (speed - field_1380);
    if (lim < field_1378)
        lim = field_1378;
    if (lim > field_137C)
        lim = field_137C;

    float prev = field_1424;
    if (field_1408 > prev) {
        if (field_1408 - prev > field_1388)
            field_1408 = prev + field_1388;
    } else {
        if (field_1408 - prev < -field_1388)
            field_1408 = prev - field_1388;
    }
    if (slammed && second) {
        if (field_153C != 0)
            field_1408 = 1.0f;
        else
            field_1408 = -1.0f;
    }
    field_1164 = -lim * field_1408;

    if (field_9FC > field_ABC)
        field_1520 = func_001C6F90(&field_1448, field_1400 - field_1404, field_9FC, field_13FC & 4, field_13F4->field_178C == 0);
    else
        field_1520 = func_001C6F90(&field_1448, field_1400 - field_1404, field_ABC, field_13FC & 4, field_13F4->field_178C == 0);

    if (field_13FC & 4)
        field_1444 = 1;
    else
        field_1444 = 0;
    if (field_1444 != 0 && field_1520 < 0.0f && func_001C0F00_inl1(this) && speed < 0.44704f * field_13D4)
        field_1520 = field_1520 * -0.5f;
    if (speed > 0.44704f * field_13D4)
        field_1520 = 0.0f;
    field_14A8 = 0;

    float a = field_13C4;
    float m = (field_13C8 - 1.0f) / (130.0f - a);
    float g = Max(0.1f, 0.0f + 1.0f - a * m + m * speedMph);
    if (field_13F4->field_133C != 3) {
        if (field_1404 > g)
            drift = true;
        else if (field_1400 > 0.2f && field_1404 > 0.2f)
            drift = true;
    }

    if ((unsigned int)(field_1524 - 1) < 2) {
        float d = DotProduct(field_C0, field_204->mRight);   // [G] yaw rate about the car's right axis? (as retail: row 0)
        field_1440 = 1.0f - Abs(d) / field_13D0;
        field_1440 = field_1440 * (field_1390 - field_1394);
        field_1440 = field_1440 + field_1394;
        field_1440 = field_1440 + field_1404;
        if (field_1414 > 0.5f)
            field_1440 = field_1440 - (field_1414 - 0.5f);
        if (field_1440 < field_1394)
            field_1440 = field_1394;
        if (field_1440 > field_1390)
            field_1440 = field_1390;
        field_1440 = 0.0f + field_1430 + (field_1440 - field_1430) * D_0052267C;
    } else {
        field_1440 = 0.0f + field_1430 + (field_1390 - field_1430) * D_0052267C;
    }

    if (field_1524 == 0) {
        if (Abs(field_1408) <= 0.9f || field_1400 <= 30.0f / speed)
            field_1438 = 0.0f;
        else
            field_1438 = field_1438 + D_0052267C;
        float thr = field_13A0 + ((1.5f - field_1400) - (speed - 43.0f) / 25.0f);
        if (thr < 0.2f)
            thr = 0.2f;
        bool slide = speed > 43.0f;
        if (slide) slide = field_1438 > thr;
        if (drift || slide) {
            if (field_1408 > 0.1f) {
                field_1524 = 2;
                field_142C = 0.0f;
                field_1430 = field_1390;
            } else if (field_1408 < -0.1f) {
                field_1524 = 1;
                field_142C = 0.0f;
                field_1430 = field_1390;
            }
        }
    } else {
        field_1438 = 0.0f;
        field_142C = field_142C + D_0052267C;
    }

    if (field_14C8 == 0)
        field_141C = 0.0f;
    else
        field_141C = field_1400;
    field_1420 = field_1404;
    field_1424 = field_1408;
    field_1430 = field_1440;
}
