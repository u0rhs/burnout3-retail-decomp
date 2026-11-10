// func_00389EC0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00395560.

struct UnkStruct_00389EC0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3B];
    int field_40;
};

extern "C" void func_00395560(UnkStruct_00389EC0 *);

// 0x00389EC0
extern "C" void func_00389EC0(UnkStruct_00389EC0 *self)
{
    self->field_4 = 0;
    self->field_40 = 0;
    func_00395560(self);
}
