// func_00468680 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (state guards as negated || early returns (if (!(s==8||s==10||s==9)) return 18; inner if (==11||==12||==13) {} else store); inner switch with break to a shared p0=2/return 0 tail).

// func_00468680 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00468680_1;
struct UnkStruct_00468680_4;
struct UnkStruct_00468680_a1;
struct UnkStruct_00468680_a2;
struct UnkStruct_D_004E2FC8;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00468680_1 * field_0;
};

struct UnkStruct_00468680_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x60];
    int field_70;
};

struct UnkStruct_00468680_a1 {
    int field_0;
};

struct UnkStruct_D_004E2FCC {
    UnkStruct_00468680_4 * field_0;
};

struct UnkStruct_00468680_4 {
    unsigned char pad_0[0x38];
    int field_38;
};

struct UnkStruct_00468680_a2 {
    int field_0;
};

extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;

// 0x00468680
extern "C" int func_00468680(int n0, UnkStruct_00468680_a1 * p0, UnkStruct_00468680_a2 * p1)
{
    if (p0 == 0) {
        return 18;
    }
    if (p1 == 0) {
        return 18;
    }
    int s = D_004E2FC8.field_0->field_0;
    if (!(s == 8 || s == 10 || s == 9)) return 18;
    p0->field_0 = 1;
    UnkStruct_00468680_1 * t0 = D_004E2FC8.field_0;
    switch (t0->field_4) {
    case 27:
        if (n0 != 0) {
            int s2 = t0->field_0;
            if (s2 == 11 || s2 == 12 || s2 == 13) {
            } else {
                t0->field_8 = n0;
            }
            p0->field_0 = 1;
            D_004E2FC8.field_0->field_0 = 11;
            D_004E2FC8.field_0->field_4 = 24;
            ((void (*)(int, UnkStruct_00468680_a1 *, UnkStruct_00468680_a2 *, UnkStruct_00468680_1 *))D_004E2FCC.field_0->field_38)(D_004E2FC8.field_0->field_C, p0, p1, t0);
            return 0;
        }
        break;
    case 29:
    case 28:
        if (n0 == 0) {
            if (t0->field_70 == p1->field_0) {
                p0->field_0 = 2;
                return 0;
            }
            p0->field_0 = 2;
            return 10;
        }
            int s2 = t0->field_0;
            if (s2 == 11 || s2 == 12 || s2 == 13) {
            } else {
                t0->field_8 = n0;
            }
            p0->field_0 = 1;
            D_004E2FC8.field_0->field_0 = 11;
            D_004E2FC8.field_0->field_4 = 24;
            ((void (*)(int, UnkStruct_00468680_a1 *, UnkStruct_00468680_a2 *, UnkStruct_00468680_1 *))D_004E2FCC.field_0->field_38)(D_004E2FC8.field_0->field_C, p0, p1, t0);
            return 0;
    default:
        p0->field_0 = 2;
        return 18;
    }
    p0->field_0 = 2;
    return 0;
}
