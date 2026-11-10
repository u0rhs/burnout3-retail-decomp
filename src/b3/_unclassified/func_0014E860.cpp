// func_0014E860 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0014E860;
struct UnkStruct_0014E860_1;

struct UnkStruct_0014E860_1 {
    unsigned char pad_0[0x3B8];
    int field_3B8;
};

struct UnkStruct_0014E860 {
    unsigned char pad_0[0x560];
    int field_560;
    UnkStruct_0014E860_1 * field_564;
};

// 0x0014E860
extern "C" int func_0014E860(UnkStruct_0014E860 * self)
{
    int v0 = 0;
    if (self->field_560 != 0) {
        v0 = self->field_564->field_3B8;
    }
    return v0;
}
