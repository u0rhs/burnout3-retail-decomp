// CB3SoundCrashManager::AirRam(GtMathPs2::CGtV3d,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

#include "b3/GtMathPs2.h"

// N182: retail compiled this function with `#pragma opt_dead_assignments off` (file-wide consistent: the file's other proven functions stay identical, build/vt/pragma/tucheck.py).
#pragma push
#pragma opt_dead_assignments off
using GtMathPs2::CGtV3d;
struct UnkStruct_0027B4C0_params {
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18; float field_1C; unsigned char pad_20[4];
    float field_24; unsigned char pad_28[0x1C];
    unsigned char field_44; unsigned char pad_45[0xB];
};
struct UnkStruct_0027B4C0_voice { unsigned char pad_0[0xC]; int field_C; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7569C D_01E7569C;
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[12]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern float D_004E0C18;
struct UnkStruct_kB3AirRamWaveID { unsigned long field_0; unsigned char pad_8[8]; };
extern UnkStruct_kB3AirRamWaveID kB3AirRamWaveID;
static inline void func_0027B4C0_inl1(UnkStruct_0027B4C0_params *p, CGtV3d v) { p->field_0 = ((float *)&v)[0]; p->field_4 = ((float *)&v)[1]; p->field_8 = ((float *)&v)[2]; }
extern unsigned char D_00522660[];
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const unsigned long *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" UnkStruct_0027B4C0_voice *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
class CB3SoundCrashManager {
public:
    void AirRam(CGtV3d, float, bool);
    unsigned int Next() {
        field_520 = (field_520 << 16) + (field_520 >> 16);
        field_520 = field_520 + field_524;
        field_524 = field_524 + field_520;
        return field_520;
    }
    unsigned char pad_0[0x520];
    int field_520;
    int field_524;
    unsigned char pad_528[0x34C];
    UnkStruct_0027B4C0_voice *field_874;
    unsigned char pad_878[8];
    void *field_880;
    unsigned char pad_884[0x18];
    float field_89C;
    float field_8A0;
    unsigned char pad_8A4[8];
    int field_8AC;
    unsigned char pad_8B0[0x26];
    unsigned char field_8D6;
    unsigned char pad_8D7[8];
    unsigned char field_8DF;
};
// 0x0027B4C0
void CB3SoundCrashManager::AirRam(CGtV3d p0, float f, bool b)
{
    CGtV3d pos = p0;
    UnkStruct_0027B4C0_params p;
    if (!b) return;
    {
        Construct__19CGtSoundVoiceParamsFv(&p);
        func_0027B4C0_inl1(&p, pos);
        p.field_18 = FindWave__12CGtSoundBankCFRCUlb(field_880, &kB3AirRamWaveID.field_0, true);
        p.field_1C = field_89C + f * (field_8A0 - field_89C);
        bool a = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            bool t = true;
            if (!a) {
                if (*((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C63A) == 0) t = false;
            }
            a = t;
        }
        if (!a) return;
        if (field_8DF != 0) p.field_1C *= 0.5f;
        float t = 2.0f * (2.3283064e-10f * (float)Next());
        float k = 1.5f * (1.0f + D_004E0C18 * t - D_004E0C18);
        p.field_24 = k * CalcFrequency__12CGtSoundWaveCFv((void *)(p.field_18));
        if (b && D_0064D3A0.field_0 == 1) {
            if (field_874 != 0) return;
            p.field_44 = 3;
            field_874 = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
            field_8D6 = 1;
            if (field_874 != 0) field_8AC = field_874->field_C;
        } else {
            p.field_44 = 3;
            field_874 = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
            if (field_874 != 0) {
                Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_874, &p);
                field_874 = 0;
            }
        }
    }
}

#pragma pop
