// CB3HUDComponent::SetAllLayerVisible(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element field_40 modelled as sub-struct at +0x14 (field_2C inside); hoisted local = &field_4[idx].field_14 then ->field_2C in loop (retail addiu base,0x14; lw 0x2C)).

// lifter variant 0
// CB3HUDComponent::SetAllLayerVisible(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HUDComponent;
struct UnkStruct_0019F420_e0;
struct UnkStruct_0019F420_e1;

struct UnkStruct_0019F420_e2 {
    unsigned char pad_0[0x2C];
    UnkStruct_0019F420_e1 * field_2C;
    unsigned char pad_30[0x2C];
};

struct UnkStruct_0019F420_e0 {
    unsigned char pad_0[0x14];
    UnkStruct_0019F420_e2 field_14;
};

struct UnkStruct_0019F420_e1 {
    int field_0;
    unsigned char pad_4[0xC];
};

class CB3HUDComponent {
public:
    void SetAllLayerVisible(bool p0);

    unsigned char pad_0[0x4];
    UnkStruct_0019F420_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    short field_12;
    unsigned char pad_14[0x8];
    signed char field_1C;
};

// 0x0019F420
void CB3HUDComponent::SetAllLayerVisible(bool p0)
{
    signed char t0 = field_1C;
    UnkStruct_0019F420_e2 * t1 = &field_4[t0].field_14;
    for (int i = field_10; (i < (field_10 + field_12)); i++) {
        UnkStruct_0019F420_e1 * t2 = t1->field_2C;
        int t3 = t2[i].field_0;
        if (p0) {
            t2[i].field_0 = (t3 & -2);
        } else {
            t2[i].field_0 = (t3 | 1);
        }
    }
}
