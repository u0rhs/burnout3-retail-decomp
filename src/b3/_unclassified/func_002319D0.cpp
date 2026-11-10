// func_002319D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002319D0;
struct UnkStruct_002319D0_2;
struct UnkStruct_002319D0_e0;

struct UnkStruct_002319D0_e0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x78];
};

struct UnkStruct_002319D0_2 {
    unsigned char pad_0[0x5C];
    unsigned char field_5C;
};

struct UnkStruct_002319D0 {
    unsigned char pad_0[0x4];
    int field_4;
};

// 0x002319D0
extern "C" void func_002319D0(UnkStruct_002319D0 * self, int p0, UnkStruct_002319D0_e0 * p1)
{
    int t0 = self->field_4;
    UnkStruct_002319D0_2 * v0;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (t0 == p1[i].field_14) {
            v0 = (UnkStruct_002319D0_2 *)&p1[i];
            goto g17;
        }
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
    v0 = 0;
g17:;
    v0->field_5C = 1;
}
