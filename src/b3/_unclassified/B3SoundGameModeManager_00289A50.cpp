// CB3SoundGameModeManager::StartTakedownPitcher() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (D_004E1B80 sized (gp-rel); float *p=&local.field_1C; *p=0.5f; field_30=*p).

// CB3SoundGameModeManager::StartTakedownPitcher() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceParams;

class CB3SoundGameModeManager;
class CGtSoundRealVoice;
class CGtSoundVoiceManager;
struct UnkStruct_00289A50_0;
struct UnkStruct_D_004E1B80;
struct UnkStruct_D_01E75648;

class CGtSoundRealVoice {
public:
    void Stop();
};

class CGtSoundVoiceManager {
public:
    int TriggerRealVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00289A50_0 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x8];
    int field_28;
    int field_2C;
    float field_30;
    unsigned char pad_34[0x10];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_D_01E75648 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundGameModeManager {
public:
    void StartTakedownPitcher();

    unsigned char pad_0[0x52C0];
    float field_52C0;
    CGtSoundRealVoice * field_52C4;
};

struct UnkStruct_D_004E1B80 { unsigned long field_0; };
extern UnkStruct_D_004E1B80 D_004E1B80;
extern UnkStruct_D_01E75648 D_01E75648;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, void *, bool);  // CGtSoundBankManager::FindWave(const unsigned long&,bool) const

// 0x00289A50
void CB3SoundGameModeManager::StartTakedownPitcher()
{
    UnkStruct_00289A50_0 local;
    Construct__19CGtSoundVoiceParamsFv(&local);
    local.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &D_004E1B80, 0);
    float *p = &local.field_1C;
    local.field_28 = 0;
    *p = 0.5f;
    local.field_30 = *p;
    local.field_45 = 1;
    local.field_2C = 0;
    if (field_52C4 != 0) {
        field_52C4->Stop();
        field_52C4 = 0;
    }
    local.field_44 = 1;
    field_52C4 = (CGtSoundRealVoice *)D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams*)&local);
    field_52C0 = 3.0f;
}
