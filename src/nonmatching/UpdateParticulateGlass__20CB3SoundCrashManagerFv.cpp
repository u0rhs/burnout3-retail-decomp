// NONMATCHING: UpdateParticulateGlass__20CB3SoundCrashManagerFv -- retail 189 / ours 168 instructions, 163 in changed runs
// a253: lifter's duplicated branch removed (sequential 'if(!v){if(m1)start} if(v){...}' per retail L148 retest); params struct @0x60, two 16B temps; remaining: i*0x27D0 strength-reduced into s0 (retail recomputes mult), frame 0xC0 vs 0xB0, 168 vs 189 instrs (retail m1 4-lane loop not unrolled?)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3SoundCrashManager::UpdateParticulateGlass() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CB3SoundCrashManager;
class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_0027C070_5;
struct UnkStruct_0027C070_7;
struct UnkStruct_0027C070_e0;
struct UnkStruct_0027C070_e1;
struct UnkStruct_0027C070_e2;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;

class CGtSoundVirtualVoice {
public:
    void Update(const CGtSoundVoiceParams*);
    void Stop();

    unsigned char pad_0[0xC];
    int field_C;
};

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027C070_e0 {
    unsigned char pad_0[0x400];
    u_long128 field_400;
    unsigned char pad_410[0x18AA];
    unsigned char field_1CBA;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_0027C070_e1 {
    unsigned char pad_0[0x30];
    UnkStruct_0027C070_5 * field_30;
    unsigned char pad_34[0x279C];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_0027C070_e0 field_12A980[1];  // [G] element count unknown
    UnkStruct_0027C070_e1 field_12D150[1];  // [G] element count unknown
};

struct UnkStruct_0027C070_e2 {
    unsigned char pad_0[0x93];
    unsigned char field_93;
    unsigned char pad_94[0x2C];
};

struct UnkStruct_0027C070_5 {
    unsigned char pad_0[0x212];
    unsigned char field_212;
    unsigned char pad_213[0x62D];
    UnkStruct_0027C070_e2 field_840[1];  // [G] element count unknown
};

struct UnkStruct_0027C070_7 {
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
struct UnkVec_0027C070 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

class CB3SoundCrashManager {
public:
    void UpdateParticulateGlass();

    unsigned char pad_0[0x7CC];
    float field_7CC;
    unsigned char pad_7D0[0x4];
    int field_7D4;
    float field_7D8;
    float field_7DC;
    float field_7E0;
    float field_7E4;
    unsigned char pad_7E8[0x6C];
    CGtSoundWave * field_854;
    unsigned char pad_858[0xC];
    CGtSoundVirtualVoice * field_864;
    unsigned char pad_868[0x69];
    signed char field_8D1;
    unsigned char pad_8D2[0x7];
    unsigned char field_8D9;
    unsigned char pad_8DA[0x5];
    unsigned char field_8DF;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0027C070
void CB3SoundCrashManager::UpdateParticulateGlass()
{
    UnkStruct_0027C070_7 params;
    UnkVec_0027C070 tB;
    UnkVec_0027C070 tA;
    if (field_8DF != 0) {
        return;
    }
    int m0 = 0;
    for (int i = 0; i < D_0064D3A0.field_0; i++) {
        if (D_00522660.field_12A980[i].field_1CBA == 0) {
            continue;
        }
        m0++;
        int m1 = 1;
        if (D_00522660.field_12D150[i].field_30->field_212 != 0) {
            m1 = 0;
        }
        UnkStruct_0027C070_5 * t0 = D_00522660.field_12D150[i].field_30;
        for (int i1 = 0; i1 < 4; i1++) {
            if (t0->field_840[i1].field_93 != 0) {
                m1 = 0;
            }
        }
        CGtSoundVirtualVoice * v = field_864;
        if (v == 0) {
            if (m1 != 0) {
                field_7CC = 0.0f;
                Construct__19CGtSoundVoiceParamsFv(&params);
                params.field_45 = 1;
                *(u_long128 *)&tB = D_00522660.field_12A980[i].field_400;
                float y = tB.field_4;
                float z = tB.field_8;
                params.field_0 = tB.field_0;
                params.field_4 = y;
                params.field_8 = z;
                params.field_1C = field_7CC;
                params.field_18 = (int)field_854;
                params.field_24 = field_854->CalcFrequency();
                params.field_44 = 3;
                field_864 = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
                if (field_864 == 0) {
                    return;
                }
                field_8D9 = 0;
                field_7D4 = field_864->field_C;
                field_8D1 = i;
                continue;
            }
        }
        if (v != 0) {
            if (field_8D1 == i) {
                if (m1 == 0) {
                    field_7CC = (field_7CC - field_7E4);
                    field_8D9 = 0;
                    if (field_7CC < 0.0f) {
                        CGtSoundVirtualVoice * v2 = field_864;
                        if (v2 != 0) {
                            v2->Stop();
                            field_864 = 0;
                        }
                        continue;
                    }
                } else {
                    float f;
                    if (field_8D9 != 0) {
                        f = (field_7CC * field_7E0);
                    } else {
                        f = (field_7CC + field_7DC);
                    }
                    field_7CC = f;
                    if (!(field_7CC <= field_7D8)) {
                        field_8D9 = 1;
                        field_7CC = field_7D8;
                    }
                }
                Construct__19CGtSoundVoiceParamsFv(&params);
                *(u_long128 *)&tA = D_00522660.field_12A980[i].field_400;
                float y = tA.field_4;
                float z = tA.field_8;
                params.field_0 = tA.field_0;
                params.field_4 = y;
                params.field_8 = z;
                params.field_1C = field_7CC;
                field_864->Update((const CGtSoundVoiceParams*)&params);
            }
        }
    }
    if (m0 != 0) {
        return;
    }
    if (field_864 == 0) {
        return;
    }
    field_864->Stop();
    field_864 = 0;
}
