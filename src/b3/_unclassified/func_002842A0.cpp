// func_002842A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGtRandom::Random() inline (GtRandom.h) through 'CGtRandom * const g' on a 16-byte global wrapper; ref local to params.field_18 assigned in the test; outer if-block).

// from build/vt\try_func_002842A0_best.cpp
// func_002842A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundVoiceParams;

class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct UnkStruct_002842A0;
struct UnkStruct_002842A0_1;
struct UnkStruct_D_004BF228;
struct UnkStruct_D_01E78A30;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void IgnoreGlobalPitch();
};

struct UnkStruct_002842A0_1 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x18];
    int field_40;
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_D_01E78A30 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF228 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002842A0 {
    unsigned char pad_0[0x4];
    CGtSoundVirtualVoice * field_4;
    unsigned char pad_8[0x74];
    int field_7C;
};


extern UnkStruct_D_004BF228 D_004BF228;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const

#include "b3/_unclassified/GtRandom.h"
struct UnkStruct_D_01E78A30_w {
    CGtRandom r;
    unsigned char pad_8[0x8];
};
extern UnkStruct_D_01E78A30_w D_01E78A30;
// 0x002842A0
extern "C" void func_002842A0(UnkStruct_002842A0 * self)
{
    UnkStruct_002842A0_1 local;
    if (self->field_4 == 0) {
    Construct__19CGtSoundVoiceParamsFv(&local);
    int & w = local.field_18;
    if ((w = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_7C, &D_004BF228, 0)) == 0) return;
    int r = w;
    local.field_1C = 0.25f;
    local.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)r);
    local.field_44 = 1;
    CGtRandom * const g = &D_01E78A30.r;
    local.field_40 = g->Random() % 80000;
    self->field_4 = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
    if (self->field_4 != 0) {
        self->field_4->IgnoreGlobalPitch();
    }
    }
}
