// func_001AB000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001AB000;

struct UnkStruct_001AB000 {
    unsigned char pad_0[0x216];
    signed char field_216;
};

// 0x001AB000
extern "C" bool func_001AB000(UnkStruct_001AB000 * self)
{
    return ((~self->field_216) == 0);
}
