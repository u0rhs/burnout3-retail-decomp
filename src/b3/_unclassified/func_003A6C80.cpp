// Construct__24CB3ReplaySymbolComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003A6C80;

struct UnkStruct_003A6C80 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003A6C80
extern "C" void Construct__24CB3ReplaySymbolComponentFv(UnkStruct_003A6C80 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 2);
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = 0;
}
