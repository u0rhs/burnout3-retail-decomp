// func_00230560 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00230560 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x49C];
    int field_4AC;
};

// 0x00230560
extern "C" void func_00230560(UnkStruct_00230560 *self)
{
    self->field_4AC = 0;
    self->field_C = 0;
}
