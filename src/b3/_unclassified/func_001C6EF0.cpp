// func_001C6EF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001C6EF0;

struct UnkStruct_001C6EF0 {
    unsigned char pad_0[0x1169];
    unsigned char field_1169;
    unsigned char field_116A;
    unsigned char pad_116B[0x28D];
    int field_13F8;
};

extern "C" void func_001CFD20(UnkStruct_001C6EF0 *);

// 0x001C6EF0
extern "C" void func_001C6EF0(UnkStruct_001C6EF0 * self)
{
    func_001CFD20(self);
    self->field_1169 = 4;
    self->field_116A = 4;
    self->field_13F8 = 0;
}
