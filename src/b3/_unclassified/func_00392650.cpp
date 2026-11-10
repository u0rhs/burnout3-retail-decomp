// func_00392650 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00391DB0.

struct UnkStruct_00392650 {
    unsigned char pad_0[0x6C];
    int field_6C;
    int field_70;
};

extern "C" void func_00391DB0(UnkStruct_00392650 *);

// 0x00392650
extern "C" void func_00392650(UnkStruct_00392650 *self)
{
    self->field_6C = 0;
    self->field_70 = 0;
    func_00391DB0(self);
}
