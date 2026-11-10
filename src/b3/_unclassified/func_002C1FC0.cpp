// func_002C1FC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C1FC0;

struct UnkStruct_002C1FC0 {
    unsigned char field_0;
    unsigned char pad_1[0x1];
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0x8];
    short field_C;
    unsigned char pad_E[0x2];
    int field_10;
    short field_14;
};

extern "C" void func_0022D850(UnkStruct_002C1FC0 *);

// 0x002C1FC0
extern "C" void func_002C1FC0(UnkStruct_002C1FC0 * self, int p0, int p1, int p2)
{
    self->field_10 = p1;
    self->field_14 = p2;
    if ((self->field_0 & 2) == 2) {
        func_0022D850(self);
    } else {
    }
    self->field_3 = 3;
    self->field_C = p0;
    self->field_2 = 1;
    self->field_0 = (self->field_0 | 1);
}
