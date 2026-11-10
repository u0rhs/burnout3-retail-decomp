// func_004670A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (goto shared return; range test as <= 2; reload self->field_0 via const pun).

// Hand-written; the lifter's draft was wrong (a176: callback dispatch by state; nested inline-style checks).

struct UnkStruct_004670A0_i {
    unsigned char pad_0[0x40];
    int (*field_40)();
    unsigned char pad_44[0x8];
    int (**field_4C)(int, void *, void *);
    int (**field_50)(int, int, int);
};
struct UnkStruct_D_004E2FCC_a { UnkStruct_004670A0_i * field_0; };
struct UnkStruct_004670A0_s { int field_0; int field_4; };
struct UnkStruct_D_004E2FC8_a { UnkStruct_004670A0_s * field_0; };
struct UnkStruct_004670A0_p { int field_0; };
extern UnkStruct_D_004E2FCC_a D_004E2FCC;
extern UnkStruct_D_004E2FC8_a D_004E2FC8;
extern "C" void func_00462150(int);

static inline int func_004670A0_inl1()
{
    return D_004E2FCC.field_0 != 0;
}

// 0x004670A0
extern "C" int func_004670A0(UnkStruct_004670A0_p * self, UnkStruct_004670A0_p * p1)
{
    if (func_004670A0_inl1() == 0) return 2;
    if (D_004E2FCC.field_0->field_40 == 0) return 13;
    if (self == 0) return 12;
    if (p1 == 0) return 12;
    int s0 = D_004E2FCC.field_0->field_40();
    int v1 = self->field_0;
    if (v1 == 0) {
        if (D_004E2FC8.field_0->field_0 != 0) return 15;
    }
    if (v1 != 2) goto out;
    int r = D_004E2FCC.field_0->field_50[D_004E2FC8.field_0->field_4](s0, *(const int *)&self->field_0, p1->field_0);
    if (r == 10) {
        D_004E2FC8.field_0->field_0 = 0;
        D_004E2FC8.field_0->field_4 = 0;
        return r;
    }
    if (r == 16) return r;
    s0 = D_004E2FCC.field_0->field_4C[D_004E2FC8.field_0->field_0](r, self, p1);
    if (self->field_0 == 2) {
        int t = D_004E2FC8.field_0->field_0;
        if (t == 5 || t == 2 || t == 7 || (unsigned int)(t - 11) <= 2) func_00462150(0);
        D_004E2FC8.field_0->field_0 = 0;
        D_004E2FC8.field_0->field_4 = 0;
    }
out:
    return s0;
}
