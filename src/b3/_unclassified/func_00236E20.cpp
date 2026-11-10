// func_00236E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00236E20;

struct UnkStruct_00236E20 {
    int field_0;
    unsigned char pad_4[0x4];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    int field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x1C];
    int field_4C;
    int field_50[1];  // [G] element count unknown
    unsigned char pad_54[0x1C];
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    unsigned char pad_80[0x4];
    int field_84;
    unsigned char pad_88[0xC];
    int field_94;
};

extern "C" void func_00234C30(void *);

// 0x00236E20
extern "C" void func_00236E20(UnkStruct_00236E20 * self)
{
    for (int i = 0; (i < 8); i++) {
        self->field_8[i] = 0;
        self->field_2C[i] = 0;
        self->field_50[i] = 0;
    }
    self->field_74 = 0;
    self->field_28 = 0;
    self->field_4C = 0;
    self->field_70 = 0;
    self->field_7C = 0;
    self->field_78 = -1;
    self->field_84 = 0;
    self->field_94 = 0;
    func_00234C30(((char *)self + 0x4E0));
    self->field_0 = 25;
}
