// func_0038A5A0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00392240.

struct UnkStruct_0038A5A0 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern "C" void func_00392240(UnkStruct_0038A5A0 *);

// 0x0038A5A0
extern "C" void func_0038A5A0(UnkStruct_0038A5A0 *self)
{
    self->field_60 = 0;
    func_00392240(self);
}
