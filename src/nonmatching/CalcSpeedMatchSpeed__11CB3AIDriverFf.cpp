// NONMATCHING: CalcSpeedMatchSpeed__11CB3AIDriverFf -- retail 329 / ours 329 instructions, 20 in changed runs
// near21: 20 changed (was 22). The target's W read moved into its own static inline (func_00144180_inl2) and the final return uses inl1: all three W() lane-read slots now at retail's 0x80/0x70/0x60. Left: prologue scheduling only -- address arithmetic register naming for the two element reads, and retail puts the target's lwc1 f20 in the CalcSeparationAlongTrack jal delay slot (ours before the jal)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3AIDriver::CalcSpeedMatchSpeed(float) -- hand-written (L265; lifter draft restructured).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Callees: func_0014DD80 = CB3Burn::GetCurrentBurnDuration(const CB3RaceCar*) [L] (E map note in
// config/symbol_addrs_b3names.txt), func_001D17B0 = CB3AICarPhysics::IgnoreInRaceBrake(float) [L] (same).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

class CB3RaceCar;
struct UnkStruct_00144180_phys {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};
struct UnkStruct_00144180_e0 {
    UnkStruct_00144180_phys * field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_00144180_e1 {
    unsigned char pad_0[0x2C];
    UnkStruct_00144180_phys * field_2C;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C960];
    UnkStruct_00144180_e1 field_3C960[1];  // [G] element count unknown
};
struct UnkStruct_00144180_burn {
    unsigned char pad_0[0x1];
};
struct UnkStruct_00144180_contact {
    unsigned char pad_0[0x1914];
    int field_1914;
};
class CB3Score {
public:
    UnkStruct_00144180_contact * GetLastContactCar(float);
    float GetTotalRaceAmount();
    float GetTotalRaceDistFromAILaneStart();
    unsigned char pad_0[0xCC];
    UnkStruct_00144180_burn field_CC;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_118D[0x51];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x1A5];
    int field_1384;
    unsigned char pad_1388[0x624];
    signed char field_19AC;
    unsigned char pad_19AD[0xA83];
    void * field_2430;
    unsigned char pad_2434[0xC];
    int field_2440;
};
class CB3AICar : public CB3RaceCar {
public:
    float CalcSeparationAlongTrack(CB3RaceCar *);
};
class CB3AIDriver {
public:
    float CalcSpeedMatchSpeed(float p0);

