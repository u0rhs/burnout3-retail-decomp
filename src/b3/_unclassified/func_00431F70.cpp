// func_00431F70 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00431F70 {
    unsigned char pad_0[0x93C];
    int field_93C;
    int field_940;
    unsigned char pad_944[0x74];
    int field_9B8;
    int field_9BC;
    int field_9C0;
};

// 0x00431F70
extern "C" void func_00431F70(UnkStruct_00431F70 *self)
{
    self->field_9B8 = 0;
    self->field_9BC = 0;
    self->field_940 = 0;
    self->field_93C = 0;
    self->field_9C0 = 1;
}
