// func_00255C50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00255C50;

struct UnkStruct_00255C50 {
    float field_0;
    float field_4;
    int field_8;
};

// 0x00255C50
extern "C" int func_00255C50(UnkStruct_00255C50 * self)
{
    int v2 = 1;
    if (self->field_8 == 1) {
        int v0 = 1;
        if (self->field_0 <= (0.5f * self->field_4)) {
            v0 = 0;
        }
        v2 = v0;
    }
    return v2;
}
