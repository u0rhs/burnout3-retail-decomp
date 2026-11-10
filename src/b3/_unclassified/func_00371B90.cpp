// func_00371B90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00371B90;

struct UnkStruct_00371B90 {
    unsigned char pad_0[0x6C0];
    int field_6C0;
    int field_6C4;
    int field_6C8[1];  // [G] element count unknown
    unsigned char pad_6CC[0x1C];
    int field_6E8[1];  // [G] element count unknown
    unsigned char pad_6EC[0x1C];
    int field_708;
    unsigned char pad_70C[0x4];
    int field_710;
    unsigned char field_714;
    signed char field_715;
};

// 0x00371B90
extern "C" void func_00371B90(UnkStruct_00371B90 * self)
{
    for (int i = 0; (i < 8); i++) {
        self->field_6C8[i] = 0;
        self->field_6E8[i] = 0;
    }
    self->field_714 = 0;
    self->field_708 = 0;
    self->field_710 = 0;
    self->field_6C0 = 1;
    self->field_6C4 = 0;
    self->field_715 = -1;
}
