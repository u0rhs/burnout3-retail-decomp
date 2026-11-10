// CB3CrashCombo::GetFirstItem(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sets the ring cursor ((x+15)%16) then returns an inlined copy of GetNextItem's body (static helper)).

// lifter variant 0
// CB3CrashCombo::GetFirstItem(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CrashCombo;
struct UnkStruct_00363930_e0;

struct UnkStruct_00363930_e0 {
    unsigned char pad_0[0x10];
};

class CB3CrashCombo {
public:
    void * GetFirstItem(bool p0);

    UnkStruct_00363930_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0xF0];
    int field_100;
    int field_104;
    int field_108;
    unsigned char pad_10C[0xF];
    unsigned char field_11B;
    unsigned char pad_11C[0x110];
    short field_22C;
    unsigned char field_22E;
};

// [L] inlined body of CB3CrashCombo::GetNextItem() (0x00363870, matched in B3CrashCombo_00363870.cpp): same
// shape; a static helper here so this unit does not redefine the member.
static inline void * func_00363930_inl1(CB3CrashCombo * c)
{
    if (c->field_100 == 0) {
        return 0;
    }
    UnkStruct_00363930_e0 * e = &c->field_0[c->field_22C];
    if (c->field_22E != 0) {
        if (c->field_22C == (c->field_104 + 15) % 16) {
            return 0;
        }
        c->field_22C = (c->field_22C + 15) % 16;
    } else {
        if (c->field_22C == c->field_108) {
            return 0;
        }
        c->field_22C = (c->field_22C + 1) % 16;
    }
    return e;
}
// 0x00363930
void * CB3CrashCombo::GetFirstItem(bool p0)
{
    if (field_11B != 0) {
        return 0;
    }
    if (p0) {
        field_22C = field_104;
        field_22E = 0;
    } else {
        field_22C = (field_108 + 15) % 16;
        field_22E = 1;
    }
    return func_00363930_inl1(this);
}
