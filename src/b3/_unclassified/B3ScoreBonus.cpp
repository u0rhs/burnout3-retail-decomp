// B3ScoreBonus.cpp -- translation unit regrouped by tools/tu_merge.py from 17 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3ScoreBonus.cpp, 5 by a medium-confidence name confirmed by a neighbour, 7 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3ScoreCategory.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/EB3ScoreMedalType.h"
#include "b3/classes/EScoreBonusAttackType.h"
#include "b3/classes/EScoreBonusCategory.h"
#include "b3/classes/EScoreBonusEvent.h"

struct UnkStruct_00368D20;
struct UnkStruct_00368D20_2;
struct UnkStruct_00369080;
struct UnkStruct_00369200;
struct UnkStruct_00369210;
struct UnkStruct_00369240;
struct UnkStruct_00369450;

struct UnkStruct_00368D20_2 {
    unsigned char pad_0[0x11DE];
    unsigned char field_11DE;
};

struct UnkStruct_00368D20 {
    unsigned char pad_0[0x148];
    UnkStruct_00368D20_2 * field_148;
};

struct UnkStruct_00369080 {
    unsigned char pad_0[0x140];
    int field_140;
    float field_144;
};

struct UnkStruct_00369200 {
    unsigned char pad_0[0x11C];
    int field_11C;
};

struct UnkStruct_00369210 {
    unsigned char pad_0[0x114];
    int field_114;
    unsigned char pad_118[0x10];
    int field_128;
};

struct UnkStruct_00369240 {
    unsigned char pad_0[0x114];
    int field_114;
    unsigned char pad_118[0x10];
    int field_128;
};

struct UnkStruct_00369450 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char field_11;
    unsigned char pad_12[0x11E];
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    float field_144;
    int field_148;
    int field_14C;
    int field_150;
};

extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(void *, EScoreBonusAttackType, void *, int, EScoreBonusCategory);  // CB3ScoreBonus::OnAttack(EScoreBonusAttackType,CB3RaceCar*,int,EScoreBonusCategory)
extern "C" void ClearAttackData__13CB3ScoreBonusFv(void *);  // CB3ScoreBonus::ClearAttackData()

// CB3ScoreBonus::SetGamebreakerEvent(EScoreBonusEvent) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00368330
void CB3ScoreBonus::SetGamebreakerEvent(EScoreBonusEvent p0)
{
    field_14C = p0;
}

// CB3ScoreBonus::GetDuellingCar() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00368340
int CB3ScoreBonus::GetDuellingCar()
{
    int v0;
    if (field_E4 > 0) {
        v0 = field_D4;
    } else {
        v0 = 0;
    }
    return v0;
}

// CB3ScoreBonus::OnMedal(EB3ScoreMedalType,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00368360
void CB3ScoreBonus::OnMedal(EB3ScoreMedalType p0, int p1)
{
    switch (p0) {
    case 0:
        OnEvent((EScoreBonusEvent)197, p1, 3, 0);
        return;
    case 1:
        OnEvent((EScoreBonusEvent)198, p1, 3, 0);
        return;
    case 2:
        OnEvent((EScoreBonusEvent)199, p1, 3, 0);
        return;
    }
}

// CB3ScoreBonus::OnCrashReset() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x003684A0
void CB3ScoreBonus::OnCrashReset()
{
    ClearAttackData();
}

// CB3ScoreBonus::OnCrashStart() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x003684B0
void CB3ScoreBonus::OnCrashStart()
{
    field_130 = 0;
    field_134 = 0;
    field_138 = 0;
    field_10 = 0;
    field_11 = 0;
}

// CB3ScoreBonus::OnYouWereLucky(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x003684F0
void CB3ScoreBonus::OnYouWereLucky(CB3RaceCar* p0)
{
    OnEvent((EScoreBonusEvent)54, CB3Score::gmnYouWereLuckyBP, 1, 0);
}

// CB3ScoreBonus::OnDenied(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00368510
void CB3ScoreBonus::OnDenied(CB3RaceCar* p0)
{
    OnEvent((EScoreBonusEvent)53, CB3Score::gmnDeniedBP, 1, 0);
}

// func_00368D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00368D20
extern "C" void func_00368D20(UnkStruct_00368D20 * self, void *p0_, int p1)
{
    int p0 = (int)p0_;
    int v0;
    int v1;
    if (p1 != 0) {
        v0 = 4;
        v1 = CB3Score::gmnTradingPaintBP;
    } else {
        v0 = 3;
        v1 = CB3Score::gmnTradingPaintBP;
    }
    int v2 = v1;
    if (self->field_148->field_11DE != 0) {
        v2 = (v1 + CB3Score::gmnBurningSlamExtraBP);
    }
    OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(self, (EScoreBonusAttackType)v0, (CB3RaceCar*)p0, v2, (EScoreBonusCategory)0);
}

// CB3ScoreBonus::OnAward(EScoreBonusEvent,int,const CB3ScoreCategory*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00368E90
int CB3ScoreBonus::OnAward(EScoreBonusEvent p0, int p1, const CB3ScoreCategory* p2)
{
    int r0 = OnEvent(p0, p1, 1, 0);
    if (r0 == 0) {
        return 0;
    }
    field_13C = p2->field_11;
    return 1;
}

// func_00369080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369080
extern "C" void func_00369080(UnkStruct_00369080 * self, int p0)
{
    self->field_140 = p0;
    self->field_144 = 1.0f;
}

// func_00369090 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369090
extern "C" int func_00369090(void *n0_, int p0)
{
    int n0 = (int)n0_;
    if ((unsigned int)(p0 - 197) <= 2) return 0;
    if (p0 >= 147 && p0 <= 196 || p0 == 133) return 0;
    if (p0 == 134) return 0;
    if ((unsigned int)(p0 - 122) <= 4) {} else return ((unsigned int)(p0 - 118) < 3) ^ 1;
    return 0;
}

// func_00369200 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369200
extern "C" bool func_00369200(UnkStruct_00369200 * self)
{
    return (self->field_11C == 5);
}

// func_00369210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369210
extern "C" bool func_00369210(UnkStruct_00369210 * self)
{
    bool v0;
    if (self->field_114 != 3) {
        v0 = (self->field_128 == 3);
    } else {
        v0 = 1;
    }
    return v0;
}

// func_00369240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369240
extern "C" bool func_00369240(UnkStruct_00369240 * self)
{
    bool v0;
    if (self->field_114 != 2) {
        v0 = (self->field_128 == 2);
    } else {
        v0 = 1;
    }
    return v0;
}

// CB3ScoreBonus::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x00369440
void CB3ScoreBonus::Release()
{
}

// func_00369450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00369450
extern "C" void func_00369450(UnkStruct_00369450 * self, void *p0_)
{
    int p0 = (int)p0_;
    self->field_148 = p0;
    self->field_130 = 0;
    self->field_134 = 0;
    self->field_138 = 0;
    self->field_13C = 0;
    self->field_10 = 0;
    self->field_11 = 0;
    self->field_14C = 196;
    self->field_150 = 0;
    ClearAttackData__13CB3ScoreBonusFv(self);
    self->field_140 = 209;
    self->field_144 = -1.0f;
}

// CB3ScoreBonus::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// 0x003694B0
void CB3ScoreBonus::Construct()
{
    field_148 = 0;
}
