// CB3Score::CalculateScoreForAir(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (slot: speed test via CGtV4d::W() (N152 copy + source slot); D_004E1DA0/DA4 are vdb-registered float globals, not literals; field_54 update as an end-of-function goto block).

#include "b3/GtMathPs2.h"
#include "b3/classes/EScoreBonusEvent.h"

struct CB3ScoreCategory;
class CB3Burn {
public:
    void AddBurn(float p0);
};
class CB3ScoreBonus {
public:
    int OnAward(EScoreBonusEvent p0, int p1, const CB3ScoreCategory * p2);
    unsigned char pad_0[0x1];
};
struct UnkStruct_7FA0_ls {
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
struct UnkStruct_7FA0_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_7FA0_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_7FA0_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_7FA0_phys {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};
struct UnkStruct_7FA0_car {
    unsigned char pad_0[0x10B0];
    unsigned char field_10B0;
    unsigned char pad_10B1[0x863];
    int field_1914;
    unsigned char pad_1918[0xB18];
    UnkStruct_7FA0_phys * field_2430;
    unsigned char pad_2434[0x38C];
    signed char field_27C0;
};
struct UnkStruct_7FA0_370 {
    unsigned char pad_0[0xC];
    float field_C;
};
struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0x10];
};
class CB3Score {
public:
    void CalculateScoreForAir(float p0);
    unsigned char pad_0[0x4C];
    int field_4C;
    float field_50;
    float field_54;
    unsigned char pad_58[0x60];
    int field_B8;
    unsigned char pad_BC[0xC];
    UnkStruct_7FA0_car * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x22F];
    int field_354;
    float field_358;
    float field_35C;
    float field_360;
    float * field_364;
    unsigned char field_368;
    signed char field_369;
    signed char field_36A;
    signed char field_36B;
    unsigned char pad_36C[0x4];
    UnkStruct_7FA0_370 * field_370;
    unsigned char pad_374[0x54];
    bool field_3C8;
    static int gmanAirBP[4];
    static float gmrAirDistanceBurnValue;
    static float gmrAirMinimumDistanceValue;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern int D_004E2DBC;
extern float D_004E2DC0;
extern float D_004E1DA0;   // [C] a vdb-registered float (func_00344310), 0.35f in retail's data
extern float D_004E1DA4;   // [C] a vdb-registered float (func_00344310), 0.1f in retail's data
extern "C" void func_0022C2F0(void *, int, int, int, float, float, float, float);

// 0x00157FA0
void CB3Score::CalculateScoreForAir(float p0)
{
    UnkStruct_7FA0_car * car = field_C8;
    field_368 = car->field_10B0;
    float f1;
    if (field_368 != 0) goto active;
    if (field_3C8 == 0) goto reset;
    if (field_369 >= 0) goto award;
    f1 = field_358;
tail50:
    field_50 = field_50 + f1;
    field_354 = field_354 + 1;
    f1 = field_358;
    if (field_54 < f1) goto best;
back:
    {
        UnkStruct_7FA0_car * c2 = field_C8;
        if (c2->field_1914 == 0) {
            int lv = field_369;
            if (lv >= 0) {
                float k = D_004E1DA4 * (float)lv;
                if (2.236936331f * (float)c2->field_2430->field_B0.W() > 20.0f) {   // W(): the 16-byte copy + its source slot (N152)  // [C] retail FPU form, not a VU lane op: 0x158054 lwc1 / 0x158060 mul.s (the cast keeps the port's PS2 float model)
                    func_0022C2F0(&D_004F50C0, D_004E2DBC, c2->field_27C0, 0xFFFF, k, 0.0f, D_004E1DA0, D_004E2DC0);
                }
            }
        }
    }
reset:
    field_360 = field_358;
    field_36A = field_369;
    field_35C = field_370->field_C;
    field_358 = 0.0f;
    field_368 = false;
    field_369 = -1;
    field_3C8 = false;
    goto done;
active:
    {
        float f0 = field_358;
        f1 = f0 + p0;
        field_360 = f0;
        field_358 = f1;
        field_35C = field_370->field_C;
        int n = field_36B;
        int lv = field_369;
        if (lv < n - 1) {
            int i = n;
            int old;
            goto test;
body:
            if (!(f1 < field_364[i])) {
                field_36A = lv;
                field_369 = i;
                goto after;
            }
            old = i;
test:
            old = i;
            i = i - 1;
            if (old != 0) goto body;
        }
    }
after:
    {
        float d = field_358;
        if (d <= gmrAirMinimumDistanceValue) {
            return;
        }
        if (field_3C8 != 0) {
            field_CC.AddBurn(p0 * gmrAirDistanceBurnValue);
        } else {
            field_CC.AddBurn(d * gmrAirDistanceBurnValue);
        }
        field_3C8 = true;
        goto done;
    }
award:
    {
        int bp = gmanAirBP[field_369];
        if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) {
            float k = 1.0f;
            int add = (int)((float)bp * k);
            field_4C = field_4C + add;
            field_B8 = field_B8 + add;
        }
        field_124.OnAward((EScoreBonusEvent)0x72, gmanAirBP[field_369], (const CB3ScoreCategory *)&field_358);
        f1 = field_358;
        goto tail50;
    }
best:
    field_54 = f1;
    goto back;
done:
    return;
}
