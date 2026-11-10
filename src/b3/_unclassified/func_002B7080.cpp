// func_002B7080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002B7080;
struct UnkStruct_002B7080_a1;

struct UnkStruct_002B7080_a1 {
    float field_0;
};

struct UnkStruct_002B7080 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    float field_10;
};

// 0x002B7080
extern "C" int func_002B7080(UnkStruct_002B7080 * self, UnkStruct_002B7080_a1 * p0)
{
    if ((self->field_0 & 1) != 1) {
        return 0;
    }
    p0->field_0 = self->field_10;
    self->field_0 = (self->field_0 & -2);
    return 1;
}
