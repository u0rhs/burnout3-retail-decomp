// func_00285A60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (pointer local p=&local.field_18; store, test and pass *p (keeps the address in s0); TriggerVoice result null-tested as void*).

// func_00285A60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
struct UnkStruct_00285A60;
struct UnkStruct_00285A60_0;
struct UnkStruct_D_004BF250;
struct UnkStruct_D_004E1AFC;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00285A60_0 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_D_004E1AFC {
    float field_0;
};

struct UnkStruct_D_004BF250 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00285A60 {
    unsigned char pad_0[0x78];
    int field_78;
};

extern UnkStruct_D_004E1AFC D_004E1AFC;
extern UnkStruct_D_004BF250 D_004BF250;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const
extern "C" void IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv(void *);  // CGtSoundVirtualVoice::IgnoreGlobalPitch()

// 0x00285A60
extern "C" void func_00285A60(UnkStruct_00285A60 * self)
{
    UnkStruct_00285A60_0 local;  // [G] the frame's one local (size: up to the frame top)
    Construct__19CGtSoundVoiceParamsFv(&local);
    int * p = &local.field_18;
    *p = FindWave__12CGtSoundBankCFRCUlb((void *)self->field_78, &D_004BF250, 0);
    if (*p != 0) {
        local.field_1C = D_004E1AFC.field_0;
        local.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)*p);
        local.field_44 = 1;
        void * r3 = (void *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
        if (r3 != 0) {
            IgnoreGlobalPitch__20CGtSoundVirtualVoiceFv(r3);
        }
    }
}
