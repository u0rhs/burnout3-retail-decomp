// func_0013A7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013A7E0;

struct UnkStruct_0013A7E0 {
    unsigned char pad_0[0x447];
    unsigned char field_447[1];  // [G] element count unknown
};

// 0x0013A7E0
extern "C" unsigned char func_0013A7E0(UnkStruct_0013A7E0 * self, int p0)
{
    return self->field_447[p0];
}
