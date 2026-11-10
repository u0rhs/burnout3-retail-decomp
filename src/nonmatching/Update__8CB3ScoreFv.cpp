// NONMATCHING: Update__8CB3ScoreFv -- retail 1229 / ours 1198 instructions, 564 in changed runs
// draftAF: logic complete (race-state switch 0/1/2/3+default, lap target-time inline x3, checkpoint ring, active-car scoring: Detect* passes, lucky/denied, best-position BP + OnEvent 0x7A..0x7E, CalculateScoreFor*, reset block with 7 CB3ScoreCategory::Stopped [L], split-lap counter, burn, speed category UpdateValue [L] / OnAward 0x75, crash-mode func_001BAD00). 1198/1229; call multiset identical (order = block placement); op counts equal except retail's extra reloads (lw +13, lui +3) and branch layout
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (B0..C334 walked by hand, Ghidra + m2c cross-checked); call multiset identical (calls.sh sorted); VU ops equal (2 GetLength, 1 DotProduct)

// CB3Score::Update() [C name: config/symbol_addrs_b3names.txt]. No Revenge counterpart (stabs_lookup). Per-frame race
// scoring: the race-state machine (field_27C: 0 countdown, 1 start, 2 racing, 3 finished [G]) with the lap/checkpoint line
// tests, then (while the car is active) distance, the Detect* passes, denied/lucky bonuses, best-position points, the
// distance-based category scores and the lap-split tracking, the burn update, the speed category (field_3AC) and the
// crash-mode trigger. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EB3ScoreFinishState {};
enum EScoreBonusEvent {};
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };   // [G] start, end (Revenge CGtLine: two CGtV3d, 0x20)
// [G] 8 bytes: retail indexes field_2E4 by idx << 3 (Revenge's CB4SpatialTrigger is 4)
class CB3SpatialTrigger { public: bool TestLine(const CGtLine &); unsigned char pad_0[8]; };
class CB3RaceCar;
struct CB3ScoreCategory;
class CB3ScoreBonus {
public:
    void Update();
    void OnYouWereLucky(CB3RaceCar *);
    void OnDenied(CB3RaceCar *);
    int OnEvent(EScoreBonusEvent, int, int, bool);
    int OnAward(EScoreBonusEvent, int, const CB3ScoreCategory *);
    unsigned char pad_0[0x1];
};
class CB3Burn { public: void Update(CB3RaceCar *); unsigned char pad_0[0x1]; };
class CB3RaceCar {
public:
    void SetFinished(EB3ScoreFinishState);
    unsigned char pad_0[0x20];
    CGtV3d field_20;                  // [G] a direction (dot with field_18D0)
    CGtV3d field_30;                  // [G] position
    unsigned char pad_40[0x11A4];
    CB3ScoreBonus field_11E4;
    unsigned char pad_11E5[0x5A7];
    int field_178C;                   // [G] race started flag
    unsigned char pad_1790[0x124];
    int field_18B4;
    unsigned char pad_18B8[4];
    float field_18BC;
    int field_18C0;
    unsigned char pad_18C4[0xC];
    CGtV3d field_18D0;
    unsigned char pad_18E0[8];
    unsigned char field_18E8;
    unsigned char pad_18E9;
    unsigned char field_18EA;
    unsigned char field_18EB;
    unsigned char pad_18EC[0x28];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xE13];
    int field_27C0;
};
class CB3Score;
// [L] layout: Revenge's CB4ScoreCategory (0x1C: mrValue, mrPrevTime, mrPrevValue, mprCategoryArray, mbActive, mn8Category,
// mn8PrevCategory, mn8MaxCategory, meType) with B3's owner pointer last (E map CB3ScoreCategory::GetOwner()); names kept
// as placeholders
struct CB3ScoreCategory {
    float field_0;                    // value
    float field_4;                    // previous time
    float field_8;                    // previous value
    float *field_C;                   // category thresholds
    unsigned char field_10;           // active
    signed char field_11;             // category
    signed char field_12;             // previous category
    signed char field_13;             // max category
    int field_14;
    CB3Score *field_18;               // owner
    void Stopped();
    void UpdateValue(float);
};
// [G] a lap split: the time at the end of split i is field_0
struct UnkStruct_D_0064D364 { float field_0; unsigned char pad_4[4]; };
struct UnkStruct_0015B000_obj {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(int, int);
};
struct UnkStruct_0015B000_mode {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C();
    virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual void vfunc_44(); virtual int vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68();
    virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C();
    virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90();
    virtual void vfunc_94(); virtual void vfunc_98(); virtual int vfunc_9C();
};
struct UnkStruct_0015B000_gm { unsigned char pad_0[0x1B4]; UnkStruct_0015B000_mode *field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_0015B000_gm *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0015B000_slot { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x150]; unsigned char field_210; };
struct UnkStruct_D_0055EFEC { UnkStruct_0015B000_slot *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_0015B000_car2 { unsigned char pad_0[0x1678]; unsigned char field_1678; };
class CB3Score {
public:
    void Update();
    void DetectNonSlamTakedowns();
    void DetectAndScoreNearMiss();
    void DetectAndScoreCrashEscape();
    void DetectAndScoreTailgating();
    void CalculateScoreForAir(float);
    void CalculateScoreForOncoming(float);
    void CalculateScoreForDrift(float);
    void CalculateScoreForTakedowns();
    static float gmrTakedownCrashTime;
    static float gmrPropHitChainTime;
    static int gmnYouWereLuckyBP;
    static int gmnDeniedBP;
    static int gmanBestRacePositionBP[];
    short field_0;                    // [G] race position
    unsigned char pad_2[6];
    int field_8;
    float field_C;                    // race time
    float field_10;                   // distance
    int field_14;                     // [G] lap
    unsigned char pad_18[0x2C];
    int field_44;                     // best position so far
    float field_48;
    int field_4C;                     // score
    unsigned char pad_50[0x50];
    unsigned char field_A0;
    unsigned char pad_A1[0xF];
    int field_B0;
    unsigned char pad_B4[4];
    int field_B8;
    unsigned char pad_BC[0xC];
    CB3RaceCar *field_C8;
    CB3Burn field_CC;
    unsigned char pad_CD[0x51];
    unsigned char field_11E;
    unsigned char pad_11F[5];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x157];
    int field_27C;                    // race state
    float field_280;                  // start time
    unsigned char pad_284[4];
    float field_288;
    float field_28C;                  // target time (-1 = not set)
    CB3SpatialTrigger *field_290;
    CB3SpatialTrigger *field_294;
    unsigned char pad_298[8];
    CGtLine field_2A0;                // last frame's position -> this frame's
    unsigned char field_2C0;
    unsigned char pad_2C1[7];
    float field_2C8;
    float field_2CC;
    float field_2D0;
    unsigned char field_2D4;
    unsigned char pad_2D5;
    unsigned char field_2D6;
    unsigned char pad_2D7[5];
    int field_2DC;                    // checkpoint index
    int field_2E0;                    // checkpoint count
    CB3SpatialTrigger *field_2E4;
    float field_2E8[8];
    unsigned char pad_308[0x3C];
    int field_344;
    float field_348;
    int field_34C;
    int field_350;
    unsigned char pad_354[4];
    CB3ScoreCategory field_358, field_374, field_390, field_3AC;
    unsigned char field_3C8, field_3C9, field_3CA, field_3CB;
    unsigned char pad_3CC[4];
    int field_3D0;
    unsigned char pad_3D4[0x14];
    signed char field_3E8[8];
    unsigned char pad_3F0[0x28];
    CB3ScoreCategory field_418;
    unsigned char pad_434[4];
    unsigned char field_438[8];
    float field_440[0x3A];
    float field_528[0xC];
    unsigned char field_558[6];
    unsigned char field_55E[6];
    CB3ScoreCategory field_564;
    unsigned char pad_580[0xC];
    float field_58C;
    int field_590;
    unsigned char pad_594[4];
    CB3ScoreCategory field_598;
    int field_5B4;
    unsigned char field_5B8;
    unsigned char pad_5B9[0xB];
    CB3ScoreCategory field_5C4;
    unsigned char pad_5E0[5];
    unsigned char field_5E5;
    unsigned char field_5E6;
    unsigned char pad_5E7[5];
    CB3RaceCar *field_5EC;
    float field_5F0;
};
extern unsigned char D_004EE040[];
extern unsigned char D_0055EF70[];
extern UnkStruct_D_0055EFEC D_0055EFEC[];
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned char D_0051B2A4[];
// [G] absolute (lui) addressing in retail: members of larger objects, so padded past 8 bytes (N50)
struct UnkStruct_0015B000_f { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0015B000_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0015B000_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0015B000_p { UnkStruct_D_0064D364 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0015B000_f D_00522680;   // [G] game time
extern UnkStruct_0015B000_f D_0052267C;   // [G] frame time
extern UnkStruct_0015B000_p D_0064D364;
extern UnkStruct_0015B000_i D_0064D368;   // split count
extern UnkStruct_0015B000_b D_0064D378;
extern UnkStruct_0015B000_i D_0064D37C;   // car count
extern UnkStruct_0015B000_car2 *D_0064D388[];
extern UnkStruct_0015B000_i D_0064D3A0, D_0064D3A4;
extern unsigned char D_0064CE40[];
extern unsigned char D_0066A3D0[];
extern UnkStruct_0015B000_i D_00645170;
extern int D_004B62E8[];
extern float D_004E0D6C, D_004E0DE4, D_004E0EE0, D_004E104C;
extern "C" int func_00131E40(void *);  // [L] CB3Game::IsCrashMode() (E map, high)
extern "C" void func_001A08D0(void *);
extern "C" void func_001BED00(UnkStruct_0015B000_slot *, float);
extern "C" void func_00150280(CB3RaceCar *, int);
extern "C" int func_003CC910(void *, int);
extern "C" void func_001BAD00(void *);
extern "C" void func_001576B0(CB3Score *);
extern "C" void func_0015A1F0(CB3Score *);

// [L] CB3ScoreCategory::Stopped() (E map name; Revenge's is 12 instructions, the size of each copy here)
inline void CB3ScoreCategory::Stopped()
{
    field_8 = field_0;
    field_12 = field_11;
    field_4 = *(float *)((char *)field_18 + 0xC);
    field_0 = 0.0f;
    field_10 = 0;
    field_11 = -1;
}
// [L] CB3ScoreCategory::UpdateValue(float) (E map name; Revenge's has the lnCategory local): accumulate, then step the
// category down from the top while the value is below its threshold
inline void CB3ScoreCategory::UpdateValue(float lrValue)
{
    float v = field_0 + lrValue;
    field_8 = field_0;
    field_0 = v;
    field_4 = *(float *)((char *)field_18 + 0xC);
    if (field_11 < field_13 - 1) {
        int lnCategory = field_13;
        while (lnCategory != 0) {
            lnCategory--;
            if (!(v < field_C[lnCategory])) {
                field_12 = field_11;
                field_11 = lnCategory;
                break;
            }
        }
    }
    field_10 = 1;
}
// [G] the lap's target time from the split table, then the lap-start bookkeeping (three inlined copies)
static inline void func_0015B000_inl1(CB3Score *self)
{
    if (D_0064D368.field_0 == 0) {
        self->field_28C = 0.0f;
    } else {
        float prev;
        if (self->field_34C == 0) prev = 0.0f;
        else prev = D_0064D364.field_0[self->field_34C - 1].field_0;
        float seg = D_0064D364.field_0[self->field_34C].field_0 - prev;
        if (D_0064D378.field_0 != 0) self->field_28C = 0.0f + prev + self->field_348 * seg;
        else self->field_28C = 0.0f + prev + self->field_348 * seg + (float)(self->field_350 + 1) * D_0064D364.field_0[D_0064D368.field_0 - 1].field_0;
    }
    self->field_2CC = self->field_C;
    self->field_14 = 0;
    self->field_2D4 = 1;
    if (self->field_11E != 0) self->field_2D6 = 1;
}
// [G] points added to the score and one tally (the 1.0f factor a variable: retail keeps the mul.s, func_00156E20)
static inline void func_0015B000_inl2(CB3Score *self, int bp, int *tally)
{
    float s = 1.0f;
    if ((D_0051BA88.field_0->field_1B4->vfunc_48() & 1) != 0) {
        int d = (int)((float)bp * s);
        self->field_4C += d;
        *tally += d;
    }
}
// [G] the checkpoint's split time into the 8-entry ring
static inline void func_0015B000_inl3(CB3Score *self)
{
    if (self->field_14 >= 0) self->field_2E8[(self->field_2DC + self->field_14 * (self->field_2E0 + 1)) % 8] = self->field_C;
}

// 0x0015B000
// the line tests compared with != 0: retail masks the bool (andi 0xFF; source-shape-rules "if (f() == 0)")
void CB3Score::Update()
{
    bool lbFinish = true;
    field_124.Update();
    field_2A0.field_10 = field_C8->field_30;
    if (field_2D0 < 0.0f) lbFinish = false;
    if (field_C8->field_1914 == 2) lbFinish = false;
    if (func_00131E40(D_004EE040) && D_0055EFEC[field_C8->field_19AC].field_0->field_210 != 0) lbFinish = false;
    switch (field_27C) {
    case 3:
    default:
        field_CC.Update(field_C8);
        return;
    case 1:
        if (field_280 < 0.0f || D_00522680.field_0 <= field_280) {
            func_001A08D0(D_0066A3D0);
            field_C = 0.0f;
            field_44 = field_0;
        } else {
            if (field_C8->field_178C == 0) field_C8->field_178C = 1;
            field_C = D_00522680.field_0 - field_280;
            field_27C = 2;
            if (field_290 == 0 || field_290->TestLine(field_2A0) != 0) func_0015B000_inl1(this);
        }
        if (lbFinish && field_C >= field_2D0 && field_8 == 0) field_C8->SetFinished((EB3ScoreFinishState)2);
        break;
    case 0: {
        int r = D_0051BA88.field_0->field_1B4->vfunc_9C();
        bool lbOnline = r == 2;
        bool lbStart;
        if (lbOnline && field_A0 != 0 && !(field_280 < 0.0f) && field_280 - D_00522680.field_0 <= 3.0f) lbStart = true;
        else if ((lbOnline && field_A0 != 0) || field_280 < 0.0f) lbStart = false;
        else lbStart = true;
        if (lbStart) {
            if (field_C8->field_178C == 0) {
                func_001BED00(D_0055EFEC[field_C8->field_19AC].field_0, D_004E0DE4);
                if (field_C8->field_1914 == 0) func_00150280(field_C8, 1);
                field_C8->field_178C = 1;
            }
            if (D_00522680.field_0 <= field_280) {
                if (field_280 - D_00522680.field_0 <= D_004E0EE0) func_001A08D0(D_0066A3D0);
                field_C = 0.0f;
                field_44 = field_0;
            } else {
                if (field_C8->field_1914 == 0) {
                    func_00150280(field_C8, 0);
                    UnkStruct_0015B000_obj *o = (UnkStruct_0015B000_obj *)(D_004EE040 + 0x28E00 + field_C8->field_27C0 * 0xBB0);
                    o->vfunc_14(0x11, 0);
                }
                field_C = D_00522680.field_0 - field_280;
                field_27C = 2;
            }
            if (field_28C == -1.0f && (field_290 == 0 || field_290->TestLine(field_2A0) != 0)) func_0015B000_inl1(this);
        } else {
            field_C8->field_18E8 = 0;
            field_C = 0.0f;
            field_44 = field_0;
        }
        if (lbFinish && field_C >= field_2D0 && field_8 == 0) field_C8->SetFinished((EB3ScoreFinishState)2);
        break;
    }
    case 2:
        field_C = D_00522680.field_0 - field_280;
        field_2C8 = field_C - field_2CC;
        if (field_28C == -1.0f) {
            if (field_290 == 0 || field_290->TestLine(field_2A0) != 0) func_0015B000_inl1(this);
        } else if (field_2DC < field_2E0) {
            if (field_2E4 != 0 && field_2E4[field_2DC].TestLine(field_2A0) != 0) {
                func_0015B000_inl3(this);
                field_2DC++;
            }
        } else if (field_294 != 0 && field_294->TestLine(field_2A0) != 0) {
            func_0015B000_inl3(this);
            func_0015A1F0(this);
        }
        if (lbFinish && field_C >= field_2D0 && field_8 == 0) field_C8->SetFinished((EB3ScoreFinishState)2);
        break;
    }
    if (field_C8->field_178C != 0) {
        CGtV3d d = field_2A0.field_10 - field_2A0.field_0;
        if (field_C8->field_18EA == 0 && field_C8->field_18EB == 0) {
            float len = d.GetLength();
            field_288 += len;
            DetectNonSlamTakedowns();
            DetectAndScoreNearMiss();
            DetectAndScoreCrashEscape();
            DetectAndScoreTailgating();
            if (field_5E5 != 0) {
                CB3RaceCar *car;
                if (field_5F0 == -1.0f) car = 0;
                else if (field_5F0 + gmrTakedownCrashTime < field_C) car = 0;
                else car = field_5EC;
                if (car != 0) {
                    if (field_5E6 != 0) {
                        field_124.OnYouWereLucky(car);
                        func_0015B000_inl2(this, gmnYouWereLuckyBP, &field_B0);
                    }
                    car->field_11E4.OnDenied(field_C8);
                    func_0015B000_inl2(this, gmnDeniedBP, &field_B0);
                    field_5E5 = 0;
                    field_5E6 = 0;
                }
            }
            func_001576B0(this);
            while (field_0 < field_44) {
                field_44--;
                if (D_0064D3A4.field_0 > 0 || D_0064D3A0.field_0 >= 2) {
                    int bp = gmanBestRacePositionBP[field_44 - 1];
                    func_0015B000_inl2(this, bp, &field_B8);
                    if ((D_0051BA88.field_0->field_1B4->vfunc_48() & 1) != 0) {
                        EScoreBonusEvent e;
                        if (field_44 == 5) e = (EScoreBonusEvent)0x7A;
                        else if (field_44 == 4) e = (EScoreBonusEvent)0x7B;
                        else if (field_44 == 3) e = (EScoreBonusEvent)0x7C;
                        else if (field_44 == 2) e = (EScoreBonusEvent)0x7D;
                        else e = (EScoreBonusEvent)0x7E;
                        field_124.OnEvent(e, bp, 1, 0);
                    }
                    field_48 = field_C;
                }
            }
            CalculateScoreForAir(len);
            CalculateScoreForOncoming(len);
            CalculateScoreForDrift(len);
            CalculateScoreForTakedowns();
            if (!(field_C <= field_58C + gmrPropHitChainTime)) field_590 = 0;
        } else {
            CalculateScoreForTakedowns();
            for (int i = 0; i < 8; i++) field_3E8[i] = -1;
            field_3D0 = 0;
            field_590 = 0;
            field_3C8 = 0;
            field_3C9 = 0;
            field_3CA = 0;
            field_5B8 = 0;
            if (field_5B4 != -1) {
                D_0064D388[field_5B4]->field_1678 = 0;
                field_5B4 = -1;
            }
            for (int i = 0; i < D_0064D37C.field_0; i++) {
                field_438[i] = 0;
                field_440[i] = -1.0f;
                field_528[i] = 0.0f;
                field_55E[i] = 0;
                field_558[i] = 0;
            }
            field_358.Stopped();
            field_374.Stopped();
            field_390.Stopped();
            field_564.Stopped();
            field_598.Stopped();
            field_5C4.Stopped();
            field_418.Stopped();
        }
        if (field_C8->field_18EB == 0) field_10 += d.GetLength();
        field_2C0 = 0;
        if (field_C8->field_18B4 != 0) {
            if ((float)DotProduct(field_C8->field_18D0, field_C8->field_20) < D_004E104C) field_2C0 = 1;
            if (field_C8->field_18C0 >= 0 && D_0064D368.field_0 > 0) {
                field_34C = field_C8->field_18C0;
                field_348 = field_C8->field_18BC;
                int q3 = D_0064D368.field_0 * 3 / 4 + 1;
                if (q3 < field_344) {
                    if (field_34C < D_0064D368.field_0 / 4 + 1) field_350++;
                } else if (field_344 < D_0064D368.field_0 / 4 + 1 && q3 < field_34C) {
                    field_350--;
                }
                field_344 = field_34C;
            }
        }
    }
    field_CC.Update(field_C8);
    if (field_11E == 0) field_2D6 = 0;
    if (field_11E != 0 && D_004E0D6C * (float)D_0055EFEC[field_C8->field_19AC].field_0->field_B0.W() > 120.0f) {
        field_3AC.UpdateValue(D_0052267C.field_0);
    } else {
        if (field_C8->field_18EA == 0 && D_0051BA88.field_0 != 0 &&
            D_0051BA88.field_0->field_1B4 == (UnkStruct_0015B000_mode *)D_0051B2A4 && field_3AC.field_10 != 0 &&
            field_3AC.field_11 >= 0) {
            func_0015B000_inl2(this, D_004B62E8[field_3AC.field_11], &field_B8);
            field_124.OnAward((EScoreBonusEvent)0x75, D_004B62E8[field_3AC.field_11], &field_3AC);
        }
        field_3AC.Stopped();
    }
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        field_558[i] = field_55E[i];
        field_55E[i] = 0;
    }
    field_2A0.field_0 = field_2A0.field_10;
    if (func_00131E40(D_004EE040) && func_003CC910(D_0064CE40, field_C8->field_19AC) <= 0 && field_3CB == 0 &&
        field_C8->field_1914 == 0 && field_C8->field_18EA != 0) {
        void *p;
        if (field_C8->field_27C0 < D_00645170.field_0) p = D_0055EF70 + 0x1CB80 + field_C8->field_27C0 * 0x4590;
        else p = 0;
        func_001BAD00(p);
        field_3CB = 1;
    }
}
