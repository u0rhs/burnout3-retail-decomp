// CB3Score::IsAheadOfRoadRage(CB3Score*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool return + bool field; > vs < per slt at/v0; last compare as if/return true/return false).

class CB3Score;
struct UnkStruct_0015ADB0_2;

struct UnkStruct_0015ADB0_2 {
    unsigned char pad_0[0x1998];
    bool field_1998;
    unsigned char pad_1999[0x13];
    signed char field_19AC;
};

class CB3Score {
public:
    bool IsAheadOfRoadRage(CB3Score* p0);

    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x30];
    int field_9C;
    unsigned char pad_A0[0x28];
    UnkStruct_0015ADB0_2 * field_C8;
};

// 0x0015ADB0
bool CB3Score::IsAheadOfRoadRage(CB3Score* p0)
{
    UnkStruct_0015ADB0_2 * o = p0->field_C8;
    UnkStruct_0015ADB0_2 * m = field_C8;
    if (m->field_1998 != o->field_1998) {
        return m->field_1998;
    }
    if (field_68 > p0->field_68) {
        return true;
    }
    if (field_68 < p0->field_68) {
        return false;
    }
    if (field_9C < p0->field_9C) {
        return true;
    }
    if (field_9C > p0->field_9C) {
        return false;
    }
    if (o->field_19AC < m->field_19AC) {
        return true;
    }
    return false;
}
