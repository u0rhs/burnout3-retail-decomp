// func_002C1C10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C1C10;

struct UnkStruct_002C1C10 {
    unsigned char pad_0[0x8204];
    unsigned char field_8204;
};

// 0x002C1C10
extern "C" void func_002C1C10(UnkStruct_002C1C10 * self)
{
    if (self->field_8204 == 0) return;
    self->field_8204 = 0;
}
