// func_002840D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (store-then-test call result as chained assignment: int r = local.field_18 = FindWave(...); (moves the &local.field_18 address calc before the call)).

// from build/vt\try_func_002840D0_best.cpp
// func_002840D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
struct UnkStruct_002840D0;
struct UnkStruct_002840D0_1;
struct UnkStruct_D_004BF218;
struct UnkStruct_D_004BF220;

class CGtSoundVoiceManager {
public:
    void TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002840D0_1 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    float field_28;
    unsigned char pad_2C[0x18];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_D_004BF218 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF220 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002840D0 {
    unsigned char pad_0[0x69];
    unsigned char field_69;
    unsigned char pad_6A[0x12];
    int field_7C;
};

extern UnkStruct_D_004BF218 D_004BF218;
extern CGtSoundVoiceManager D_01E7569C;
extern UnkStruct_D_004BF220 D_004BF220;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const

// 0x002840D0
extern "C" void func_002840D0(UnkStruct_002840D0 * self)
{
    UnkStruct_002840D0_1 local;  // [G] the frame's one local (size: up to the frame top)
    if (self->field_69 == 0) {
        Construct__19CGtSoundVoiceParamsFv(&local);
        int r1 = local.field_18 = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_7C, &D_004BF218, 0);

        if (r1 != 0) {
            local.field_1C = 0.5f;
            float r2 = CalcFrequency__12CGtSoundWaveCFv((void *)r1);
            local.field_44 = 1;
            local.field_24 = r2;
            local.field_28 = -1.0f;
            D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
        } else {
        }
        int r4 = local.field_18 = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_7C, &D_004BF220, 0);

        if (r4 != 0) {
            local.field_28 = 1.0f;
            D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
        } else {
        }
        self->field_69 = 20;
    }
}
