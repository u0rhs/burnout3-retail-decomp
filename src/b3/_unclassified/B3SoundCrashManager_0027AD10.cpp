// CB3SoundCrashManager::UpdateSteam() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'float t8;'; 'UnkStruct_281_v3 pos = *(UnkStruct_281_v3 *)&t; if (ph == 0)' -> 'UnkStruct_281_v3 * t5 = (UnkStruct_281_v3 *)&t; UnkStruct_281_v3 pos = *(t5); fo'; 'if (voice == 0) goto create; if (voice == 0) continue; if (f' -> 'if (!(field_860)) { goto create; } if (field_860 != 0) { } else { continue; } if'; 't2 = ph->field_B0;' -> 'GtMathPs2::CGtV4d * t9 = &ph->field_B0; t2 = (*t9); field_3E0).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_281_v3 { float x; float y; float z; };
struct UnkStruct_AB00_sub { unsigned char pad_0[0x1016]; unsigned char field_1016; };
struct UnkStruct_AB00_phys { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0xC04]; UnkStruct_AB00_sub *field_CC4; };
struct UnkStruct_AB00_car { unsigned char pad_0[0x30]; CGtV4d field_30; unsigned char pad_40[0x18AA]; unsigned char field_18EA; unsigned char pad_18EB[0xB45]; UnkStruct_AB00_phys *field_2430; unsigned char pad_2434[0x39C]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD50]; UnkStruct_AB00_car field_12AD50[1]; };
struct UnkStruct_AB00_params {
    UnkStruct_281_v3 field_0; UnkStruct_281_v3 field_C; void *field_18; float field_1C; float field_20; float field_24;
    unsigned char pad_28[0x1C]; unsigned char field_44; unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_01E7569C D_01E7569C;
extern float _grSteamGain;
struct UnkStruct_kB3SteamWaveID { unsigned long field_0; unsigned long pad; };
extern UnkStruct_kB3SteamWaveID kB3SteamWaveID;
extern int _gbForceSteam;
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
class CB3SoundCrashManager {
public:
    void UpdateSteam();
    unsigned char pad_0[0x3E0];
    UnkStruct_AB00_params field_3E0;
    unsigned char pad_430[0x840 - 0x430];
    void *field_840;
    unsigned char pad_844[0x860 - 0x844];
    void *field_860;
    unsigned char pad_864[0x880 - 0x864];
    void *field_880;
    unsigned char pad_884[0x8D2 - 0x884];
    signed char field_8D2;
    unsigned char pad_8D3[3];
    unsigned char field_8D6;
    unsigned char pad_8D7[8];
    unsigned char field_8DF;
};
// 0x0027AD10
void CB3SoundCrashManager::UpdateSteam()
{
    int i;
    int found;
    float t8;
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        found = 0;
        UnkStruct_AB00_car *car = (UnkStruct_AB00_car *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50);
        UnkStruct_AB00_phys *ph = car->field_2430;
        found = 0;
        CGtV4d t;
        t = car->field_30;
        UnkStruct_281_v3 * t5 = (UnkStruct_281_v3 *)&t;
        UnkStruct_281_v3 pos = *(t5);
        found = 0;
        if (ph != 0) {
        } else {
            continue;
        }
        UnkStruct_AB00_sub * t4 = ph->field_CC4;
        if (!(((((t4->field_1016 & 0xF)) != 0) && car->field_18EA != 0) || 0 != _gbForceSteam)) continue;
        found++;
        if (!(field_860)) {
            goto create;
        }
        if (field_860 != 0) {
        } else {
            continue;
        }
        if (field_8D2 == i) {
        } else {
            continue;
        }
        CGtV4d t2;
        GtMathPs2::CGtV4d * t9 = &ph->field_B0;
        t2 = (*t9);
        field_3E0.field_C = *(UnkStruct_281_v3 *)&t2;
        float g = _grSteamGain;
        float a = D_00522680.field_0;
        float k = 1.0f;
        float t1 = ((t8 = a - a)) / k;
        float t3 = k - t1;
        field_3E0.field_1C = ((t3) * g);
        float t12;
        float t13 = (k - ((((a - a))) / k)) * g;
        if (((t12 = t13)) <= 0.0f) {
            Stop__20CGtSoundVirtualVoiceFv(field_860);
            field_860 = 0;
        } else {
            field_3E0.field_0 = pos;
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_860, &field_3E0);
        }
        continue;
    create:
        field_840 = (void *)FindWave__12CGtSoundBankCFRCUlb(field_880, &kB3SteamWaveID, true);
        void *wave = field_840;
        float gain = _grSteamGain;
        if (field_8DF == 0) {
            Construct__19CGtSoundVoiceParamsFv(&field_3E0);
            field_3E0.field_0 = pos;
            field_3E0.field_1C = gain;
            field_3E0.field_45 = 1;
            field_3E0.field_18 = wave;
            field_3E0.field_24 = CalcFrequency__12CGtSoundWaveCFv(wave);
            field_3E0.field_44 = 3;
            field_860 = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &field_3E0);
        }
        field_8D2 = i;
        field_8D6 = 1;
    }
    if (found == 0) {
        if (field_860 != 0) {
            Stop__20CGtSoundVirtualVoiceFv(field_860);
            field_860 = 0;
        }
    }
}
