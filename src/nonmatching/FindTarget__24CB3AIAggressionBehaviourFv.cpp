// NONMATCHING: FindTarget__24CB3AIAggressionBehaviourFv -- retail 245 / ours 243 instructions, 96 in changed runs
// a149: logic complete (243/245, 94 changed). Reuses StopAttacking's archived helper + car struct (extended: field_1894 float[8], 1914, 27C8, 2430). Open: retail emits a dead own-car W() read at the top (sq to sp+0xA0 + lwc1 0xAC, result unused: frame 0xD0 vs ours 0xC0) which MWCC drops from every source form tried; out-of-line 'b ret0; move v0,zero' stubs and f20 (D_004E0D6C kept in a float s-reg across the calls) differ
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV4d;
class CB3RaceCar;
class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
};
class CB3AICar {
public:
    float CalcSeparationAcrossTrack(CB3RaceCar *);
    float CalcSeparationAlongTrack(CB3RaceCar *);
};
struct UnkStruct_SA_Body { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_SA_Tbl { UnkStruct_SA_Body *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_SA_Lane { unsigned char pad_0[2]; unsigned char field_2; unsigned char pad_3[7]; };
struct UnkStruct_SA_Lanes { unsigned char pad_0[8]; UnkStruct_SA_Lane *field_8; };
struct UnkStruct_SA_Sub { unsigned char pad_0[4]; UnkStruct_SA_Lanes *field_4; };
struct UnkStruct_SA_Car {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C1[0x7D3];
    float field_1894[8];
    UnkStruct_SA_Sub *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x30];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0x234];
    unsigned char field_1BE1;
    unsigned char pad_1BE2[0x7EE];
    float field_23D0;
    unsigned char pad_23D4[0x5C];
    int field_2430;
    unsigned char pad_2434[0x4];
    float field_2438;
    unsigned char pad_243C[0x4];
    void *field_2440;
    unsigned char pad_2444[0x384];
    unsigned char field_27C8;
    unsigned char pad_27C9[0x7];
};
struct UnkStruct_SA_F { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_SA_F D_01E755A4, D_01E755B0, D_01E755B4, D_01E755B8, D_01E755D8;
struct UnkStruct_FT_I { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_FT_I D_0064D3A0;
struct UnkStruct_FT_Cars { unsigned char pad_0[0x12AD50]; };
extern UnkStruct_FT_Cars D_00522660, D_0064D3B0;
extern float D_004E0C14;
extern "C" int func_001D0CB0(void *);
extern float D_004E0E88, D_004E0D6C;
extern UnkStruct_SA_Tbl D_0055EFEC[];
class CB3AIAggressionBehaviour {
public:
    bool FindTarget();
    bool CanSlam();
    bool CanStickySpeedMatch() const;
    int field_0;
    unsigned char pad_4[0x1C];
    unsigned char field_20;
    unsigned char field_21;
    unsigned char field_22;
    unsigned char pad_23[5];
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    unsigned char field_40;
    unsigned char field_41;
    unsigned char field_42;
    unsigned char pad_43;
    UnkStruct_SA_Car *field_44;
    UnkStruct_SA_Car *field_48;
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

// 0x0032F550
static inline bool func_0032F550_inl1(CB3AIAggressionBehaviour *self)
{
    UnkStruct_SA_Car *tg = self->field_48;
    if (tg == 0)
        return false;
    float wa = D_0055EFEC[tg->field_19AC].field_0->field_B0.W();
    float wb = D_0055EFEC[self->field_44->field_19AC].field_0->field_B0.W();
    if (fabsf(D_004E0D6C * wa - D_004E0D6C * wb) <= 20.0f) {
        float d = tg->field_10C0.GetTotalRaceDistFromAILaneStart();
        float e = -(d - self->field_44->field_10C0.GetTotalRaceDistFromAILaneStart());
        float h = self->field_44->field_2438;
        if (e < D_004E0E88 + h || !(e <= D_01E755D8.field_0 + h))
            return false;
        if (self->field_44->field_18B4->field_4->field_8[self->field_44->field_18B8 * 5].field_2 == 0xFF)
            return true;
        return false;
    }
    return false;
}


bool CB3AIAggressionBehaviour::FindTarget()
{
    float scale = D_004E0D6C;
    UnkStruct_SA_Car *best = 0;
    UnkStruct_SA_Car *me;
    field_48 = 0;
    D_0055EFEC[field_44->field_19AC].field_0->field_B0.W();
    if (field_44->field_23D0 < D_01E755A4.field_0) return false;
    if (D_0064D3A0.field_0 == 1) {
        best = (UnkStruct_SA_Car *)&D_0064D3B0;
    } else {
        float bestd = D_004E0C14;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            UnkStruct_SA_Car *c = (UnkStruct_SA_Car *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50);
            if (c != field_44) {
                float d = fabsf(field_44->field_1894[c->field_19AC]);
                if (d <= bestd && c->field_18EA == 0) {
                    best = c;
                    bestd = d;
                }
            }
        }
        if (!(bestd <= 50.0f)) best = (UnkStruct_SA_Car *)func_001D0CB0((void *)(field_44->field_2430));
    }
    if (best == 0) return false;
    me = field_44;
    if (best == me) return false;
    if (best->field_1914 == 0 && best->field_27C8 != 0) return false;
    if (me->field_2440 == 0) {
        float d0 = best->field_10C0.GetTotalRaceDistFromAILaneStart();
        float d1 = me->field_10C0.GetTotalRaceDistFromAILaneStart();
        float diff = d0 - d1;
        if (!(diff <= D_01E755B4.field_0)) return false;
        if (diff < -D_01E755B0.field_0) return false;
        if (scale * D_0055EFEC[best->field_19AC].field_0->field_B0.W() < D_01E755B8.field_0) return false;
    }
    field_48 = best;
    if (field_48 == 0) {
        field_38 = 0;
        field_3C = 0;
        field_40 = 0;
        field_41 = 0;
        field_42 = 0;
        return true;
    }
    field_38 = ((CB3AICar *)field_44)->CalcSeparationAcrossTrack((CB3RaceCar *)field_48);
    field_3C = ((CB3AICar *)field_44)->CalcSeparationAlongTrack((CB3RaceCar *)field_48);
    field_40 = CanSlam();
    field_41 = func_0032F550_inl1(this);
    field_42 = CanStickySpeedMatch();
    return true;
}
