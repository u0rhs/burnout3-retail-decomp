// func_003B6200 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003B6200 {
    unsigned char pad_0[0x54];
    int field_54;
    unsigned char pad_58[0x8];
    int field_60;
};

// 0x003B6200
extern "C" void func_003B6200(UnkStruct_003B6200 *self)
{
    self->field_60 = 0;
    self->field_54 = 5;
}
