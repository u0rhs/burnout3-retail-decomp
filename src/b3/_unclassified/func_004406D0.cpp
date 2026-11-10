// func_004406D0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_004406D0 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
};

// 0x004406D0
extern "C" void func_004406D0(UnkStruct_004406D0 *self)
{
    self->field_8 = 0;
}
