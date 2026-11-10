// func_0028BF90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (voice-params blocks and u_long128 temps declared at function scope (frame order); position read from the 128-bit temp through a float pointer; field_68 into a local before the copy; phantom TriggerVoice arg dropped).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CGtSoundVirtualVoice {
public:
    int IsPlaying();
    void Update(const CGtSoundVoiceParams*);

    unsigned char pad_0[0xC];
    int field_C;
};

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028BF90_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x1068];
    int field_10A8;
};

// [G] the CGtSoundVoiceParams block filled on the stack (cf. CB3SoundAICar::StartBassVoices).
struct UnkStruct_0028BF90_2 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_0028BF90_3 {
    unsigned char pad_0[0x28];
    float field_28;
};

struct UnkStruct_D_004E078C {
    float field_0;
};

struct UnkStruct_0028BF90 {
    unsigned char pad_0[0x68];
    UnkStruct_0028BF90_3 * field_68;
    unsigned char pad_6C[0xD4];
    int field_140;
    unsigned char pad_144[0x40];
    int field_184;
    CGtSoundVirtualVoice * field_188;
    int field_18C;
};

extern UnkStruct_D_004E078C D_004E078C;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" void func_003872C0(CGtSoundVirtualVoice *, int, float, float, float, float, float, float);

// 0x0028BF90
extern "C" void func_0028BF90(UnkStruct_0028BF90 * self, UnkStruct_0028BF90_a1 * p0)
{
    UnkStruct_0028BF90_2 params1;
    UnkStruct_0028BF90_2 params2;
    u_long128 v1;
    u_long128 v2;
    int prev = self->field_140;
    if (prev != 0 && prev != -1 && prev < p0->field_10A8) {
        Construct__19CGtSoundVoiceParamsFv(&params1);
        UnkStruct_0028BF90_3 * t = self->field_68;
        v1 = p0->field_30;
        params1.field_1C = t->field_28;
        params1.field_18 = self->field_184;
        params1.field_0 = ((float *)&v1)[0];
        params1.field_4 = ((float *)&v1)[1];
        params1.field_44 = 4;
        params1.field_8 = ((float *)&v1)[2];
        self->field_188 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params1);
        if (self->field_188 != 0) {
            func_003872C0(self->field_188, 1, 1.0f, 1.0f, 0.0f, 0.0f, D_004E078C.field_0, D_004E078C.field_0);
            self->field_18C = self->field_188->field_C;
        }
    }
    self->field_140 = p0->field_10A8;
    if (self->field_188 != 0 && self->field_188->IsPlaying() && self->field_18C == self->field_188->field_C) {
        Construct__19CGtSoundVoiceParamsFv(&params2);
        v2 = p0->field_30;
        params2.field_0 = ((float *)&v2)[0];
        params2.field_4 = ((float *)&v2)[1];
        params2.field_8 = ((float *)&v2)[2];
        self->field_188->Update((const CGtSoundVoiceParams *)&params2);
    } else {
        self->field_188 = 0;
        self->field_18C = 0;
    }
}
