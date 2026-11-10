// func_00460180 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00460180;

struct UnkStruct_00460180 {
    unsigned char pad_0[0x680];
    int field_680;
    int field_684;
    int field_688;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00460180
extern "C" void func_00460180(UnkStruct_00460180 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 1);
    self->field_680 = 0;
    self->field_684 = 0;
    self->field_688 = 0;
}
