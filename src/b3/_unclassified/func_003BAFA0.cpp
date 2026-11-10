// func_003BAFA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BAFA0;

struct UnkStruct_003BAFA0 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x44];
    unsigned char field_58;
};

extern "C" void func_003BA880();

// 0x003BAFA0
extern "C" void func_003BAFA0(UnkStruct_003BAFA0 * self)
{
    func_003BA880();
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = -1;
    self->field_58 = 0;
}
