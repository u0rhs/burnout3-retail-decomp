// Hand-written; the lifter refused it (nested state/event switch; one-case switches with break (not if/return); constants reused as args (13/12/3/14 regs)).

#include "b3/classes/UnkStruct_D_004F507F.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_003F4200 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x14];
    int field_1C;
};

extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" void func_003F3F90(UnkStruct_003F4200 *, int);
extern "C" void func_003F4600(UnkStruct_003F4200 *, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" void OnFormatSuccess__24CB3MemCardControllerBaseFv(void *);

// 0x003F4200
extern "C" void func_003F4200(UnkStruct_003F4200 * self, int ev)
{
    switch (self->field_4) {
    case 0:
        switch (ev) {
        case 0x31:
            self->field_4 = 2;
            func_003F4600(self, 2);
            break;
        case 0x2E:
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            func_003F3F90(self, 3);
            self->field_4 = 5;
            break;
        case 0x32:
        case 0x36:
            self->field_4 = 5;
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            func_003F3F90(self, 3);
            break;
        case 0x37:
        case 0x38:
        case 0x39:
            self->field_4 = 5;
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            func_003F3F90(self, 3);
            break;
        case 0x2F:
            self->field_4 = 3;
            func_003F4600(self, 9);
            break;
        case 0x3A:
            func_003F4600(self, 14);
            self->field_4 = 16;
            break;
        case 0x33:
            func_003F4600(self, 16);
            self->field_4 = 16;
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (ev) {
        case 0x31:
            self->field_4 = 2;
            func_003F4600(self, 2);
            break;
        }
        break;
    case 2:
        switch (ev) {
        case 0x30:
            self->field_4 = 0;
            func_003F4600(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x32:
            self->field_4 = 0;
            func_003F4600(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    case 6:
        switch (ev) {
        case 0x34:
            self->field_4 = 9;
            D_004F507F.field_0 = self->field_1C;
            func_003F4600(self, 5);
            break;
        case 0x35:
            self->field_4 = 7;
            break;
        case 0x32:
            self->field_4 = 13;
            func_003F4600(self, 11);
            break;
        }
        break;
    case 14:
        switch (ev) {
        case 0x3C:
            self->field_4 = 6;
            func_003F4600(self, 3);
            OnFormatSuccess__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x3B:
            self->field_4 = 15;
            D_004F507F.field_0 = self->field_1C;
            func_003F4600(self, 12);
            break;
        }
        break;
    case 3:
        switch (ev) {
        case 0x31:
            self->field_4 = 2;
            func_003F4600(self, 2);
            break;
        }
        break;
    case 12:
        switch (ev) {
        case 0x31:
            self->field_4 = 2;
            func_003F4600(self, 2);
            break;
        }
        break;
    case 13:
    case 16:
        switch (ev) {
        case 0x31:
            self->field_4 = 2;
            func_003F4600(self, 2);
            break;
        }
        break;
    }
}
