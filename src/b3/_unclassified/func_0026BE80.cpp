// func_0026BE80 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0026BE80 {
    unsigned char pad_0[0x4];
    int field_4;
};

// 0x0026BE80
extern "C" int func_0026BE80(UnkStruct_0026BE80 *self, void *p0_)
{
    int p0 = (int)p0_;
    self->field_4 = p0;
    return 1;
}
