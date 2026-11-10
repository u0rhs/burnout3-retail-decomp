// func_0038E460 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0038E460 {
    unsigned char pad_0[0x70];
    unsigned char field_70;
};

// 0x0038E460
extern "C" void func_0038E460(UnkStruct_0038E460 *self)
{
    self->field_70 = 1;
}
