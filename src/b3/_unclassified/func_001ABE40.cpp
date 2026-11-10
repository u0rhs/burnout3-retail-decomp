// func_001ABE40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001ABE40;

struct UnkStruct_001ABE40 {
    unsigned char pad_0[0x20E];
    unsigned char field_20E;
    unsigned char pad_20F[0x1];
    unsigned char field_210;
    unsigned char pad_211[0x7];
    unsigned char field_218;
};

// 0x001ABE40
extern "C" void func_001ABE40(UnkStruct_001ABE40 * self, int p0)
{
    if (self->field_210 != 0) return;
    self->field_218 = p0;
    self->field_210 = 1;
    self->field_20E = 0;
}
