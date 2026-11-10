// Hand-written; the lifter refused it (a156: page state setter switch 0..8 on func_003F4600's shape; cases in block-address order 0,2,3,4,5,7,8,6,1; devirtualised D_01E89788 vcall via cast).

// Hand-written (a156): menu page state setter (switch 0..8), shape of func_003F4600 / func_004365B0.
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_0051BF9C.h"

struct UnkStruct_0041FE00 {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_D_01E89792_x { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0041FE00_a { int field_0; };

extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E89792_x D_01E89792;
extern unsigned short D_004D1370[];
extern "C" void func_00449F10(void *, int, int, int, int, int);
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0013B730(void *);
extern "C" void func_003180A0(void *, void *, const UnkStruct_0041FE00_a *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);

// 0x0041FE00
extern "C" void func_0041FE00(UnkStruct_0041FE00 * self, int p0)
{
    UnkStruct_0041FE00_a l3C;
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    }
    if (D_01E89792.field_0 != 0) {
        ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
    }
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, D_004D1370, 0, 80.0f);
    switch (p0) {
    case 0:
        func_00449F10(&D_01E8F360, 0, 168, 0, 0, 0);
        if (D_01E8980A.field_0 == 0) goto done;
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        break;
    case 2:
        l3C.field_0 = func_0013B730(D_0051BF9C.field_0);
        func_003180A0((void *)(self->field_C), (void *)(func_00271A00(&D_0051BA44, 167)), &l3C);
        func_00449B70(&D_01E8F360, 1, self->field_C, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 264, 3);
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_00449F10(&D_01E8F360, 0, 171, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        if (D_01E89792.field_0 != 0) {
            ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
        }
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 436), 0, 80.0f);
        break;
    case 7:
        func_00449F10(&D_01E8F360, 2, 2256, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 16, 3);
        break;
    case 8:
        func_00449F10(&D_01E8F360, 2, 172, 0, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 16, 3);
        break;
    case 6:
        func_00449F10(&D_01E8F360, 1, 2257, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 264, 3);
        break;
    case 1:
        func_00449F10(&D_01E8F360, 1, 2258, 1, 0, 0);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        func_0031ECD0(&D_01E89800, 264, 3);
        break;
    }
done:
    return;
}
