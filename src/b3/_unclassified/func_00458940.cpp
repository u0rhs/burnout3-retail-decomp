// func_00458940 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00458940;
struct UnkStruct_00458940_1;

struct UnkStruct_00458940_1 {
    unsigned char pad_0[0x28];
    float field_28;
};

struct UnkStruct_00458940 {
    UnkStruct_00458940_1 * field_0;
};

// 0x00458940
extern "C" void func_00458940(UnkStruct_00458940 * self, float f0)
{
    self->field_0->field_28 = (self->field_0->field_28 + f0);
}
