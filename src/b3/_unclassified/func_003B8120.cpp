// func_003B8120 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003B8120;

struct UnkStruct_003B8120 {
    unsigned char pad_0[0x20];
    int field_20;
    unsigned char pad_24[0xC];
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003B8120
extern "C" void func_003B8120(UnkStruct_003B8120 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 3);
    self->field_20 = 0;
    self->field_30 = 0;
    self->field_34 = 0;
    self->field_38 = 0;
    self->field_3C = 0;
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
    self->field_4C = 0;
    self->field_50 = 0;
}
