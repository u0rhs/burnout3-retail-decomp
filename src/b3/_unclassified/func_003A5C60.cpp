// func_003A5C60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003A5C60 {
    unsigned char pad_0[0x64];
    int field_64;
};

// 0x003A5C60
extern "C" int func_003A5C60(UnkStruct_003A5C60 *self)
{
    return self->field_64;
}
