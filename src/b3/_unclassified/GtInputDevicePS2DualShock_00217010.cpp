// CGtInputDevicePS2DualShock::BindToPort(CGtInputManagerPS2Pad2*,EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool temps tested as 'a != false && b != false' (gives andi 0xFF per test)).

// CGtInputDevicePS2DualShock::BindToPort(CGtInputManagerPS2Pad2*,EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputManagerPS2Pad2;
enum EGtPS2InputPort {};

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    int BindToPort(CGtInputManagerPS2Pad2* p0, EGtPS2InputPort p1);

    unsigned char pad_0[0xE4];
    CGtInputManagerPS2Pad2 * field_E4;
    int field_E8;
};

// 0x00217010
int CGtInputDevicePS2DualShock::BindToPort(CGtInputManagerPS2Pad2* p0, EGtPS2InputPort p1)
{
    bool a = p0 != 0;
    bool b = false;
    if (p1 >= 0 && p1 < 2) b = true;
    if (a != false && b != false) {
        field_E4 = p0;
        field_E8 = p1;
        return 1;
    }
    return 0;
}
