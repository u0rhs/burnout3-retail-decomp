// func_003A7000 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003A7000 {
    unsigned char pad_0[0x8E6];
    unsigned char field_8E6;
};

// 0x003A7000
extern "C" unsigned char func_003A7000(UnkStruct_003A7000 *self)
{
    return self->field_8E6;
}
