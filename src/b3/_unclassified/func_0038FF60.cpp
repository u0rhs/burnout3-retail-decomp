// func_0038FF60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00392330.

struct UnkStruct_0038FF60 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern "C" void func_00392330(UnkStruct_0038FF60 *);

// 0x0038FF60
extern "C" void func_0038FF60(UnkStruct_0038FF60 *self)
{
    self->field_60 = 0;
    func_00392330(self);
}
