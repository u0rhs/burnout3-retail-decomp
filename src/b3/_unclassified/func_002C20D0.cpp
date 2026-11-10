// func_002C20D0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_002C20D0 {
    int field_0;
};

// 0x002C20D0
extern "C" void func_002C20D0(UnkStruct_002C20D0 *self, void *p0_)
{
    int p0 = (int)p0_;
    self->field_0 = p0;
}
