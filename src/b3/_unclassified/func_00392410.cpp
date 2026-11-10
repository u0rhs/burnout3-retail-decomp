// func_00392410 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00392410 {
    unsigned char pad_0[0x11E];
    unsigned char field_11E;
};

// 0x00392410
extern "C" unsigned char func_00392410(UnkStruct_00392410 *self)
{
    return self->field_11E;
}
