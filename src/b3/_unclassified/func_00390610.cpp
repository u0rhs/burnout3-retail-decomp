// func_00390610 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00390610;

struct UnkStruct_00390610 {
    unsigned char pad_0[0x44];
    int field_44;
    unsigned char pad_48[0x14];
    unsigned char field_5C;
    unsigned char field_5D;
};

// 0x00390610
extern "C" void func_00390610(UnkStruct_00390610 * self, int p0, int p1)
{
    if ((((signed char)p1) & 1) != 0) {
        self->field_44 = p0;
        self->field_5C = 1;
    }
    if ((((signed char)p1) & 2) != 0) {
        self->field_44 = -1;
        self->field_5D = 1;
    }
    if ((((signed char)p1) & 4) != 0) {
        self->field_44 = -1;
        self->field_5C = 0;
    }
}
