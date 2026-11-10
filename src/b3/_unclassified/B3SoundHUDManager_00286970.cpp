// CB3HUDSoundManager::Slam(GtMathPs2::CGtV3d,CB3RaceCarPhysics*,CB3RaceCarPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling Shunt's scoped opt_optimizecontrolflow off [G] + goto-form out-of-line halving block).

// CB3HUDSoundManager::Slam(GtMathPs2::CGtV3d,CB3RaceCarPhysics*,CB3RaceCarPhysics*) -- hand-matched (s315) from the archive + the sibling Shunt's scoped pragma.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders, types [G] (instruction widths).

#include "b3/GtMathPs2.h"

// N182: retail compiled this function with `#pragma opt_optimizecontrolflow off` ([G] scoped to this function; same as the sibling Shunt).
#pragma push
#pragma opt_optimizecontrolflow off
using GtMathPs2::CGtV3d;
class CGtSoundVoiceParams;
class CGtSoundBank;
class CB3RaceCarPhysics;
class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);
    unsigned char pad_0[0x10];
};
class CB3SoundGameModeManager {
public:
    void TriggerSpotDucker(float);
    unsigned char pad_0[0x10];
};
struct UnkStruct_Slam_1 { unsigned char pad_0[0x1914]; void *field_1914; };
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0x13F4];
    UnkStruct_Slam_1 *field_13F4;
};
struct UnkStruct_Slam_V { float x, y, z; };
struct UnkStruct_Slam_P {
    float field_0;
    float field_4;
    float field_8;
    int pad_c;
    int pad_10;
    int pad_14;
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};
struct UnkStruct_D_004E0FEC { float field_0; };
extern UnkStruct_D_004E0FEC D_004E0FEC;
extern CGtSoundVoiceManager D_01E7569C;
extern CB3SoundGameModeManager D_01E77540;
struct UnkStruct_kw { unsigned long field_0; unsigned long pad; };
extern UnkStruct_kw kWaveIdSlam;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void SetBias__20CGtSoundVirtualVoiceFf(void *, float);
extern "C" void SetPriority__20CGtSoundVirtualVoiceFf(void *, float);
class CB3HUDSoundManager {
public:
    void Slam(CGtV3d, CB3RaceCarPhysics *, CB3RaceCarPhysics *);
    unsigned char pad_0[0x50];
    int field_50;
    unsigned char pad_54[0x8];
    float field_5C;
    unsigned char pad_60[0x18];
    CGtSoundBank *field_78;
};
// 0x00286970
void CB3HUDSoundManager::Slam(CGtV3d p0, CB3RaceCarPhysics *p1, CB3RaceCarPhysics *p2)
{
    CGtV3d pos;
    pos = p0;
    bool quiet = false;
    if (field_50 > 0) return;
    void *a = p2->field_13F4->field_1914;
    if (a != 0) {
        if (p1->field_13F4->field_1914 != 0) return;
    }
    if (a == 0) quiet = true;
    UnkStruct_Slam_P local;
    Construct__19CGtSoundVoiceParamsFv(&local);
    int *p = &local.field_18;
    *p = FindWave__12CGtSoundBankCFRCUlb(field_78, &kWaveIdSlam, true);
    float *q = &local.field_1C;
    *q = field_5C;
    local.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)*p);
    local.field_44 = 2;
    D_01E77540.TriggerSpotDucker(D_004E0FEC.field_0);
    CGtV3d tmp = pos;
    local.field_0 = ((UnkStruct_Slam_V *)&tmp)->x; local.field_4 = ((UnkStruct_Slam_V *)&tmp)->y; local.field_8 = ((UnkStruct_Slam_V *)&tmp)->z;
    if (quiet) goto half;
tail:
    {
    void *v = (void *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&local);
    if (v != 0) {
        SetBias__20CGtSoundVirtualVoiceFf(v, 0.75f);
        SetPriority__20CGtSoundVirtualVoiceFf(v, 1.0f);
    }
    }
    field_50 = 30;
    return;
half:
    *q = *q / 2.0f;
    goto tail;
}

#pragma pop
