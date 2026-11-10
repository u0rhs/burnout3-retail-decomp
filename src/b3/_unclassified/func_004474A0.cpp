// func_004474A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004474A0;
struct UnkStruct_004474A0_a1;

struct UnkStruct_004474A0_a1 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
};

struct UnkStruct_004474A0 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
};

extern "C" void func_00447370(UnkStruct_004474A0 *);

// 0x004474A0
extern "C" int func_004474A0(UnkStruct_004474A0 * self, UnkStruct_004474A0_a1 * p0)
{
    self->field_0 = p0->field_0;
    self->field_4 = p0->field_4;
    self->field_8 = p0->field_8;
    self->field_C = p0->field_C;
    func_00447370(self);
    return 1;
}
