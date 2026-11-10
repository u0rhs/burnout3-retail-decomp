// func_00427A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (missing float arg to func_00427D00).

// lifter variant 0
// func_00427A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00427A30;

struct UnkStruct_00427A30 {
    unsigned char pad_0[0xA4];
    float field_A4;
    unsigned char pad_A8[0x2C];
    unsigned char field_D4;
};

extern "C" void func_0042A4E0(UnkStruct_00427A30 *);
extern "C" void func_00427D00(UnkStruct_00427A30 *, float);
extern "C" void func_00427C30(UnkStruct_00427A30 *, float);
extern "C" void func_00429BE0(UnkStruct_00427A30 *, float);
extern "C" void UpdateMaskCarChangeState__19CB3CarViewComponentFf(UnkStruct_00427A30 *, float);

// 0x00427A30
extern "C" void func_00427A30(UnkStruct_00427A30 * self, float f0)
{
    self->field_A4 = (self->field_A4 + f0);
    func_0042A4E0(self);
    if (self->field_D4 != 0) {
        func_00427D00(self, f0);
        func_00427C30(self, f0);
    } else {
        func_00429BE0(self, f0);
    }
    if (self->field_D4 == 0) {
        UpdateMaskCarChangeState__19CB3CarViewComponentFf(self, f0);
    }
}
