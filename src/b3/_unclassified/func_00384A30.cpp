// func_00384A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00384A30;
struct UnkStruct_00384A30_1;

struct UnkStruct_00384A30_1 {
    unsigned char pad_0[0x80];
    float field_80;
    unsigned char pad_84[0x4];
    int field_88;
};

struct UnkStruct_00384A30 {
    unsigned char pad_0[0x10];
    UnkStruct_00384A30_1 * field_10;
};

// 0x00384A30
extern "C" void func_00384A30(UnkStruct_00384A30 * self, float f0)
{
    self->field_10->field_80 = f0;
    self->field_10->field_88 = (self->field_10->field_88 | 32);
}
