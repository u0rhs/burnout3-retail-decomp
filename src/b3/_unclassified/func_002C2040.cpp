// func_002C2040 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C2040;

struct UnkStruct_002C2040 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern "C" void func_0022DA20(UnkStruct_002C2040 *);

// 0x002C2040
extern "C" void func_002C2040(UnkStruct_002C2040 * self)
{
    func_0022DA20(self);
    self->field_10 = 0;
}
