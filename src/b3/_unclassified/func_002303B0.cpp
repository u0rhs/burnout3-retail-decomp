// func_002303B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_002303B0 {
    unsigned char pad_0[0x10];
    int field_10;
};

// 0x002303B0
extern "C" void func_002303B0(UnkStruct_002303B0 *self, int p0)
{
    self->field_10 = p0;
}
