// CB3Score::GetRaceCheckpointTime(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (p0 < 0 (not <= -1); count in a local, guards merged with ||; field_2E8[p0 % 8]).

// CB3Score::GetRaceCheckpointTime(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Score;

class CB3Score {
public:
    float GetRaceCheckpointTime(int p0);

    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x2C4];
    int field_2DC;
    int field_2E0;
    unsigned char pad_2E4[0x4];
    float field_2E8[1];  // [G] element count unknown
};

// 0x0015A750
float CB3Score::GetRaceCheckpointTime(int p0)
{
    if (p0 < 0) {
        return -1.0f;
    }
    int n = field_2DC + field_14 * (field_2E0 + 1);
    if (n - p0 >= 8 || p0 >= n) {
        return -1.0f;
    }
    return field_2E8[p0 % 8];
}
