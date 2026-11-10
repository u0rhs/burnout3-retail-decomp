// NONMATCHING: func_00468850 -- retail 272 / ours 272 instructions, 4 in changed runs
// Only the case-2 callback call: retail passes 2 in a1 by reusing the switch-compare register (no li), ours re-emits li a1,2 in the jalr delay slot. Tried: literal, switch-variable copy (fixes the call but moves the switch var to a1), inline wrapper with code param, int local, *status+1. Layout, returns (break + shared return 0), case order, if/else err paths, 3-arg field_14 callback, 0 > v all settled. | guard: n/a (classic ops) | mwperm: 14 -> 4 ('if (0 > v) {' -> 'if (v < 0) {')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00468850 -- hand-written from the retail structure (lifter draft failed to compile: func_00463070
// declared with int parameters but called with pointers).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths).

struct UnkStruct_00468850_1;
struct UnkStruct_00468850_4;
struct UnkStruct_00468850_6;

struct UnkStruct_00468850_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char field_14[0x20];
    unsigned char field_34[0x20];
    unsigned char field_54[0x18];
    int field_6C;
};

struct UnkStruct_00468850_4 {
    unsigned short field_0;
    unsigned char pad_2[0x2];
    void (*field_4)(UnkStruct_00468850_6 *, int);
    unsigned char pad_8[0x8];
    void (*field_10)(int);
    void (*field_14)(int, int, int *);
    void (*field_18)(void *, void *, int, int);
    unsigned char pad_1C[0x38];
    unsigned char field_54[0x10];
};

struct UnkStruct_00468850_6 {
    unsigned char pad_0[0x50];
};

extern UnkStruct_00468850_1 * D_004E2FC8;
extern UnkStruct_00468850_4 * D_004E2FCC;

extern "C" void func_00463070(void *, void *, void *, void *);
extern "C" int func_00469450(unsigned short, int);
extern "C" char *func_00463410(UnkStruct_00468850_6 *, void *, void *);

// [G] inlined helpers, placeholder names
static inline void func_00468850_inl1(int err)
{
    if (D_004E2FC8->field_0 != 11 && D_004E2FC8->field_0 != 12 && D_004E2FC8->field_0 != 13) {
        D_004E2FC8->field_8 = err;
    }
}

static inline void func_00468850_inl2(int h, int * status, int * data)
{
    *status = 1;
    D_004E2FC8->field_0 = 13;
    D_004E2FC8->field_4 = 26;
    D_004E2FCC->field_14(h, 13, data);
}

// 0x00468850
extern "C" int func_00468850(int err, int * status, int * data)
{
    if (status == 0) {
        return 18;
    }
    if (data == 0) {
        return 18;
    }
    if (D_004E2FC8->field_0 != 3 && D_004E2FC8->field_0 != 6) {
        return 18;
    }
    *status = 1;
    switch (D_004E2FC8->field_4) {
    case 1:
        if (err == 0) {
            UnkStruct_00468850_6 local;
            func_00463410(&local, D_004E2FCC->field_54, D_004E2FC8->field_54);
            D_004E2FC8->field_4 = 2;
            D_004E2FCC->field_4(&local, D_004E2FC8->field_10);
            break;
        } else if (err == 3) {
            if (D_004E2FC8->field_0 == 3) {
                D_004E2FC8->field_10 = func_00469450(D_004E2FCC->field_0, D_004E2FC8->field_6C);
                if (D_004E2FC8->field_10 != -1) {
                    D_004E2FC8->field_4 = 1;
                    D_004E2FCC->field_10(D_004E2FC8->field_10);
                    return 0;
                }
            }
            *status = 2;
            return err;
        } else {
            *status = 2;
            return err;
        }
    case 2:
        if (err == 0) {
            int v = *data;
            if (v == 1) {
                func_00463070(D_004E2FC8->field_14, D_004E2FC8->field_34, D_004E2FCC->field_54, D_004E2FC8->field_54);
                D_004E2FC8->field_4 = 22;
                D_004E2FCC->field_18(D_004E2FC8->field_14, D_004E2FC8->field_34, D_004E2FC8->field_10, 3);
                break;
            }
            if (v != 0) {
                *status = 2;
                return 10;
            }
            func_00468850_inl1(4);
            D_004E2FC8->field_4 = 26;
            D_004E2FCC->field_14(D_004E2FC8->field_10, 2, data);
            break;
        } else {
            func_00468850_inl1(err);
            func_00468850_inl2(D_004E2FC8->field_10, status, data);
            return 0;
        }
    case 22:
        if (err == 0) {
            int v = *data;
            if (v < 0) {
                D_004E2FC8->field_C = v;
                *status = 2;
                return 10;
            }
            D_004E2FC8->field_C = v;
            *status = 2;
            return 0;
        } else {
            func_00468850_inl1(err);
            func_00468850_inl2(D_004E2FC8->field_10, status, data);
            return 0;
        }
    case 26:
        if (err == 0) {
            if (D_004E2FC8->field_0 == 4 || D_004E2FC8->field_0 == 6) {
                *status = 2;
                return D_004E2FC8->field_8;
            }
            if (D_004E2FC8->field_8 != 0) {
                D_004E2FC8->field_10 = func_00469450(D_004E2FCC->field_0, D_004E2FC8->field_6C);
                if (D_004E2FC8->field_10 != -1) {
                    D_004E2FC8->field_4 = 1;
                    D_004E2FCC->field_10(D_004E2FC8->field_10);
                    return 0;
                }
                *status = 2;
                return D_004E2FC8->field_8;
            }
            *status = 2;
            return 0;
        } else {
            *status = 2;
            return err;
        }
    default:
        *status = 2;
        return 18;
    }
    return 0;
}
