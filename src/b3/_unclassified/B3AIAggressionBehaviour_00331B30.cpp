// CB3AIAggressionBehaviour::Prepare(CB3AICar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AIAggressionBehaviour has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (fam1: clone of matched ClearState + resets + state-5 tail).

// CB3AIAggressionBehaviour::Prepare(CB3AICar*) -- hand-finished by fam1: clone of the matched ClearState (same file,
// same inlined target test with the mph factor through the extern D_004E0D6C) plus the member resets and the state-5
// tail (k read before the state store). Returns int 1 (retail `addiu v0,zero,1`). The random-seed global's type is a
// local placeholder (the proven Construct uses a {int,int} struct too). Types are [G].

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
extern UnkStruct_SA_F D_01E755C8;
struct UnkStruct_00331B30_rnd { int field_0; int field_4; };
extern UnkStruct_00331B30_rnd _gAggressiveHornRandom;
extern UnkStruct_SA_Tbl D_0055EFEC[];
class CB3AIAggressionBehaviour {
public:
    bool FindTarget();
    bool CanSlam();
    void ClearState();
    bool CanStickySpeedMatch() const;
    int Prepare(CB3AICar *);
    int field_0;
    unsigned char pad_4[0xC];
    GtMathPs2::CGtV3d field_10;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char field_22;
    unsigned char field_23;
    unsigned char field_24;
    unsigned char pad_25[3];
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
    int field_4C;
    int field_50;
    int field_54;
    unsigned char field_58;
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern float D_004E0D6C;  // [L] 2.236936331f (.lit4), m/s -> mph (near18)
static inline float func_0032F550_inl3(const CGtV4d &a, const CGtV4d &b)
{
    return fabsf(D_004E0D6C * (float)a.W() - D_004E0D6C * (float)b.W());  // [C] retail FPU form, not a VU lane op: mula.s/msub.s before abs.s 0x331C68 (the cast keeps the port's PS2 float model)
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
// 0x00331B30
int CB3AIAggressionBehaviour::Prepare(CB3AICar *p0)
{
    float m1 = -1.0f;
    field_44 = (UnkStruct_SA_Car *)p0;
    field_10.Zero();
    field_0 = 0;
    field_2C = m1;
    field_30 = m1;
    field_20 = 0;
    field_21 = 0;
    field_22 = 0;
    field_23 = 1;
    field_28 = m1;
    field_34 = 0;
    field_24 = 0;
    _gAggressiveHornRandom.field_4 = 0x2B9D6F8;
    _gAggressiveHornRandom.field_0 = 0xFD462907;
    field_4C = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
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
    float k = D_01E755C8.field_0;
    field_0 = 5;
    field_30 = D_00522680.field_0;
    if (m1 == k)
        field_2C = m1;
    else
        field_2C = field_30 + k;
    return 1;
}
