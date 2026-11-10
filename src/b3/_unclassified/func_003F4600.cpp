// Hand-written; the lifter refused it (state setter switch 0..16, siblings func_004365B0/func_003F3F90 shape (goto done on D_01E8980A==0); case order 13 before 12).

// func_003F4600 -- CB3MyBurnoutProfileCreateNewPage state setter [G] (switch on state 0..16; sibling of func_004365B0 / func_003F3F90)
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"

struct UnkStruct_003F4600 {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_D_01ECD528_x { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2D11_x { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01EA2D12_x { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003F4600_a { int field_0; };

extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01ECD528_x D_01ECD528;
extern UnkStruct_D_01EA2D11_x D_01EA2D11;
extern UnkStruct_D_01EA2D12_x D_01EA2D12;
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" void func_003F3F90(UnkStruct_003F4600 *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003EF920(int, int, const UnkStruct_003F4600_a *);

// 0x003F4600
extern "C" void func_003F4600(UnkStruct_003F4600 * self, int p0)
{
    UnkStruct_003F4600_a l3C;
    UnkStruct_003F4600_a l38;
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    }
    switch (p0) {
    case 1:
        func_00449F10(&D_01E8F360, 1, 2265, 1, 0, 0);
        func_003F3F90(self, 0);
        break;
    case 6:
        func_00449F10(&D_01E8F360, 1, 2257, 1, 0, 0);
        func_003F3F90(self, 0);
        break;
    case 7:
        func_00449F10(&D_01E8F360, 1, 2258, 1, 0, 0);
        func_003F3F90(self, 0);
        break;
    case 0:
        func_00449F10(&D_01E8F360, 0, 168, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 2:
        l3C.field_0 = D_01ECD528.field_0 >> 10;
        func_003EF920(self->field_C, func_00271A00(&D_0051BA44, 177), &l3C);
        func_00449B70(&D_01E8F360, 2, self->field_C, 0, 0, 0);
        func_003F3F90(self, 1);
        break;
    case 3:
        func_00449F10(&D_01E8F360, 0, 171, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 4:
        func_00449F10(&D_01E8F360, 2, 0x8D0, 0, 0, 0);
        func_003F3F90(self, 1);
        D_01EA2D11.field_0 = 0;
        D_01EA2D12.field_0 = 0;
        break;
    case 5:
        func_00449F10(&D_01E8F360, 2, 172, 0, 0, 0);
        func_003F3F90(self, 1);
        break;
    case 8:
        func_00449F10(&D_01E8F360, 1, 2259, 1, 0, 0);
        func_003F3F90(self, 0);
        break;
    case 9:
        l38.field_0 = D_01ECD528.field_0 >> 10;
        func_003EF920(self->field_C, func_00271A00(&D_0051BA44, 178), &l38);
        func_00449B70(&D_01E8F360, 2, self->field_C, 0, 0, 0);
        func_003F3F90(self, 1);
        break;
    case 10:
        break;
    case 11:
        func_00449F10(&D_01E8F360, 1, 173, 1, 0, 0);
        func_003F3F90(self, 4);
        break;
    case 13:
        func_00449F10(&D_01E8F360, 0, 175, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 12:
        func_00449F10(&D_01E8F360, 2, 176, 0, 0, 0);
        func_003F3F90(self, 1);
        break;
    case 14:
        func_00449F10(&D_01E8F360, 3, 179, 1, 0, 0);
        func_003F3F90(self, 2);
        break;
    case 15:
        func_00449F10(&D_01E8F360, 3, 2253, 1, 0, 0);
        func_003F3F90(self, 2);
        break;
    case 16:
        func_00449F10(&D_01E8F360, 3, 180, 1, 0, 0);
        func_003F3F90(self, 2);
        break;
    }
done:
    return;
}
