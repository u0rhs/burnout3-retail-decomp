// Hand-written; the lifter refused it (near6: missing self argument to func_0022DEF0/func_0022DB20 (a0 live -> jtbl base a1)).

#include "b3/classes/CGtPS2LibNet.h"

struct UnkStruct_0022E110_1 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    short field_2;
    int field_4;
    unsigned char pad_8[0x8];
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_00237320(int);
extern "C" int sceInsockSocket(int, int, int);
extern "C" void sceInsockBind(int, UnkStruct_0022E110_1 *, int);
extern "C" void SleepThreadTillVBlank__12CGtThreadMgrFv();
extern "C" void func_0022DEF0(CGtPS2LibNet *);
extern "C" void func_0022DB20(CGtPS2LibNet *);

// 0x0022E110
extern "C" void func_0022E110(CGtPS2LibNet *self)
{
    UnkStruct_0022E110_1 local;
    if (self->field_4C != 0) return;
    switch (self->field_48) {
    case 0: break;
    case 4: break;
    case 1: SleepThreadTillVBlank__12CGtThreadMgrFv(); break;
    case 2: self->field_4C = 1; break;
    case 3: func_0022DEF0(self); break;
    case 5: func_0022DB20(self); break;
    case 6:
        self->field_704 = 0xE4A;
        memset(&local, 0, 16);
        local.field_1 = 2;
        local.field_2 = func_00237320(0xE4A);
        local.field_4 = self->field_A8;
        self->field_AC = sceInsockSocket(2, 2, 0);
        sceInsockBind(self->field_AC, &local, 16);
        self->field_4C = 1;
        break;
    }
}
