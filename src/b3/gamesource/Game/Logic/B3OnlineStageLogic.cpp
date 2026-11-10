// B3OnlineStageLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 10 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3OnlineStageLogic.cpp, 8 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Burn.h"
#include "b3/classes/CB3OnlineStageLogic.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/EB3ScoreMedalType.h"
#include "b3/classes/EScoreBonusEvent.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E65458.h"
#include "b3/classes/UnkStruct_D_01E654A4.h"
#include "b3/classes/UnkStruct_D_01E654AC.h"
#include "b3/classes/UnkStruct_D_01E9584C.h"

struct UnkStruct_00391630;
struct UnkStruct_00391B20;
struct UnkStruct_00391B40;
struct UnkStruct_00391DD0;
struct UnkStruct_00392330;

struct UnkStruct_00391630 {
    unsigned char pad_0[0x58];
    float field_58;
};

struct UnkStruct_00391B20 {
    unsigned char pad_0[0x51];
    unsigned char field_51;
};

struct UnkStruct_00391B40 {
    unsigned char pad_0[0x54];
    float field_54;
};

struct UnkStruct_00391DD0 {
    unsigned char pad_0[0x44];
    int field_44;
    unsigned char pad_48[0x9];
    unsigned char field_51;
    unsigned char pad_52[0xA];
    unsigned char field_5C;
};

extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_01E654AC D_01E654AC;
extern UnkStruct_D_01E654A4 D_01E654A4;
extern UnkStruct_D_01E65458 D_01E65458;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E9584C D_01E9584C;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern "C" bool func_003914A0();
extern "C" void func_0026FAA0(void *, int);
extern "C" void func_0043C570(void *);
extern "C" void func_00392330(UnkStruct_00392330 *);
extern "C" void OnTakedown__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);  // CB3StageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*)
extern "C" void SetNumExtraBoostBarSegments__7CB3BurnFi(void *, int);  // CB3Burn::SetNumExtraBoostBarSegments(int)
extern "C" void OnBoostLocked__13CB3ScoreBonusFv(void *);  // CB3ScoreBonus::OnBoostLocked()
extern "C" void SetInfiniteBoost__7CB3BurnFb(void *, bool);  // CB3Burn::SetInfiniteBoost(bool)
extern "C" void AddBurn__7CB3BurnFf(void *, float);  // CB3Burn::AddBurn(float)

// CB3OnlineStageLogic::StartReplay() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineStageLogic.cpp.
// 0x003906A0
int CB3OnlineStageLogic::StartReplay()
{
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(20, 0);
    field_4 = 0;
    return 1;
}

// func_00391490 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391490
extern "C" bool func_00391490(void *a0 /* passed by every caller, not read here */)
{
    return func_003914A0();
}

// func_00391630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391630
extern "C" int func_00391630(UnkStruct_00391630 * self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    float v0;
    if (D_01E654AC.field_0 != 0) {
        v0 = D_01E654A4.field_0;
    } else {
        v0 = -1.0f;
    }
    if (!(v0 == self->field_58)) {
        self->field_58 = v0;
    }
    if (!(D_01E65458.field_0 < self->field_58)) {
        func_0043C570(&D_01E9584C);
    }
    return 0;
}

// func_00391B20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391B20
extern "C" void func_00391B20(UnkStruct_00391B20 * self)
{
    self->field_51 = 0;
    func_0026FAA0(&D_01E32AE0, 1);
}

// UpdateLaunch__19CB3OnlineStageLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391B40
extern "C" int UpdateLaunch__19CB3OnlineStageLogicFv(UnkStruct_00391B40 * self)
{
    self->field_54 = D_004F50A0.field_0;
    func_0026FAA0(&D_01E32AE0, 1);
    return 1;
}

// func_00391DB0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391DB0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_00391DB0(UnkStruct_00392330 *self)
{
    func_00392330(self);
}

// func_00391DC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391DC0
extern "C" void func_00391DC0()
{
    func_0026FAA0(&D_01E32AE0, 1);
}

// func_00391DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391DD0
extern "C" void func_00391DD0(UnkStruct_00391DD0 * self, int p0, int p1)
{
    self->field_51 = 0;
    if (p1 != self->field_44) {
        self->field_5C = 0;
    }
}

// func_00391F00 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00391F00
extern "C" void func_00391F00()
{
}

// CB3OnlineStageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineStageLogic.cpp.
// 0x00391F10
void CB3OnlineStageLogic::OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1)
{
    OnTakedown__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar(this, p0, (CB3RaceCar*)p1);
    int t0 = p1->field_11BC;
    if (t0 < 3) {
        SetNumExtraBoostBarSegments__7CB3BurnFi(((char *)p1 + 0x118C), (t0 + 1));
    } else {
        if (p1->field_11DC == 0) {
            OnBoostLocked__13CB3ScoreBonusFv(((char *)p1 + 0x11E4));
            SetInfiniteBoost__7CB3BurnFb(((char *)p1 + 0x118C), 1);
        }
    }
    AddBurn__7CB3BurnFf(((char *)p1 + 0x118C), CB3Score::gmrTakedownBurnValue);
}
