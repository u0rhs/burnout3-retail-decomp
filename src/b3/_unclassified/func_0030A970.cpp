// func_0030A970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0030A970;

struct UnkStruct_0030A970 {
    unsigned char pad_0[0x10];
    float field_10;
};

// 0x0030A970
extern "C" float func_0030A970(UnkStruct_0030A970 * self)
{
    float m0 = (self->field_10 - 1.0f);
    m0 = m0 * m0;
    return (1.0f - m0);
}
