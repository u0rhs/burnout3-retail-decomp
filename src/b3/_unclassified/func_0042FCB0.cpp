// func_0042FCB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042FCB0;

struct UnkStruct_0042FCB0 {
    unsigned char pad_0[0x39D];
    unsigned char field_39D;
};

extern "C" void func_0042FBC0(UnkStruct_0042FCB0 *);

// 0x0042FCB0
extern "C" void func_0042FCB0(UnkStruct_0042FCB0 * self)
{
    func_0042FBC0(self);
    self->field_39D = 1;
}
