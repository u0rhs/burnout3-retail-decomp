// func_0038E350 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038E350_a2;
struct UnkStruct_0038E350_a3;

struct UnkStruct_0038E350_a2 {
    unsigned char pad_0[0x98];
    int field_98;
};

struct UnkStruct_0038E350_a3 {
    int field_0;
};

// 0x0038E350
extern "C" void func_0038E350(int n0, int p0, UnkStruct_0038E350_a2 * p1, UnkStruct_0038E350_a3 * p2)
{
    p2->field_0 = p1->field_98;
}
