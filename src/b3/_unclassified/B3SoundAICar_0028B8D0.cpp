// CB3SoundAICar::StartBassVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pointer-to-field locals declared at first use (field_18/24/44)).

// CB3SoundAICar::StartBassVoices() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceParams;

class CB3SoundAICar;
class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_0028B8D0_0;
struct UnkStruct_0028B8D0_3;
struct UnkStruct_0028B8D0_4;
struct UnkStruct_D_004E0794;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028B8D0_0 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    float field_3C;
    unsigned char pad_40[0x4];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_D_004E0794 {
    float field_0;
};

struct UnkStruct_0028B8D0_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0028B8D0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3SoundAICar {
public:
    void StartBassVoices();

    unsigned char pad_0[0x148];
    CGtSoundWave * field_148;
    CGtSoundWave * field_14C;
    UnkStruct_0028B8D0_3 * field_150;
    UnkStruct_0028B8D0_4 * field_154;
    int field_158;
    int field_15C;
};

extern UnkStruct_D_004E0794 D_004E0794;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0028B8D0
void CB3SoundAICar::StartBassVoices()
{
    UnkStruct_0028B8D0_0 local;
    Construct__19CGtSoundVoiceParamsFv(&local);
    local.field_1C = 0;
    local.field_38 = 35.0f;
    local.field_3C = 5.0f;
    local.field_45 = 1;
    int *p18 = &local.field_18;
    *p18 = (int)field_148;
    float *p24 = &local.field_24;
    *p24 = field_148->CalcFrequency();
    unsigned char *p44 = &local.field_44;
    *p44 = 12;
    field_150 = (UnkStruct_0028B8D0_3 *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
    *p18 = (int)field_14C;
    float r3 = field_14C->CalcFrequency();
    *p44 = 12;
    *p24 = D_004E0794.field_0 * r3;
    field_154 = (UnkStruct_0028B8D0_4 *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
    if (field_150 != 0) {
        field_158 = field_150->field_C;
    }
    if (field_154 != 0) {
        field_15C = field_154->field_C;
    }
}
