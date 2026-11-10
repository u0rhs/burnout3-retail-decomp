// CGtInputDevicePS2DualShock::UpdateVibration() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: bool field_8, field_E8 typed EGtPS2InputPort (no cast: a1 loaded before a0), if/else-if with block-scoped profile/data locals).

// lifter variant 0
// CGtInputDevicePS2DualShock::UpdateVibration() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtPS2InputPort {};

class CGtInputDevicePS2DualShock;
class CGtInputManagerPS2Pad2;
struct UnkStruct_00217070_1;

class CGtInputManagerPS2Pad2 {
public:
    int GetConnectedDeviceID(EGtPS2InputPort);
    int GetSocketNumber(EGtPS2InputPort);
};

struct UnkStruct_00217070_1 {
    short field_0;
    short field_2;
    unsigned char field_4;
    unsigned char field_5;
};

class CGtInputDevicePS2DualShock {
public:
    void UpdateVibration();

    unsigned char pad_0[0x4];
    int field_4;
    bool field_8;
    unsigned char field_9;
    unsigned char pad_A[0x38];
    unsigned char field_42;
    unsigned char field_43;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x9D];
    CGtInputManagerPS2Pad2 * field_E4;
    EGtPS2InputPort field_E8;
};

extern "C" void sceVibSetActParam(int, int, void *, int, void *);

// 0x00217070
void CGtInputDevicePS2DualShock::UpdateVibration()
{
    if (field_E4 == 0) return;
    field_8 = field_4 == field_E4->GetConnectedDeviceID(field_E8);
    if (!field_8) {
        field_9 = 0;
        field_43 = 0;
        field_45 = 0;
        return;
    }
    unsigned char t = field_46;
    if (t != 0 && (field_43 != field_42 || field_45 != field_44)) {
        unsigned char p;
        short d;
        p = 3;
        d = (((short)field_43) << 1) + field_45;
        sceVibSetActParam(field_E4->GetSocketNumber(field_E8), 1, &p, 2, &d);
        field_42 = field_43;
        field_44 = field_45;
    } else if (t == 0 && (field_42 > 0 || field_44 != 0)) {
        unsigned char p;
        short d;
        d = 0;
        p = 3;
        sceVibSetActParam(field_E4->GetSocketNumber(field_E8), 1, &p, 2, &d);
        field_42 = 0;
        field_44 = 0;
        field_43 = 0;
        field_45 = 0;
    }
}
