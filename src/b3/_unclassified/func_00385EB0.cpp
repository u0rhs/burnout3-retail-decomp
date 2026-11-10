// func_00385EB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00385EB0;

struct UnkStruct_00385EB0 {
    unsigned char pad_0[0x1ED];
    unsigned char field_1ED;
};

// 0x00385EB0
extern "C" void func_00385EB0(UnkStruct_00385EB0 * self)
{
    self->field_1ED = (self->field_1ED | 16);
}
