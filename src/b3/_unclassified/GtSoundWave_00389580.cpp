// CGtSoundWave::CalcFrequency() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundWave.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_10 is unsigned int; return (float) of it (MWCC unsigned->float idiom)).

// lifter variant 0
// CGtSoundWave::CalcFrequency() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundWave.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundWave;
struct UnkStruct_00389580_1;

struct UnkStruct_00389580_1 {
    unsigned char pad_0[0x10];
    unsigned int field_10;
};

class CGtSoundWave {
public:
    float CalcFrequency() const;

    unsigned char pad_0[0x8];
    UnkStruct_00389580_1 * field_8;
};

// 0x00389580
float CGtSoundWave::CalcFrequency() const
{
    return (float)field_8->field_10;
}
