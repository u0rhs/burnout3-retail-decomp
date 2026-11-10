// func_0026C790 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0026C790 {
    unsigned char pad_0[0xA0];
    unsigned char field_A0;
};

// 0x0026C790
extern "C" unsigned char func_0026C790(UnkStruct_0026C790 *self)
{
    return self->field_A0;
}
