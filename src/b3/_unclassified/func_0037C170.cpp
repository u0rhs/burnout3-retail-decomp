// func_0037C170 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0037C170_t1;

struct UnkStruct_0037C170_t1 {
    unsigned char pad_0[0x18C8];
    int field_18C8;
    int field_18CC[1];  // [G] element count unknown
    unsigned char pad_18D0[0x71];
    unsigned char field_1941;
};

// 0x0037C170
extern "C" int func_0037C170(int n0, int p0, int p1, int p2, int p3, UnkStruct_0037C170_t1 * p4)
{
    p4->field_1941 = p3;
    int t0 = p4->field_18C8;
    if (t0 != 20) {
        p4->field_18CC[t0] = n0;
        p4->field_18C8 = (p4->field_18C8 + 1);
        return 1;
    }
    p4->field_1941 = 1;
    return 0;
}
