// CB3AIAggressionBehaviour::ClearState() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fam1: mph factor via extern D_004E0D6C (lit4 label) fixes FPR numbering).

// CB3AIAggressionBehaviour::ClearState() -- hand-finished by fam1 from the near29/lit4fix archive.
// The m/s -> mph factor (near18) is read through the extern D_004E0D6C (its .lit4 label, as the proven func_001508C0):
// as a literal MWCC numbers the constant f1 and coalesces the msub result with it; the global load gives retail's
// k=f2 / wa=f3 / wb=f1. Types are [G].

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
extern "C" int func_001D0CB0(void *);
extern UnkStruct_SA_F D_00522680;
extern UnkStruct_SA_Tbl D_0055EFEC[];
class CB3AIAggressionBehaviour {
public:
    bool FindTarget();
    bool CanSlam();
    void ClearState();
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

extern float D_004E0D6C;  // [L] 2.236936331f (.lit4), m/s -> mph (near18)
static inline float func_0032F550_inl3(const CGtV4d &a, const CGtV4d &b)
{
    return fabsf(D_004E0D6C * (float)a.W() - D_004E0D6C * (float)b.W());  // [C] retail FPU form, not a VU lane op: 0x32F43C lwc1 / 0x32F448 mula.s + 0x32F44C msub.s (the cast keeps the port's PS2 float model)
}
static inline bool func_0032F550_inl1(CB3AIAggressionBehaviour *self)
{
    UnkStruct_SA_Car *tg = self->field_48;
    if (tg == 0)
        return false;
    if (func_0032F550_inl3(D_0055EFEC[tg->field_19AC].field_0->field_B0, D_0055EFEC[self->field_44->field_19AC].field_0->field_B0) <= 20.0f) {
        float d = tg->field_10C0.GetTotalRaceDistFromAILaneStart();
        float e = -(d - self->field_44->field_10C0.GetTotalRaceDistFromAILaneStart());
        float h = self->field_44->field_2438;
        if (e < 9.999999747e-05f + h || !(e <= h + D_01E755D8.field_0))
            return false;
        if (self->field_44->field_18B4->field_4->field_8[self->field_44->field_18B8].field_2 != 0xFF)
            return false;
        return true;
    }
    return false;
}
// 0x0032F360
void CB3AIAggressionBehaviour::ClearState()
{
    field_0 = 0;
    field_30 = D_00522680.field_0;
    field_2C = -1.0f;
    field_20 = 0;
    field_21 = 0;
    field_22 = 0;
    field_44->field_1BE1 = 0;
    field_48 = 0;
    if (field_48 != 0) {
        field_38 = ((CB3AICar *)field_44)->CalcSeparationAcrossTrack((CB3RaceCar *)field_48);
        field_3C = ((CB3AICar *)field_44)->CalcSeparationAlongTrack((CB3RaceCar *)field_48);
        field_40 = CanSlam();
        field_41 = func_0032F550_inl1(this);
        field_42 = CanStickySpeedMatch();
    } else {
        field_38 = 0;
        field_3C = 0;
        field_40 = 0;
        field_41 = 0;
        field_42 = 0;
    }
}
