// CB3CrashCombo::GetNextItem() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element pointer taken first; ring index (x+15)%16 / (x+1)%16 as in AddPickupToCombo; early return 0 arms).

// CB3CrashCombo::GetNextItem() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CrashCombo;
struct UnkStruct_00363870_e0;

struct UnkStruct_00363870_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CB3CrashCombo {
public:
    UnkStruct_00363870_e0 * GetNextItem();

    UnkStruct_00363870_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0xF0];
    int field_100;
    int field_104;
    int field_108;
    unsigned char pad_10C[0x120];
    short field_22C;
    unsigned char field_22E;
};

// 0x00363870
UnkStruct_00363870_e0 * CB3CrashCombo::GetNextItem()
{
    if (field_100 == 0) {
        return 0;
    }
    UnkStruct_00363870_e0 * e = &field_0[field_22C];
    if (field_22E != 0) {
        if (field_22C == (field_104 + 15) % 16) {
            return 0;
        }
        field_22C = (field_22C + 15) % 16;
    } else {
        if (field_22C == field_108) {
            return 0;
        }
        field_22C = (field_22C + 1) % 16;
    }
    return e;
}
