// func_00393930 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00395570.

struct UnkStruct_00393930 {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0xD];
    unsigned char field_51;
};

extern "C" void func_00395570(UnkStruct_00393930 *);

// 0x00393930
extern "C" void func_00393930(UnkStruct_00393930 *self)
{
    self->field_51 = 0;
    self->field_40 = 0;
    func_00395570(self);
}
