// NONMATCHING: func_00395A40 -- retail 273 / ours 273 instructions, 6 in changed runs
// a151 CB3StageLogic::UpdateCarDamage [L] DNAT: 273/273 instrs, 30 changed. Logic, s-regs (car s0, idx s1, counters s2/s3, i s4) exact via function-top decls (int i,idx,s2,s3,m order) and pun reloads CC4P/CC0P in the count loop. Left: the (k==1||0||6||5||3) bool materialisation: retail keeps 'b; move a1,zero / move a1,a2(hoisted 1) / bnez a1' (and 'b; move v1,0 / daddiu v1,1 / bnez v1' in the first search loop); ours threads the true branches straight to the skip (no diamond) and hoists the 1 into a1 not a2. Enum-typed result, int/bool returns, switch (reverses compare order) all tried. | guard: ok | mwperm: 30 -> 8 (+'goto ret0;'; +'r = true; return r; ret0:')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMath.h"
struct UnkStruct_395A40_vd {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0xAB7];
    int field_AC4[1];
};
struct UnkStruct_395A40_cc0 {
    unsigned char pad_0[0x40];
    UnkStruct_395A40_vd * field_40;
};
struct UnkStruct_395A40_cc4 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[8];
    unsigned char pad_4BA[0xB5A];
    unsigned char field_1014;
};
struct UnkStruct_395A40_13F4 {
    unsigned char pad_0[0x16B4];
    float field_16B4;
    unsigned char pad_16B8[0x2A8];
    long field_1960;
};
struct UnkStruct_395A40_car {
    unsigned char pad_0[0x210];
    unsigned char field_210;
    unsigned char pad_211[4];
    signed char field_215;
    unsigned char pad_216[0xAAA];
    UnkStruct_395A40_cc0 * field_CC0;
    UnkStruct_395A40_cc4 * field_CC4;
    unsigned char pad_CC8[0x72C];
    UnkStruct_395A40_13F4 * field_13F4;
};
struct UnkStruct_395A40_e3 {
    unsigned char pad_0[0x2C];
    UnkStruct_395A40_car * field_2C;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C960];
    UnkStruct_395A40_e3 field_3C960[1];
};
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_int D_0064D37C;
extern int D_004C9900[7];
enum EVehicleFlyingBit {};
extern "C" int GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit(void *, int);
extern "C" void ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(void *, void *, int, float, float);
extern "C" void ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(void *, void *, long, int, float, float);
extern "C" void func_001CBE50(void *, int);
extern "C" void func_001CBD80(void *, int);

static inline bool func_00395A40_inl1(int k)
{
    bool r;
    if (k == 1 || k == 0 || k == 6 || k == 5 || k == 3) {
        r = true;
    } else {
        r = false;
        goto ret0;
    }
    r = true;
    return r;
ret0:
    return r;
}

#define CC4P(c) (*(UnkStruct_395A40_cc4 * const *)&(c)->field_CC4)
#define CC0P(c) (*(UnkStruct_395A40_cc0 * const *)&(c)->field_CC0)
// 0x00395A40
extern "C" void func_00395A40(void *a0 /* passed by every caller, not read here */)
{
    float one = 1.0f;
    int i, s3, m, s2, idx;
    for (i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_395A40_car * car = D_00522660.field_3C960[i].field_2C;
        int cnt = 0;
        if (car->field_210 == 0) {
            float t = car->field_13F4->field_16B4;
            if (t < 0.7f) {
                car->field_CC4->field_1014 = 2;
            } else if (t < 0.95f) {
                car->field_CC4->field_1014 = 1;
            }
            int n = car->field_CC0->field_40->field_C;
            for (int j = 0; j < n; j++) {
                if (CC4P(car)->field_4B2[j] == 3 || CC4P(car)->field_4B2[j] == 4) {
                    continue;
                }
                if (!func_00395A40_inl1(CC0P(car)->field_40->field_AC4[j])) {
                    cnt++;
                }
            }
            float f = GtMath::Min(0.1f + car->field_13F4->field_16B4, one);
            int thr = (int)(f * (float)n);
            s2 = cnt - thr;
            while (s2 > 0) {
                for (m = 0; m < 7; m++) {
                    idx = GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit(car->field_CC0->field_40, D_004C9900[m]);
                    if (idx < 0) {
                        continue;
                    }
                    if (car->field_CC4->field_4B2[idx] == 0) {
                        if (car->field_215 == 1) {
                            ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff((char *)car->field_CC4 + 0x300, car, idx, 1.0f, 0.5f);
                        }
                        ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff((char *)car->field_CC4 + 0x300, car, car->field_13F4->field_1960, 0, 1.0f, 0.5f);
                        func_001CBE50(car, idx);
                    }
                    if (car->field_CC4->field_4B2[idx] != 2) {
                        continue;
                    }
                    if (func_00395A40_inl1(car->field_CC0->field_40->field_AC4[idx])) {
                        continue;
                    }
                    func_001CBD80(car, idx);
                    s2--;
                    break;
                }
            }
            int cnt2 = 0;
            for (int a = 0; a < n; a++) {
                if ((unsigned int)car->field_CC4->field_4B2[a] < 2) {
                    cnt2++;
                }
            }
            s3 = cnt2 - thr;
            while (s3 > 0) {
                for (m = 0; m < 7; m++) {
                    idx = GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit(car->field_CC0->field_40, D_004C9900[m]);
                    if (idx < 0) {
                        continue;
                    }
                    if ((unsigned int)car->field_CC4->field_4B2[idx] >= 2) {
                        continue;
                    }
                    if (car->field_215 == 1) {
                        ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff((char *)car->field_CC4 + 0x300, car, idx, 1.0f, 0.5f);
                    }
                    ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff((char *)car->field_CC4 + 0x300, car, car->field_13F4->field_1960, 0, 1.0f, 0.5f);
                    func_001CBE50(car, idx);
                    s3--;
                    break;
                }
            }
        }
    }
}
