// func_0043EDE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043EDE0;

struct UnkStruct_0043EDE0 {
    unsigned char pad_0[0x10];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x8];
    int field_1C[1];  // [G] element count unknown
    unsigned char pad_20[0x8];
    int field_28[1];  // [G] element count unknown
    unsigned char pad_2C[0xA8];
    int field_D4;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0043EDE0
extern "C" void func_0043EDE0(UnkStruct_0043EDE0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 3);
    self->field_D4 = 1;
    for (int i = 0; (i < 3); i++) {
        self->field_10[i] = 0;
        self->field_1C[i] = 0;
        self->field_28[i] = 0;
    }
}
