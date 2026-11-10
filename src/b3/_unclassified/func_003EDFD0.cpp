// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/func_003EDFD0_l263da.cpp)).

// Hand-written; the lifter refused it (nested state/event switch, cloned from func_003F4200; jump-table cases in retail's block order).

// func_003EDFD0 -- [G] CB3MyBurnoutProfileSavePage event handler (file neighbours func_003EDEE0 OnKeyboardDone, func_003EEB20 Update [L] DNAT; shape of func_003F4200 ProcessMemoryCardEvent)
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_004F507F.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_003EDFD0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
    int field_8;
    unsigned char pad_C[0x14];
    int field_20;
    int field_24;
};
struct UnkStruct_003EDFD0_o { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_003EDFD0_o D_01E899C0;
extern "C" int func_00449B70(void *, int, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003EE470(UnkStruct_003EDFD0 *, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" void OnFormatSuccess__24CB3MemCardControllerBaseFv(void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);

// 0x003EDFD0
extern "C" void func_003EDFD0(UnkStruct_003EDFD0 * self, int ev)
{
    switch (self->field_8) {
    case 0:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            return;
        case 0x2E:
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x105, 3);
            self->field_8 = 4;
            break;
        case 0x32:
            self->field_8 = 4;
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x105, 3);
            break;
        case 0x37:
        case 0x38:
        case 0x39:
            self->field_8 = 4;
            if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
            func_00449B70(&D_01E8F360, 6, 0, 0, 0, 0);
            if (D_01E8980A.field_0 != 0) ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x105, 3);
            break;
        case 0x2F:
            self->field_8 = 2;
            func_003EE470(self, 2);
            break;
        case 0x3A:
            func_003EE470(self, 11);
            self->field_8 = 13;
            break;
        case 0x33:
            func_003EE470(self, 12);
            self->field_8 = 13;
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            break;
        }
        break;
    case 1:
        switch (ev) {
        case 0x30:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x32:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    case 5:
        switch (ev) {
        case 0x34:
            self->field_8 = 8;
            if (self->field_4 != 0) D_004F507F.field_0 = self->field_20;
            func_003EE470(self, 6);
            break;
        case 0x35:
            self->field_8 = 6;
            break;
        case 0x32:
            self->field_8 = 9;
            func_003EE470(self, 7);
            break;
        }
        break;
    case 10:
        switch (ev) {
        case 0x3C:
            self->field_8 = 5;
            self->field_24 = 0;
            func_003EE470(self, 4);
            OnFormatSuccess__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x3B:
            self->field_8 = 11;
            func_003EE470(self, 9);
            break;
        }
        break;
    case 2:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            break;
        }
        break;
    case 12:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            break;
        }
        break;
    case 9:
    case 13:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            break;
        }
        break;
    case 14:
        switch (ev) {
        case 0x31:
            self->field_8 = 1;
            func_003EE470(self, 1);
            Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
            break;
        }
        break;
    }
}
