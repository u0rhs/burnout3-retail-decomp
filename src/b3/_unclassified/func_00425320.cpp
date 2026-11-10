// func_00425320 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00425320 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
};

// 0x00425320
extern "C" void func_00425320(UnkStruct_00425320 *self)
{
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 0;
}
