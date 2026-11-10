// Hand-written; the lifter refused it (mwperm: 'done:' -> 'done:'; +'UnkStruct_00464320_e * s2 = D_004E2FBC.field_0->field_9C;'; 'UnkStruct_00464320_e * s2 = D_004E2FBC.field_0->field_9C;' -> '').

// Hand-written; the lifter refused it (a176: nth-entry search + vtable-style call chain; goto-laid-out loops).

struct UnkStruct_00464320_e { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_00464320_o { int field_0; int field_4; };
struct UnkStruct_00464320_v {
    unsigned char pad_0[0xC];
    int (*vfunc_C)();
    int (*vfunc_10)(unsigned int, int);
    int (*vfunc_14)(void *);
};
struct UnkStruct_00464320_g {
    unsigned char pad_0[0x70];
    UnkStruct_00464320_v * field_70;
    int field_74;
    int field_78;
    int field_7C;
    unsigned char pad_80[0x4];
    int field_84;
    unsigned char field_88[4];
    int field_8C;
    unsigned char pad_90[0x4];
    int field_94;
    int field_98;
    UnkStruct_00464320_e * field_9C;
};
struct UnkStruct_D_004E2FBC_a { UnkStruct_00464320_g * field_0; };
extern UnkStruct_D_004E2FBC_a D_004E2FBC;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_00467440(void *, int, int);
extern "C" char *func_004651E0(int, int, void *);

static inline int func_00464320_inl1(int r)
{
    if (r == 0) return 0;
    return r + 0x12C;
}
static inline int func_00464320_inl2(int r)
{
    if (r == 0) return 0;
    return r + 0x64;
}

// 0x00464320
extern "C" int func_00464320(char * a0, int a1, int a2, int a3, int t0)
{
    UnkStruct_00464320_o * o9C = 0;
    UnkStruct_00464320_o * o98;
    D_004E2FBC.field_0->field_74 = 6;
    D_004E2FBC.field_0->field_78 = 5;
    memcpy(D_004E2FBC.field_0, a0, 0x64);
    int n = 0;
    D_004E2FBC.field_0->field_8C = a1;
    D_004E2FBC.field_0->field_7C = a3;
    D_004E2FBC.field_0->field_84 = t0;
    UnkStruct_00464320_e * e = D_004E2FBC.field_0->field_9C;
    UnkStruct_00464320_e * end = e + D_004E2FBC.field_0->field_94;
    goto test;
body:
    if (a1 == e->field_0) goto inner;
inc:
    e++;
test:
    if (e < end) goto body;
    e = 0;
found:
    {
        int s5 = D_004E2FBC.field_0->field_84;
        int s6 = D_004E2FBC.field_0->field_7C;
        UnkStruct_00464320_v * s0 = D_004E2FBC.field_0->field_70;
        int r = s0->vfunc_C();
        int v;
        if (r == 0) {
            r = s0->vfunc_10(s6, s5);
            if (r == 0) {
                r = s0->vfunc_14(&o9C);
                if (r == 0) {
                    v = 0;
                    goto done;
                }
            }
        }
        v = func_00464320_inl1(r);
    done:
        if (v != 0) return v;
    }
    memcpy(D_004E2FBC.field_0->field_88, (void *)o9C->field_4, 4);
    int s5;
    if (e == 0) {
        s5 = D_004E2FBC.field_0->field_98;
        func_004651E0(a1, D_004E2FBC.field_0->field_84, D_004E2FBC.field_0->field_88);
    } else {
        s5 = e->field_4;
        unsigned char * p6 = D_004E2FBC.field_0->field_88;
        UnkStruct_00464320_e * q = D_004E2FBC.field_0->field_9C;
        UnkStruct_00464320_e * qend = q + D_004E2FBC.field_0->field_94;
        int c = 0;
        for (; q < qend; q++) {
            if (a1 == q->field_0) {
                if (a2 == c) memcpy(&q->field_C, p6, 4);
                c++;
            }
        }
    }
    int s0 = D_004E2FBC.field_0->field_94 * 16;
    if (s0 == 0) {
        memset(a0 + 0x60, 0, 4);
    } else {
        UnkStruct_00464320_e * s2 = D_004E2FBC.field_0->field_9C;
        UnkStruct_00464320_v * s1 = D_004E2FBC.field_0->field_70;
        if (s1->vfunc_C() == 0) {
            if (s1->vfunc_10((unsigned int)s2, s0) == 0) s1->vfunc_14(&o98);
        }
        memcpy(a0 + 0x60, (void *)o98->field_4, 4);
    }
    int r2 = func_00467440(a0, s5, 0);
    return func_00464320_inl2(r2);
inner:
    if (a2 == n) goto found;
    n++;
    goto inc;
}
