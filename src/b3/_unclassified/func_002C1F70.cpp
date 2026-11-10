// func_002C1F70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C1F70;
struct UnkStruct_002C1F70_a1;
struct UnkStruct_002C1F70_a2;

struct UnkStruct_002C1F70_a1 {
    int field_0;
};

struct UnkStruct_002C1F70_a2 {
    short field_0;
};

struct UnkStruct_002C1F70 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
    unsigned short field_14;
};

// 0x002C1F70
extern "C" int func_002C1F70(UnkStruct_002C1F70 * self, UnkStruct_002C1F70_a1 * p0, UnkStruct_002C1F70_a2 * p1)
{
    if ((self->field_0 & 1) != 1) {
        return 0;
    }
    p0->field_0 = self->field_10;
    p1->field_0 = self->field_14;
    self->field_0 = (self->field_0 & -2);
    return 1;
}
