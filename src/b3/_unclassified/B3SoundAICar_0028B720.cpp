// CB3SoundAICar::UpdateBassVoices(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near26: pos/vel as 3-float struct copies (vel through a field pointer), early return in the forget arm, gain stored then clamped in place through a pointer).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"

class CB3RaceCar;
class CGtSoundVoiceParams;

class CB3SoundAICar;
class CGtSoundVirtualVoice;
struct UnkStruct_0028B720_2;
struct UnkStruct_0028B720_5;
struct UnkStruct_0028B720_e0;
struct UnkStruct_D_0055EFEC;

class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    void Update(const CGtSoundVoiceParams*);
};

struct UnkStruct_0028B720_3 {
    float field_0;
    float field_4;
    float field_8;
};

struct UnkStruct_0028B720_0 {
    UnkStruct_0028B720_3 field_0;
    UnkStruct_0028B720_3 field_C;
    void * field_18;
    float field_1C;
    unsigned char pad_20[0x30];
};

struct UnkStruct_0028B720_2 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};

struct CB3RaceCar {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x18D4];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0xA83];
    UnkStruct_0028B720_2 * field_2430;
};

struct UnkStruct_0028B720_5 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};

struct UnkStruct_0028B720_e0 {
    UnkStruct_0028B720_5 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0028B720_e0 field_0[1];  // [G] element count unknown
};

class CB3SoundAICar {
public:
    void UpdateBassVoices(const CB3RaceCar* p0);

    unsigned char pad_0[0x140];
    int field_140;
    unsigned char pad_144[0xC];
    CGtSoundVirtualVoice * field_150;
    CGtSoundVirtualVoice * field_154;
    int field_158;
    int field_15C;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0028B720
void CB3SoundAICar::UpdateBassVoices(const CB3RaceCar* p0)
{
    UnkStruct_0028B720_0 local;
    u_long128 pos1;
    u_long128 vel1;
    u_long128 pos2;
    u_long128 vel2;
    Construct__19CGtSoundVoiceParamsFv(&local);
    if (p0->field_1914 == 1) {
        pos1 = p0->field_30;
        local.field_0 = *(UnkStruct_0028B720_3 *)&pos1;
        vel1 = p0->field_2430->field_B0;
        UnkStruct_0028B720_3 * pv = &local.field_C;
        *pv = *(UnkStruct_0028B720_3 *)&vel1;
    } else {
        pos2 = p0->field_30;
        local.field_0 = *(UnkStruct_0028B720_3 *)&pos2;
        vel2 = D_0055EFEC.field_0[p0->field_19AC].field_0->field_B0;
        UnkStruct_0028B720_3 * pv = &local.field_C;
        *pv = *(UnkStruct_0028B720_3 *)&vel2;
    }
    int t12 = field_140;
    if (t12 <= 0) {
        if (field_150 != 0) {
            field_150->ForgetMe(0.5f);
            field_150 = 0;
            field_158 = 0;
        }
        if (field_154 != 0) {
            field_154->ForgetMe(0.5f);
            field_154 = 0;
            field_15C = 0;
        }
        field_140 = 0;
        return;
    }
    float *pg = &local.field_1C;
    *pg = (float)t12 / 30.0f;
    *pg = GtMath::Min(GtMath::Max(*pg, 0.0f), 1.0f);
    field_150->Update((const CGtSoundVoiceParams*)&local);
    field_154->Update((const CGtSoundVoiceParams*)&local);
}
