// Hand-written; the lifter refused it (L274: hand-written from asm after HandleBoostStart/func_00155280; while(n--) scan inline; vfunc_48 unsigned long + <<32>>32 zero-extend).

// func_0015A1F0 -- [G] CB3Score::IncrementLapCount() (research/nahelam_check.csv row marked reject -- not evidence; name not applied).
// Hand-written (L274) after the proven siblings HandleBoostStart (func_00156E20.cpp: bonus-points block with a
// 1.0f local) and func_00155280 (lap-time rounding, inlined here); fastest-lap scan as a `while (n--)` inline (keeps
// retail's `li 3; beqz`); vfunc_48 declared unsigned long, the led-lap test `(r << 32) >> 32` [G] gives retail's
// dsll32/dsrl32. Field names are placeholders; every type is [G].

enum EScoreBonusEvent {};
enum EB3ScoreFinishState {};

class CB3Burn {
public:
    void AddBurn(float);
};
class CB3ScoreBonus {
public:
    void OnEvent(EScoreBonusEvent, int, int, bool);
};
struct UnkStruct_0015A1F0_ls {
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
    virtual unsigned long vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70(void *);
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual int vfunc_B8();
};
struct UnkStruct_0015A1F0_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0015A1F0_ls * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_0015A1F0_2 * field_0;
    unsigned char pad_4[0xC];
};
class CB3RaceCar {
public:
    void SetFinished(EB3ScoreFinishState);
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char pad_1162[0x788];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
};
class CB3Score {
public:
    static float gmrPerfectLapBurnValue;
    static int gmnPerfectLapBP;
    static float gmrBurnoutLapBurnValue;
    static int gmnBurnoutLapBP;
    static int gmnLedLapBP;
};
struct UnkStruct_0015A1F0 {
    short field_0;
    unsigned char pad_2[6];
    int field_8;
    float field_C;
    unsigned char pad_10[4];
    int field_14;
    int field_18;
    float field_1C[8];
    float field_3C;
    int field_40;
    unsigned char pad_44[8];
    int field_4C;
    unsigned char pad_50[0x20];
    int field_70;
    unsigned char pad_74[8];
    float * field_7C;
    unsigned char pad_80[0x38];
    int field_B8;
    unsigned char pad_BC[0xC];
    CB3RaceCar * field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x51];
    unsigned char field_11E;
    unsigned char pad_11F[5];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x19C];
    unsigned char field_2C1;
    unsigned char pad_2C2[2];
    int field_2C4;
    float field_2C8;
    float field_2CC;
    unsigned char pad_2D0[4];
    unsigned char field_2D4;
    unsigned char field_2D5;
    unsigned char field_2D6;
    unsigned char field_2D7;
    float field_2D8;
    int field_2DC;
    unsigned char pad_2E0[0x38];
    int field_318[8];
    int field_338;
};
struct UnkStruct_D_0064D378 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D378 D_0064D378;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131E40(void *);
extern "C" int func_00131E00(void *);

// [L] inlined lap-time rounding (same body as func_00155280)
static inline float func_0015A1F0_inl1(float f0)
{
    if (3.4028235e+38f == f0 || 0.0f == f0) {
        return f0;
    }
    float r = f0 - 60.0f * (float)(int)(f0 / 60.0f);
    float s = (float)(int)r;
    int h = (int)(100.0f * (r - s));
    float m = (float)(int)(0.016666668f * f0);
    float res = m * 60.0f;
    res += s;
    res += (float)(h % 100) / 100.0f;
    return res;
}
static inline void func_0015A1F0_inl2(UnkStruct_0015A1F0 * self, float * p, float t, int n)
{
    while (n--) {
        if (t <= p[n]) {
            if (n > self->field_70 || self->field_70 == 4) {
                self->field_70 = n;
                return;
            }
        }
    }
}

