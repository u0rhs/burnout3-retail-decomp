// func_00443820 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00443820;

struct UnkStruct_00443820 {
    unsigned char pad_0[0x50];
    float field_50[1];  // [G] element count unknown
};

// 0x00443820
extern "C" float func_00443820(UnkStruct_00443820 * self, int p0)
{
    return self->field_50[p0];
}
