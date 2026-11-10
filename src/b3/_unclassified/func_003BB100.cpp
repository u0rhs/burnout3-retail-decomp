// func_003BB100 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BB100;

struct UnkStruct_003BB100 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x3C];
    int field_50;
    int field_54;
    unsigned char field_58;
};

extern "C" void func_003BA8A0();

// 0x003BB100
extern "C" void func_003BB100(UnkStruct_003BB100 * self)
{
    func_003BA8A0();
    self->field_4 = 1;
    self->field_58 = 0;
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = -1;
    self->field_50 = 0;
    self->field_54 = 0;
}
