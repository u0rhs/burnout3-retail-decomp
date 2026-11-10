// Hand-written; the lifter refused it (near28: sibling func_004655C0's do/while bounded-copy inline (s, n, d); (a0==0 && a1==0) test as goto chk placed after the final return).

struct UnkStruct_00465740_v {
    unsigned char pad_0[0xC];
    int (*vfunc_C)();
    int (*vfunc_10)(int, int);
    int (*vfunc_14)(void *);
};
struct UnkStruct_00465740_n { int field_0; };
struct UnkStruct_00465740_m { int field_0; UnkStruct_00465740_n * field_4; };
struct UnkStruct_00465740_g {
    unsigned char pad_0[0xAC];
    char field_AC[0x11];
    char field_BD[0x11];
    unsigned char pad_CE[0x6];
    int field_D4;
};
struct UnkStruct_D_004E2FC4_a { UnkStruct_00465740_g * field_0; };
extern UnkStruct_D_004E2FC4_a D_004E2FC4;
extern "C" UnkStruct_00465740_v * func_004697C0();
extern "C" int func_00461F40(int);
extern "C" int func_00465EB0(int);

static inline void func_00465740_inl1(const char * s, int n, char * d)
{
    if (s != 0 && d != 0 && s != d) {
        do {
            if (--n == 0) {
                *d = 0;
                break;
            }
        } while ((*d++ = *s++) != 0);
    }
}
static inline int func_00465740_inl2(int a)
{
    int err = 0;
    UnkStruct_00465740_m * m;
    UnkStruct_00465740_v * v = func_004697C0();
    int r = v->vfunc_C();
    if (r == 0) {
        r = v->vfunc_10(a, 0x296E);
        if (r == 0) {
            r = v->vfunc_14(&m);
            if (r == 0) {
                if (m->field_4->field_0 != 0x836C71D) err = 0x15;
            }
        }
    }
    if (r != 0) err = 0x18;
    return err;
}

// 0x00465740
extern "C" int func_00465740(void *a0_, const char * a1)
{
    int a0 = (int)a0_;
    int err = 0;
    int s1 = a0;
    if (s1 == 0) goto chk;
body:
    func_00465740_inl1(a1, 0x11, D_004E2FC4.field_0->field_AC);
    func_00465740_inl1(a1 + 0x11, 0x11, D_004E2FC4.field_0->field_BD);
after:
    if (err == 0) err = func_00465740_inl2(s1);
    if (err == 0) err = func_00461F40(s1);
    if (err == 0) {
        int r = 0;
        if (D_004E2FC4.field_0->field_D4 == 4) func_00465EB0(0); else r = 0x16;
        err = r;
    }
    return err;
chk:
    if (a1 != 0) goto body;
    err = 7;
    goto after;
}
