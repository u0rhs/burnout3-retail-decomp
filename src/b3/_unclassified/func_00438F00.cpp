// func_00438F00 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00438F00 {
    unsigned char pad_0[0x40];
    int field_40;
    int field_44;
    int field_48;
};

// 0x00438F00
extern "C" void func_00438F00(UnkStruct_00438F00 *self)
{
    self->field_40 = 0;
    self->field_44 = 0;
    self->field_48 = 0;
}
