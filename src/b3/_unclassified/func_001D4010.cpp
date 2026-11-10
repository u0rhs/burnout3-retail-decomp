// func_001D4010 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_001D4010 {
    unsigned char field_0;
};

// 0x001D4010
extern "C" void func_001D4010(UnkStruct_001D4010 *self)
{
    self->field_0 = 1;
}
