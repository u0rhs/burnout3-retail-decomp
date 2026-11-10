// SetOptionText__26CB3VOptionsSelectComponentFiUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BC5B0;
struct UnkStruct_003BC5B0_e0;

struct UnkStruct_003BC5B0_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x6];
};

struct UnkStruct_003BC5B0 {
    unsigned char pad_0[0x10];
    UnkStruct_003BC5B0_e0 * field_10;
};

extern float D_004CA2A0[];  // [G] element count unknown

extern "C" void func_003BD760(UnkStruct_003BC5B0 *, int, int, float);

// 0x003BC5B0
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(UnkStruct_003BC5B0 * self, int p0, int p1)
{
    UnkStruct_003BC5B0_e0 * t0 = self->field_10;
    unsigned char t1 = t0[p0].field_D;
    if (t1 != 0) {
        if (t1 != 6) {
            func_003BD760(self, p0, p1, D_004CA2A0[t1]);
        }
    }
}
