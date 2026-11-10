// func_00285B00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (reference local to the wave field (int& w = local.field_18), assigned then tested/passed through it).

// from build/vt\try_func_00285B00_best.cpp
// func_00285B00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
struct UnkStruct_00285B00;
struct UnkStruct_00285B00_0;
struct UnkStruct_D_004BF258;
struct UnkStruct_D_004E1B00;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00285B00_0 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_D_004E1B00 {
    float field_0;
};

struct UnkStruct_D_004BF258 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00285B00 {
    unsigned char pad_0[0x78];
    int field_78;
};

extern UnkStruct_D_004E1B00 D_004E1B00;
extern UnkStruct_D_004BF258 D_004BF258;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const
extern "C" void IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::IgnoreGlobalPitch()

// 0x00285B00
extern "C" void func_00285B00(UnkStruct_00285B00 * self)
{
    UnkStruct_00285B00_0 local;  // [G] the frame's one local (size: up to the frame top)
    Construct__19CGtSoundVoiceParamsFv(&local);
    int & w = local.field_18;
    w = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_78, &D_004BF258, 0);
    if (w != 0) {
        local.field_1C = D_004E1B00.field_0;
        local.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)w);
        local.field_44 = 1;
        int r3 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
        if (r3 == 0) {
        } else {
            IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv((void *)r3);
            int r5 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
            if (r5 == 0) {
            } else {
                IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv((void *)r5);
            }
        }
    } else {
    }
}
