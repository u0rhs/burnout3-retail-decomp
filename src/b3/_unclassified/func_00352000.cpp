// func_00352000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00352000;

struct UnkStruct_00352000 {
    unsigned char pad_0[0x30];
    int field_30;
    int field_34;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00352000
extern "C" void func_00352000(UnkStruct_00352000 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_30 = 0;
    self->field_34 = 0;
}
