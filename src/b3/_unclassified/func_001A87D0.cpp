// func_001A87D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001A87D0;

struct UnkStruct_001A87D0 {
    unsigned char pad_0[0x2C];
    unsigned char field_2C;
};

// 0x001A87D0
extern "C" bool func_001A87D0(UnkStruct_001A87D0 * self)
{
    return ((self->field_2C & 4) != 0);
}
