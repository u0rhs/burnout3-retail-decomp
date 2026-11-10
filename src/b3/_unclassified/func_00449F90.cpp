// func_00449F90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00449F90;

struct UnkStruct_00449F90 {
    unsigned char pad_0[0x88];
    int field_88;
    int field_8C;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00449F90
extern "C" void func_00449F90(UnkStruct_00449F90 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_88 = 0;
    self->field_8C = 0;
}
