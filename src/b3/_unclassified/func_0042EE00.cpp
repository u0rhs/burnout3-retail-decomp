// func_0042EE00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042EE00;

struct UnkStruct_0042EE00 {
    unsigned char pad_0[0x35C];
    signed char field_35C[1];  // [G] element count unknown
    unsigned char pad_35D[0xB];
    int field_368[1];  // [G] element count unknown
};

// 0x0042EE00
extern "C" int func_0042EE00(UnkStruct_0042EE00 * self, int p0)
{
    return (self->field_35C[p0] - self->field_368[p0]);
}
