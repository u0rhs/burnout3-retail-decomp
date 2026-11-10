// func_00440770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00440770;

struct UnkStruct_00440770 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
};

// 0x00440770
extern "C" void func_00440770(UnkStruct_00440770 * self)
{
    self->field_8 = (self->field_8 - self->field_14);
    int t0 = self->field_C;
    if (self->field_8 < t0) {
        self->field_8 = t0;
    }
}
