// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// func_0027EC10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early returns; Min/Max clamp + lerps; position struct copied by value to a stack slot; field RNG step; 44=3 after CalcFrequency; .lit4 0.1f/0.85f literals).

// lifter variant 0
// func_0027EC10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_0027EC10;
struct UnkStruct_0027EC10_2;
struct UnkStruct_0027EC10_a1;
struct UnkStruct_D_004BEE10;
struct UnkStruct_D_004EE040;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    void TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027EC10_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027EC10_2 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    CGtSoundWave * field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    unsigned char pad_3C[0x8];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_0027EC10_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004BEE10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027EC10 {
    unsigned char pad_0[0x520];
    int field_520;
    int field_524;
    unsigned char pad_528[0xB8];
    float field_5E0;
    float field_5E4;
    float field_5E8;
    float field_5EC;
    float field_5F0;
    float field_5F4;
    unsigned char pad_5F8[0x288];
    int field_880;
    unsigned char pad_884[0x3F];
    signed char field_8C3;
    unsigned char pad_8C4[0x1B];
    unsigned char field_8DF;
};

extern UnkStruct_D_004BEE10 D_004BEE10;
extern UnkStruct_D_004EE040 D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int func_00131E40(void *);

// 0x0027EC10
extern "C" void func_0027EC10(UnkStruct_0027EC10 * self, const UnkStruct_0027EC10_a1 * p0, float f0)
{
    UnkStruct_0027EC10_a1 pos = *p0;
    UnkStruct_0027EC10_2 params;
    UnkStruct_0027EC10_v v;
    if (self->field_8DF != 0) return;
    if (f0 < self->field_5E0) return;
    if (self->field_8C3 != 0) return;
    self->field_8C3 = 4;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_5E0) / (self->field_5E4 - self->field_5E0), 0.0f), 1.0f);
    float vol = self->field_5E8 + t * (self->field_5EC - self->field_5E8);
    float pitch = self->field_5F0 + t * (self->field_5F4 - self->field_5F0);
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    params.field_1C = vol;
    params.field_20 = 1.0f;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEE10, 1);
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    pitch *= (1.0f + 0.1f * (2.0f * (2.3283064e-10f * (float)(unsigned int)self->field_520))) - 0.1f;
    params.field_24 = pitch * params.field_18->CalcFrequency();
    params.field_44 = 3;
    if (func_00131E40(&D_004EE040) != 0) {
        params.field_38 = 105.0f;
        params.field_1C *= 0.85f;
    } else {
        params.field_38 = 35.0f;
    }
    D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
}
