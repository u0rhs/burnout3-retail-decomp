// CGtInputDevicePS2DualShock::DeadzoneAxis(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (clamp and scale the parameter p0 in place (no result temps); p0 > 0.0f guard).

// lifter variant 0
// CGtInputDevicePS2DualShock::DeadzoneAxis(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    float DeadzoneAxis(float p0, float p1);

    unsigned char pad_0[0xDC];
    float field_DC;
    float field_E0;
};

// 0x00216E40
float CGtInputDevicePS2DualShock::DeadzoneAxis(float p0, float p1)
{
    if (p0 > 0.0f) {
        float m = field_DC;
        if (p0 > m) {
            p0 = m;
        }
        float dz = field_E0 + p1;
        p0 -= dz;
        if (p0 < 0.0f) {
            p0 = 0.0f;
        }
        p0 *= 1.0f / (m - dz);
    } else {
        float m = field_DC;
        if (p0 < -m) {
            p0 = -m;
        }
        float dz = field_E0 + p1;
        p0 += dz;
        if (p0 > 0.0f) {
            p0 = 0.0f;
        }
        p0 *= 1.0f / (m - dz);
    }
    return p0;
}
