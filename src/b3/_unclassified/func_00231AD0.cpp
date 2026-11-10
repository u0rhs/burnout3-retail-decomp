// func_00231AD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00231AD0;
struct UnkStruct_00231AD0_2;
struct UnkStruct_00231AD0_e0;

struct UnkStruct_00231AD0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x78];
};

struct UnkStruct_00231AD0_2 {
    unsigned char pad_0[0x58];
    unsigned char field_58;
};

struct UnkStruct_00231AD0 {
    unsigned char pad_0[0x4];
    int field_4;
};

// 0x00231AD0
extern "C" void func_00231AD0(UnkStruct_00231AD0 * self, int p0, UnkStruct_00231AD0_e0 * p1)
{
    int t0 = self->field_4;
    UnkStruct_00231AD0_2 * v0;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (t0 == p1[i].field_14) {
            v0 = (UnkStruct_00231AD0_2 *)&p1[i];
            goto g17;
        }
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
    v0 = 0;
g17:;
    v0->field_58 = 1;
}
