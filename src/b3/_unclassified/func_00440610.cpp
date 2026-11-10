// func_00440610 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00440610;

struct UnkStruct_00440610 {
    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
    unsigned char pad_10[0x4];
    float field_14;
};

// 0x00440610
extern "C" float func_00440610(UnkStruct_00440610 * self)
{
    self->field_8 = (self->field_8 - self->field_14);
    float t0 = self->field_C;
    float t1 = self->field_8;
    if (t1 < t0) {
        self->field_8 = t0;
    }
    return t1;
}
