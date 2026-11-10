// func_0013AE20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013AE20;

struct UnkStruct_0013AE20 {
    unsigned char pad_0[0x334];
    int field_334;
    unsigned char pad_338[0x4];
    int field_33C;
};

// 0x0013AE20
extern "C" int func_0013AE20(UnkStruct_0013AE20 * self, int p0)
{
    int v0;
    if (p0 != 0) {
        v0 = self->field_334;
    } else {
        v0 = self->field_33C;
    }
    return v0;
}
