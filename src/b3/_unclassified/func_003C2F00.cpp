// func_003C2F00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (result variable v0 dropped: return 1 inside the if body, return 0 after it).

// func_003C2F00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C2F00;

struct UnkStruct_003C2F00 {
    unsigned char pad_0[0x58];
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
    unsigned char pad_B2[0x2];
    unsigned char field_B4;
};

extern "C" int func_003BA890();

// 0x003C2F00
extern "C" int func_003C2F00(UnkStruct_003C2F00 * self)
{
    if (self->field_B4 != 0) {
        return 1;
    }
    if (func_003BA890() != 0) {
        for (int i = 0; (i < 8); i++) {
            self->field_58[i] = 0;
            self->field_78[i] = 0;
            self->field_98[i] = 0;
            self->field_A0[i] = i;
            self->field_A8[i] = i;
        }
        self->field_B0 = 0;
        self->field_B1 = 0;
        self->field_B4 = 1;
        return 1;
    }
    return 0;
}
