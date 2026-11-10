// func_002F9930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002F9930;
struct UnkStruct_002F9930_a1;

struct UnkStruct_002F9930_a1 {
    int field_0;
};

struct UnkStruct_002F9930 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
};

// 0x002F9930
extern "C" int func_002F9930(UnkStruct_002F9930 * self, UnkStruct_002F9930_a1 * p0)
{
    if ((self->field_0 & 1) != 1) {
        return 0;
    }
    p0->field_0 = self->field_10;
    self->field_0 = (self->field_0 & -2);
    return 1;
}
