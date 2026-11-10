// func_003F6010 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003F6010 {
    unsigned char pad_0[0x18];
    int field_18;
};

// 0x003F6010
extern "C" void func_003F6010(UnkStruct_003F6010 *self)
{
    self->field_18 = 0;
}
