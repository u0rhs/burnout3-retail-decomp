// func_00276A10 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00276A10 {
    unsigned char pad_0[0xD0];
    unsigned char field_D0;
};

// 0x00276A10
extern "C" void func_00276A10(UnkStruct_00276A10 *self)
{
    self->field_D0 = 0;
}
