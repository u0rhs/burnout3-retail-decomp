// func_00458900 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sub-struct at +0x20 reached through a hoisted local pointer; (unsigned char)p0 & 32 test).

struct UnkStruct_00458900_s20 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
};
struct UnkStruct_00458900_1 {
    unsigned char pad_0[0x20];
    UnkStruct_00458900_s20 field_20;
};
struct UnkStruct_00458900 {
    UnkStruct_00458900_1 * field_0;
};

// 0x00458900
extern "C" void func_00458900(UnkStruct_00458900 * self, int p0)
{
    UnkStruct_00458900_s20 * s = &self->field_0->field_20;
    s->field_C = p0;
    if (((unsigned char)p0 & 32) != 0) {
        s->field_D |= 1;
    }
    s->field_8 = 0;
}
