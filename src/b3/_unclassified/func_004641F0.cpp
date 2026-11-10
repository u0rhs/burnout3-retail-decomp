// Hand-written; the lifter refused it (a118: nth-match search with goto-laid-out blocks (inner/ret7/doit after chk); e declared before n).

struct UnkStruct_004641F0_e { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_004641F0_g {
    unsigned char pad_0[0x74];
    int field_74;
    int field_78;
    int field_7C;
    unsigned char pad_80[0x4];
    int field_84;
    unsigned char pad_88[0x4];
    int field_8C;
    unsigned char pad_90[0x4];
    int field_94;
    int field_98;
    UnkStruct_004641F0_e * field_9C;
    unsigned char pad_A0[0x4];
    int field_A4;
};
struct UnkStruct_D_004E2FBC_a { UnkStruct_004641F0_g * field_0; };
extern UnkStruct_D_004E2FBC_a D_004E2FBC;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int func_00467440(void *, int, int);

// 0x004641F0
extern "C" int func_004641F0(void * a0, int a1, int a2, int a3, int t0)
{
    D_004E2FBC.field_0->field_74 = 8;
    D_004E2FBC.field_0->field_78 = 5;
    memcpy(D_004E2FBC.field_0, a0, 0x64);
    D_004E2FBC.field_0->field_8C = a1;
    D_004E2FBC.field_0->field_7C = a3;
    D_004E2FBC.field_0->field_84 = t0;
    UnkStruct_004641F0_g * g = D_004E2FBC.field_0;
    UnkStruct_004641F0_e * e = g->field_9C;
    int n = 0;
    UnkStruct_004641F0_e * end = e + g->field_94;
    goto test;
body:
    if (a1 == e->field_0) goto inner;
inc:
    e++;
test:
    if (e < end) goto body;
    e = 0;
chk:
    if (e == 0) goto ret7;
    if (t0 == e->field_8) goto doit;
    return 0x6E;
inner:
    if (a2 == n) goto chk;
    n++;
    goto inc;
ret7:
    return 7;
doit:
    {
        int k = e->field_4;
        g->field_A4 = k;
        int r = func_00467440(a0, k, 0);
        if (r == 0) return 0;
        return r + 100;
    }
}
