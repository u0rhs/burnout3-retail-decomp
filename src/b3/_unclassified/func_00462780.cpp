// Hand-written; the lifter refused it (request state machine step (sibling of func_00462200): early-return chain, switch in reverse test order, every out-of-line block a goto label after the final return 0 in retail order, done: shared return 0).

// func_00462780 -- hand-written (L254) from the asm, after the archived sibling func_00462200 (same unit,
// src/nonmatching/func_00462200.cpp): an online request state machine step over D_004E2FC8 (request state)
// and D_004E2FCC (callback table). Unnamed in every table, so a placeholder with C linkage; file and Area
// unknown, so _unclassified/. Field names are placeholders; every type is [G] (instruction widths).

struct UnkStruct_00462780_P {
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    int field_C;
    int field_10;
    unsigned char field_14[0x20];
    unsigned char field_34[0x20];
    unsigned char field_54[0x18];
    int field_6C;
};
struct UnkStruct_00462780_Blk {
    int field_0;
    int field_4;
    unsigned char field_8[0x3C8];
};
struct UnkStruct_00462780_Q {
    unsigned short field_0;
    unsigned char pad_2[2];
    void (*field_4)(void *, int);
    void (*field_8)(int);
    void (*field_C)(int);
    void (*field_10)(int);
    void (*field_14)(int);
    void (*field_18)(void *, void *, int, int);
    void (*field_1C)(int);
    void (*field_20)(void *, unsigned int, int);
    unsigned char pad_24[0xC];
    void (*field_30)(int, int, int);
    unsigned char pad_34[0x4];
    void (*field_38)(int);
    unsigned char pad_3C[0x18];
    UnkStruct_00462780_Blk field_54;
    unsigned int field_424;
    unsigned int field_428;
};
struct UnkStruct_D_004E2FC8 { UnkStruct_00462780_P * field_0; };
struct UnkStruct_D_004E2FCC { UnkStruct_00462780_Q * field_0; };
extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;
extern unsigned char D_004D3AF8[], D_004D3B08[];
extern "C" int func_00469400();
extern "C" void func_00469410(int);
extern "C" int func_00469310(int, int *);
extern "C" int func_00469360(int *, int *);
extern "C" int func_004693B0(int *, int *);
extern "C" int func_00469450(int, int);
extern "C" char *func_00463410(void *, void *, void *);
extern "C" void func_00463070(void *, void *, void *, void *);

