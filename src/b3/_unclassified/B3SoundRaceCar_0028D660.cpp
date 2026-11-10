// CB3SoundRaceCar::StartBoost(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C; early return on field_6C; g=car->field_1914 read right after the position quad).

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtSoundVoiceParams;
class CGtSoundVirtualVoice {
public:
    unsigned char pad_0[0xC];
    int field_C;
};
class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);
    unsigned char pad_0[0x10];
};
struct UnkStruct_SB_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x18D4];
    int field_1914;
};
struct UnkStruct_SB_P {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};
struct UnkStruct_SB_G { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_SB_F { float field_0; };
struct UnkStruct_SB_S {
    unsigned char pad_0[0x6C];
    CGtSoundVirtualVoice *field_6C;
    CGtSoundVirtualVoice *field_70;
    unsigned char pad_74[0x14];
    int field_88;
    float field_8C;
    unsigned char pad_90[0xC];
    int field_9C;
    int field_A0;
};
extern UnkStruct_SB_G D_00665E53;
extern UnkStruct_SB_F D_004E0764;
extern CGtSoundVoiceManager D_01E7569C;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void func_003872C0(CGtSoundVirtualVoice *, int, float, float, float, float, float, float);
extern "C" void func_0028D300(void *, UnkStruct_SB_a1 *);
extern "C" void StartBoost__15CB3SoundRaceCarFPC10CB3RaceCar(UnkStruct_SB_S *self, UnkStruct_SB_a1 *car)
{
    UnkStruct_SB_P params;
    u_long128 v;
    if (self->field_6C != 0) return;
    {
        Construct__19CGtSoundVoiceParamsFv(&params);
        v = car->field_30;
        int g = car->field_1914;
        params.field_0 = ((float *)&v)[0];
        params.field_4 = ((float *)&v)[1];
        params.field_8 = ((float *)&v)[2];
        if (g == 0) {
            if (D_00665E53.field_0 == 1) return;
            self->field_8C = 0.0f;
            params.field_44 = 1;
            params.field_1C = self->field_8C;
            params.field_45 = 1;
            params.field_18 = self->field_9C;
            self->field_6C = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
            if (self->field_6C == 0) return;
            func_003872C0(self->field_6C, 1, 1.0f, 1.0f, 1.0f, D_004E0764.field_0, 1.0f, 1.0f);
            self->field_88 = self->field_6C->field_C;
            params.field_18 = self->field_A0;
            self->field_70 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
            if (self->field_70 == 0) return;
            func_003872C0(self->field_70, 1, 1.0f, 1.0f, 1.0f, D_004E0764.field_0, 1.0f, 1.0f);
        }
        func_0028D300(self, car);
    }
}
