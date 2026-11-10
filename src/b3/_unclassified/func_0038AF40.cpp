// func_0038AF40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038AF40;

struct UnkStruct_0038AF40 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0038AF40
extern "C" void func_0038AF40(UnkStruct_0038AF40 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = 0;
}
