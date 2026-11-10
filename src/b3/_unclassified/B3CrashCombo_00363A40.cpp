// CB3CrashCombo::AddPickupToCombo() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (ring index (x+1)%16; element pointer taken before field_100++ (forces 0x108 reload); pointer fields).

// lifter variant 0
// CB3CrashCombo::AddPickupToCombo() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CrashCombo;
struct UnkStruct_00363A40_e0;

struct UnkStruct_00363A40_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CB3CrashCombo {
public:
    void AddPickupToCombo();

    UnkStruct_00363A40_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0xF0];
    int field_100;
    int field_104;
    int field_108;
    UnkStruct_00363A40_e0 * field_10C;
    UnkStruct_00363A40_e0 * field_110;
    UnkStruct_00363A40_e0 * field_114;
    unsigned char field_118;
};

// 0x00363A40
void CB3CrashCombo::AddPickupToCombo()
{
    UnkStruct_00363A40_e0 * e = &field_0[field_108];
    field_100++;
    field_108 = (field_108 + 1) % 16;
    if (field_108 == field_104) {
        field_104 = (field_104 + 1) % 16;
    }
    if (field_110 == e) {
        field_110 = 0;
    }
    if (field_114 == e) {
        field_114 = 0;
    }
    field_118 = 1;
    field_10C = e;
    e->field_0 = 0;
    e->field_4 = 29;
    e->field_8 = 0;
    e->field_C = 0;
}
