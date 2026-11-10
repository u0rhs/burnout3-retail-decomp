// func_003904E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003904E0 {
    unsigned char pad_0[0x5D];
    unsigned char field_5D;
};

// 0x003904E0
extern "C" unsigned char func_003904E0(UnkStruct_003904E0 *self)
{
    return self->field_5D;
}
