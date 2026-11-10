// func_002C20C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_002C20C0 {
    unsigned char pad_0[0x8];
    int field_8;
};

// 0x002C20C0
extern "C" void func_002C20C0(UnkStruct_002C20C0 *self, void *p0_)
{
    int p0 = (int)p0_;
    self->field_8 = p0;
}
