// func_00392440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00392440;

struct UnkStruct_00392440 {
    unsigned char pad_0[0x68];
    int field_68;
};

// 0x00392440
extern "C" bool func_00392440(UnkStruct_00392440 * self)
{
    return (self->field_68 == 8);
}
