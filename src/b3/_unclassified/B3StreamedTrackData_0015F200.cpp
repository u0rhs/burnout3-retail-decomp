// CB3StreamedTrackHighData::FixUp(short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void* offset fields fixed through an element pointer; base address in a local before the test).

// lifter variant 0
// CB3StreamedTrackHighData::FixUp(short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StreamedTrackHighData;
struct UnkStruct_0015F200_e0;

struct UnkStruct_0015F200_e0 {
    unsigned char pad_0[0xC];
    void * field_C;
    unsigned char pad_10[0xC];
    void * field_1C;
    unsigned char pad_20[0x20];
};

class CB3StreamedTrackHighData {
public:
    void FixUp(short p0);

    unsigned char pad_0[0x50];
    short field_50;
    unsigned char pad_52[0x2];
    UnkStruct_0015F200_e0 * field_54;
    int field_58;
};

// 0x0015F200
void CB3StreamedTrackHighData::FixUp(short p0)
{
    char *base = (char *)&field_50;
    if (field_50 > 0) {
        field_54 = (UnkStruct_0015F200_e0 *)((char *)field_54 + (int)base);
        for (int i = 0; i < field_50; i++) {
            UnkStruct_0015F200_e0 * e = &field_54[i];
            if (e->field_C) {
                e->field_C = (char *)e->field_C + (int)e;
            }
            if (e->field_1C) {
                e->field_1C = (char *)e->field_1C + (int)e;
            }
        }
    }
    field_58 = 0;
}
