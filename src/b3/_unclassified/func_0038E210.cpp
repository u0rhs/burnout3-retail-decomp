// func_0038E210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038E210;

struct UnkStruct_0038E210 {
    unsigned char pad_0[0x60];
    int field_60;
};

// 0x0038E210
extern "C" bool func_0038E210(UnkStruct_0038E210 * self)
{
    return (self->field_60 == 9);
}
