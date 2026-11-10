// func_003CBCF0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_003CBCF0 {
    unsigned char pad_0[0xA0];
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    unsigned char pad_B4[0x4];
    unsigned char field_B8;
};

// 0x003CBCF0
extern "C" void func_003CBCF0(UnkStruct_003CBCF0 *self)
{
    self->field_A0 = 0;
    self->field_A4 = 0;
    self->field_A8 = 2;
    self->field_AC = 1;
    self->field_B0 = 0;
    self->field_B8 = 1;
}
