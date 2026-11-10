// func_00438F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00438F10;

struct UnkStruct_00438F10 {
    unsigned char pad_0[0x3C];
    float field_3C;
    int field_40;
    int field_44;
    int field_48;
};

// 0x00438F10
extern "C" void func_00438F10(UnkStruct_00438F10 * self, int p0, int p1, int p2)
{
    self->field_40 = p0;
    self->field_44 = p1;
    self->field_48 = p2;
    self->field_3C = 5.0f;
}
