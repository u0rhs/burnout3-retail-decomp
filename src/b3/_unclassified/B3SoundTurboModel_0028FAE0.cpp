// CB3SoundTurboModel::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTurboModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_0 typed CGtSoundBank* and tested/passed directly (int field + cast tail-duplicated the stores)).

// CB3SoundTurboModel::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTurboModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBank;

class CB3SoundTurboModel;
class CGtSoundBankManager;

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundTurboModel {
public:
    void Release();

    CGtSoundBank * field_0;  // [G] pointer type: an int field cast at the call gives a tail-duplicated store pair
    int field_4;
};

extern CGtSoundBankManager D_01E75648;

// 0x0028FAE0
void CB3SoundTurboModel::Release()
{
    if (field_0 != 0) {
        D_01E75648.UnloadBank(field_0);
    }
    field_0 = 0;
    field_4 = 0;
}
