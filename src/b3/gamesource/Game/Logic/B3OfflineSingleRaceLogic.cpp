// B3OfflineSingleRaceLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 17 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OfflineSingleRaceLogic.cpp, 2 by a medium-confidence name confirmed by a neighbour, 14 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Burn.h"
#include "b3/classes/CB3CrashCombo.h"
#include "b3/classes/CB3OfflineSingleRaceLogic.h"
#include "b3/classes/CB3OfflineStageLogic.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"

struct UnkStruct_003897E0;
struct UnkStruct_00389A40_a1;
struct UnkStruct_00389A50_a1;
struct UnkStruct_00389A80_1;
struct UnkStruct_00389A80_a1;
struct UnkStruct_00389B50;
struct UnkStruct_00389B50_3;
struct UnkStruct_00389B50_4;

struct UnkStruct_003897E0 {
    unsigned char pad_0[0x40];
    int field_40;
};

struct UnkStruct_00389A40_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

struct UnkStruct_00389A50_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

struct UnkStruct_00389A80_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_00389A80_1 * field_13F4;
};

struct UnkStruct_00389A80_1 {
    unsigned char pad_0[0x1338];
    CB3CrashCombo * field_1338;
};

struct UnkStruct_00389B50_3 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00389B50_4 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00389B50 {
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
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
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
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual int vfunc_C0();
    unsigned char field_4;
    unsigned char pad_5[0x3B];
    int field_40;
    unsigned char pad_44[0x4];
    float field_48;
};

extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern "C" void OnTakedown__20CB3OfflineStageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);  // CB3OfflineStageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*)
extern "C" void AddSegment__7CB3BurnFv(void *);  // CB3Burn::AddSegment()
extern "C" void AddBurn__7CB3BurnFf(void *, float);  // CB3Burn::AddBurn(float)
extern "C" void HandleNonFatalCollision__8CB3ScoreFP17CB3TrafficVehicle(void *, void *);
extern "C" void HandleCrashReset__8CB3ScoreFv(void *);
extern "C" void StartReplay__20CB3OfflineStageLogicFv(void *);  // CB3OfflineStageLogic::StartReplay()

// CB3OfflineSingleRaceLogic::GetScoreModeFlags() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineSingleRaceLogic.cpp.
// 0x003897B0
int CB3OfflineSingleRaceLogic::GetScoreModeFlags()
{
    return 1;
}

// func_003897C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003897C0
extern "C" int func_003897C0()
{
    return 0;
}

// func_003897D0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003897D0
extern "C" int func_003897D0()
{
    return 6;
}

// func_003897E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003897E0
extern "C" bool func_003897E0(UnkStruct_003897E0 * self)
{
    return (self->field_40 == 2);
}

// func_003897F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003897F0
extern "C" void func_003897F0()
{
}

// func_00389800 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389800
extern "C" int func_00389800()
{
    return 1;
}

// func_00389810 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389810
extern "C" int func_00389810()
{
    return 0;
}

// func_00389820 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389820
extern "C" int func_00389820()
{
    return 1;
}

// func_003899D0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003899D0
extern "C" void func_003899D0()
{
}

// CB3OfflineSingleRaceLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineSingleRaceLogic.cpp.
// 0x003899E0
void CB3OfflineSingleRaceLogic::OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1)
{
    OnTakedown__20CB3OfflineStageLogicFP10CB3RaceCarP10CB3RaceCar(this, p0, (CB3RaceCar*)p1);
    if (p1->field_11BC < 3) {
        AddSegment__7CB3BurnFv(((char *)p1 + 0x118C));
    }
    AddBurn__7CB3BurnFf(((char *)p1 + 0x118C), CB3Score::gmrTakedownBurnValue);
}

// func_00389A30 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389A30
extern "C" void func_00389A30()
{
}

// func_00389A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389A40
extern "C" void func_00389A40(int n0, UnkStruct_00389A40_a1 * p0, int p1)
{
    HandleNonFatalCollision__8CB3ScoreFP17CB3TrafficVehicle((void *)((p0->field_13F4 + 4288)), (void *)(p1));
}

// func_00389A50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389A50
extern "C" void func_00389A50(CB3StageLogic * self, UnkStruct_00389A50_a1 * p0)
{
    self->OnPostCrashReset((CB3RaceCarPhysics*)p0);
    HandleCrashReset__8CB3ScoreFv((void *)((p0->field_13F4 + 4288)));
}

// func_00389A80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389A80
extern "C" void func_00389A80(void *n0_, UnkStruct_00389A80_a1 * p0)
{
    int n0 = (int)n0_;
    UnkStruct_00389A80_1 * t0 = p0->field_13F4;
    CB3CrashCombo * t1 = t0->field_1338;
    if (t1 == 0) return;
    t1->OnCrashFinishing();
}

// func_00389B50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389B50
extern "C" int func_00389B50(UnkStruct_00389B50 * self)
{
    StartReplay__20CB3OfflineStageLogicFv(self);
    self->field_4 = 0;
    self->field_40 = 1;
    int r1 = self->vfunc_C0();
    if (r1 != 0) {
        ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(16, 0);
        ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(16, 0);
    } else {
        ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(17, 0);
        ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(17, 0);
    }
    self->field_48 = -1.0f;
    return 1;
}

// func_00389C20 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00389C20
extern "C" int func_00389C20()
{
    return 2;
}

// CB3OfflineSingleRaceLogic::GetHUDType() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineSingleRaceLogic.cpp.
// 0x00389C30
int CB3OfflineSingleRaceLogic::GetHUDType()
{
    return 1;
}
