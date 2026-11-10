// CGtScreenCentre::MoveScreen(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtScreenCentre.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (spilled %hi/%lo pairs: diff_vs_retail RESOLVED rule (a64)).

class CGtScreenCentre;

// [G] GS DISPLAY-style register: DX bits 0-11, DY bits 12-22 (the masks retail applies)
struct UnkStruct_002210A0_disp {
    unsigned int field_0 : 12;
    unsigned int field_0b : 11;
    unsigned int pad : 9;
};

struct UnkStruct__rwDMAFlipData {
    unsigned char pad_0[0x18];
    UnkStruct_002210A0_disp field_18;
    unsigned char pad_1C[0x24];
    UnkStruct_002210A0_disp field_40;
    unsigned char pad_44[0x2F4];
    UnkStruct_002210A0_disp field_338;
    unsigned char pad_33C[0xC];
    UnkStruct_002210A0_disp field_348;
    unsigned char pad_34C[0x1C];
    UnkStruct_002210A0_disp field_368;
    unsigned char pad_36C[0x24];
    UnkStruct_002210A0_disp field_390;
    unsigned char pad_394[0x14];
    UnkStruct_002210A0_disp field_3A8;
    unsigned char pad_3AC[0xC];
    UnkStruct_002210A0_disp field_3B8;
};

class CGtScreenCentre {
public:
    void MoveScreen(float p0, float p1);

    float field_0;
    float field_4;
    int field_8;
    int field_C;
};

extern UnkStruct__rwDMAFlipData _rwDMAFlipData;

// 0x002210A0
void CGtScreenCentre::MoveScreen(float p0, float p1)
{
    float sx = 2500;
    field_0 += p0;
    field_4 += p1;
    field_8 += (int)(sx * p0);
    field_C += (int)(450.0f * p1);
    _rwDMAFlipData.field_18.field_0 = field_8;
    _rwDMAFlipData.field_40.field_0 = field_8;
    _rwDMAFlipData.field_18.field_0b = field_C;
    _rwDMAFlipData.field_40.field_0b = field_C;
    _rwDMAFlipData.field_338.field_0 = field_8;
    _rwDMAFlipData.field_348.field_0 = field_8;
    _rwDMAFlipData.field_338.field_0b = field_C;
    _rwDMAFlipData.field_348.field_0b = field_C;
    _rwDMAFlipData.field_368.field_0 = field_8;
    _rwDMAFlipData.field_390.field_0 = field_8;
    _rwDMAFlipData.field_368.field_0b = field_C;
    _rwDMAFlipData.field_390.field_0b = field_C;
    _rwDMAFlipData.field_3A8.field_0 = field_8;
    _rwDMAFlipData.field_3B8.field_0 = field_8;
    _rwDMAFlipData.field_3A8.field_0b = field_C;
    _rwDMAFlipData.field_3B8.field_0b = field_C;
}
