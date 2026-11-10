// func_00284650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two voice-param locals; int *p = &x.field_18; *p = FindWave(); if (*p) (func_00285A60 shape)).

// func_00284650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
struct UnkStruct_00284650;
struct UnkStruct_00284650_1;
struct UnkStruct_D_004BF240;
struct UnkStruct_D_004BF248;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00284650_1 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    float field_28;
    unsigned char pad_2C[0x18];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_D_004BF240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF248 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00284650 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    unsigned char pad_10[0xC];
    float field_1C;
    unsigned char pad_20[0x28];
    int field_48;
    unsigned char pad_4C[0x30];
    int field_7C;
};

extern UnkStruct_D_004BF240 D_004BF240;
extern CGtSoundVoiceManager D_01E7569C;
extern UnkStruct_D_004BF248 D_004BF248;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const

// 0x00284650
extern "C" void func_00284650(UnkStruct_00284650 * self)
{
    UnkStruct_00284650_1 a;
    UnkStruct_00284650_1 b;
    self->field_1C = 1.0f;
    if (self->field_8 == 0) {
        Construct__19CGtSoundVoiceParamsFv(&a);
        int * p = &a.field_18;
        *p = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_7C, &D_004BF240, 0);
        if (*p != 0) {
            a.field_1C = 1.0f;
            float r2 = CalcFrequency__12CGtSoundWaveCFv((void *)*p);
            a.field_44 = 1;
            a.field_24 = r2;
            a.field_45 = 1;
            a.field_28 = -1.0f;
            self->field_8 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&a);
        }
    }
    if (self->field_C == 0) {
        Construct__19CGtSoundVoiceParamsFv(&b);
        int * p = &b.field_18;
        *p = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_7C, &D_004BF248, 0);
        if (*p != 0) {
            b.field_1C = 1.0f;
            float r6 = CalcFrequency__12CGtSoundWaveCFv((void *)*p);
            b.field_44 = 1;
            b.field_24 = r6;
            b.field_45 = 1;
            b.field_28 = 1.0f;
            self->field_C = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&b);
        }
    }
    self->field_48 = 3600;
}
