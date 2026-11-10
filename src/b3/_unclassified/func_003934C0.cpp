// func_003934C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003934C0 {
    unsigned char pad_0[0x51];
    unsigned char field_51;
};

// 0x003934C0
extern "C" unsigned char func_003934C0(UnkStruct_003934C0 *self)
{
    return self->field_51;
}
