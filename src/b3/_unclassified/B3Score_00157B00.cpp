// CB3Score::CalculateScoreForDrift(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a92: goto-structured; bool on = a && spd >= min; done: label for fall-off exits (b; ld ra)).

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
struct UnkStruct_7B00_ls {
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
struct UnkStruct_7B00_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_7B00_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_7B00_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_7B00_car {
    unsigned char pad_0[0x54];
    float field_54;
    unsigned char pad_58[0x105A];
    unsigned char field_10B2;
};
struct UnkStruct_7B00_3A8 {
    unsigned char pad_0[0xC];
    float field_C;
};
class CB3Score {
public:
    void CalculateScoreForDrift(float p0);
    unsigned char pad_0[0x4C];
    int field_4C;
    unsigned char pad_50[0x10];
    float field_60;
    float field_64;
    unsigned char pad_68[0x50];
    int field_B8;
    unsigned char pad_BC[0xC];
    UnkStruct_7B00_car * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x26B];
    float field_390;
    float field_394;
    float field_398;
    float * field_39C;
    bool field_3A0;
    signed char field_3A1;
    signed char field_3A2;
    signed char field_3A3;
    unsigned char pad_3A4[0x4];
    UnkStruct_7B00_3A8 * field_3A8;
    unsigned char pad_3AC[0x1E];
    bool field_3CA;
    static int gmanDriftBP[4];
    static float gmrDriftDistanceBurnValue;
    static float gmrDriftMinimumDistanceValue;
    static float gmrDriftMinimumSpeed;
};
extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x00157B00
void CB3Score::CalculateScoreForDrift(float p0)
{
    UnkStruct_7B00_car * car = field_C8;
    float spd = 2.236936331f * car->field_54;
    bool on = car->field_10B2 != 0 && spd >= gmrDriftMinimumSpeed;
    field_3A0 = on;
    float f1;
    if (field_3A0 != 0) goto active;
    if (field_3CA == 0) goto reset;
    if (field_3A1 >= 0) goto award;
    f1 = field_390;
tail70:
    field_60 = field_60 + f1;
    f1 = field_390;
    if (field_64 < f1) {
        field_64 = f1;
    }
reset:
    field_398 = field_390;
    field_3A2 = field_3A1;
    field_394 = field_3A8->field_C;
    field_390 = 0.0f;
    field_3A0 = false;
    field_3A1 = -1;
    field_3CA = false;
    goto done;
active:
    {
        float f0 = field_390;
        f1 = f0 + p0;
        field_398 = f0;
        field_390 = f1;
        field_394 = field_3A8->field_C;
        int n = field_3A3;
        int lv = field_3A1;
        if (lv < n - 1) {
            int i = n;
            int old;
            goto test;
body:
            if (!(f1 < field_39C[i])) {
                field_3A2 = lv;
                field_3A1 = i;
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
        float d = field_390;
        if (d <= gmrDriftMinimumDistanceValue) {
            return;
        }
        if (field_3CA != 0) {
            field_CC.AddBurn(p0 * gmrDriftDistanceBurnValue);
        } else {
            field_CC.AddBurn(d * gmrDriftDistanceBurnValue);
        }
        field_3CA = true;
        goto done;
    }
award:
    {
        int bp = gmanDriftBP[field_3A1];
        if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) {
            float k = 1.0f;
            int add = (int)((float)bp * k);
            field_4C = field_4C + add;
            field_B8 = field_B8 + add;
        }
        field_124.OnAward((EScoreBonusEvent)0x71, gmanDriftBP[field_3A1], (const CB3ScoreCategory *)&field_390);
        f1 = field_390;
        goto tail70;
    }
done:
    return;
}
