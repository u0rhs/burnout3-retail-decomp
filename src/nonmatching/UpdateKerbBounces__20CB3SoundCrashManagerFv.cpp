// NONMATCHING: UpdateKerbBounces__20CB3SoundCrashManagerFv -- retail 91 / ours 85 instructions, 28 in changed runs
// psweep: scoped #pragma opt_pulloutconstants off [G] improves 53 -> 52
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_pulloutconstants off
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_UpdateKerbBounces__20CB3SoundCrashManage_best.cpp
// CB3SoundCrashManager::UpdateKerbBounces() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CB3SoundCrashManager;
class CGtSoundVoiceManager;
struct UnkStruct_0027BF00_5;
struct UnkStruct_0027BF00_6;
struct UnkStruct_0027BF00_e0;
struct UnkStruct_0027BF00_e1;
struct UnkStruct_0027BF00_e2;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_kB3KerbBounceWaveID;

class CGtSoundVoiceManager {
public:
    void TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027BF00_e0 {
    unsigned char pad_0[0x30];
    UnkStruct_0027BF00_5 * field_30;
    unsigned char pad_34[0x279C];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12D150];
    UnkStruct_0027BF00_e0 field_12D150[1];  // [G] element count unknown
};

struct UnkStruct_0027BF00_e1 {
    unsigned char pad_0[0x92];
    unsigned char field_92;
    unsigned char pad_93[0x2D];
};

struct UnkStruct_0027BF00_e2 {
    unsigned char pad_0[0xA0];
    u_long128 field_A0;
    unsigned char pad_B0[0x10];
};

struct UnkStruct_0027BF00_5 {
    unsigned char pad_0[0x780];
    UnkStruct_0027BF00_e2 field_780[1];  // [G] element count unknown
    UnkStruct_0027BF00_e1 field_840[1];  // [G] element count unknown
};

struct UnkStruct_0027BF00_6 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0xC];
    int field_28;
    float field_2C;
    unsigned char pad_30[0x4];
    float field_34;
    unsigned char pad_38[0x1C];
    unsigned char field_54;
    unsigned char field_55;
    unsigned char pad_56[0xA];
};

struct UnkStruct_kB3KerbBounceWaveID {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashManager {
public:
    void UpdateKerbBounces();

    unsigned char pad_0[0x880];
    int field_880;
    unsigned char pad_884[0x5B];
    unsigned char field_8DF;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_kB3KerbBounceWaveID kB3KerbBounceWaveID;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const

// 0x0027BF00
void CB3SoundCrashManager::UpdateKerbBounces()
{
    UnkStruct_0027BF00_6 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_8DF != 0) {
        return;
    }
    for (int i = 0; (i < D_0064D3A0.field_0); i++) {
        int m0 = 0;
        do {
            if (D_00522660.field_12D150[i].field_30->field_840[m0].field_92 != 0) {
                Construct__19CGtSoundVoiceParamsFv(((char *)&local + 0x10));
                *(u_long128 *)&local.field_0 = D_00522660.field_12D150[i].field_30->field_780[m0].field_A0;
                float t0 = local.field_0;
                local.field_2C = 1.0f;
                float t1 = local.field_4;
                local.field_55 = 0;
                float t2 = local.field_8;
                local.field_10 = t0;
                local.field_14 = t1;
                local.field_18 = t2;
                int r1 = FindWave__12CGtSoundBankCFRCUlb((void *)field_880, &kB3KerbBounceWaveID, 1);
                local.field_28 = r1;
                float r2 = CalcFrequency__12CGtSoundWaveCFv((void *)r1);
                local.field_34 = r2;
                local.field_54 = 5;
                D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)((char *)&local + 0x10));
            } else {
            }
            m0 = (m0 + 1);
        } while (m0 < 4);
    }
}


#pragma pop
