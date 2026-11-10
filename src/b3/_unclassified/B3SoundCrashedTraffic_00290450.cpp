// CB3SoundCrashedTraffic::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bank fields typed CGtSoundBank* (were int); plain if-blocks, no early return).

// CB3SoundCrashedTraffic::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashedTraffic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBank;

class CB3SoundCrashedTraffic;
class CGtSoundBankManager;
class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    void Stop();
};

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashedTraffic {
public:
    void Release();

    unsigned char pad_0[0x4];
    int field_4;
    CGtSoundBank * field_8;
    unsigned char pad_C[0xC];
    CGtSoundVirtualVoice * field_18;
    int field_1C;
    unsigned char pad_20[0x18];
    int field_38;
    unsigned char pad_3C[0x8];
    CGtSoundBank * field_44;
    unsigned char pad_48[0x4];
    CGtSoundVirtualVoice * field_4C;
    CGtSoundVirtualVoice * field_50;
    int field_54;
    int field_58;
};

extern CGtSoundBankManager D_01E75648;

// 0x00290450
void CB3SoundCrashedTraffic::Release()
{
    if (field_18 != 0) {
        field_18->Stop();
        field_18 = 0;
        field_1C = 0;
    }
    field_4 = 0;
    if (field_4C != 0) {
        field_4C->Stop();
        field_4C = 0;
        field_54 = 0;
    }
    if (field_50 != 0) {
        field_50->Stop();
        field_50 = 0;
        field_58 = 0;
    }
    field_38 = 0;
    if (field_44 != 0) {
        D_01E75648.UnloadBank(field_44);
        field_44 = 0;
    }
    if (field_8 != 0) {
        D_01E75648.UnloadBank(field_8);
        field_8 = 0;
    }
}
