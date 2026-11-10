// CB3Profile::EvaluateGameCounts() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (regrot: loop sum as (int)((unsigned)global + (unsigned)elem) -- unsigned add makes the result reuse the first operand's register (probe p21e)).


class CB3Profile;
struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
};
class CB3Profile {
public:
    void EvaluateGameCounts();

    unsigned char pad_0[0x154];
    int field_154[7];
    unsigned char pad_170[0x90];
    unsigned int field_200;
    unsigned int field_204;
    unsigned int field_208;
    unsigned char pad_20C[0x227];
    unsigned char field_433[20];
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x00136FA0
void CB3Profile::EvaluateGameCounts()
{
    unsigned int t0 = field_200;
    unsigned int t1 = field_208;
    if (t0 == t1) {
        gCalculatedData.field_14 = 50;
    } else {
        gCalculatedData.field_14 = (int)(100.0f * ((float)t1 / (float)(t1 + t0)));
    }
    gCalculatedData.field_20 = 0;
    for (int i = 0; i < 7; i++) {
        gCalculatedData.field_20 = (int)((unsigned)gCalculatedData.field_20 + (unsigned)field_154[i]);
    }
    int s = (gCalculatedData.field_20 -= field_200);
    unsigned int t4 = field_204;
    if (s == t4) {
        gCalculatedData.field_18 = 50;
    } else {
        gCalculatedData.field_18 = (int)(100.0f * ((float)t4 / (float)(t4 + s)));
    }
    gCalculatedData.field_1C = 0;
    for (int i1 = 0; i1 < 20; i1++) {
        if (field_433[i1] != 0) {
            gCalculatedData.field_1C = gCalculatedData.field_1C + 1;
        }
    }
}
