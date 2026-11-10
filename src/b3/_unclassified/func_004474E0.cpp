// func_004474E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_004474E0 {
    unsigned char pad_0[0x10];
    int field_10;
};

// 0x004474E0
extern "C" void func_004474E0(UnkStruct_004474E0 *self, void *p0_)
{
    int p0 = (int)p0_;
    self->field_10 = p0;
}
