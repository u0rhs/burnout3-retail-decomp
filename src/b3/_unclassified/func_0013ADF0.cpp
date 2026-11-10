// func_0013ADF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013ADF0;

struct UnkStruct_0013ADF0 {
    unsigned char pad_0[0x338];
    int field_338;
    unsigned char pad_33C[0x4];
    int field_340;
};

// 0x0013ADF0
extern "C" void func_0013ADF0(UnkStruct_0013ADF0 * self, int p0)
{
    if (p0 != 0) {
        self->field_338 = (self->field_338 + 1);
    } else {
        self->field_340 = (self->field_340 + 1);
    }
}
