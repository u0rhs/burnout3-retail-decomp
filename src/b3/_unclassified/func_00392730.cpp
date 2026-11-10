// func_00392730 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00392730 {
    unsigned char pad_0[0x11C];
    unsigned char field_11C;
};

// 0x00392730
extern "C" int func_00392730(UnkStruct_00392730 *self)
{
    self->field_11C = 1;
    return 0;
}
