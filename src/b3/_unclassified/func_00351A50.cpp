// func_00351A50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00351A50;

struct UnkStruct_00351A50 {
    unsigned char pad_0[0x48];
    int field_48;
    int field_4C;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00351A50
extern "C" void func_00351A50(UnkStruct_00351A50 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 3);
    self->field_48 = 0;
    self->field_4C = 0;
}
