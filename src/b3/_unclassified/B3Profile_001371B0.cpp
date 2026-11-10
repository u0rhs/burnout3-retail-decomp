// CB3Profile::EvaluateFavourites() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (one loop counter declared before the init-0 max accumulator (register order), reused by both loops).

// lifter variant 0
// CB3Profile::EvaluateFavourites() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Profile;
struct UnkStruct_gCalculatedData;

struct UnkStruct_gCalculatedData {
    int field_0;
    int field_4;
    float field_8;
    int field_C;
    float field_10;
};

class CB3Profile {
public:
    void EvaluateFavourites();

    unsigned char pad_0[0x48];
    int field_48[1];  // [G] element count unknown
    unsigned char pad_4C[0x1C0];
    float field_20C[1];  // [G] element count unknown
    unsigned char pad_210[0x90];
    float field_2A0[1];  // [G] element count unknown
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x001371B0
void CB3Profile::EvaluateFavourites()
{
    gCalculatedData.field_0 = -1;
    int i;
    int m0 = 0;
    for (i = 0; (i < 67); i++) {
        if ((unsigned int)m0 < (unsigned int)field_48[i]) {
            gCalculatedData.field_0 = i;
            m0 = field_48[i];
        }
    }
    gCalculatedData.field_4 = -1;
    gCalculatedData.field_8 = 0.0f;
    gCalculatedData.field_C = -1;
    gCalculatedData.field_10 = 0.0f;
    for (i = 0; (i < 36); i++) {
        float t0 = field_20C[i];
        if (gCalculatedData.field_8 < t0) {
            gCalculatedData.field_8 = t0;
            gCalculatedData.field_4 = i;
        }
        float t1 = field_2A0[i];
        if (gCalculatedData.field_10 < t1) {
            gCalculatedData.field_10 = t1;
            gCalculatedData.field_C = i;
        }
    }
}
