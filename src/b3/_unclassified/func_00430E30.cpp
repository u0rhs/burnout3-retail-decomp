// func_00430E30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (constant address into a local first; if (field_D0) { switch (cases 2,1,0,default) } instead of early return).

// lifter variant 0
// func_00430E30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00430E30;
struct UnkStruct_D_0064EA70;

struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[0x78];
    int field_78;
};

struct UnkStruct_00430E30 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xA0];
    int field_C4;
    unsigned char pad_C8[0x8];
    unsigned char field_D0;
    unsigned char pad_D1[0x3];
    unsigned char field_D4;
};

extern UnkStruct_D_0064EA70 D_0064EA70;

// 0x00430E30
extern "C" void func_00430E30(UnkStruct_00430E30 * self)
{
    UnkStruct_D_0064EA70 *d = &D_0064EA70;
    self->field_D4 = 1;
    self->field_1C = 16;
    self->field_20 = 512;
    self->field_14 = 2505;
    if (self->field_D0) {
    switch (d->field_78) {
    case 2:
        self->field_C = 1;
        self->field_C4 = 0;
        break;
    case 1:
        self->field_C = 2;
        self->field_C4 = 1;
        break;
    case 0:
        self->field_C = 3;
        self->field_C4 = 2;
        break;
    default:
        self->field_C = 4;
        break;
    }
    }
}
