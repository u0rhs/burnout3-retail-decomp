// func_0042B6A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042B6A0;
struct UnkStruct_0042B6A0_e0;
struct UnkStruct_0042B6A0_e1;

struct UnkStruct_0042B6A0_e0 {
    unsigned char pad_0[0x7];
    unsigned char field_7;
    unsigned char pad_8[0x4];
};

struct UnkStruct_0042B6A0_e1 {
    unsigned char pad_0[0x7];
    unsigned char field_7;
    unsigned char pad_8[0x4];
};

struct UnkStruct_0042B6A0 {
    unsigned char pad_0[0xC];
    UnkStruct_0042B6A0_e0 field_C[1];  // [G] element count unknown
    unsigned char pad_18[0xE4];
    UnkStruct_0042B6A0_e1 field_FC[1];  // [G] element count unknown
    unsigned char pad_108[0x12C];
    int field_234;
    int field_238;
};

// 0x0042B6A0
extern "C" unsigned char func_0042B6A0(UnkStruct_0042B6A0 * self, int p0)
{
    if ((self->field_234 != 4) || ((unsigned int)(self->field_238 + -3) >= (unsigned int)2)) {
        return self->field_C[p0].field_7;
    }
    return self->field_FC[p0].field_7;
}
