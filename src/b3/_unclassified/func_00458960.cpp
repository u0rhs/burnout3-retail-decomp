// func_00458960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00458960;

struct UnkStruct_00458960 {
    int field_0;
};

// 0x00458960
extern "C" bool func_00458960(UnkStruct_00458960 * self)
{
    return (self->field_0 != 0);
}
