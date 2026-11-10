// Construct__21CB3GenericVSelectPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C9A10;

struct UnkStruct_003C9A10 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x24];
    unsigned char field_38[1];  // [G] element count unknown
    unsigned char pad_39[0x9];
    unsigned char field_42[1];  // [G] element count unknown
    unsigned char pad_43[0x9];
    unsigned char field_4C;
};

// 0x003C9A10
extern "C" void Construct__21CB3GenericVSelectPageFv(UnkStruct_003C9A10 * self)
{
    self->field_8 = 0;
    self->field_4 = 0;
    self->field_C = 317;
    for (int i = 0; (i < 10); i++) {
        self->field_10[i] = 317;
        self->field_38[i] = 1;
        self->field_42[i] = 0;
    }
    self->field_4C = 0;
}
