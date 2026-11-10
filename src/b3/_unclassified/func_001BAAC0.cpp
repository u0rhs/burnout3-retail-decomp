// func_001BAAC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001BAAC0;

struct UnkStruct_001BAAC0 {
    unsigned char pad_0[0x216];
    signed char field_216;
    unsigned char pad_217[0x113B];
    unsigned char field_1352;
};

// 0x001BAAC0
extern "C" int func_001BAAC0(UnkStruct_001BAAC0 * self)
{
    int v0 = ((~self->field_216) == 0);
    if (((~self->field_216) == 0) == false) {
        v0 = ((self->field_1352 != 0) ^ 1);
    }
    return v0;
}
