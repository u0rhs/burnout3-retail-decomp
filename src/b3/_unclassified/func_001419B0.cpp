// func_001419B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001419B0;
struct UnkStruct_001419B0_1;

struct UnkStruct_001419B0_1 {
    unsigned char pad_0[0x1550];
    unsigned char field_1550;
};

struct UnkStruct_001419B0 {
    unsigned char pad_0[0x2430];
    UnkStruct_001419B0_1 * field_2430;
};

// 0x001419B0
extern "C" unsigned char func_001419B0(UnkStruct_001419B0 * self)
{
    UnkStruct_001419B0_1 * t0 = self->field_2430;
    unsigned char v0;
    if (t0 != 0) {
        v0 = t0->field_1550;
    } else {
        v0 = 0;
    }
    return v0;
}