// 0x0015A1F0
extern "C" void func_0015A1F0(UnkStruct_0015A1F0 * self)
{
    self->field_1C[self->field_14] = self->field_2C8;
    self->field_318[self->field_14] = self->field_338;
    self->field_2CC = self->field_C;
    if (self->field_2C1 != 0) {
        if (self->field_14 == self->field_40) {
            self->field_40 = -1;
        }
    } else {
        self->field_18 = self->field_18 + 1;
        if (self->field_14 == 0) {
            self->field_3C = self->field_1C[0];
            self->field_40 = 0;
        }
    }
    if (self->field_1C[self->field_14] < self->field_3C) {
        self->field_3C = self->field_1C[self->field_14];
        self->field_40 = self->field_14;
    }
    float * p = self->field_7C;
    if (p != 0) {
        float t = func_0015A1F0_inl1(self->field_2C8);
        func_0015A1F0_inl2(self, p, t, 3);
    }
    if (self->field_2D4 != 0) {
        self->field_2D5 = 1;
        self->field_CC.AddBurn(CB3Score::gmrPerfectLapBurnValue);
        int bp = CB3Score::gmnPerfectLapBP;
        float k = 1.0f;
        if ((D_0051BA88.field_0->field_1B4->vfunc_48() & 1) != 0) {
            int d = (int)((float)bp * k);
            self->field_4C = self->field_4C + d;
            self->field_B8 = self->field_B8 + d;
        }
        self->field_124.OnEvent((EScoreBonusEvent)0x77, CB3Score::gmnPerfectLapBP, 1, 0);
    } else {
        self->field_2D5 = 0;
    }
    if (self->field_2D6 != 0) {
        self->field_2D7 = 1;
        self->field_CC.AddBurn(CB3Score::gmrBurnoutLapBurnValue);
        int bp = CB3Score::gmnBurnoutLapBP;
        float k = 1.0f;
        if ((D_0051BA88.field_0->field_1B4->vfunc_48() & 1) != 0) {
            int d = (int)((float)bp * k);
            self->field_4C = self->field_4C + d;
            self->field_B8 = self->field_B8 + d;
        }
        self->field_124.OnEvent((EScoreBonusEvent)0x78, CB3Score::gmnBurnoutLapBP, 1, 0);
    } else {
        self->field_2D7 = 0;
    }
    self->field_14 = self->field_14 + 1;
    if (self->field_2C4 > 0 && !(self->field_14 < self->field_2C4)) {
        if (func_00131E40(&D_004EE040) == 0 || self->field_C8->field_18EA == 0) {
            if (func_00131E00(&D_004EE040) == 0) {
                CB3RaceCar * car = self->field_C8;
                if (car->field_1914 != 2) {
                    if (car->field_1161 != 0 && self->field_8 == 0) {
                        if (D_0064D378.field_0 != 0) {
                            car->SetFinished((EB3ScoreFinishState)4);
                        }
                    } else if (self->field_8 == 0) {
                        car->SetFinished((EB3ScoreFinishState)1);
                    }
                }
            }
        }
    } else if (self->field_0 == 1 && D_0064D37C.field_0 > 1 && D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 != 0
               && D_0051BA88.field_0->field_1B4->vfunc_B8() == 0 && D_01E65499.field_0 == 0) {
        int bp = CB3Score::gmnLedLapBP;
        float k = 1.0f;
        if (((D_0051BA88.field_0->field_1B4->vfunc_48() << 32) >> 32) != 0) {
            int d = (int)((float)bp * k);
            self->field_4C = self->field_4C + d;
            self->field_B8 = self->field_B8 + d;
        }
        self->field_124.OnEvent((EScoreBonusEvent)0x76, CB3Score::gmnLedLapBP, -1, 0);
        self->field_2D8 = self->field_C;
    }
    if (!(self->field_14 < 8)) {
        self->field_14 = 0;
        self->field_2C1 = 1;
    }
    self->field_338 = 0;
    self->field_2DC = 0;
    self->field_2D4 = 1;
    if (self->field_11E != 0) {
        self->field_2D6 = 1;
    }
    D_0051BA88.field_0->field_1B4->vfunc_70(self->field_C8);
}
