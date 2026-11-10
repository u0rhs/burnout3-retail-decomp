// func_00442C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00442C90;

struct UnkStruct_00442C90 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0xD7];
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    unsigned char pad_F4[0x10C];
    int field_200;
    unsigned char field_204;
};

extern "C" void lgDevDestroyForceEffect(int);

// 0x00442C90
extern "C" void func_00442C90(UnkStruct_00442C90 * self)
{
    lgDevDestroyForceEffect(self->field_EC);
    lgDevDestroyForceEffect(self->field_E4);
    lgDevDestroyForceEffect(self->field_E8);
    lgDevDestroyForceEffect(self->field_F0);
    self->field_E0 = -1;
    self->field_8 = 0;
    self->field_4 = 0;
    self->field_200 = -1;
    self->field_204 = 0;
}
