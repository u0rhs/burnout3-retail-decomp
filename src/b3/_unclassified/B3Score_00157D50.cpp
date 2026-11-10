// CB3Score::CalculateScoreForOncoming(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a92: sibling of CalculateScoreForDrift (offsets 0x374.., event 0x73)).

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
struct UnkStruct_7D50_ls {
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
struct UnkStruct_7D50_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_7D50_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_7D50_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_7D50_car {
    unsigned char pad_0[0x54];
    float field_54;
    unsigned char pad_58[0x1894];
    unsigned char field_18EC;
};
struct UnkStruct_7D50_3A8 {
    unsigned char pad_0[0xC];
    float field_C;
};
class CB3Score {
public:
    void CalculateScoreForOncoming(float p0);
    unsigned char pad_0[0x4C];
    int field_4C;
    unsigned char pad_50[0x8];
    float field_58;
    float field_5C;
    unsigned char pad_60[0x58];
    int field_B8;
    unsigned char pad_BC[0xC];
    UnkStruct_7D50_car * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x24F];
    float field_374;
    float field_378;
    float field_37C;
    float * field_380;
    bool field_384;
    signed char field_385;
    signed char field_386;
    signed char field_387;
    unsigned char pad_388[0x4];
    UnkStruct_7D50_3A8 * field_38C;
    unsigned char pad_390[0x39];
    bool field_3C9;
    static int gmanOncomingBP[4];
    static float gmrOncomingDistanceBurnValue;
    static float gmrOncomingMinimumDistanceValue;
    static float gmrOncomingMinimumSpeed;
};
extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x00157D50
void CB3Score::CalculateScoreForOncoming(float p0)
{
    UnkStruct_7D50_car * car = field_C8;
    float spd = 2.236936331f * car->field_54;
    bool on = car->field_18EC != 0 && spd >= gmrOncomingMinimumSpeed;
    field_384 = on;
    float f1;
    if (field_384 != 0) goto active;
    if (field_3C9 == 0) goto reset;
    if (field_385 >= 0) goto award;
    f1 = field_374;
tail70:
    field_58 = field_58 + f1;
    f1 = field_374;
    if (field_5C < f1) {
        field_5C = f1;
    }
reset:
    field_37C = field_374;
    field_386 = field_385;
    field_378 = field_38C->field_C;
    field_374 = 0.0f;
    field_384 = false;
    field_385 = -1;
    field_3C9 = false;
    goto done;
active:
    {
        float f0 = field_374;
        f1 = f0 + p0;
        field_37C = f0;
        field_374 = f1;
        field_378 = field_38C->field_C;
        int n = field_387;
        int lv = field_385;
        if (lv < n - 1) {
            int i = n;
            int old;
            goto test;
body:
            if (!(f1 < field_380[i])) {
                field_386 = lv;
                field_385 = i;
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
        float d = field_374;
        if (d <= gmrOncomingMinimumDistanceValue) {
            return;
        }
        if (field_3C9 != 0) {
            field_CC.AddBurn(p0 * gmrOncomingDistanceBurnValue);
        } else {
            field_CC.AddBurn(d * gmrOncomingDistanceBurnValue);
        }
        field_3C9 = true;
        goto done;
    }
award:
    {
        int bp = gmanOncomingBP[field_385];
        if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) {
            float k = 1.0f;
            int add = (int)((float)bp * k);
            field_4C = field_4C + add;
            field_B8 = field_B8 + add;
        }
        field_124.OnAward((EScoreBonusEvent)0x73, gmanOncomingBP[field_385], (const CB3ScoreCategory *)&field_374);
        f1 = field_374;
        goto tail70;
    }
done:
    return;
}
