// CB3SoundESMLow::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_28 typed CGtSoundBank* (int-typed null test flips the branch); unsigned loop index).

// CB3SoundESMLow::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVirtualVoice;
class CGtSoundBank;

class CB3SoundESMLow;
class CGtSoundBankManager;
class CGtSoundVoiceManager;
struct UnkStruct_00287670_1;

class CGtSoundVoiceManager {
public:
    void FreeVirtualVoice(CGtSoundVirtualVoice*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00287670_1 {
    unsigned char pad_0[0x40];
    unsigned char field_40;
};

class CB3SoundESMLow {
public:
    void Release();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    unsigned char pad_4[0x24];
    CGtSoundBank * field_28;
    UnkStruct_00287670_1 * field_2C;
    int field_30;
    unsigned char pad_34[0x2C];
    int field_60[1];  // [G] element count unknown
};

extern CGtSoundVoiceManager D_01E7569C;
extern CGtSoundBankManager D_01E75648;

// 0x00287670
void CB3SoundESMLow::Release()
{
    vfunc_18();
    for (unsigned int i = 0; i < field_2C->field_40; i++) {
        D_01E7569C.FreeVirtualVoice((CGtSoundVirtualVoice*)field_60[i]);
        field_60[i] = 0;
    }
    if (field_28 != 0) {
        D_01E75648.UnloadBank(field_28);
        field_28 = 0;
    }
    field_2C = 0;
    field_30 = 0;
}
