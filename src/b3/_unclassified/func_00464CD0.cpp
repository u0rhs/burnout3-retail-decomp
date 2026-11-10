// Hand-written; the lifter refused it (vtable helper inls + guarded copy inl (early return)).

// Hand-written; the lifter refused it (a176: DirtySock-style record check; vtable-call helpers, null-guarded 4-byte copies).

struct UnkStruct_00464CD0_v {
    unsigned char pad_0[0xC];
    int (*vfunc_C)(int, int);
    int (*vfunc_10)(unsigned int, int);
    int (*vfunc_14)(int, int);
    int (*vfunc_18)();
};
struct UnkStruct_00464CD0_w {
    unsigned char pad_0[0xC];
    int (*vfunc_C)();
    int (*vfunc_10)(unsigned int, int);
    int (*vfunc_14)(void *);
};
struct UnkStruct_00464CD0_r { int field_0; int field_4; };
struct UnkStruct_00464CD0_g {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
    UnkStruct_00464CD0_v * field_6C;
    UnkStruct_00464CD0_w * field_70;
    unsigned char pad_74[0x4];
    int field_78;
    int field_7C;
    unsigned char pad_80[0x4];
    int field_84;
    unsigned char field_88[4];
    int field_8C;
};
struct UnkStruct_D_004E2FBC_a { UnkStruct_00464CD0_g * field_0; };
extern UnkStruct_D_004E2FBC_a D_004E2FBC;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int memcmp(const void *, const void *, unsigned int);

static inline int func_00464CD0_inl1(int a, int b)
{
    UnkStruct_00464CD0_g * g = D_004E2FBC.field_0;
    if (g->field_6C == 0) return 0;
    int r = g->field_6C->vfunc_C(g->field_64, g->field_68);
    if (r == 0) {
        r = D_004E2FBC.field_0->field_6C->vfunc_14(a, b);
        if (r == 0) {
            r = D_004E2FBC.field_0->field_6C->vfunc_18();
            if (r == 0) return 0;
        }
    }
    return r == 0 ? 0 : r + 200;
}
static inline void func_00464CD0_inl2(void * d, const void * s)
{
    if (d == 0) return;
    memcpy(d, s, 4);
}

// 0x00464CD0
extern "C" int func_00464CD0()
{
    UnkStruct_00464CD0_r * rec = 0;
    int x48 = 0;
    int x44;
    D_004E2FBC.field_0->field_78 = 10;
    char * s0 = (char *)D_004E2FBC.field_0->field_7C - 12;
    int err = func_00464CD0_inl1((int)s0, 12);
    if (err != 0) return err;
    unsigned char * s1 = D_004E2FBC.field_0->field_88;
    func_00464CD0_inl2(&x44, s0);
    func_00464CD0_inl2(&x48, s0 + 4);
    func_00464CD0_inl2(s1, s0 + 8);
    if (x44 != D_004E2FBC.field_0->field_8C) return 11;
    int n = D_004E2FBC.field_0->field_84;
    if (x48 != n) return 0x6E;
    err = func_00464CD0_inl1(D_004E2FBC.field_0->field_7C, n);
    if (err != 0) return err;
    {
        int s2 = D_004E2FBC.field_0->field_84;
        int t1 = D_004E2FBC.field_0->field_7C;
        UnkStruct_00464CD0_w * w = D_004E2FBC.field_0->field_70;
        int r = w->vfunc_C();
        if (r == 0) {
            r = w->vfunc_10(t1, s2);
            if (r == 0) {
                r = w->vfunc_14(&rec);
                if (r == 0) { err = 0; goto done; }
            }
        }
        err = r == 0 ? 0 : r + 0x12C;
    }
done:
    if (err != 0) return err;
    if (rec->field_0 != 4) return 11;
    return memcmp((void *)rec->field_4, D_004E2FBC.field_0->field_88, 4) != 0 ? 10 : 0;
}
