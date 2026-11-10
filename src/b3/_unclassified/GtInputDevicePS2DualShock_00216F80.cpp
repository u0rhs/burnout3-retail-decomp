// CGtInputDevicePS2DualShock::DeadzoneButton(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (clamp the float parameter in place (no copies)).

// CGtInputDevicePS2DualShock::DeadzoneButton(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    float DeadzoneButton(float p0);

    unsigned char pad_0[0xCC];
    float field_CC;
    float field_D0;
};

// 0x00216F80
float CGtInputDevicePS2DualShock::DeadzoneButton(float p0)
{
    if (p0 > field_CC) {
        p0 = field_CC;
    }
    p0 -= field_D0;
    if (p0 < 0.0f) {
        p0 = 0.0f;
    }
    return p0 * (1.0f / (field_CC - field_D0));
}
