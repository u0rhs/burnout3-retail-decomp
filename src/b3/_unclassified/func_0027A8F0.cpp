// func_0027A8F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0027A8F0 {
    unsigned char pad_0[0x93E];
    unsigned char field_93E;
};

// 0x0027A8F0
extern "C" void func_0027A8F0(UnkStruct_0027A8F0 *self, int p0)
{
    self->field_93E = (unsigned char)p0;
}
