// func_003FBAA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FBAA0_a2;
struct UnkStruct_003FBAA0_e0;

struct UnkStruct_003FBAA0_a2 {
    unsigned char pad_0[0x4C];
    UnkStruct_003FBAA0_e0 * field_4C;
};

struct UnkStruct_003FBAA0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
};

// 0x003FBAA0
extern "C" void func_003FBAA0(void *n0_, int p0, UnkStruct_003FBAA0_a2 * p1, int p2)
{
    int n0 = (int)n0_;
    p1->field_4C[p0].field_14 = (p1->field_4C[p0].field_14 & -8);
    p1->field_4C[p0].field_14 = (p1->field_4C[p0].field_14 & -9);
    p1->field_4C[p0].field_14 = (p1->field_4C[p0].field_14 | (p2 & 255));
}
