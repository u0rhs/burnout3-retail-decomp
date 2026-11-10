// Hand-written; the lifter refused it (a90: hand-written switch; sw hoisted into local first).

#include "b3/classes/UnkStruct_gCalculatedData.h"

struct UnkStruct_00137C40 {
    unsigned char pad_0[0x200];
    int field_200;
    unsigned char pad_204[0x140];
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    unsigned char pad_364[0x4];
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
};

extern UnkStruct_gCalculatedData gCalculatedData;
extern "C" int func_003F5F90(int);
extern "C" int func_003F5F70(int);

// 0x00137C40
extern "C" bool func_00137C40(UnkStruct_00137C40 * self, int p1)
{
    int sw = func_003F5F90(p1);
    bool r = false;
    int s0 = 0;
    switch (sw) {
    case 0:
        s0 = self->field_358;
        break;
    case 1:
        s0 = self->field_344;
        break;
    case 2:
        s0 = self->field_350;
        break;
    case 3:
        s0 = self->field_348;
        break;
    case 4:
        s0 = self->field_34C;
        break;
    case 5:
        s0 = self->field_354;
        break;
    case 6:
        s0 = self->field_368;
        break;
    case 7:
        s0 = self->field_36C;
        break;
    case 8:
        s0 = self->field_370;
        break;
    case 9:
        s0 = self->field_374;
        break;
    case 10:
        s0 = self->field_35C;
        break;
    case 11:
        s0 = self->field_378;
        break;
    case 12:
        s0 = self->field_37C;
        break;
    case 13:
        s0 = self->field_360;
        break;
    case 14:
        s0 = gCalculatedData.field_20 + self->field_200;
        break;
    }
    if (!(s0 < func_003F5F70(p1))) {
        r = true;
    }
    return r;
}
