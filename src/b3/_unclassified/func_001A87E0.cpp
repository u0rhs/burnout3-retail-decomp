// func_001A87E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001A87E0;

struct UnkStruct_001A87E0 {
    unsigned char field_0;
};

// 0x001A87E0
extern "C" void func_001A87E0(UnkStruct_001A87E0 * self)
{
    self->field_0 = (self->field_0 & -2);
}
