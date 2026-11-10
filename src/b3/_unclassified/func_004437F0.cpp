// func_004437F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004437F0;

struct UnkStruct_004437F0 {
    unsigned char pad_0[0xA];
    unsigned char field_A[1];  // [G] element count unknown
    unsigned char pad_B[0x22];
    unsigned char field_2D[1];  // [G] element count unknown
};

// 0x004437F0
extern "C" int func_004437F0(UnkStruct_004437F0 * self, int p0)
{
    int v0 = (self->field_2D[p0] != 0);
    if ((self->field_2D[p0] != 0) != false) {
        v0 = ((self->field_A[p0] != 0) ^ 1);
    }
    return v0;
}
