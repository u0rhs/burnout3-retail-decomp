// func_0012FB50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool callees, phantom a2 dropped from func_004437F0, '(t0 == 0 ? 0 : t0->field_8)' ternary, '(a | b) != 0' return).

// lifter variant 0
// func_0012FB50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtInputDevicePS2DualShock;
struct UnkStruct_0012FB50;
struct UnkStruct_0012FB50_1;

class CGtInputDevicePS2DualShock {
public:
    int IsConnected();
};

struct UnkStruct_0012FB50_1 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
};

struct UnkStruct_0012FB50 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012FB50_1 * field_8;
};

extern int D_00487B60[];  // [G] element count unknown
extern int D_00487BD0[];  // [G] element count unknown

extern "C" bool IsControlJustPressed__26CGtInputDevicePS2DualShockFi(CGtInputDevicePS2DualShock *, int);
extern "C" bool func_004437F0(UnkStruct_0012FB50_1 *, int);

// 0x0012FB50
extern "C" bool func_0012FB50(UnkStruct_0012FB50 * self, int p0)
{
    bool a = false;
    if (self->field_4->IsConnected() != 0) {
        a = IsControlJustPressed__26CGtInputDevicePS2DualShockFi(self->field_4, p0);
    }
    UnkStruct_0012FB50_1 * t0 = self->field_8;
    bool b = false;
    if ((t0 == 0 ? 0 : t0->field_8) != 0) {
        int v4 = t0->field_9 != 0 ? D_00487B60[p0] : D_00487BD0[p0];
        if (v4 != -1) {
            b = func_004437F0(t0, v4);
        }
    }
    return (a | b) != 0;
}
