// func_00272DD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00272DD0;
struct UnkStruct_00272DD0_a1;

struct UnkStruct_00272DD0_a1 {
    unsigned char pad_0[0x8];
    int field_8;
    float field_C;
    unsigned char pad_10[0x2C];
    float field_3C;
    unsigned char pad_40[0x28];
    int field_68;
    unsigned char pad_6C[0x18];
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    unsigned char pad_96[0x2];
    int field_98;
    unsigned char pad_9C[0x4];
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
};

struct UnkStruct_00272DD0 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    int field_4;
    float field_8;
    float field_C;
    int field_10;
    unsigned char pad_14[0x4];
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char pad_2A[0x2];
    int field_2C;
};

// 0x00272DD0
extern "C" void func_00272DD0(UnkStruct_00272DD0 * self, UnkStruct_00272DD0_a1 * p0)
{
    self->field_0 = 1;
    self->field_1 = p0->field_A0;
    self->field_2 = p0->field_A1;
    self->field_3 = p0->field_A2;
    self->field_4 = p0->field_8;
    self->field_8 = p0->field_C;
    self->field_C = p0->field_3C;
    self->field_10 = p0->field_68;
    self->field_1C = p0->field_88;
    self->field_18 = p0->field_84;
    self->field_20 = p0->field_8C;
    self->field_24 = p0->field_90;
    self->field_28 = p0->field_94;
    self->field_29 = p0->field_95;
    self->field_2C = p0->field_98;
}
