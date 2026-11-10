// func_00240D40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240D40;

struct UnkStruct_00240D40 {
    unsigned char field_0;
    unsigned char pad_1[0x2];
    unsigned char field_3;
    unsigned char pad_4[0x8];
    short field_C;
    unsigned char pad_E[0x2];
    float field_10;
    float field_14;
};

extern "C" void func_0022D850(UnkStruct_00240D40 *);

// 0x00240D40
extern "C" void func_00240D40(UnkStruct_00240D40 * self, int p0, float f0, float f1)
{
    if ((self->field_0 & 1) == 1) {
        return;
    }
    self->field_10 = f0;
    self->field_14 = f1;
    unsigned char t0 = self->field_0;
    if ((t0 & 2) == 2) {
        func_0022D850(self);
    } else {
    }
    self->field_3 = 1;
    self->field_C = p0;
    self->field_0 = (self->field_0 | 1);
}
