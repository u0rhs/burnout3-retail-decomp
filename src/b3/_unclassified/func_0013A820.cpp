// func_0013A820 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013A820;

struct UnkStruct_0013A820 {
    unsigned char pad_0[0x433];
    unsigned char field_433[1];  // [G] element count unknown
};

// 0x0013A820
extern "C" unsigned char func_0013A820(UnkStruct_0013A820 * self, int p0)
{
    return self->field_433[p0];
}
