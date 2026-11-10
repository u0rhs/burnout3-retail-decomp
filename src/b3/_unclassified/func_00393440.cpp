// func_00393440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00393440_a2;
struct UnkStruct_00393440_a3;

struct UnkStruct_00393440_a2 {
    unsigned char pad_0[0x84];
    int field_84;
};

struct UnkStruct_00393440_a3 {
    int field_0;
};

// 0x00393440
extern "C" void func_00393440(int n0, int p0, UnkStruct_00393440_a2 * p1, UnkStruct_00393440_a3 * p2)
{
    p2->field_0 = p1->field_84;
}
