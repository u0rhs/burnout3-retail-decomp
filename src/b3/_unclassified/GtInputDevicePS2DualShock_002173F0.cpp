// CGtInputDevicePS2DualShock::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void return; .lit4 floats as literals 0.2f/0.9f/0.1f).

// CGtInputDevicePS2DualShock::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    void Construct();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A[1];  // [G] element count unknown
    unsigned char pad_B[0x1B];
    unsigned char field_26[1];  // [G] element count unknown
    unsigned char pad_27[0x1B];
    unsigned char field_42;
    unsigned char field_43;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x1];
    int field_48[1];  // [G] element count unknown
    unsigned char pad_4C[0x6C];
    int field_B8[1];  // [G] element count unknown
    unsigned char pad_BC[0xC];
    float field_C8;
    float field_CC;
    float field_D0;
    float field_D4;
    float field_D8;
    float field_DC;
    float field_E0;
    int field_E4;
    int field_E8;
};


// 0x002173F0
void CGtInputDevicePS2DualShock::Construct()
{
    field_8 = 0;
    field_42 = 0;
    field_43 = 0;
    field_44 = 0;
    field_45 = 0;
    field_46 = 1;
    for (int i = 0; (i < 28); i++) {
        field_A[i] = 0;
        field_26[i] = 0;
        field_48[i] = 0;
    }
    int i1 = 0;
    goto loop1_test;
loop1_body:
    {
        field_B8[i1] = 0;
    }
    i1++;
loop1_test:
    if ((unsigned int)i1 < (unsigned int)4) goto loop1_body;
    field_9 = 0;
    field_C8 = 0.2f;
    field_CC = 0.9f;
    field_D0 = 0.1f;
    field_D4 = 0.9f;
    field_D8 = 0.1f;
    field_DC = 0.9f;
    field_E0 = 0.1f;
    field_E4 = 0;
    field_E8 = -1;
    field_4 = 3;
}