    unsigned char pad_0[0x790];
    int field_790;
    CB3RaceCar * field_794;
    unsigned char pad_798[0x8];
    CB3AICar * field_7A0;
    unsigned char pad_7A4[0x234];
    float field_9D8;
    unsigned char pad_9DC[0x4];
    float field_9E0;
    unsigned char pad_9E4[0x33];
    unsigned char field_A17;
    unsigned char field_A18;
    unsigned char field_A19;
    unsigned char pad_A1A[0x2];
    CB3RaceCar * field_A1C;
    float field_A20;
    float field_A24;
    float field_A28;
    float field_A2C;
    unsigned char field_A30;
};
struct UnkStruct_D_float16 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_0064D344 {
    void * field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_00144180_e0 D_0055EFEC[];
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D344 D_0064D344;
extern UnkStruct_D_float16 D_01E754EC;
extern UnkStruct_D_float16 D_01E754F0;
extern UnkStruct_D_float16 D_01E75598;
extern UnkStruct_D_float16 D_01E755BC;
extern UnkStruct_D_float16 D_01E755C0;
extern UnkStruct_D_float16 D_01E755C4;
extern UnkStruct_D_float16 D_00522680;

extern "C" float func_0014DD80(UnkStruct_00144180_burn *, const CB3RaceCar *);
extern "C" void func_001D17B0(void *, float);
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

static inline float func_00144180_inl1(CB3RaceCar * c)
{
    return D_0055EFEC[c->field_19AC].field_0->field_B0.W();
}

static inline float func_00144180_inl2(CB3RaceCar * c)
{
    return (*(UnkStruct_00144180_phys **)((char *)&D_00522660 + 0x3C98C + c->field_19AC * 0x30))->field_B0.W();
}
// 0x00144180
float CB3AIDriver::CalcSpeedMatchSpeed(float p0)
{
    if (field_790 == 0) {
        field_A1C = 0;
        return p0;
    }
    CB3AICar * car = field_7A0;
    CB3RaceCar * tgt = field_794;
    float myW = func_00144180_inl1(car);
    float tgW = func_00144180_inl2(tgt);
    float sep = car->CalcSeparationAlongTrack(tgt);
    bool ahead = sep > 0.0f;
    float z = 0.0f;
    float k = tgW * GtMath::Min(GtMath::Max(sep / 100.0f, -1.0f), 1.0f);
    float mx = GtMath::Max(D_01E754F0.field_0, tgW + k);
    int s = field_790;
    if (s == 5) {
        field_9D8 = GtMath::Min(GtMath::Max(mx, myW - 1.0f), myW + 1.0f);
        field_A1C = 0;
        CB3RaceCar * t = field_794;
        bool f = false;
        if (t->field_11DE != 0) goto burn;
    st:
        field_A17 = f;
        field_A18 = f;
        return field_9D8;
    burn:
        if (func_0014DD80(&t->field_10C0.field_CC, t) > 1.5f) {
            f = true;
        }
        goto st;
    }
    if (s == 4) {
        bool b = true;
        UnkStruct_00144180_contact * lc = field_7A0->field_10C0.GetLastContactCar(1.0f);
        if (lc != 0 && lc->field_1914 == 0) {
            b = false;
        }
        if (0.0f == field_794->field_10C0.GetTotalRaceAmount()) {
            if (field_7A0->field_1384 > 0 && D_0064D344.field_0 != 0) {
                b = false;
            }
        }
        float res = p0;
        if (field_7A0->field_2440 != 1) {
            float d0 = field_7A0->field_10C0.GetTotalRaceDistFromAILaneStart();
            float d1 = field_794->field_10C0.GetTotalRaceDistFromAILaneStart();
            float diff = d1 - d0;
            if (field_A1C == field_794) {
                float ga = tgW;
                ga += 5.0f;
                ga = ga + d1;
                float gb = myW + z;
                gb = gb + d0;
                float gap = ga - gb;
                if (b && !(diff <= -z)) {
                    res = D_01E754EC.field_0;
                    field_A17 = 1;
                } else {
                    if (diff < 10.0f && !(gap <= 10.0f) && !(myW - tgW <= 13.4112f)) {
                        field_A17 = 1;
                    }
                    res = GtMath::Max(tgW, myW + gap);
                    if (!(fabsf(diff) <= D_01E75598.field_0)) {
                        if (diff > 0.0f) {
                            res = res * 2.0f;
                        } else {
                            res = GtMath::Max(res * D_01E755BC.field_0, p0 - 20.0f);
                        }
                    }
                }
            } else {
                field_A30 = ahead;
            }
            field_A1C = field_794;
            field_A20 = myW;
            field_A24 = tgW;
        } else {
            res = mx;
            if (field_A1C == field_794) {
                if (field_A30 != 0) {
                    float th = 0.0f + D_01E755C0.field_0 + field_9E0 * D_01E755C4.field_0;
                    if (b && !(sep <= th)) {
                        res = D_01E754EC.field_0;
                        field_A17 = 1;
                    }
                }
            } else {
                field_A30 = ahead && sep > 10.0f;
                field_A1C = field_794;
            }
        }
        if (field_A17 != 0 && -1.0f == field_A2C) {
            float t = D_00522680.field_0;
            if (!(t <= field_A28)) {
                field_A2C = 2.0f + t;
                field_A28 = 2.0f + field_A2C;
            }
        }
        if (field_A19 != 0 && field_A17 == 0) {
            func_001D17B0(field_7A0->field_2430, 1.0f);
        }
        return res;
    }
    field_A1C = 0;
    int m = field_790;
    if (m == 3 || (!ahead && m == 2) || (ahead && m == 1)) {
        return func_00144180_inl1(field_794);
    }
    return p0;
}
