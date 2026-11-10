// CB3SoundManager::SetSpeakerConfig(EB3SpeakerConfig) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (switch per case: if (field_7210 == K) return; field_7210 = K; break; then one shared field_1ED8->field_6A4 store).

// CB3SoundManager::SetSpeakerConfig(EB3SpeakerConfig) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3SpeakerConfig {};

class CB3SoundManager;
struct UnkStruct_0028AD10_1;

struct UnkStruct_0028AD10_1 {
    unsigned char pad_0[0x6A4];
    int field_6A4;
};

class CB3SoundManager {
public:
    void SetSpeakerConfig(EB3SpeakerConfig p0);

    unsigned char pad_0[0x1ED8];
    UnkStruct_0028AD10_1 * field_1ED8;
    unsigned char pad_1EDC[0x5330];
    int field_720C;
    int field_7210;
};

// 0x0028AD10
void CB3SoundManager::SetSpeakerConfig(EB3SpeakerConfig p0)
{
    field_720C = p0;
    switch (p0) {
    case 2:
        if (field_7210 == 2) return;
        field_7210 = 2;
        break;
    case 0:
        if (field_7210 == 1) return;
        field_7210 = 1;
        break;
    case 1:
        if (field_7210 == 4) return;
        field_7210 = 4;
        break;
    default:
        if (field_7210 == 1) return;
        field_7210 = 1;
        break;
    }
    field_1ED8->field_6A4 = field_7210;
}
