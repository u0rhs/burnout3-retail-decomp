// func_0013B570 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0013B570 {
    unsigned char pad_0[0x44];
    int field_44;
};

// 0x0013B570
extern "C" int func_0013B570(UnkStruct_0013B570 *self)
{
    return self->field_44;
}
