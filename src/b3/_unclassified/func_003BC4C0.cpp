// func_003BC4C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BC4C0;
struct UnkStruct_003BC4C0_e0;

struct UnkStruct_003BC4C0_e0 {
    unsigned char pad_0[0xC];
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[0x6];
};

struct UnkStruct_003BC4C0 {
    unsigned char pad_0[0x10];
    UnkStruct_003BC4C0_e0 * field_10;
};

extern float D_004CA2A0[];  // [G] element count unknown

extern "C" void func_003BD760(UnkStruct_003BC4C0 *, int, int, float);

// 0x003BC4C0
extern "C" void func_003BC4C0(UnkStruct_003BC4C0 * self, int p0, int p1)
{
    self->field_10[p0].field_C = p1;
    func_003BD760(self, p0, p1, D_004CA2A0[self->field_10[p0].field_D]);
}
