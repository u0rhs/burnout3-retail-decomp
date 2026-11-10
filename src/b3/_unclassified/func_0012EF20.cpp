// func_0012EF20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0012EF20;
struct UnkStruct_0012EF20_1;

struct UnkStruct_0012EF20_1 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
};

struct UnkStruct_0012EF20 {
    unsigned char pad_0[0x8];
    UnkStruct_0012EF20_1 * field_8;
};

// 0x0012EF20
extern "C" unsigned char func_0012EF20(UnkStruct_0012EF20 * self)
{
    UnkStruct_0012EF20_1 * t0 = self->field_8;
    unsigned char v0;
    if (t0 == 0) {
        v0 = 0;
    } else {
        v0 = t0->field_8;
    }
    return v0;
}
