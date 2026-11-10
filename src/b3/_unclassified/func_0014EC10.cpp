// func_0014EC10 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0014EC10 {
    unsigned char pad_0[0x57C];
    int field_57C;
    int field_580;
    unsigned char pad_584[0x7];
    unsigned char field_58B;
};

// 0x0014EC10
extern "C" void func_0014EC10(UnkStruct_0014EC10 *self)
{
    self->field_57C = 9;
    self->field_580 = 3;
    self->field_58B = 0;
}
