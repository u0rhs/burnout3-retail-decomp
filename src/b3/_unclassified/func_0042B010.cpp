// func_0042B010 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0042B010 {
    unsigned char pad_0[0x88];
    unsigned long field_88;
    unsigned char field_90;
    unsigned char pad_91[0x47];
    int field_D8;
    int field_DC;
};

// 0x0042B010
extern "C" void func_0042B010(UnkStruct_0042B010 *self, unsigned long p0, int p1)
{
    self->field_88 = p0;
    self->field_90 = (unsigned char)p1;
    self->field_DC = 0;
    self->field_D8 = 0;
}
