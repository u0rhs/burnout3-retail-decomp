// NONMATCHING: GetRacingDrivingControls__15CB3AICarPhysicsFv -- retail 510 / ours 524 instructions, 361 in changed runs
// fix3 (2026-11-01): constants from retail gp literals: speed-gap test -13.4112 (was 0.5) x2, burn-out flag 8.9408 (was 2) x2, ramp test 13.4112 (was 3), 2.23693633 (bits 0x400F29F7); dot clamp [-1,1] (was [0,1], retail vsubw.x 0-1) | Before: son9 first archive (337 changed, 532 vs 510 instrs): first ~0x490 bytes exact. Left: lq/sq speed-copy temps (7 slots, frame 0xD0/0x110 vs 0x170; union pun slot at 0x16C), VU dot/clamp is scalar DotProduct+Max/Min (retail vmax/vminiw), s-reg assignment (done/near/burning), tail block order. gp .lit4 vs sdata for D_004E.. consts unverified (used literals)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix3: reviewed end to end against retail asm (every branch, store, constant)


// CB3AICarPhysics::GetRacingDrivingControls() -- son9 first archive. Layout [G] from instruction widths.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

extern float D_0052267C;
extern float D_00522680;
extern float D_01E754FC;
extern float D_01E75500;

class CB3AICarPhysics;

struct UnkStruct_001D17D0_car {
    unsigned char pad_0[0x118C];
    unsigned char field_118C;
    unsigned char pad_118D[0x51];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x71D];
    float field_18FC;
    unsigned char pad_1900[0x878];
    unsigned char field_2178;
    unsigned char field_2179;
    unsigned char pad_217A[0x6];
    int field_2180;
    unsigned char pad_2184[0x22C];
    float field_23B0;
    float field_23B4;
    unsigned char pad_23B8[0x30];
    int field_23E8;
    unsigned char pad_23EC[0x17];
    unsigned char field_2403;
    unsigned char field_2404;
    unsigned char field_2405;
    unsigned char pad_2406[0x3];
    unsigned char field_2409;
};

struct UnkStruct_001D17D0_car2 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_001D17D0_phys {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0;
    unsigned char pad_10C1[0x27B];
    int field_133C;
    unsigned char pad_1340[0x590];
    CGtV4d field_18D0;
};

struct UnkStruct_001D17D0_xf {
    CGtV4d field_0;
};

class CB3AICarPhysics {
public:
    void GetRacingDrivingControls();
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_001D17D0_xf * field_204; // [C] single indirection: retail lw a0, 0x204(s3) then lqc2 vf2, 0(a0) (before 0x1D1914)
    unsigned char pad_208[0x11DC];
    float field_13E4;
    unsigned char pad_13E8[0xC];
    UnkStruct_001D17D0_phys * field_13F4;
    unsigned char pad_13F8[0x4];
    unsigned char field_13FC;
    unsigned char pad_13FD[0x3];
    float field_1400;
    float field_1404;
    float field_1408;
    unsigned char pad_140C[0x8];
    float field_1414;
    unsigned char pad_1418[0x58];
    float field_1470;
    unsigned char pad_1474[0x28];
    float field_149C;
    float field_14A0;
    int field_14A4;
    unsigned char pad_14A8[0x20];
    int field_14C8;
    unsigned char pad_14CC[0x58];
    int field_1524;
    unsigned char pad_1528[0xC];
    float field_1534;
    unsigned char pad_1538[0x1A];
    unsigned char field_1552;
    unsigned char pad_1553[0x15];
    UnkStruct_001D17D0_car * field_1568;
    float field_156C;
    unsigned char pad_1570[0x4];
    float field_1574;
    float field_1578;
    float field_157C;
};

