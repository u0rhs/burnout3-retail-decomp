// func_003C2E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C2E60;

struct UnkStruct_003C2E60 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned long field_8[1];  // [G] element count unknown
    unsigned char pad_10[0x20];
    unsigned long field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x20];
    int field_58[1];  // [G] element count unknown
    unsigned char pad_5C[0x1C];
    int field_78[1];  // [G] element count unknown
    unsigned char pad_7C[0x1C];
    unsigned char field_98[1];  // [G] element count unknown
    unsigned char pad_99[0x7];
    unsigned char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x7];
    unsigned char field_A8[1];  // [G] element count unknown
    unsigned char pad_A9[0x7];
    unsigned char field_B0;
    unsigned char field_B1;
    unsigned char field_B2;
    unsigned char field_B3;
    unsigned char field_B4;
};

extern "C" void func_003BA880();

// 0x003C2E60
extern "C" void func_003C2E60(UnkStruct_003C2E60 * self)
{
    func_003BA880();
    self->field_4 = 2;
    self->field_B4 = 0;
    for (int i = 0; (i < 5); i++) {
        self->field_8[i] = 0;
        self->field_30[i] = 0;
    }
    for (int i1 = 0; (i1 < 8); i1++) {
        self->field_58[i1] = 0;
        self->field_78[i1] = 0;
        self->field_98[i1] = 0;
        self->field_A0[i1] = i1;
        self->field_A8[i1] = i1;
    }
    self->field_B0 = 0;
    self->field_B1 = 0;
    self->field_B2 = 0;
    self->field_B3 = 0;
}
