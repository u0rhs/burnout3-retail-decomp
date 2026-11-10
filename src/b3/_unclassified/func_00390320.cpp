// func_00390320 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (int return; four early returns; second test written self>p0 (slt at) not p0<self (slt v0); last as if(d<c) return 1; return 0).

// lifter variant 0
// func_00390320 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00390320;
struct UnkStruct_00390320_a1;

struct UnkStruct_00390320_a1 {
    int field_0;
    unsigned char pad_4[0x4];
    int field_8;
};

struct UnkStruct_00390320 {
    int field_0;
    unsigned char pad_4[0x4];
    int field_8;
};

// 0x00390320
extern "C" int func_00390320(UnkStruct_00390320 * self, UnkStruct_00390320_a1 * p0)
{
    if (self->field_0 < p0->field_0) return 1;
    if (self->field_0 > p0->field_0) return -1;
    if (self->field_8 < p0->field_8) return -1;
    if (p0->field_8 < self->field_8) return 1;
    return 0;
}
