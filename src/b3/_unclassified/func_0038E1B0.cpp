// func_0038E1B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0038E1B0 {
    unsigned char pad_0[0x68];
    int field_68;
};

// 0x0038E1B0
extern "C" int func_0038E1B0(UnkStruct_0038E1B0 *self)
{
    return self->field_68;
}
