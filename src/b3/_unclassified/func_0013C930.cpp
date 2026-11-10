// func_0013C930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013C930;

struct UnkStruct_0013C930 {
    unsigned char pad_0[0x1C0];
    int field_1C0[1];  // [G] element count unknown
};

// 0x0013C930
extern "C" int func_0013C930(UnkStruct_0013C930 * self, int p0)
{
    return self->field_1C0[p0];
}
