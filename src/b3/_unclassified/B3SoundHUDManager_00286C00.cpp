// CB3HUDSoundManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (fields typed CGtSoundBank* (int fields inverted the null tests)).

// CB3HUDSoundManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundHUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundBank;

class CB3HUDSoundManager;
class CGtSoundBankManager;

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDSoundManager {
public:
    void Release();

    unsigned char pad_0[0x78];
    CGtSoundBank * field_78;  // [L] passed straight to UnloadBank(CGtSoundBank*)
    CGtSoundBank * field_7C;
};

extern CGtSoundBankManager D_01E75648;

// 0x00286C00
// [L] the two banks are pointers: typed int, MWCC inverts both null tests.
void CB3HUDSoundManager::Release()
{
    if (field_78 != 0) {
        D_01E75648.UnloadBank(field_78);
        field_78 = 0;
    }
    if (field_7C != 0) {
        D_01E75648.UnloadBank(field_7C);
        field_7C = 0;
    }
}
