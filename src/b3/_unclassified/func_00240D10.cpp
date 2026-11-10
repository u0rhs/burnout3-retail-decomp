// func_00240D10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240D10;

struct UnkStruct_00240D10 {
    unsigned char pad_0[0x20];
    unsigned char field_20;
};

// 0x00240D10
extern "C" void * func_00240D10(UnkStruct_00240D10 * self)
{
    void * v0;
    if ((self->field_20 & 1) == 1) {
        v0 = ((char *)self + 0x20);
    } else {
        v0 = 0;
    }
    return v0;
}
