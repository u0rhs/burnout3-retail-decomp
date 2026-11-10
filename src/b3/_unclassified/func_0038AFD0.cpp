// func_0038AFD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038AFD0;

struct UnkStruct_0038AFD0 {
    unsigned char pad_0[0x40];
    int field_40;
};

// 0x0038AFD0
extern "C" bool func_0038AFD0(UnkStruct_0038AFD0 * self)
{
    return (self->field_40 == 2);
}
