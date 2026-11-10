// HandleBoostStart__8CB3ScoreFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (1.0f factor held in a local float (literal x*1.0f is folded)).

// HandleBoostStart__8CB3ScoreFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EScoreBonusEvent {};

class CB3Burn;
class CB3Score;
class CB3ScoreBonus;
struct UnkStruct_00156E20;
struct UnkStruct_00156E20_3;
struct UnkStruct_00156E20_4;
struct UnkStruct_00156E20_e0;
struct UnkStruct_00156E20_e1;
struct UnkStruct_D_0051BA88;

class CB3Burn {
public:
    void AddBurn(float);
};

class CB3ScoreBonus {
public:
    void OnEvent(EScoreBonusEvent, int, int, bool);
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00156E20_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00156E20_3 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00156E20_4 * field_1B4;
};

struct UnkStruct_00156E20_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual int vfunc_48();
};

struct UnkStruct_00156E20_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00156E20_e1 {
    unsigned char pad_0[0x1];
};

class CB3Score {
public:
    static float gmrBoostStartBurnValue;
    static int gmnBoostStartBP;
};

struct UnkStruct_00156E20 {
    unsigned char pad_0[0x4C];
    UnkStruct_00156E20_e0 * field_4C;
    unsigned char pad_50[0x68];
    UnkStruct_00156E20_e1 * field_B8;
    unsigned char pad_BC[0x10];
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x157];
    int field_27C;
};

extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x00156E20
// [L] the 1.0f factor is a local variable: MWCC folds `x * 1.0f` written as a literal, but keeps the
// mul.s when it is propagated from a variable (retail multiplies). What the factor stands for is unknown.
extern "C" void HandleBoostStart__8CB3ScoreFv(UnkStruct_00156E20 * self)
{
    if (self->field_27C == 3) {
        return;
    }
    self->field_CC.AddBurn(CB3Score::gmrBoostStartBurnValue);
    int t0 = CB3Score::gmnBoostStartBP;
    float s = 1.0f;
    if ((D_0051BA88.field_0->field_1B4->vfunc_48() & 1) != 0) {
        int d = (int)((float)t0 * s);
        self->field_4C = &self->field_4C[d];
        self->field_B8 = &self->field_B8[d];
    }
    self->field_124.OnEvent((EScoreBonusEvent)121, CB3Score::gmnBoostStartBP, 1, 0);
}
