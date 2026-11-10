// func_0023B870 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0023B870;

struct UnkStruct_0023B870 {
    unsigned char pad_0[0x1644];
    int field_1644;
};

extern "C" void func_00230560(UnkStruct_0023B870 *);
extern "C" void func_002C1C40(int, UnkStruct_0023B870 *);

// 0x0023B870
extern "C" void func_0023B870(UnkStruct_0023B870 * self)
{
    func_00230560(self);
    int t0 = self->field_1644;
    if (t0 == 0) return;
    func_002C1C40(t0, self);
}
