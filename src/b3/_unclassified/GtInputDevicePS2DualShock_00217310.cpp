// CGtInputDevicePS2DualShock::GetControlValue(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool range check).

class CGtInputDevicePS2DualShock {
public:
    float GetControlValue(int p0);
    unsigned char pad_0[0x48];
    float field_48[28];
};
// 0x00217310
float CGtInputDevicePS2DualShock::GetControlValue(int p0)
{
    bool v0 = p0 >= 0;
    if (v0) v0 = p0 < 28;
    if (v0 == false) return 0.0f;
    return field_48[p0];
}
