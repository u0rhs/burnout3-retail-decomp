// CB3SoundCrashManager::UpdateFire() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'static inline bool func_0027AB00_inl1(const UnkStruct_AB00_car * a0) { const uns'; +'UnkStruct_AB00_sub * t10; UnkStruct_AB00_phys *ph; UnkStruct_0027AB00_pad pad;'; 'for (i = 0; i < D_0064D3A0.field_0; i++) {' -> 'bool t16; i = 0; float t7; if (found) { } for (; i < (D_0064D3A0.field_0 ^ 0); i'; 't = car->field_30; UnkStruct_AB00_phys *ph = car->field_2430' -> 't = (*car).field_30; ph = car->fi).

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
extern float _grFireGain;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
class CB3SoundCrashManager {
public:
    void UpdateFire();
    unsigned char pad_0[0x428];
    UnkStruct_AB00_params field_428;
    unsigned char pad_478[0x858 - 0x478];
    void *field_858;
    unsigned char pad_85C[0x878 - 0x85C];
    void *field_878;
    unsigned char pad_87C[0x8D5 - 0x87C];
    signed char field_8D5;
    unsigned char field_8D6;
    unsigned char pad_8D7[8];
    unsigned char field_8DF;
};
static inline bool func_0027AB00_inl1(const UnkStruct_AB00_car * a0)
{
    const unsigned char t14 = a0->field_18EA;
    return 0 != t14;
}

struct UnkStruct_0027AB00_pad { int x[1]; UnkStruct_0027AB00_pad() {} ~UnkStruct_0027AB00_pad() {} };  // [G] N140 frame pad (mwperm)
// 0x0027AB00
void CB3SoundCrashManager::UpdateFire()
{
    int i;
    UnkStruct_AB00_sub * t10;
    UnkStruct_AB00_phys *ph;
    UnkStruct_0027AB00_pad pad;
    int found;
    bool t16;
    i = 0;
    float t7;
    if (found) {
    }
    for (; i < (D_0064D3A0.field_0 ^ 0); i++) {
        found = 0;
        UnkStruct_AB00_car *car = &D_00522660.field_12AD50[i];
        found = 0;
        CGtV4d t;
        t = (*car).field_30;
        ph = car->field_2430;
        unsigned int t6;
        t10 = ph->field_CC4;
        unsigned char t15;
        unsigned char t17 = t10->field_1016;
        char t11 = (t15 = t17);
        unsigned char t5 = t11;
        UnkStruct_281_v3 pos = *((UnkStruct_281_v3 *)&t);
        t6 = t5 & 0xF0;
        if ((t6)) {
        } else continue;
        if (func_0027AB00_inl1(car)) {
        } else {
            continue;
        }
        found++;
        if (field_878 != 0) {
        } else {
            goto create;
        }
        if (!(field_878 == 0 || field_8D5 != i)) {
        } else {
            continue;
        }
        CGtV4d t2;
        float k = 1.0f;
        GtMathPs2::CGtV4d * t1;
        UnkStruct_AB00_phys * t3;
        UnkStruct_AB00_phys * t13;
        t2 = (*(t1 = &(t3 = (t13 = car->field_2430))->field_B0));
        field_428.field_C = *(UnkStruct_281_v3 *)&t2;
        float g = _grFireGain;
        float * t12 = &D_00522680.field_0;
        bool t4;
        t7 = (((((*t12) - (*t12))))) / k;
        if (1) {
            unsigned int t9;
            float t8;
            float t0;
            t8 = (t0 = 1.0f - t7);
            field_428.field_1C = (t9 = 0 == t7) ? ((1.0f - t7) * g) : (((k - t7)) * g);
            if ((t4 = (0, ((g * (t8)))) <= 0.0f)) {
                Stop__20CGtSoundVirtualVoiceFv(field_878);
                field_878 = 0;
            } else {
                field_428.field_0 = pos;
                Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_878, &field_428);
            }
        }
        continue;
    create:
        const float gain = ((float)_grFireGain);
        void *wave = field_858;
        t16 = _grFireGain;
        if (field_8DF == 0) {
            Construct__19CGtSoundVoiceParamsFv(&field_428);
            field_428.field_0 = pos;
            field_428.field_1C = gain;
            field_428.field_45 = 1;
            field_428.field_18 = wave;
            field_428.field_24 = CalcFrequency__12CGtSoundWaveCFv(wave);
            field_428.field_44 = 3;
            field_878 = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &field_428);
        }
        field_8D5 = i;
        field_8D6 = 1;
    }
    if (found == 0) {
        if (field_878 != 0) {
            Stop__20CGtSoundVirtualVoiceFv(field_878);
            field_878 = 0;
        }
    }
}
