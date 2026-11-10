// func_00150D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00150D00;
struct UnkStruct_00150D00_1;

struct UnkStruct_00150D00_1 {
    unsigned char pad_0[0x4EFC];
    unsigned char field_4EFC;
};

struct UnkStruct_00150D00 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char pad_1162[0x7B2];
    int field_1914;
    unsigned char pad_1918[0x170];
    UnkStruct_00150D00_1 * field_1A88;
};

// 0x00150D00
extern "C" int func_00150D00(UnkStruct_00150D00 * self)
{
    if (self->field_1161 != 0) {
        return 1;
    }
    if ((self->field_1914 != 2) || (self->field_1A88->field_4EFC == 0)) {
        return 0;
    }
    return 1;
}
