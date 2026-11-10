// func_00288F60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00288F60 {
    unsigned char pad_0[0x52CD];
    unsigned char field_52CD;
};

// 0x00288F60
extern "C" void func_00288F60(UnkStruct_00288F60 *self)
{
    self->field_52CD = 1;
}
