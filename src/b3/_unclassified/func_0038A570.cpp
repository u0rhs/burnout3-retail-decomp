// func_0038A570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038A570;

struct UnkStruct_0038A570 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern "C" void func_00392040(UnkStruct_0038A570 *);

// 0x0038A570
extern "C" void func_0038A570(UnkStruct_0038A570 * self)
{
    func_00392040(self);
    self->field_60 = 6;
}