// 0x00462780
extern "C" int func_00462780(int p0, int * out, int * p2)
{
    if (out == 0) return 0x12;
    if (p2 == 0) return 0x12;
    if (D_004E2FC8.field_0->field_0 != 1 && D_004E2FC8.field_0->field_0 != 4) return 0x12;
    *out = 1;
    switch (D_004E2FC8.field_0->field_4) {
    case 1:
        if (p0 == 0) goto c1_zero;
        if (p0 != 3) goto c1_not3;
        if (D_004E2FC8.field_0->field_0 == 1) goto c1_retry;
        *out = 2;
        return p0;
    case 2:
        if (p0 != 0) goto c2_err;
        if (*p2 == 0) goto c2_zero;
        if (*p2 == 1) goto c2_one;
        *out = 2;
        return 0xA;
    case 3:
        if (p0 != 0) goto c3_err;
        if (0 > *p2) goto c3_neg;
        if (!(D_004E2FCC.field_0->field_424 > *p2)) {
            D_004E2FC8.field_0->field_4 = 4;
            D_004E2FCC.field_0->field_C(D_004E2FC8.field_0->field_10);
            break;
        }
        func_00469410(0xE);
        D_004E2FC8.field_0->field_4 = 0x1A;
        D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
        break;
    case 4:
        if (p0 != 0) goto c4_err;
        if (0 > *p2) goto c4_neg;
        if (D_004E2FCC.field_0->field_428 > *p2) goto c4_lt;
        func_00463070(D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_34, &D_004E2FCC.field_0->field_54, D_004E2FC8.field_0->field_54);
        D_004E2FC8.field_0->field_4 = 5;
        D_004E2FCC.field_0->field_20(D_004E2FC8.field_0->field_14, D_004E2FCC.field_0->field_424, D_004E2FC8.field_0->field_10);
        break;
    case 5:
        if (p0 == 0) goto c5_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 0xE:
        if (p0 != 0) goto cE_err;
        if (0 > *p2) goto cE_neg;
        D_004E2FC8.field_0->field_C = *p2;
        D_004E2FC8.field_0->field_4 = 0x10;
        D_004E2FCC.field_0->field_38(D_004E2FC8.field_0->field_C);
        break;
    case 0x10:
        if (p0 == 0) goto c10_zero;
        func_00469410(p0);
        return func_00469360(&D_004E2FC8.field_0->field_C, out);
    case 0x11:
        if (p0 == 0) goto c11_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 6:
        if (p0 == 0) goto c6_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 7:
        if (p0 == 0) goto c7_zero;
        func_00469410(p0);
        return func_004693B0(&D_004E2FC8.field_0->field_C, out);
    case 8:
        if (p0 == 0) goto c8_zero;
        func_00469410(p0);
        return func_00469360(&D_004E2FC8.field_0->field_C, out);
    case 9:
        if (p0 == 0) goto c9_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 0xA:
        if (p0 == 0) goto cA_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 0xB:
        if (p0 == 0) goto cB_zero;
        func_00469410(p0);
        return func_004693B0(&D_004E2FC8.field_0->field_C, out);
    case 0xC:
        if (p0 == 0) goto cC_zero;
        func_00469410(p0);
        return func_00469360(&D_004E2FC8.field_0->field_C, out);
    case 0xD:
        if (p0 == 0) goto cD_zero;
        func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 0x1A:
        if (p0 != 0) goto c1A_err;
        if (D_004E2FC8.field_0->field_0 == 4) goto c1A_four;
        if (func_00469400() != 0) goto c1A_retry;
        *out = 2;
        return 0;
    default:
        *out = 2;
        return 0x12;
    }
done:
    return 0;
c1_zero: {
        unsigned char buf[0x50];
        func_00463410(buf, &D_004E2FCC.field_0->field_54, D_004E2FC8.field_0->field_54);
        D_004E2FC8.field_0->field_4 = 2;
        D_004E2FCC.field_0->field_4(buf, D_004E2FC8.field_0->field_10);
        goto done;
    }
c1_retry:
    D_004E2FC8.field_0->field_10 = func_00469450(D_004E2FCC.field_0->field_0, D_004E2FC8.field_0->field_6C);
    if (D_004E2FC8.field_0->field_10 != -1) {
        D_004E2FC8.field_0->field_4 = 1;
        D_004E2FCC.field_0->field_10(D_004E2FC8.field_0->field_10);
        return 0;
    }
    *out = 2;
    return func_00469400();
c1_not3:
    *out = 2;
    return p0;
c2_zero:
    D_004E2FC8.field_0->field_4 = 3;
    D_004E2FCC.field_0->field_8(D_004E2FC8.field_0->field_10);
    goto done;
c2_one:
    func_00469410(8);
    D_004E2FC8.field_0->field_4 = 0x1A;
    D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
    goto done;
c2_err:
    func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c3_neg:
    *out = 2;
    return 0xA;
c3_err:
    func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c4_neg:
    *out = 2;
    return 0xA;
c4_lt:
    func_00469410(0xE);
    D_004E2FC8.field_0->field_4 = 0x1A;
    D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
    goto done;
c4_err:
    func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c5_zero:
    D_004E2FC8.field_0->field_4 = 0xE;
    D_004E2FCC.field_0->field_18(D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_10, 0x203);
    goto done;
cE_neg:
    func_00469410(p0);
    return func_004693B0(&D_004E2FC8.field_0->field_C, out);
cE_err:
    func_00469410(p0);
    return func_004693B0(&D_004E2FC8.field_0->field_C, out);
c10_zero:
    D_004E2FC8.field_0->field_4 = 0x11;
    D_004E2FCC.field_0->field_1C(D_004E2FC8.field_0->field_C);
    goto done;
c11_zero:
    D_004E2FC8.field_0->field_4 = 6;
    D_004E2FCC.field_0->field_18(D_004E2FC8.field_0->field_14, D_004D3AF8, D_004E2FC8.field_0->field_10, 0x203);
    goto done;
c6_zero:
    D_004E2FC8.field_0->field_C = *p2;
    D_004E2FC8.field_0->field_4 = 7;
    D_004E2FCC.field_0->field_30(D_004E2FC8.field_0->field_C, D_004E2FCC.field_0->field_54.field_0, D_004E2FCC.field_0->field_54.field_4);
    goto done;
c7_zero:
    D_004E2FC8.field_0->field_4 = 8;
    D_004E2FCC.field_0->field_38(D_004E2FC8.field_0->field_C);
    goto done;
c8_zero:
    D_004E2FC8.field_0->field_4 = 9;
    D_004E2FCC.field_0->field_1C(D_004E2FC8.field_0->field_C);
    goto done;
c9_zero:
    D_004E2FC8.field_0->field_4 = 0xA;
    D_004E2FCC.field_0->field_18(D_004E2FC8.field_0->field_14, D_004D3B08, D_004E2FC8.field_0->field_10, 0x203);
    goto done;
cA_zero:
    D_004E2FC8.field_0->field_C = *p2;
    D_004E2FC8.field_0->field_4 = 0xB;
    D_004E2FCC.field_0->field_30(D_004E2FC8.field_0->field_C, (int)D_004E2FCC.field_0->field_54.field_8, 0x3C4);
    goto done;
cB_zero:
    D_004E2FC8.field_0->field_4 = 0xC;
    D_004E2FCC.field_0->field_38(D_004E2FC8.field_0->field_C);
    goto done;
cC_zero:
    D_004E2FC8.field_0->field_4 = 0xD;
    D_004E2FCC.field_0->field_1C(D_004E2FC8.field_0->field_C);
    goto done;
cD_zero:
    D_004E2FC8.field_0->field_4 = 0x1A;
    D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
    goto done;
c1A_four:
    *out = 2;
    return func_00469400();
c1A_retry:
    D_004E2FC8.field_0->field_10 = func_00469450(D_004E2FCC.field_0->field_0, D_004E2FC8.field_0->field_6C);
    if (D_004E2FC8.field_0->field_10 != -1) {
        D_004E2FC8.field_0->field_4 = 1;
        D_004E2FCC.field_0->field_10(D_004E2FC8.field_0->field_10);
        return 0;
    }
    *out = 2;
    return func_00469400();
c1A_err:
    *out = 2;
    return p0;
}
