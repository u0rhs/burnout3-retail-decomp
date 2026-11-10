// func_00455B00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00455B00;

struct UnkStruct_00455B00 {
    unsigned char pad_0[0x70];
    float field_70;
    float field_74;
};

// 0x00455B00
extern "C" int func_00455B00(UnkStruct_00455B00 * self)
{
    int v0 = 1;
    if (self->field_70 <= self->field_74) {
        v0 = 0;
    }
    return v0;
}
