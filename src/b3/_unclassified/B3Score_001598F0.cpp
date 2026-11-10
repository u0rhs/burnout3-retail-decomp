// CB3Score::DetectAndScoreNearMiss() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written after CalculateScoreForAir/Drift (category chain at +0x418); counter before found flag; loop's score-add as goto block after award; (float)count read before the 420 store).

// CB3Score::DetectAndScoreNearMiss() -- hand-written (L264) from the asm after the proven siblings
// CalculateScoreForAir / CalculateScoreForDrift (B3Score_00157FA0.cpp / B3Score_00157B00.cpp: the same score-category
// chain, here at +0x418). [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv ->
// B3Score.cpp. Area not evidenced, so _unclassified/. Field names are placeholders; every type is [G].

#include "b3/classes/EScoreBonusEvent.h"

struct CB3ScoreCategory;
class CB3TrafficVehicle;
class CB3Burn {
public:
    void AddBurn(float p0);
};
class CB3ScoreBonus {
public:
    int OnAward(EScoreBonusEvent p0, int p1, const CB3ScoreCategory * p2);
    unsigned char pad_0[0x1];
};
struct UnkStruct_98F0_ls {
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
struct UnkStruct_98F0_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_98F0_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_98F0_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_98F0_car {
    unsigned char pad_0[0x54];
    float field_54;
    unsigned char pad_58[0x1954];
    signed char field_19AC;
};
struct UnkStruct_98F0_drv {
    unsigned char pad_0[0x177];
    unsigned char field_177;
};
struct UnkStruct_98F0_tv {
    unsigned char pad_0[0x10C];
    UnkStruct_98F0_drv * field_10C;
};
struct UnkStruct_98F0_430 {
    unsigned char pad_0[0xC];
    float field_C;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
class CB3Score {
public:
    void DetectAndScoreNearMiss();
    bool DetectNormalNearMiss(CB3TrafficVehicle * p0);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x3C];
    int field_4C;
    unsigned char pad_50[0x68];
    int field_B8;
    unsigned char pad_BC[0xC];
    UnkStruct_98F0_car * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x2A7];
    int field_3CC;
    int field_3D0;
    unsigned char pad_3D4[0x8];
    float field_3DC;
    float field_3E0;
    float field_3E4;
    unsigned char field_3E8[8];
    float field_3F0[8];
    unsigned char field_410[8];
    float field_418;
    float field_41C;
    float field_420;
    float * field_424;
    unsigned char field_428;
    signed char field_429;
    signed char field_42A;
    signed char field_42B;
    unsigned char pad_42C[0x4];
    UnkStruct_98F0_430 * field_430;
    static int gmanNearMissBP[4];
    static float gmrNearMissMinimumSpeed;
    static float gmrNearMissMinimumChainSpeed;
    static float gmrNearMissBurnValue;
    static float gmrNearMissChainTime;
    static int gmnNearMissBP;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_00522660 D_00522660;
extern unsigned char D_0055D79C[];

// 0x001598F0
void CB3Score::DetectAndScoreNearMiss()
{
    float spd = 2.236936331f * field_C8->field_54;
    int idx = field_C8->field_19AC;
    int n = D_0055D79C[idx];
    unsigned char * row = (unsigned char *)&D_00522660 + idx * 8;
    int i;
    for (i = 0; i < n; i++) {
        unsigned char id = row[i + 0x3B08E];
        UnkStruct_98F0_tv * tv = (UnkStruct_98F0_tv *)((char *)&D_00522660 + id * 0x180 + 0x175B0);
        if (DetectNormalNearMiss((CB3TrafficVehicle *)tv)) {
            if (tv->field_10C != 0) {
                id = tv->field_10C->field_177;
            }
            if (!(spd < gmrNearMissMinimumSpeed)) {
                int j;
                bool found = false;
                for (j = 0; j < 8; j++) {
                    if (field_3E8[j] == id) {
                        field_3F0[j] = field_C;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    bool placed = false;
                    int k;
                    for (k = 0; k < 8; k++) {
                        unsigned char * e = &field_3E8[k];
                        if (*e == 0xFF) {
                            *e = id;
                            field_3F0[k] = field_C;
                            field_410[k] = 1;
                            placed = true;
                            break;
                        }
                    }
                    if (!placed) {
                        float best = field_3DC;
                        int bi = -1;
                        int m;
                        for (m = 0; m < 8; m++) {
                            if (field_3F0[m] < best) {
                                best = field_3F0[m];
                                bi = m;
                            }
                        }
                        if (bi >= 0) {
                            field_3E8[bi] = id;
                            field_3F0[bi] = field_C;
                            field_410[bi] = 1;
                        }
                    }
                }
            }
        }
    }
    if (field_3D0 != 0) {
        float t = field_C;
        if (t > field_3E0 + gmrNearMissChainTime || spd < gmrNearMissMinimumChainSpeed) {
            field_3E4 = t;
            field_3D0 = 0;
            if (field_429 >= 0) goto award;
        reset:
            field_420 = field_418;
            field_42A = field_429;
            field_41C = field_430->field_C;
            field_418 = 0.0f;
            field_428 = 0;
            field_429 = -1;
        }
    }
    int s;
    int bp;
    for (s = 0; s < 8; s++) {
        unsigned char * slot = &field_3E8[s];
        if (*slot != 0xFF && field_3F0[s] < field_3DC && field_410[s] != 0) {
            field_410[s] = 0;
            field_3D0 = field_3D0 + 1;
            field_3CC = field_3CC + 1;
            field_CC.AddBurn(gmrNearMissBurnValue);
            bp = gmnNearMissBP * field_3D0;
            if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) goto chainadd;
        chainback:
            field_428 = 1;
            float f1 = (float)field_3D0;
            field_420 = field_418;
            field_418 = f1;
            field_41C = field_430->field_C;
            int nn = field_42B;
            int lv = field_429;
            if (lv < nn - 1) {
                int ii = nn;
                int old;
                goto test;
            body:
                if (!(f1 < field_424[ii])) {
                    field_42A = lv;
                    field_429 = ii;
                    goto after;
                }
                old = ii;
            test:
                old = ii;
                ii = ii - 1;
                if (old != 0) goto body;
            }
        after:
            field_3E0 = field_C;
        }
        if (*slot != 0xFF && field_3F0[s] + 1.0f < field_3DC) {
            *slot = 0xFF;
        }
    }
    field_3DC = field_C;
    return;
award:
    {
        int bp = gmanNearMissBP[field_429];
        if (D_0051BA88.field_0->field_1B4->vfunc_48() & 1) {
            float k = 1.0f;
            int add = (int)((float)bp * k);
            field_4C = field_4C + add;
            field_B8 = field_B8 + add;
        }
        field_124.OnAward((EScoreBonusEvent)0x74, gmanNearMissBP[field_429], (const CB3ScoreCategory *)&field_418);
        goto reset;
    }
chainadd:
    {
        float k = 1.0f;
        int add = (int)((float)bp * k);
        field_4C = field_4C + add;
        field_B8 = field_B8 + add;
        goto chainback;
    }
}
