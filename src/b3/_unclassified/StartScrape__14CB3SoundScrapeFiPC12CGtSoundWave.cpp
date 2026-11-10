// Hand-written; the lifter refused it (pos = *(const v3*)&t lane copy (no inline-return temp); merged || early return + separate field_3C return; (off + (int)this + 0x10) slot for addu order).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtSoundWave;
struct UnkStruct_002835C0_v3 { float x; float y; float z; };
struct UnkStruct_002835C0_params {
    UnkStruct_002835C0_v3 field_0; unsigned char pad_C[0xC];
    const CGtSoundWave *field_18; int field_1C; float field_20; float field_24; unsigned char pad_28[0x1D];
    unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_002835C0_voice { unsigned char pad_0[0xC]; int field_C; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E78A40 { float field_0[1]; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E7569C D_01E7569C;
extern UnkStruct_D_01E78A40 D_01E78A40;
extern UnkStruct_D_01E78A40 D_01E78A50;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" UnkStruct_002835C0_voice *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(const CGtSoundWave *);


class CB3SoundScrape {
public:
    void StartScrape(int, const CGtSoundWave *);
    CGtV4d field_0;
    UnkStruct_002835C0_voice *field_10[2];
    int field_18[2];
    int pad_20[3];
    float field_2C;
    unsigned char pad_30[0xC];
    unsigned char field_3C;
};

// 0x00283800
void CB3SoundScrape::StartScrape(int type, const CGtSoundWave *wave)
{
    if (field_2C < D_01E78A40.field_0[type] || field_2C < D_01E78A50.field_0[type]) return;
    if (field_3C == 0) return;
    UnkStruct_002835C0_params p;
    CGtV4d t;
    t = field_0;
    UnkStruct_002835C0_v3 pos = *(const UnkStruct_002835C0_v3 *)&t;  // [G] 12-byte lane copy (lwc1/swc1 x3)
    Construct__19CGtSoundVoiceParamsFv(&p);
    p.field_45 = 1;
    p.field_1C = 0;
    p.field_18 = wave;
    p.field_0 = pos;
    p.field_24 = CalcFrequency__12CGtSoundWaveCFv(wave);
    int off = type * 4;
    UnkStruct_002835C0_voice **slot = (UnkStruct_002835C0_voice **)(off + (int)this + 0x10);
    *slot = TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
    if (*slot != 0) {
        field_18[type] = (*slot)->field_C;
    }
}
