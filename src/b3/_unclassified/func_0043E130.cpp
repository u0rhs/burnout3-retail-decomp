// func_0043E130 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043E130;

struct UnkStruct_0043E130 {
    unsigned char pad_0[0xD4];
    int field_D4;
};

extern "C" void func_0043E1F0(UnkStruct_0043E130 *);
extern "C" void func_0043E6F0(UnkStruct_0043E130 *);

// 0x0043E130
extern "C" void func_0043E130(UnkStruct_0043E130 * self, int p0)
{
    func_0043E1F0(self);
    self->field_D4 = p0;
    func_0043E6F0(self);
}
