// func_003933D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003933D0;

struct UnkStruct_003933D0 {
    unsigned char pad_0[0x40];
    int field_40;
};

// 0x003933D0
extern "C" bool func_003933D0(UnkStruct_003933D0 * self)
{
    return (self->field_40 == 4);
}
