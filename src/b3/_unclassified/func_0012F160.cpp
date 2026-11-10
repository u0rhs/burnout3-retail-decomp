// func_0012F160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool fields; null-guarded bool as if (t0 == 0) false else t0->field_8; += accumulation; if (v > 1.0f) clamp).

// func_0012F160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtInputDevicePS2DualShock;
struct UnkStruct_0012F160;
struct UnkStruct_0012F160_1;

class CGtInputDevicePS2DualShock {
public:
    float GetControlValue(int);
};

struct UnkStruct_0012F160_1 {
    unsigned char pad_0[0x8];
    bool field_8;
    bool field_9;
};

struct UnkStruct_0012F160 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012F160_1 * field_8;
};

extern "C" float func_00443820(UnkStruct_0012F160_1 *, int);

// 0x0012F160
extern "C" float func_0012F160(UnkStruct_0012F160 * self)
{
    UnkStruct_0012F160_1 * t0 = self->field_8;
    bool b;
    if (t0 == 0) {
        b = false;
    } else {
        b = t0->field_8;
    }
    float v;
    if (b) {
        if (t0->field_9) {
            v = func_00443820(t0, 1);
        } else {
            v = func_00443820(t0, 23);
            v += func_00443820(self->field_8, 17);
            v += func_00443820(self->field_8, 18);
            v += func_00443820(self->field_8, 16);
        }
    } else {
        v = self->field_4->GetControlValue(12);
    }
    if (v > 1.0f) {
        v = 1.0f;
    }
    return v;
}
