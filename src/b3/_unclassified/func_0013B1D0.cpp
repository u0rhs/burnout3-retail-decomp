// IncreaseSlamTotal__10CB3ProfileFUib -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013B1D0;
struct UnkStruct_0013B1D0_e0;
struct UnkStruct_0013B1D0_e1;

struct UnkStruct_0013B1D0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0013B1D0_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0013B1D0 {
    unsigned char pad_0[0x204];
    UnkStruct_0013B1D0_e1 * field_204;
    UnkStruct_0013B1D0_e0 * field_208;
};

// 0x0013B1D0
extern "C" void IncreaseSlamTotal__10CB3ProfileFUib(UnkStruct_0013B1D0 * self, int p0, int p1)
{
    if (p1 != 0) {
        self->field_208 = (UnkStruct_0013B1D0_e0 *)&self->field_208[p0];
    } else {
        self->field_204 = (UnkStruct_0013B1D0_e1 *)&self->field_204[p0];
    }
}
