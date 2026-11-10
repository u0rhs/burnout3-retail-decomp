// func_00440730 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00440730;

struct UnkStruct_00440730 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
    int field_14;
};

// 0x00440730
extern "C" void func_00440730(UnkStruct_00440730 * self)
{
    self->field_8 = (self->field_8 + self->field_14);
    int t0 = self->field_10;
    if (self->field_8 > t0) {
        self->field_8 = t0;
    }
}
