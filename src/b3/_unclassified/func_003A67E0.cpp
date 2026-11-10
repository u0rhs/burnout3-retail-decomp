// func_003A67E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003A67E0;

struct UnkStruct_003A67E0 {
    unsigned char pad_0[0x58];
    int field_58;
    unsigned char pad_5C[0x4];
    int field_60;
    unsigned char pad_64[0x68];
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8[1];  // [G] element count unknown
    unsigned char pad_DC[0x10];
    int field_EC[1];  // [G] element count unknown
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003A67E0
extern "C" void func_003A67E0(UnkStruct_003A67E0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_60 = 0;
    self->field_CC = 0;
    self->field_D0 = 0;
    self->field_D4 = 0;
    for (int i = 0; (i < 5); i++) {
        self->field_D8[i] = 0;
        self->field_EC[i] = 0;
    }
    self->field_58 = 0;
}
