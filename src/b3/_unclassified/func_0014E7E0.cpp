// func_0014E7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0014E7E0;
struct UnkStruct_0014E7E0_1;
struct UnkStruct_0014E7E0_a1;
struct UnkStruct_0014E7E0_a2;
struct UnkStruct_0014E7E0_a3;

struct UnkStruct_0014E7E0_1 {
    unsigned char pad_0[0x3A0];
    float field_3A0;
    float field_3A4;
    float field_3A8;
};

struct UnkStruct_0014E7E0_a1 {
    int field_0;
};

struct UnkStruct_0014E7E0_a2 {
    int field_0;
};

struct UnkStruct_0014E7E0_a3 {
    int field_0;
};

struct UnkStruct_0014E7E0 {
    unsigned char pad_0[0x564];
    UnkStruct_0014E7E0_1 * field_564;
};

// 0x0014E7E0
extern "C" void func_0014E7E0(UnkStruct_0014E7E0 * self, UnkStruct_0014E7E0_a1 * p0, UnkStruct_0014E7E0_a2 * p1, UnkStruct_0014E7E0_a3 * p2)
{
    p0->field_0 = ((int)self->field_564->field_3A8);
    p1->field_0 = ((int)self->field_564->field_3A4);
    p2->field_0 = ((int)self->field_564->field_3A0);
}
