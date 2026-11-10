// Hand-written; the lifter refused it (a153: sibling of func_004365B0 shape (vfunc_C pre-call, 10-case jtbl, goto done in case 1)).

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
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003ECCD0
extern "C" void func_003ECCD0(void * self, int p0)
{
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    } else {
    }
    switch (p0) {
    case 0:
        func_00449F10(&D_01E8F360, 1, 0x8D9, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    case 1:
        func_00449F10(&D_01E8F360, 0, 0xA8, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 2:
        func_00449B70(&D_01E8F360, 2, func_00271A00(&D_0051BA44, 0xBA), 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 17, 3);
        break;
    case 3:
        break;
    case 4:
        func_00449F10(&D_01E8F360, 2, 0xCD, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 16, 3);
        break;
    case 5:
        func_00449F10(&D_01E8F360, 2, 0xAA, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 16, 3);
        break;
    case 6:
        func_00449F10(&D_01E8F360, 3, 0xAA, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    case 7:
        func_00449F10(&D_01E8F360, 3, 0xB3, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    case 8:
        func_00449F10(&D_01E8F360, 1, 0x8CD, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    case 9:
        func_00449F10(&D_01E8F360, 3, 0xB4, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    }
done:
    return;
}
