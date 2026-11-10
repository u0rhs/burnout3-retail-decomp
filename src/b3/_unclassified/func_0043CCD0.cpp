// func_0043CCD0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.
// Tail call: func_00457130.

struct UnkStruct_0043CCD0 {
    unsigned char pad_0[0xD4];
    int field_D4;
};

extern "C" void func_00457130(void *, int);

// 0x0043CCD0
extern "C" void func_0043CCD0(UnkStruct_0043CCD0 *self)
{
    self->field_D4 = 0;
    func_00457130((char *)self + 0x10, 1);
}
