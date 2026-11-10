// func_00240EC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240EC0;

struct UnkStruct_00240EC0 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

extern "C" void func_0022DA20(UnkStruct_00240EC0 *);

// 0x00240EC0
extern "C" void func_00240EC0(UnkStruct_00240EC0 * self)
{
    func_0022DA20(self);
    self->field_10 = 0;
    self->field_14 = 0;
}
