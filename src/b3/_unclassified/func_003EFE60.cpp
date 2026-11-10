// func_003EFE60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003EFE60 {
    unsigned char pad_0[0x4];
    int field_4;
};

// 0x003EFE60
extern "C" void func_003EFE60(UnkStruct_003EFE60 *self)
{
    self->field_4 = 0;
}
