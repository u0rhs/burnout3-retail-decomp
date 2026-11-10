// CB3SoundCrashManager::PlayerCarHasBeenOnRamp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (.lit4 D_004E06B4 -> 0.7f literal).

// CB3SoundCrashManager::PlayerCarHasBeenOnRamp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceParams;

class CB3SoundCrashManager;
class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct UnkStruct_0027B770_0;
struct UnkStruct_D_004E06B4;
struct UnkStruct_D_00522680;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void SetPriority(float);
    void IgnoreGlobalPitch();
};

struct UnkStruct_0027B770_0 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E06B4 {
    float field_0;
};

class CB3SoundCrashManager {
public:
    void PlayerCarHasBeenOnRamp();

    unsigned char pad_0[0x85C];
    int field_85C;
    unsigned char pad_860[0x1C];
    CGtSoundVirtualVoice * field_87C;
    unsigned char pad_880[0x64];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x3];
    float field_8E8;
};

extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_004E06B4 D_004E06B4;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// 0x0027B770
void CB3SoundCrashManager::PlayerCarHasBeenOnRamp()
{
    UnkStruct_0027B770_0 local;
    Construct__19CGtSoundVoiceParamsFv(&local);
    if (field_8E4 == 0) {
        field_8E8 = D_00522680.field_0;
        local.field_18 = field_85C;
        local.field_1C = 0.7f;
        local.field_45 = 1;
        local.field_44 = 2;
        field_87C = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&local);
        field_87C->SetPriority(1.0f);
        if (field_87C != 0) {
            field_87C->IgnoreGlobalPitch();
        }
    }
    field_8E4 = 1;
}
