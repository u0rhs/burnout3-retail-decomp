// func_00433230 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00433230 {
    unsigned char pad_0[0x6B4];
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
};

// 0x00433230
extern "C" void func_00433230(UnkStruct_00433230 *self)
{
    self->field_6B4 = 0;
    self->field_6B8 = 0;
    self->field_6BC = 0;
    self->field_6C0 = 5;
}
