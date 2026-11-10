// func_00240E90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00240E90;

struct UnkStruct_00240E90 {
    unsigned char pad_0[0x40];
    int field_40;
};

extern "C" void func_00240EC0(void *);

// 0x00240E90
extern "C" void func_00240E90(UnkStruct_00240E90 * self, int p0)
{
    self->field_40 = p0;
    func_00240EC0(self);
    func_00240EC0(((char *)self + 0x20));
}
