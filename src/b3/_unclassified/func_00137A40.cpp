// Hand-written; the lifter refused it (near11: split case-14 sum (s0 = k; s0 += a + b) + bool r declared before the hoisted address).

#include "b3/classes/UnkStruct_gCalculatedData.h"
struct UnkStruct_00137A40 {
    unsigned char pad_0[0x200];
    unsigned int field_200;
    unsigned char pad_204[0x140];
    unsigned int field_344;
    unsigned int field_348;
    unsigned int field_34C;
    unsigned int field_350;
    unsigned int field_354;
    unsigned int field_358;
    unsigned int field_35C;
    unsigned int field_360;
    unsigned char pad_364[0x4];
    unsigned int field_368;
    unsigned int field_36C;
    unsigned int field_370;
    unsigned int field_374;
    unsigned int field_378;
    unsigned int field_37C;
};
struct UnkStruct_D_0064D3B0_00137A40 { unsigned char pad_0[0x1128]; unsigned int field_1128; };
extern UnkStruct_D_0064D3B0_00137A40 D_0064D3B0;
extern UnkStruct_gCalculatedData gCalculatedData;
extern unsigned int D_0051C638[];
extern unsigned int D_0051C624[];
extern unsigned int D_0051C630[];
extern unsigned int D_0051C628[];
extern unsigned int D_0051C62C[];
extern unsigned int D_0051C634[];
extern unsigned int D_0051C648[];
extern unsigned int D_0051C64C[];
extern unsigned int D_0051C650[];
extern unsigned int D_0051C654[];
extern unsigned int D_0051C63C[];
extern unsigned int D_0051C658[];
extern unsigned int D_0051C65C[];
extern unsigned int D_0051C640[];
extern "C" int func_003F5F90(int);
extern "C" int func_003F5F70(int);

// near11: case 14 as `s0 = g->field_1128; s0 += gCalculatedData.field_20 + self->field_200;` (load/addu order);
// `bool r` declared between the call result and the hoisted &D_0064D3B0 (its addiu slot). Max cases as s314.
// 0x00137A40
extern "C" bool func_00137A40(UnkStruct_00137A40 * self, int p1)
{
    int sw = func_003F5F90(p1);
    bool r = false;
    UnkStruct_D_0064D3B0_00137A40 * const g = &D_0064D3B0;
    unsigned int s0 = 0;
    switch (sw) {
    case 0: {
        unsigned int b = self->field_358;
        unsigned int d = D_0051C638[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 1: {
        unsigned int b = self->field_344;
        unsigned int d = D_0051C624[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 2: {
        unsigned int b = self->field_350;
        unsigned int d = D_0051C630[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 3: {
        unsigned int b = self->field_348;
        unsigned int d = D_0051C628[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 4: {
        unsigned int b = self->field_34C;
        unsigned int d = D_0051C62C[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 5: {
        unsigned int b = self->field_354;
        unsigned int d = D_0051C634[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 6: {
        unsigned int b = self->field_368;
        unsigned int d = D_0051C648[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 7: {
        unsigned int b = self->field_36C;
        unsigned int d = D_0051C64C[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 8: {
        unsigned int b = self->field_370;
        unsigned int d = D_0051C650[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 9: {
        unsigned int b = self->field_374;
        unsigned int d = D_0051C654[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 10: {
        unsigned int b = self->field_35C;
        unsigned int d = D_0051C63C[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 11: {
        unsigned int b = self->field_378;
        unsigned int d = D_0051C658[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 12: {
        unsigned int b = self->field_37C;
        unsigned int d = D_0051C65C[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 13: {
        unsigned int b = self->field_360;
        unsigned int d = D_0051C640[0];
        if (b < d) s0 = d; else s0 = b;
        break;
    }
    case 14:
        s0 = g->field_1128;
        s0 += gCalculatedData.field_20 + self->field_200;
        break;
    }
    if (!((int)s0 < func_003F5F70(p1))) {
        r = true;
    }
    return r;
}
