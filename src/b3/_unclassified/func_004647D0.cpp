// Hand-written; the lifter refused it (near23: alignment if (!(12 < n)) goto fix + s0==0 goto block, scoped opt_repositioncode off [G]; early-return error tails via r==0?0:r+K inline).

// Hand-finished by near23: alignment as if (!(12 < n)) goto fix (fix and the s0 == 0 block out of line, goto form under a scoped
// opt_repositioncode off [G]); error tails as early returns through a static inline (r == 0 ? 0 : r + K) as in func_00464320.

struct UnkStruct_004647D0_5 { int field_0; int field_4; };
struct UnkStruct_004647D0_g {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
    UnkStruct_004647D0_5 * field_6C;
    UnkStruct_004647D0_5 * field_70;
    unsigned char pad_74[0xC];
    int field_80;
    unsigned char pad_84[0xC];
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
};
struct UnkStruct_D_004E2FBC { UnkStruct_004647D0_g * field_0; };
struct UnkStruct_D_004D3B70 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2FBC D_004E2FBC;
extern UnkStruct_D_004D3B70 D_004D3B70;

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_00360AC0(int, int, int, int);
extern "C" int func_00467EC0();
extern "C" void func_004652B0(int, void *, void *);

static inline int func_004647D0_inl1()
{
    return D_004E2FBC.field_0 != 0;
}
static inline int func_004647D0_inl3(int r, int k)
{
    return r == 0 ? 0 : r + k;
}

// 0x004647D0
// [G] scoped pragma: retail lays the alignment fix and the s0 == 0 block out of line in source order (goto form)
#pragma push
#pragma opt_repositioncode off
extern "C" int func_004647D0()
{
    int la, lb, lc, ld;
    if (!func_004647D0_inl1()) return 2;
    memcpy((void *)D_004E2FBC.field_0->field_80, &D_004D3B70, 12);
    D_004E2FBC.field_0->field_80 = D_004E2FBC.field_0->field_80 + 12;
    int s1 = D_004E2FBC.field_0->field_A0;
    int s0 = D_004E2FBC.field_0->field_80;
    la = 4;
    lb = 1;
    func_004652B0(1, &la, &lb);
    lc = 4;
    ld = 1;
    func_004652B0(1, &lc, &ld);
    unsigned int n;
    unsigned int a = ld;
    int v;
    n = a;
    if (!(12 < n)) goto fix;
back1:
    if (s0 == 0) goto four;
    func_00360AC0(s1, s0 - 12, n, la);
    v = 0;
join:
    if (v != 0) {
        return v;
    }
    goto cont;
fix:
    n = (n - 12 % n) % n + 12;
    goto back1;
four:
    v = 4;
    goto join;
cont:
    func_00360AC0(D_004E2FBC.field_0->field_A0, D_004E2FBC.field_0->field_9C, D_004E2FBC.field_0->field_90 << 4, 4);
    D_004E2FBC.field_0->field_9C = 0;
    if (D_004E2FBC.field_0->field_6C != 0) {
        int r = ((int (*)())D_004E2FBC.field_0->field_6C->field_4)();
        if (r != 0) return func_004647D0_inl3(r, 200);
        func_00360AC0(D_004E2FBC.field_0->field_A0, D_004E2FBC.field_0->field_64, D_004E2FBC.field_0->field_68, 4);
        D_004E2FBC.field_0->field_64 = 0;
    }
    D_004E2FBC.field_0->field_6C = 0;
    int r2 = ((int (*)())D_004E2FBC.field_0->field_70->field_4)();
    if (r2 != 0) return func_004647D0_inl3(r2, 300);
    D_004E2FBC.field_0->field_70 = 0;
    int r3 = func_00467EC0();
    if (r3 != 0) return func_004647D0_inl3(r3, 100);
    func_00360AC0(D_004E2FBC.field_0->field_A0, (int)D_004E2FBC.field_0, 172, 4);
    D_004E2FBC.field_0 = 0;
    return 0;
}
#pragma pop
