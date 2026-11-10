// CGtSoundRealVoice::IsPlaying() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (case 0/1/3: return !(f == 3 || f == 1) != 0 (|| value, negated, explicitly compared: sltu/xori/andi/sltu chain)).

// CGtSoundRealVoice::IsPlaying() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundRealVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundRealVoice;
struct UnkStruct_003855F0_1;
struct UnkStruct_003855F0_2;

struct UnkStruct_003855F0_1 {
    unsigned char pad_0[0x30];
    UnkStruct_003855F0_2 * field_30;
};

struct UnkStruct_003855F0_2 {
    int field_0;
};

class CGtSoundRealVoice {
public:
    bool IsPlaying() const;

    unsigned char pad_0[0x14];
    UnkStruct_003855F0_1 * field_14;
    unsigned char field_18;
    unsigned char pad_19[0x2];
    unsigned char field_1B;
};

bool CGtSoundRealVoice::IsPlaying() const
{
    switch (field_18) {
    case 0:
    case 1:
    case 3:
        return !(field_14->field_30->field_0 == 3 || field_14->field_30->field_0 == 1) != 0;
    case 2:
        return (field_1B & 8) != 0;
    default:
        return 0;
    }
}
