// CB3SoundCrashedTraffic::StartBassVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (params (0x50) and position vector as two locals; reference locals to params.field_18 / field_24 declared at first use (wave ref before its store, freq ref between)).

// from build/vt\try_StartBassVoices__22CB3SoundCrashedTraffi_best.cpp
// CB3SoundCrashedTraffic::StartBassVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CB3SoundCrashedTraffic;
class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_00290320_0;
struct UnkStruct_00290320_2;
struct UnkStruct_00290320_3;
struct UnkStruct_00290320_5;
struct UnkStruct_00290320_6;
struct UnkStruct_D_004E1390;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00290320_0 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0xC];
    int field_28;
    int field_2C;
    unsigned char pad_30[0x4];
    float field_34;
    unsigned char pad_38[0x10];
    float field_48;
    float field_4C;
    unsigned char pad_50[0x5];
    unsigned char field_55;
    unsigned char pad_56[0xA];
};

struct UnkStruct_00290320_2 {
    unsigned char pad_0[0x204];
    UnkStruct_00290320_3 * field_204;
};

struct UnkStruct_00290320_3 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_004E1390 {
    float field_0;
};

struct UnkStruct_00290320_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00290320_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3SoundCrashedTraffic {
public:
    void StartBassVoices();

    UnkStruct_00290320_2 * field_0;
    unsigned char pad_4[0x44];
    CGtSoundWave * field_48;
    UnkStruct_00290320_5 * field_4C;
    UnkStruct_00290320_6 * field_50;
    int field_54;
    int field_58;
};

extern UnkStruct_D_004E1390 D_004E1390;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

struct UnkStruct_00290320_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_00290320_p {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    CGtSoundWave * field_18;
    int field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    float field_3C;
    unsigned char pad_40[0x5];
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

// 0x00290320
void CB3SoundCrashedTraffic::StartBassVoices()
{
    UnkStruct_00290320_p params;
    UnkStruct_00290320_v v;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = field_0->field_204->field_30;
    params.field_38 = 25.0f;
    params.field_3C = 5.0f;
    params.field_45 = 1;
    params.field_1C = 0;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    CGtSoundWave *& wave = params.field_18;
    wave = field_48;
    float & freq = params.field_24;
    freq = 2.0f * field_48->CalcFrequency();
    field_4C = (UnkStruct_00290320_5 *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
    wave = field_48;
    freq = D_004E1390.field_0 * field_48->CalcFrequency();
    field_50 = (UnkStruct_00290320_6 *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
    if (field_4C != 0) {
        field_54 = field_4C->field_C;
    }
    if (field_50 != 0) {
        field_58 = field_50->field_C;
    }
}
