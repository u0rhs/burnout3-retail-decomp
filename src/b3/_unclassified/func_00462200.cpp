// Hand-written; the lifter refused it (goto-label out-of-line blocks after final return 0 in retail order, shared done: (sibling func_00462780 form)).

// func_00462200 -- placeholder (a184; L264 goto layout after the proven sibling func_00462780). Online request state machine step.
struct UnkStruct_00462200_P {
    int field_0;
    int field_4;
    unsigned char pad_8[0x8];
    int field_10;
    unsigned char field_14[0x40];
    unsigned char field_54[0x18];
    int field_6C;
};
struct UnkStruct_00462200_Q {
    unsigned short field_0;
    unsigned char pad_2[2];
    void (*field_4)(void *, int);
    unsigned char pad_8[8];
    void (*field_10)(int);
    void (*field_14)(int);
    unsigned char pad_18[0xC];
    void (*field_24)(void *, const void *, int);
    void (*field_28)(void *, int);
    unsigned char pad_2C[0x18];
    void (*field_44)(void *);
    unsigned char pad_48[0xC];
    unsigned char field_54[0x18];
};
struct UnkStruct_D_004E2FC8 { UnkStruct_00462200_P * field_0; };
struct UnkStruct_D_004E2FCC { UnkStruct_00462200_Q * field_0; };
extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern UnkStruct_D_004E2FCC D_004E2FCC;
extern unsigned char D_004D3AF8[], D_004D3B08[];
extern "C" int func_00469400();
extern "C" void func_00469410(int);
extern "C" int func_00469310(int, int *);
extern "C" int func_00469450(int, int);
extern "C" char *func_00463410(void *, void *, void *);

// 0x00462200
extern "C" int func_00462200(int p0, int * out, int * p2)
{
    if (out == 0) return 0x12;
    if (p2 == 0) return 0x12;
    if (D_004E2FC8.field_0->field_0 != 2 && D_004E2FC8.field_0->field_0 != 5) return 0x12;
    *out = 1;
    switch (D_004E2FC8.field_0->field_4) {
    case 1:
        func_00469410(0);
        if (p0 == 0) goto c1_zero;
        if (p0 != 3) goto c1_not3;
        if (D_004E2FC8.field_0->field_0 == 2) goto c1_retry;
        *out = 2;
        return p0;
    case 2:
        if (p0 != 0) goto c2_err;
        if (*p2 == 1) goto c2_one;
        if (*p2 == 0) goto c2_zero;
        *out = 2;
        return 0xA;
    case 0x13:
        if (p0 == 3) goto c13_3;
        if (p0 != 4) {
            if (func_00469400() == 0) func_00469410(p0);
        }
        D_004E2FC8.field_0->field_4 = 0x14;
        D_004E2FCC.field_0->field_24(D_004E2FC8.field_0->field_14, D_004D3AF8, D_004E2FC8.field_0->field_10);
        break;
    case 0x14:
        if (p0 == 3) goto c14_3;
        if (p0 != 4) {
            if (func_00469400() == 0) func_00469410(p0);
        }
        D_004E2FC8.field_0->field_4 = 0x15;
        D_004E2FCC.field_0->field_24(D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_10);
        break;
    case 0x15:
        if (p0 == 3) goto c15_3;
        if (p0 != 4) {
            if (func_00469400() == 0) func_00469410(p0);
        }
        D_004E2FC8.field_0->field_4 = 0x12;
        D_004E2FCC.field_0->field_28(D_004E2FC8.field_0->field_14, D_004E2FC8.field_0->field_10);
        break;
    case 0x12:
        if (p0 == 0) {
            if (func_00469400() == 0) func_00469410(p0);
            D_004E2FC8.field_0->field_4 = 0x1A;
            D_004E2FCC.field_0->field_14(D_004E2FC8.field_0->field_10);
            break;
        }
        if (func_00469400() == 0) func_00469410(p0);
        return func_00469310(D_004E2FC8.field_0->field_10, out);
    case 0x1A:
        if (p0 != 0) goto c1A_err;
        if (D_004E2FC8.field_0->field_0 == 5) goto c1A_five;
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
        func_00463410(buf, D_004E2FCC.field_0->field_54, D_004E2FC8.field_0->field_54);
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
c2_one:
    D_004E2FCC.field_0->field_44(D_004E2FC8.field_0->field_14);
    D_004E2FC8.field_0->field_4 = 0x13;
    D_004E2FCC.field_0->field_24(D_004E2FC8.field_0->field_14, D_004D3B08, D_004E2FC8.field_0->field_10);
    goto done;
c2_zero:
    func_00469410(4);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c2_err:
    func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c13_3:
    if (func_00469400() == 0) func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c14_3:
    if (func_00469400() == 0) func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c15_3:
    if (func_00469400() == 0) func_00469410(p0);
    return func_00469310(D_004E2FC8.field_0->field_10, out);
c1A_five:
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
