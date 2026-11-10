// func_00427070 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00427070 {
    unsigned char pad_0[0x31];
    unsigned char field_31;
};

// 0x00427070
extern "C" void func_00427070(UnkStruct_00427070 *self, int p0)
{
    self->field_31 = (unsigned char)p0;
}
