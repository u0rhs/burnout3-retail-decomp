// func_0042BC80 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_0042BC80 {
    unsigned char pad_0[0x258];
    int field_258;
};

// 0x0042BC80
extern "C" int func_0042BC80(UnkStruct_0042BC80 *self)
{
    return self->field_258;
}
