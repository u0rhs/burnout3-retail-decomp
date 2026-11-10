// func_0022DA20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022DA20;

struct UnkStruct_0022DA20 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};

// 0x0022DA20
extern "C" void func_0022DA20(UnkStruct_0022DA20 * self)
{
    self->field_0 = 0;
    self->field_4 = -1;
    self->field_8 = -1;
    self->field_1 = 255;
    self->field_C = 65535;
    self->field_3 = -1;
    self->field_2 = 0;
}
