// func_0038D940 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0038D940 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
};

// 0x0038D940
extern "C" unsigned char func_0038D940(UnkStruct_0038D940 *self)
{
    return self->field_4;
}
