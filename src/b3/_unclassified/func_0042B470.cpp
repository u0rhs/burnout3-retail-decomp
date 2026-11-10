// func_0042B470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042B470;
struct UnkStruct_0042B470_1;

struct UnkStruct_0042B470_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
};

struct UnkStruct_0042B470 {
    unsigned char pad_0[0xC];
    unsigned char field_C;
    unsigned char pad_D[0x7B];
    unsigned long field_88;
    unsigned char field_90;
    unsigned char pad_91[0xB];
    unsigned char field_9C;
    signed char field_9D;
    signed char field_9E;
    unsigned char pad_9F[0x1];
    int field_A0;
    unsigned char pad_A4[0x3C];
    int field_E0;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0042B470
extern "C" void func_0042B470(UnkStruct_0042B470 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 1);
    ((UnkStruct_0042B470_1 *)((char *)self + 0x20))->vfunc_8();
    self->field_A0 = 0;
    self->field_E0 = 0;
    self->field_88 = 0;
    self->field_9C = 0;
    self->field_9D = -1;
    self->field_9E = -1;
    self->field_90 = 0;
    self->field_C = 0;
}
