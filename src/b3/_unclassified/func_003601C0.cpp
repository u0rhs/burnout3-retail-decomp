// func_003601C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003601C0_a3;

struct UnkStruct_003601C0_a3 {
    unsigned char pad_0[0x110];
    int field_110;
    int field_114;
};

extern "C" int ConvertHLBError__22CGtBuddiesPS2DirtySockFi(void *, int);  // CGtBuddiesPS2DirtySock::ConvertHLBError(int)

// 0x003601C0
extern "C" void func_003601C0(int n0, int p0, int p1, UnkStruct_003601C0_a3 * p2)
{
    if (p0 != 7) {
        return;
    }
    if (p2->field_110 != 0) {
        int r0 = ConvertHLBError__22CGtBuddiesPS2DirtySockFi(p2, p1);
        ((void (*)(bool, int, int, int))p2->field_110)((p1 == 0), 0, r0, p2->field_114);
        p2->field_110 = 0;
        p2->field_114 = 0;
    }
}
