// CB3TrafficParam::RemoveFromTrafficLights() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sub-struct at element+4 reached through a hoisted pointer; pointer-to-element local for the byte test/store).

// CB3TrafficParam::RemoveFromTrafficLights() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficParam;
struct UnkStruct_00161310_1;
struct UnkStruct_00161310_4;
struct UnkStruct_00161310_e0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00527440;

struct UnkStruct_D_00527440 {
    UnkStruct_00161310_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00161310_1 {
    unsigned char pad_0[0x38];
    int field_38;
};

struct UnkStruct_00161310_e0_s {
    UnkStruct_00161310_4 * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[4];  // [G] element count unknown
};

struct UnkStruct_00161310_e0 {
    unsigned char pad_0[0x4];
    UnkStruct_00161310_e0_s field_4;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x165A8];
    UnkStruct_00161310_e0 field_165A8[1];  // [G] element count unknown
};

struct UnkStruct_00161310_4 {
    unsigned char pad_0[0x15];
    unsigned char field_15;
};

class CB3TrafficParam {
public:
    void RemoveFromTrafficLights();

    unsigned char pad_0[0x49];
    unsigned char field_49;
};

extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_00522660 D_00522660;

// 0x00161310
void CB3TrafficParam::RemoveFromTrafficLights()
{
    int n = D_00527440.field_0->field_38;
    for (int i = 0; i < n; i++) {
        UnkStruct_00161310_e0_s * s = &D_00522660.field_165A8[i].field_4;
        int m = s->field_0->field_15;
        for (int j = 0; j < m; j++) {
            unsigned char * p = &s->field_10[j];
            if (*p == field_49) {
                *p = 255;
                return;
            }
        }
    }
}
