// func_0012F330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (float return clamped to 1.0f; unsigned int callee results; null-guarded byte as if/else).

// func_0012F330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0012F330;
struct UnkStruct_0012F330_1;

struct UnkStruct_0012F330_1 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
};

struct UnkStruct_0012F330 {
    unsigned char pad_0[0x4];
    int field_4;
    UnkStruct_0012F330_1 * field_8;
};

extern "C" unsigned int IsControlJustPressed__26CGtInputDevicePS2DualShockFi(void *, int);
extern "C" unsigned int func_004437F0(UnkStruct_0012F330_1 *, int);

// 0x0012F330
extern "C" float func_0012F330(UnkStruct_0012F330 * self)
{
    UnkStruct_0012F330_1 * p = self->field_8;
    unsigned char b;
    if (p == 0) {
        b = 0;
    } else {
        b = p->field_8;
    }
    float v;
    if (b) {
        if (p->field_9 != 0) {
            v = func_004437F0(p, 5);
        } else {
            v = func_004437F0(p, 19);
        }
    } else {
        v = IsControlJustPressed__26CGtInputDevicePS2DualShockFi((void *)(self->field_4), 0);
    }
    if (v > 1.0f) v = 1.0f;
    return v;
}
