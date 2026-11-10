// func_004683A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (state test as if (st!=11 && st!=12 && st!=13) return 18; int* local for &t0->field_4; calls break to a shared return 0).

// lifter variant 0
// func_004683A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004683A0_1;
struct UnkStruct_004683A0_4;
struct UnkStruct_004683A0_a1;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FC8 {
    UnkStruct_004683A0_1 * field_0;
};

struct UnkStruct_004683A0_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};

struct UnkStruct_004683A0_a1 {
    int field_0;
};

struct UnkStruct_D_004E2FCC {
    UnkStruct_004683A0_4 * field_0;
};

struct UnkStruct_004683A0_4 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;

// 0x004683A0
extern "C" int func_004683A0(int n0, UnkStruct_004683A0_a1 * p0, int p1)
{
    if (p0 == 0) {
        return 18;
    }
    if (p1 == 0) {
        return 18;
    }
    int st = D_004E2FC8.field_0->field_0;
    if (st != 11 && st != 12 && st != 13) {
        return 18;
    }
    p0->field_0 = 1;
    UnkStruct_004683A0_1 * t0 = D_004E2FC8.field_0;
    int * pp = &t0->field_4;
    switch (*pp) {
    case 24:
        *pp = 25;
        ((void (*)(int, UnkStruct_004683A0_a1 *, void *))D_004E2FCC.field_0->field_1C)(D_004E2FC8.field_0->field_C, p0, pp);
        break;
    case 25:
        *pp = 26;
        ((void (*)(int, UnkStruct_004683A0_a1 *, void *))D_004E2FCC.field_0->field_14)(D_004E2FC8.field_0->field_10, p0, pp);
        break;
    case 26:
        p0->field_0 = 2;
        return D_004E2FC8.field_0->field_8;
    default:
        p0->field_0 = 2;
        return 18;
    }
    return 0;
}
