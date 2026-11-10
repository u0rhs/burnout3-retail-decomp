// Hand-written; the lifter refused it (N182 opt_propagation off + q declared before t).

// N182: retail compiled this function with `#pragma opt_propagation off` ([G] scoped to this function).
#pragma push
#pragma opt_propagation off

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtSoundVoiceParams;
class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    unsigned char pad_0[0xC];
    int field_C;
};
class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);
    unsigned char pad_0[0x10];
};
struct UnkStruct_BV_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x1184];
    float field_11C4;
    unsigned char pad_11C8[0x74C];
    int field_1914;
};
struct UnkStruct_SB_P {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};
struct UnkStruct_BV_F { float field_0; };
struct UnkStruct_BV_S {
    unsigned char pad_0[0x6C];
    CGtSoundVirtualVoice *field_6C;
    CGtSoundVirtualVoice *field_70;
    unsigned char pad_74[0x4];
    CGtSoundVirtualVoice *field_78;
    unsigned char pad_7C[0x8];
    int field_84;
    unsigned char pad_88[0x1C];
    void *field_A4;
    void *field_A8;
    unsigned char pad_AC[0x8];
    int field_B4;
};
class CB3Burn {
public:
    static float gmarBoostBarSizes[4];
};
extern UnkStruct_BV_F D_004E06B8;
extern UnkStruct_BV_F D_004E06AC;
extern UnkStruct_BV_F D_004E077C;
extern float _grAIBoostOutVol;
extern CGtSoundVoiceManager D_01E7569C;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
// 0x0028D1A0
extern "C" void func_0028D1A0(UnkStruct_BV_S *self, UnkStruct_BV_a1 *car)
{
    UnkStruct_SB_P params;
    u_long128 v;
    if (self->field_6C == 0 && self->field_70 == 0) return;
    if (self->field_6C != 0) {
        self->field_6C->ForgetMe(D_004E06B8.field_0);
        self->field_6C = 0;
    }
    if (self->field_70 != 0) {
        self->field_70->ForgetMe(D_004E06B8.field_0);
        self->field_70 = 0;
    }
    self->field_B4 = 0;
    Construct__19CGtSoundVoiceParamsFv(&params);
    v = car->field_30;
    float ratio = car->field_11C4 / CB3Burn::gmarBoostBarSizes[3];
    int g = car->field_1914;
    params.field_0 = ((float *)&v)[0];
    params.field_4 = ((float *)&v)[1];
    params.field_8 = ((float *)&v)[2];
    params.field_18 = (int)self->field_A8;
    if (g == 0) {
        float *q = &params.field_1C;
        float t = 0.0f + 0.25f + 0.25f * ratio;
        *q = t;
        params.field_24 = (0.0f + D_004E06AC.field_0 + D_004E077C.field_0 * (1.0f - ratio)) * CalcFrequency__12CGtSoundWaveCFv(self->field_A8);
    } else {
        params.field_1C = _grAIBoostOutVol;
    }
    params.field_44 = 1;
    params.field_45 = 0;
    self->field_78 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
    if (self->field_78 == 0) return;
    self->field_84 = self->field_78->field_C;
}

#pragma pop
