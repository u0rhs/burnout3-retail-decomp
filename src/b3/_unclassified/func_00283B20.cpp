// func_00283B20 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00283B20 {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24;
};

// 0x00283B20
extern "C" void func_00283B20(UnkStruct_00283B20 *self)
{
    self->field_20 = 0;
    self->field_24 = 0;
}
