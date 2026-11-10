// NONMATCHING: func_00144E70 -- retail 147 / ours 144 instructions, 17 in changed runs
// draftAO (2026-11-01): reviewed complete against retail; scored under its member symbol (the archive scored 0 as a symbol mismatch: nonmatch.py now diffs label=<our symbol> as try.py) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 735 -> 29
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: calls identical, branches and stores checked against retail



// func_00144E70 -- hand-written (lifter refused). A CB3AIDriver method (this = a0).
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
static inline float a91_fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct UnkStruct_00144E70_p { unsigned char pad_0[0x1524]; int field_1524; unsigned char pad_1528[0x30]; int field_1558; };
struct UnkStruct_00144E70_i { unsigned char pad_0[0x18EA]; unsigned char field_18EA; };
struct UnkStruct_00144E70_car {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x26C];
    int field_133C;
    unsigned char pad_1340[0x5D4];
    int field_1914;
    unsigned char pad_1918[0xB18];
    UnkStruct_00144E70_p *field_2430;
    unsigned char pad_2434[0xC];
    int field_2440;
};
struct UnkStruct_D_float16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_float4 { float field_0; };
extern UnkStruct_D_float16 D_01E754F0;
extern UnkStruct_D_float16 D_01E754E8;
extern UnkStruct_D_float4 D_004E0EBC;
extern UnkStruct_D_float4 D_004E0DE4;
extern "C" int func_001419B0(void *);
extern "C" UnkStruct_00144E70_i *func_001D0CB0(UnkStruct_00144E70_p *);
class CB3AIDriver {
public:
    void func_00144E70();
    float CalcSpeedMatchSpeed(float);
    float CalcCatchupSpeed(float);
    float GetCurrentMinSpeed();
    unsigned char pad_0[0x213];
    unsigned char field_213;
    unsigned char pad_214[0x56C];
    float field_780;
    unsigned char pad_784[0x1C];
    UnkStruct_00144E70_car *field_7A0;
    unsigned char pad_7A4[0x21C];
    float field_9C0;
    float field_9C4;
    unsigned char pad_9C8[8];
    float field_9D0;
    float field_9D4;
    unsigned char pad_9D8[4];
    float field_9DC;
    unsigned char pad_9E0[0x28];
    float field_A08;
    float field_A0C;
    unsigned char pad_A10[0x21];
    unsigned char field_A31;
};
// 0x00144E70
void CB3AIDriver::func_00144E70()
{
    bool flag = false;
    if (func_001419B0(field_7A0) == 0 && field_7A0->field_2430->field_1558 == 3) {
        UnkStruct_00144E70_i *info = func_001D0CB0(field_7A0->field_2430);
        if (info->field_18EA != 0) {
            flag = true;
        }
    }
    float k = GtMath::Max(0.0f, 1.0f - a91_fabsf(field_9C0) / D_01E754E8.field_0);
    float base = field_780;
    float sp = base;
    if ((unsigned int)(field_7A0->field_2430->field_1524 - 1) < 2) {
    } else {
        sp = k * base;
    }
    float lim = sp + D_01E754F0.field_0;
    float v;
    if (field_213 != 0) {
        v = GtMath::Min(D_004E0EBC.field_0 * lim, base);
    } else {
        v = GtMath::Min(lim, base);
    }
    float w = GtMath::Min(v, field_A08);
    field_9D0 = w;
    field_9C4 = w;
    if (field_7A0->field_133C == 0) {
        field_9C4 = D_004E0DE4.field_0;
        field_9C4 = GtMath::Min(field_9C4, field_9D0);
    } else {
        if (field_7A0->field_1914 == 1 && !flag) {
            field_9C4 = CalcSpeedMatchSpeed(field_9C4);
            if (field_A31 == 0 && field_A0C < field_7A0->field_10CC) {
                field_9C4 = CalcCatchupSpeed(field_9C4);
            } else {
                field_9DC = 0.0f;
            }
            if (field_7A0->field_2440 != 1) {
                field_9C4 = GtMath::Max(field_9C4, D_01E754F0.field_0);
            } else {
                field_9C4 = GtMath::Max(field_9C4, 0.0f);
            }
        }
    }
    if (flag) {
        field_9C4 = GtMath::Min(field_9C4, GetCurrentMinSpeed());
    }
    float a = a91_fabsf(field_9D4);
    if (a <= 1.0f) {
        return;
    }
    float f = GtMath::Min(GtMath::Max(a / 8.0f, 0.0f), 1.0f);
    field_9C4 = field_9C4 * (1.0f - f);
}

#pragma pop
