// func_00199750 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00199750;

struct UnkStruct_00199750 {
    unsigned char pad_0[0x20];
    float field_20;
};

// 0x00199750
extern "C" float func_00199750(UnkStruct_00199750 * self)
{
    return (1800.0f - self->field_20);
}
