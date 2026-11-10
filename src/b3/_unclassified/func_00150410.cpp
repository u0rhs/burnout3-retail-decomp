// func_00150410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element pointer local e=&D_004EE040.field_28E80[i] so the base is added before the large offset).

// lifter variant 0
// func_00150410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00150410;
struct UnkStruct_00150410_a1;
struct UnkStruct_00150410_e0;
struct UnkStruct_D_004EE040;

struct UnkStruct_00150410_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x2780];
    int field_27C0;
    unsigned char pad_27C4[0x5];
    unsigned char field_27C9;
};

struct UnkStruct_00150410_e0 {
    unsigned char pad_0[0x1A0];
    u_long128 field_1A0;
    unsigned char pad_1B0[0xA00];
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E80];
    UnkStruct_00150410_e0 field_28E80[1];  // [G] element count unknown
};

struct UnkStruct_00150410 {
    u_long128 field_0;
};

extern UnkStruct_D_004EE040 D_004EE040;

// 0x00150410
extern "C" void func_00150410(UnkStruct_00150410 * self, UnkStruct_00150410_a1 * p0)
{
    if (p0->field_27C9 != 0) {
        UnkStruct_00150410_e0 *e = &D_004EE040.field_28E80[p0->field_27C0];
        self->field_0 = e->field_1A0;
    } else {
        self->field_0 = p0->field_30;
    }
}
