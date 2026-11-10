// func_00353960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00353960;
struct UnkStruct_00353960_e0;

struct UnkStruct_00353960_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_00353960 {
    UnkStruct_00353960_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0xF94];
    int field_1004;
};

// 0x00353960
extern "C" void * func_00353960(UnkStruct_00353960 * self)
{
    return ((char *)&self->field_0[self->field_1004] + 0x2E0);
}