extern "C" void func_001D28C0(CB3AICarPhysics *, float);
extern "C" bool WasSlammedWithinTime__8CB3ScoreFf(void *, float);
extern "C" UnkStruct_001D17D0_car2 * GetLastContactCar__8CB3ScoreFf(void *, float);
extern "C" void StartBurn__7CB3BurnFP17CB3RaceCarPhysics(void *, void *);
extern "C" void StopBurn__7CB3BurnFv(void *);

static inline float func_001D17D0_inl1(CB3AICarPhysics * s) { CGtV4d t = s->field_B0; return t.f[3]; }

// 0x001D17D0
void CB3AICarPhysics::GetRacingDrivingControls()
{
    bool burning = false;
    UnkStruct_001D17D0_car * c = field_1568;
    bool done = false;
    if (c->field_2180 != 0 && c->field_2179 != 0) burning = true;
    bool near = !(9.549296f * field_149C < field_1470);
    float neg = -1.0f;
    if (field_157C != -1.0f) {
        field_157C = field_157C - D_0052267C;
        if (field_157C <= 0.0f) {
            field_157C = 0.0f;
            if (func_001D17D0_inl1(this) < 0.1f) {
                field_157C = neg;
                field_14C8 = 1;
                field_14A4 = 1;
                field_14A0 = 0.35f;
                field_1414 = 0.0f;
                field_1400 = 0.0f;
                field_1404 = 0.0f;
                return;
            }
            func_001D28C0(this, 1.0f);
            field_1552 = 1;
            return;
        }
        field_1414 = 0.0f;
        field_1400 = 0.0f;
        field_1404 = 1.0f;
        float dp = DotProduct(CGtV3d(field_204->field_0.mData), CGtV3d(field_13F4->field_18D0.mData));
        dp = GtMath::Max(dp, -1.0f);   // fix3 [C] retail 0x1D1914: vsubw.x vf2 = 0 - 1, vmax.x: clamp to [-1, 1]
        if (dp > 1.0f) dp = 1.0f;
        if (dp < -0.1f) {
            field_1408 = neg;
        } else {
            if (dp > 0.1f) {
                field_1408 = 1.0f;
                return;
            }
            field_1408 = 0.0f;
        }
        return;
    }
    if (c->field_18FC >= 0.5f || c->field_23B4 <= 0.0f || 2.2369363f * func_001D17D0_inl1(this) >= 5.0f) {
        field_1578 = neg;
    } else if (field_1578 == -1.0f) {
        field_1578 = 1.0f;
    } else {
        field_1578 = field_1578 - D_0052267C;
        if (field_1578 <= 0.0f) {
            field_1578 = neg;
            field_157C = 2.0f;
            field_14C8 = -1;
            field_14A4 = 1;
            field_14A0 = 0.35f;
            field_1414 = 0.0f;
            field_1400 = 0.0f;
            field_1404 = 0.0f;
            field_1408 = 0.0f;
            return;
        }
    }
    c = field_1568;
    float steer;
    if (c->field_2178 == 0 || (c->field_2403 == 0 && c->field_2404 == 0)) {
        steer = -c->field_23B0 * D_01E754FC / 180.0f;
    } else {
        steer = -c->field_23B0 * D_01E75500 / 180.0f;
    }
    float one = 1.0f;
    steer = GtMath::Min(GtMath::Max(steer, -1.0f), one);
    if (c->field_23E8 != 2) {
        UnkStruct_001D17D0_car2 * o;
        if (WasSlammedWithinTime__8CB3ScoreFf(&field_13F4->field_10C0, field_13E4)
            && (o = GetLastContactCar__8CB3ScoreFf(&field_13F4->field_10C0, field_13E4)) != 0
            && o->field_1914 == 0) {
            field_1534 = 0.05f;
            int k = field_1568->field_23E8;
            if (k == 1) {
                steer = field_1408;
            } else if (k == 0) {
                if (WasSlammedWithinTime__8CB3ScoreFf(&field_13F4->field_10C0, field_13E4 * 0.5f)) {
                    steer = field_1408;
                } else {
                    union { float f; unsigned int u; } cv;
                    cv.f = steer;
                    cv.u = (cv.u & 0x80000000) | 0x3F800000;
                    steer = -cv.f;
                }
            }
        }
        } else {
        if (WasSlammedWithinTime__8CB3ScoreFf(&field_13F4->field_10C0, field_13E4)) {
            UnkStruct_001D17D0_car2 * o = GetLastContactCar__8CB3ScoreFf(&field_13F4->field_10C0, field_13E4);
            if (o != 0 && o->field_1914 == 0) field_1534 = 0.1f;
        }
    }
    field_1408 = steer;
    c = field_1568;
    if (c->field_2178 == 0) {
        if ((unsigned)(field_1524 - 1) > 1) field_1524 = 4;
        if (field_1568->field_23B4 - func_001D17D0_inl1(this) <= one) {
            if (burning || field_1568->field_23B4 - func_001D17D0_inl1(this) >= -13.4112f) {   // fix3 [C] retail D_004E0DA4 = 0xC1569446
                if (!near) {
                    field_1414 = 0.0f; field_1400 = 0.0f; field_1404 = 0.0f;
                } else {
                    field_1414 = one; field_1400 = one; field_1404 = 0.0f;
                }
            } else {
                func_001D28C0(this, one);
                done = true;
                if (field_1568->field_23B4 < 8.9408f) field_1552 = 1;   // fix3 [C] retail D_004E0DA8 = 0x410F0D84
            }
        } else {
            field_1414 = one;
            if (field_13F4->field_133C != 0) { field_1400 = one; field_1404 = 0.0f; }
        }
    } else {
        if (c->field_2403 != 0) {
            if (c->field_2405 != 0) { field_1524 = 2; field_1408 = one; }
        } else {
            if (c->field_2404 != 0 && c->field_2405 != 0) { field_1524 = 1; field_1408 = neg; }
        }
        if (field_1568->field_23B4 - func_001D17D0_inl1(this) <= one) {
            if (field_1568->field_23B4 - func_001D17D0_inl1(this) >= -13.4112f) {   // fix3 [C] retail D_004E0DA4 = 0xC1569446
                if (!near) {
                    field_1414 = 0.0f; field_1400 = 0.0f; field_1404 = 0.0f;
                } else {
                    field_1414 = one; field_1400 = one; field_1404 = 0.0f;
                }
            } else {
                func_001D28C0(this, one);
                done = true;
                if (field_1568->field_23B4 < 8.9408f) field_1552 = 1;   // fix3 [C] retail D_004E0DA8 = 0x410F0D84
            }
        } else {
            field_1414 = one; field_1400 = one; field_1404 = 0.0f;
        }
    }
    if (!done) {
        float t;
        if (field_1574 > D_00522680) t = 1.0f - (field_1574 - D_00522680) / 2.0f;
        else t = one;
        if (field_1400 != field_156C) {
            if (field_1400 != 1.0f || func_001D17D0_inl1(this) >= 13.4112f)   // fix3 [C] retail D_004E0DAC = 0x41569446
                field_1574 = t * 2.0f + D_00522680 + 0.0f;
            else field_1574 = neg;
            t = 1.0f - t;
        }
        field_156C = field_1400;
        if (field_1400 == one) {
            field_1400 = t; field_1414 = t;
        } else {
            field_1400 = 1.0f - t; field_1414 = 1.0f - t;
        }
    }
    if (done || field_1568->field_2409 == 0 || field_14C8 < 1) {
        if (field_1568->field_11DE != 0) StopBurn__7CB3BurnFv(&field_1568->field_118C);
    } else if (field_1568->field_11DE == 0) {
        StartBurn__7CB3BurnFP17CB3RaceCarPhysics(&field_1568->field_118C, this);
    }
    if (field_1568->field_11DE == 0) {
        field_13FC = 0;
    } else {
        field_13FC = 4;
        field_1404 = 0.0f;
    }
}
