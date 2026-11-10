// func_0035F1E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0035F1E0;
struct UnkStruct_0035F1E0_a2;

struct UnkStruct_0035F1E0_a2 {
    unsigned char field_0;
};

struct UnkStruct_0035F1E0 {
    unsigned char pad_0[0x118];
    int field_118;
};

extern "C" void * HLBListGetBuddyByName(int, int);
extern "C" int HLBBudIsSameProduct(void *);

// 0x0035F1E0
extern "C" int func_0035F1E0(UnkStruct_0035F1E0 * self, void *p0_, UnkStruct_0035F1E0_a2 * p1)
{
    int p0 = (int)p0_;
    void * r0 = HLBListGetBuddyByName(self->field_118, p0);
    if (r0 != 0) {
        int r1 = HLBBudIsSameProduct(r0);
        p1->field_0 = (r1 != 0);
        return 0;
    }
    return 5;
}
