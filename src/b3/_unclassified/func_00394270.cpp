// func_00394270 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00394270 {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0xD];
    unsigned char field_51;
};

// 0x00394270
extern "C" void func_00394270(UnkStruct_00394270 *self)
{
    self->field_51 = 0;
    self->field_40 = 0;
}
