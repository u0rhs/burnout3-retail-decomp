// Hand-written; the lifter refused it (mem-card page event handler [G]: jtbl 16 events, vcall via cast pointer, 'return' as out: label after switch (no default)).

// [G] CB3MemCardController-ish event handler (event 0..0xF via jtbl_004CE070); names are placeholders.
struct UnkStruct_D_01E89800 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8F360 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_bu { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_wu { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_3EE470 {
    unsigned char pad_0[0x10];
    int field_10;
};
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_bu D_01E8980A;
extern UnkStruct_D_bu D_01E8F36A;
extern UnkStruct_D_wu D_01ECD528;
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003EF920(int, int, void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
// 0x003EE470
extern "C" void func_003EE470(UnkStruct_3EE470 * self, unsigned int ev)
{
    if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    switch (ev) {
    case 0:
        func_00449F10(&D_01E8F360, 0, 168, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto out;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 1:
        {
            unsigned int k1 = D_01ECD528.field_0 >> 10;
            int t = func_00271A00(&D_0051BA44, 177);
            func_003EF920(self->field_10, t, &k1);
        }
        func_00449B70(&D_01E8F360, 2, self->field_10, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x10, 3);
        break;
    case 4:
        func_00449F10(&D_01E8F360, 0, 171, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto out;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 5:
        func_00449F10(&D_01E8F360, 2, 2256, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x10, 3);
        break;
    case 6:
        func_00449F10(&D_01E8F360, 2, 172, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x10, 3);
        break;
    case 10:
        func_00449F10(&D_01E8F360, 1, 2259, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 7:
        func_00449F10(&D_01E8F360, 1, 173, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 8:
        func_00449F10(&D_01E8F360, 0, 175, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto out;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 9:
        func_00449F10(&D_01E8F360, 2, 176, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x10, 3);
        break;
    case 2:
        {
            unsigned int k2 = D_01ECD528.field_0 >> 10;
            int t = func_00271A00(&D_0051BA44, 178);
            func_003EF920(self->field_10, t, &k2);
        }
        func_00449B70(&D_01E8F360, 2, self->field_10, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x10, 3);
        break;
    case 11:
        func_00449F10(&D_01E8F360, 3, 179, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 12:
        func_00449F10(&D_01E8F360, 3, 180, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 14:
        func_00449F10(&D_01E8F360, 1, 2257, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x108, 3);
        break;
    case 15:
        func_00449F10(&D_01E8F360, 1, 2258, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 13:
        func_00449F10(&D_01E8F360, 1, 3093, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        func_0031ECD0(&D_01E89800, 0x109, 3);
        break;
    case 3:
        break;
    }
out:
    return;
}
