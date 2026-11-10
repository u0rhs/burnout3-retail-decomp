// func_00255EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00255EA0;

struct UnkStruct_00255EA0 {
    int field_0;
    float field_4;
    int field_8;
};

// 0x00255EA0
extern "C" void func_00255EA0(UnkStruct_00255EA0 * self)
{
    if (self->field_8 == 0) {
        self->field_8 = 1;
        self->field_0 = 0;
        self->field_4 = 0.5f;
    }
}
