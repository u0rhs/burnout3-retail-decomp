// func_0045FF90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0045FF90;

struct UnkStruct_0045FF90 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x8];
    int field_18;
    unsigned char pad_1C[0x4];
    unsigned long field_20[1];  // [G] element count unknown
    unsigned char pad_28[0x1A8];
    unsigned long field_1D0[1];  // [G] element count unknown
};

// 0x0045FF90
extern "C" unsigned long func_0045FF90(UnkStruct_0045FF90 * self)
{
    switch (self->field_C) {
    case 0:
        return self->field_20[self->field_18];
    case 1:
    case 2:
        return self->field_1D0[self->field_18];
    default:
        return 0;
    }
}
