// func_0013C4B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013C4B0;

struct UnkStruct_0013C4B0 {
    unsigned char field_0[1];  // [G] element count unknown
    unsigned char pad_1[0x42];
    unsigned char field_43[1];  // [G] element count unknown
    unsigned char pad_44[0x13];
    unsigned char field_57[1];  // [G] element count unknown
    unsigned char pad_58[0x48];
    unsigned char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x63];
    unsigned char field_104[1];  // [G] element count unknown
    unsigned char pad_105[0x23];
    unsigned char field_128[1];  // [G] element count unknown
    unsigned char pad_129[0x9];
    unsigned char field_132[1];  // [G] element count unknown
    unsigned char pad_133[0x9];
    unsigned char field_13C[1];  // [G] element count unknown
    unsigned char pad_13D[0x13];
    unsigned char field_150[1];  // [G] element count unknown
    unsigned char pad_151[0x9];
    unsigned char field_15A[1];  // [G] element count unknown
    unsigned char pad_15B[0x4];
    unsigned char field_15F[1];  // [G] element count unknown
};

// 0x0013C4B0
extern "C" int func_0013C4B0(UnkStruct_0013C4B0 * self)
{
    for (int i = 0; (i < 67); i++) {
        self->field_0[i] = 0;
    }
    for (int i1 = 0; (i1 < 20); i1++) {
        self->field_43[i1] = 0;
    }
    for (int i2 = 0; (i2 < 73); i2++) {
        self->field_57[i2] = 0;
    }
    for (int i3 = 0; (i3 < 100); i3++) {
        self->field_A0[i3] = 0;
    }
    for (int i4 = 0; (i4 < 36); i4++) {
        self->field_104[i4] = 0;
    }
    for (int i5 = 0; (i5 < 10); i5++) {
        self->field_128[i5] = 0;
    }
    for (int i6 = 0; (i6 < 10); i6++) {
        self->field_132[i6] = 0;
    }
    for (int i7 = 0; (i7 < 20); i7++) {
        self->field_13C[i7] = 0;
    }
    for (int i8 = 0; (i8 < 10); i8++) {
        self->field_150[i8] = 0;
    }
    for (int i9 = 0; (i9 < 5); i9++) {
        self->field_15A[i9] = 0;
    }
    for (int i10 = 0; (i10 < 3); i10++) {
        self->field_15F[i10] = 0;
    }
    return 1;
}
