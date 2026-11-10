// Hand-written; the lifter refused it (a135: case 0 early exit via goto done + trailing return; empty else after prefix vcall; locals l2C,l28).

struct UnkStruct_D_01E8F360 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E89800 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8F36A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01ECD528 { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_a2 { int field_0; };
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01ECD528 D_01ECD528;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern int D_004E2F5C;
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003EF920(int, int, const UnkStruct_a2 *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x004365B0
extern "C" void func_004365B0(void * self, int p0)
{
    UnkStruct_a2 l2C;
    UnkStruct_a2 l28;
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    } else {
    }
    switch (p0) {
    case 0:
        func_00449F10(&D_01E8F360, 0, 168, 0, 0, 1);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 1:
        l2C.field_0 = D_01ECD528.field_0 / 1024;
        func_003EF920(D_004E2F5C, func_00271A00(&D_0051BA44, 165), &l2C);
        func_00449B70(&D_01E8F360, 1, D_004E2F5C, 1, 0, 1);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 260, 3);
        break;
    case 2:
        l28.field_0 = D_01ECD528.field_0 / 1024;
        func_003EF920(D_004E2F5C, func_00271A00(&D_0051BA44, 166), &l28);
        func_00449B70(&D_01E8F360, 1, D_004E2F5C, 1, 0, 1);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 260, 3);
        break;
    case 3:
        func_00449F10(&D_01E8F360, 1, 202, 1, 0, 1);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 260, 3);
        break;
    case 4:
        func_00449F10(&D_01E8F360, 1, 206, 1, 0, 1);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 260, 3);
        break;
    }
done:
    return;
}
