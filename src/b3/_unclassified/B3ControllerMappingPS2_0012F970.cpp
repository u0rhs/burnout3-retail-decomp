// CB3ControllerMapping::GetBrake() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ControllerMappingPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: GetControlValue/func_00443820 branch, abs.s via asm helper, D_004E0C18/CD0 externs).

class CGtInputDevicePS2DualShock;
struct UnkStruct_0012F970;
struct UnkStruct_0012F970_1;

class CGtInputDevicePS2DualShock {
public:
    float GetControlValue(int);
};

struct UnkStruct_0012F970_1 {
    unsigned char pad_0[0x8];
    bool field_8;
};

struct UnkStruct_0012F970 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012F970_1 * field_8;
};

extern float D_004E0C18;
extern float D_004E0CD0;
// [G] MWCC b119 has no fabsf intrinsic: abs.s via inline asm (same helper as a70 AnyInput)
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00443820(UnkStruct_0012F970_1 *, int);

// 0x0012F970
extern "C" float GetBrake__20CB3ControllerMappingFv(UnkStruct_0012F970 * self)
{
    UnkStruct_0012F970_1 * t0 = self->field_8;
    bool b;
    if (t0 == 0) {
        b = false;
    } else {
        b = t0->field_8;
    }
    float v;
    if (b) {
        v = func_00443820(t0, 34);
    } else {
        v = self->field_4->GetControlValue(1);
        if (v > D_004E0C18) {
            v = 1.0f;
        }
        float g = self->field_4->GetControlValue(21);
        float h = g * (g * g * fabsf(g));
        if (h > D_004E0CD0) {
            v += h;
        }
    }
    if (v > 1.0f) {
        v = 1.0f;
    }
    return v;
}
