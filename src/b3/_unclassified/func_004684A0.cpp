// func_004684A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (callbacks take one arg (a1-a3 were leftovers); &t0->field_4 held in a pointer local; n0==0 arms break to a shared return 0; != 11/12/13 && chain; case-25 arg read before the stores).

struct UnkStruct_004684A0_1;
struct UnkStruct_004684A0_4;

struct UnkStruct_004684A0_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};

struct UnkStruct_004684A0_4 {
    unsigned char pad_0[0x14];
    void (*field_14)(int);
    unsigned char pad_18[0x4];
    void (*field_1C)(int);
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_004684A0_1 * field_0;
};

struct UnkStruct_D_004E2FCC {
    UnkStruct_004684A0_4 * field_0;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;

// 0x004684A0
extern "C" int func_004684A0(int n0, int * p0, int p1)
{
    if (p0 == 0) {
        return 18;
    }
    if (p1 == 0) {
        return 18;
    }
    if (D_004E2FC8.field_0->field_0 != 7) {
        return 18;
    }
    *p0 = 1;
    UnkStruct_004684A0_1 * t0 = D_004E2FC8.field_0;
    int * st = &t0->field_4;
    switch (*st) {
    case 24:
        if (n0 == 0) {
            *st = 25;
            D_004E2FCC.field_0->field_1C(D_004E2FC8.field_0->field_C);
            break;
        }
        if (t0->field_0 != 11 && t0->field_0 != 12 && t0->field_0 != 13) {
            t0->field_8 = n0;
        }
        *p0 = 1;
        D_004E2FC8.field_0->field_0 = 12;
        D_004E2FC8.field_0->field_4 = 25;
        D_004E2FCC.field_0->field_1C(D_004E2FC8.field_0->field_C);
        return 0;
    case 25:
        if (n0 == 0) {
            *st = 26;
            D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
            break;
        }
        if (t0->field_0 != 11 && t0->field_0 != 12 && t0->field_0 != 13) {
            t0->field_8 = n0;
        }
        int a = D_004E2FC8.field_0->field_10;
        *p0 = 1;
        D_004E2FC8.field_0->field_0 = 13;
        D_004E2FC8.field_0->field_4 = 26;
        D_004E2FCC.field_0->field_14(a);
        return 0;
    case 26:
        if (n0 == 0) {
            *p0 = 2;
            return 0;
        }
        *p0 = 2;
        return n0;
    default:
        *p0 = 2;
        return 18;
    }
    return 0;
}
