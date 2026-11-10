// func_0012F240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sibling func_0012F610 shape: int v0 null-guard, nonzero-first ifs, sum accumulated with +=, clamp if (v > 1.0f)).

// lifter variant 0
// func_0012F240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtInputDevicePS2DualShock;
struct UnkStruct_0012F240;
struct UnkStruct_0012F240_1;

class CGtInputDevicePS2DualShock {
public:
    float GetControlValue(int);
};

struct UnkStruct_0012F240_1 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
};

struct UnkStruct_0012F240 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012F240_1 * field_8;
};

extern "C" float func_00443820(UnkStruct_0012F240_1 *, int);

// 0x0012F240
extern "C" float func_0012F240(UnkStruct_0012F240 * self)
{
    UnkStruct_0012F240_1 * t0 = self->field_8;
    int v0;
    if (t0 == 0) {
        v0 = 0;
    } else {
        v0 = t0->field_8;
    }
    float v;
    if (v0 != 0) {
        if (t0->field_9 != 0) {
            v = func_00443820(t0, 0);
        } else {
            v = func_00443820(t0, 22);
            v += func_00443820(self->field_8, 28);
            v += func_00443820(self->field_8, 29);
            v += func_00443820(self->field_8, 30);
            v += func_00443820(self->field_8, 31);
        }
    } else {
        v = self->field_4->GetControlValue(10);
    }
    if (v > 1.0f) {
        v = 1.0f;
    }
    return v;
}
