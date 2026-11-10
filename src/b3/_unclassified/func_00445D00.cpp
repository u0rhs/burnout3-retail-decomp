// func_00445D00 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00445D00 {
    unsigned char pad_0[0x48];
    unsigned char field_48;
};

// 0x00445D00
extern "C" unsigned char func_00445D00(UnkStruct_00445D00 *self)
{
    return self->field_48;
}
