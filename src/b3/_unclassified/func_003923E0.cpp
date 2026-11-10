// func_003923E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003923E0 {
    unsigned char pad_0[0x6C];
    int field_6C;
};

// 0x003923E0
extern "C" int func_003923E0(UnkStruct_003923E0 *self)
{
    return self->field_6C;
}
