// CGtInputDevicePS2DualShock::DeadzoneTrigger(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (clamp by reassigning the float parameter p0 (not a copy)).

// CGtInputDevicePS2DualShock::DeadzoneTrigger(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    float DeadzoneTrigger(float p0);

    unsigned char pad_0[0xD4];
    float field_D4;
    float field_D8;
};

// 0x00216F10
float CGtInputDevicePS2DualShock::DeadzoneTrigger(float p0)
{
    float hi = field_D4;
    if (p0 > hi) {
        p0 = hi;
    }
    float lo = field_D8;
    p0 = p0 - lo;
    if (p0 < 0.0f) {
        p0 = 0.0f;
    }
    return p0 * (1.0f / (hi - lo));
}
