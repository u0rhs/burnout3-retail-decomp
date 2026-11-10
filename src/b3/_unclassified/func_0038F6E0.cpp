// func_0038F6E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038F6E0;

struct UnkStruct_0038F6E0 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern "C" void func_00392040(UnkStruct_0038F6E0 *);

// 0x0038F6E0
extern "C" void func_0038F6E0(UnkStruct_0038F6E0 * self)
{
    func_00392040(self);
    self->field_60 = 6;
}
