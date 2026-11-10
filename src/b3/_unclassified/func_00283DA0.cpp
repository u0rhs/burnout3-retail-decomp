// func_00283DA0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00283DA0 {
    unsigned char pad_0[0x48];
    int field_48;
};

// 0x00283DA0
extern "C" void func_00283DA0(UnkStruct_00283DA0 *self)
{
    self->field_48 = 1;
}
