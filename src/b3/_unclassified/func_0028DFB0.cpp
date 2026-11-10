// func_0028DFB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0028DFB0;

struct UnkStruct_0028DFB0 {
    unsigned char pad_0[0x24];
    float field_24[1];  // [G] element count unknown
};

// 0x0028DFB0
extern "C" float func_0028DFB0(UnkStruct_0028DFB0 * self, int p0)
{
    return self->field_24[p0];
}
