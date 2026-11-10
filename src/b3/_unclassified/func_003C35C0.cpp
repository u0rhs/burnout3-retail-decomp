// func_003C35C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003C35C0 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
};

// 0x003C35C0
extern "C" void func_003C35C0(UnkStruct_003C35C0 *self)
{
    self->field_10 = 0;
}
