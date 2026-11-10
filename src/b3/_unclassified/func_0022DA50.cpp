// func_0022DA50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022DA50;

struct UnkStruct_0022DA50 {
    unsigned char pad_0[0x70C];
    int field_70C;
};

// 0x0022DA50
extern "C" bool func_0022DA50(UnkStruct_0022DA50 * self)
{
    return (0 < self->field_70C);
}
