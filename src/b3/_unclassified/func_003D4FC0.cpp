// func_003D4FC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003D4FC0;

struct UnkStruct_003D4FC0 {
    unsigned char pad_0[0x150];
    float field_150;
    float field_154;
};

// 0x003D4FC0
extern "C" int func_003D4FC0(UnkStruct_003D4FC0 * self)
{
    int v0 = 1;
    if (self->field_150 < self->field_154) {
        v0 = 0;
    }
    return (v0 ^ 1);
}
