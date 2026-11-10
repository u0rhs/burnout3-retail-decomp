// func_0038D7B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00391DB0.

struct UnkStruct_0038D7B0 {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
};

extern "C" void func_00391DB0(UnkStruct_0038D7B0 *);

// 0x0038D7B0
extern "C" void func_0038D7B0(UnkStruct_0038D7B0 *self)
{
    self->field_64 = 0;
    self->field_68 = 0;
    func_00391DB0(self);
}
