// func_00392330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00392330;

struct UnkStruct_00392330 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x1A];
    int field_20;
    int field_24[1];  // [G] element count unknown
    unsigned char pad_28[0x20];
    unsigned char field_48;
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char pad_4B[0x5];
    unsigned char field_50;
    unsigned char field_51;
    unsigned char pad_52[0x2];
    float field_54;
    float field_58;
};

extern unsigned char D_004E1E70[8];  // [G] element count: gp-relative, so at most 8 bytes
extern int D_01EA4B80[];  // [G] element count unknown

// 0x00392330
extern "C" void func_00392330(UnkStruct_00392330 * self)
{
    self->field_4 = 0;
    self->field_54 = -1.0f;
    self->field_58 = -1.0f;
    self->field_50 = 0;
    self->field_51 = 0;
    self->field_20 = -1;
    for (int i = 0; (i < 8); i++) {
        self->field_24[i] = -1;
        D_004E1E70[i] = i;
        D_01EA4B80[i] = 0;
    }
    self->field_48 = 0;
    self->field_49 = 0;
    self->field_4A = 0;
    self->field_5 = 0;
}
