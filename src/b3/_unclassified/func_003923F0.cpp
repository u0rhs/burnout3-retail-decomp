// func_003923F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003923F0 {
    unsigned char pad_0[0x70];
    int field_70;
};

// 0x003923F0
extern "C" int func_003923F0(UnkStruct_003923F0 *self)
{
    return self->field_70;
}
