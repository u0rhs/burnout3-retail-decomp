// func_00437050 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00437050 {
    unsigned char pad_0[0x90];
    int field_90;
};

// 0x00437050
extern "C" void func_00437050(UnkStruct_00437050 *self)
{
    self->field_90 = 24;
}
