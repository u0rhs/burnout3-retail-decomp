// func_0030ED40 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0030ED40 {
    unsigned char pad_0[0x818];
    int field_818;
};

// 0x0030ED40
extern "C" void func_0030ED40(UnkStruct_0030ED40 *self, int p0)
{
    self->field_818 = p0;
}
