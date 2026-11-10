// func_0038D540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038D540;

struct UnkStruct_0038D540 {
    unsigned char pad_0[0x60];
    int field_60;
};

// 0x0038D540
extern "C" bool func_0038D540(UnkStruct_0038D540 * self)
{
    return (self->field_60 == 8);
}
