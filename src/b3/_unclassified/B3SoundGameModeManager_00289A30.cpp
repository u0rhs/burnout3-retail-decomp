// CB3SoundGameModeManager::CancelTakedownPitcher() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundManager {
public:
    void SetMasterPitchScalar(float);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundGameModeManager {
public:
    void CancelTakedownPitcher();

    unsigned char pad_0[0x52C0];
    int field_52C0;
};

extern CB3SoundManager D_01E75640;

// 0x00289A30
void CB3SoundGameModeManager::CancelTakedownPitcher()
{
    field_52C0 = 0;
    D_01E75640.SetMasterPitchScalar(1.0f);
}
