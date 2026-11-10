// func_002F9CF0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_002F9CF0 {
    unsigned char pad_0[0x14];
    int field_14;
};

// 0x002F9CF0
extern "C" void func_002F9CF0(UnkStruct_002F9CF0 *self, int p0)
{
    self->field_14 = p0;
}
