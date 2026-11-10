// func_00467440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool test of D_004E2FCC, if-&& chain instead of switch, p1==0 arm first, callback takes (C,x,p1)).

// lifter variant 0
// func_00467440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00467440_2;
struct UnkStruct_00467440_3;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467440_3 * field_0;
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00467440_2 * field_0;
};

struct UnkStruct_00467440_2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x60];
    int field_70;
};

struct UnkStruct_00467440_3 {
    unsigned char pad_0[0x34];
    int field_34;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int func_00462140();

// 0x00467440
extern "C" int func_00467440(void *n0, int p0, int p1)
{
    if ((bool)D_004E2FCC.field_0 == false) {
        return 2;
    }
    if (n0 == 0) {
        return 12;
    }
    if (D_004E2FC8.field_0->field_0 != 0) {
        return 13;
    }
    D_004E2FC8.field_0->field_0 = 8;
    D_004E2FC8.field_0->field_4 = 27;
    UnkStruct_00467440_2 * t0 = D_004E2FC8.field_0;
    if (t0->field_0 != 11 && t0->field_0 != 12 && t0->field_0 != 13) {
        t0->field_8 = 0;
    }
    memcpy((void *)((char *)D_004E2FC8.field_0 + 12), (const void *)n0, 96);
    if (p1 == 0) {
        int r2 = func_00462140();
        D_004E2FC8.field_0->field_70 = (p0 + r2);
        int r3 = func_00462140();
        ((void (*)(int, int, int))D_004E2FCC.field_0->field_34)(D_004E2FC8.field_0->field_C, (p0 + r3), p1);
    } else {
        D_004E2FC8.field_0->field_70 = p0;
        ((void (*)(int, int, int))D_004E2FCC.field_0->field_34)(D_004E2FC8.field_0->field_C, p0, p1);
    }
    return 0;
}
