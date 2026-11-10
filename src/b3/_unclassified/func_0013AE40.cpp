// func_0013AE40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013AE40;

struct UnkStruct_0013AE40 {
    unsigned char pad_0[0x334];
    int field_334;
    unsigned char pad_338[0x4];
    int field_33C;
};

// 0x0013AE40
extern "C" void func_0013AE40(UnkStruct_0013AE40 * self, int p0)
{
    if (p0 != 0) {
        self->field_334 = (self->field_334 + 1);
    } else {
        self->field_33C = (self->field_33C + 1);
    }
}
