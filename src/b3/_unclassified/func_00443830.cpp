// func_00443830 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is
// whatever object a0 points to.

struct UnkStruct_00443830 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pad_A[0xD6];
    int field_E0;
    unsigned char pad_E4[0x118];
    int field_1FC;
    int field_200;
    unsigned char field_204;
};

// 0x00443830
extern "C" int func_00443830(UnkStruct_00443830 *self)
{
    self->field_4 = 0;
    self->field_E0 = -1;
    self->field_1FC = 0;
    self->field_9 = 1;
    self->field_8 = 0;
    self->field_200 = -1;
    self->field_204 = 0;
    return 1;
}
