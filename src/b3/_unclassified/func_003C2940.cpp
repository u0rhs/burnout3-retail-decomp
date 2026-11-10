// func_003C2940 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C2940;

struct UnkStruct_003C2940 {
    unsigned char pad_0[0xB0];
    unsigned char field_B0;
    unsigned char pad_B1[0x1];
    unsigned char field_B2;
};

// 0x003C2940
extern "C" int func_003C2940(UnkStruct_003C2940 * self)
{
    return (((self->field_B0 + 1) < self->field_B2) ^ 1);
}
