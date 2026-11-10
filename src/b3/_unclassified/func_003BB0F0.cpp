// func_003BB0F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003BB0F0 {
    unsigned char pad_0[0x50];
    int field_50;
    int field_54;
};

// 0x003BB0F0
extern "C" void func_003BB0F0(UnkStruct_003BB0F0 *self)
{
    self->field_50 = 0;
    self->field_54 = 0;
}
