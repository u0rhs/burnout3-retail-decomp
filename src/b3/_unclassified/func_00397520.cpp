// Hand-written; the lifter refused it (s321: archive a82 + down test as switch(func_00319330){case 0: break; default: return;} (sibling func_00397FA0)).

// func_00397520 -- [L] DNAT: CB3OnlineOpenLobbyPage::UpdatePlayerSelected() (research/proto/new_names.csv, medium)
#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_00397520_e30 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
};
struct UnkStruct_00397520 {
    unsigned char pad_0[0x4];
    unsigned char field_4[0x24];
    unsigned short field_28;
    unsigned char pad_2A[0x2];
    unsigned short field_2C;
    unsigned char pad_2E[0x2];
    UnkStruct_00397520_e30 field_30[1];
    unsigned char pad_38[0x425];
    unsigned char field_45D;
    unsigned char pad_45E[0x6];
    int field_464;
};
struct UnkStruct_D_01E89810 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};

extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8954E D_01E8954E;
extern CB3InputManager D_004F50C0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
struct UnkStruct_D_01E3D390 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E3D390 D_01E3D390;

extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, void *);
extern "C" void func_00396340(int);
extern "C" void func_00396D30(UnkStruct_00397520 *);
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00319330(unsigned short *);
extern "C" int func_00319360(unsigned short *);

// 0x00397520
extern "C" void func_00397520(UnkStruct_00397520 * self)
{
    unsigned long prompts = D_01E89810.field_0;
    if (self->field_30[self->field_2C].field_4 != 0) {
        prompts &= ~4UL;
    } else {
        prompts |= 4;
    }
    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, prompts, 3);
    if (D_004F50C0.GetMenuConfirm(0) != 0 && self->field_30[self->field_2C].field_4 == 0) {
        switch (self->field_2C) {
        case 0:
            if (self->field_464 != self->field_28) {
                self->field_45D = 4;
                if (BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, &self->field_4, (void *)func_00396340, self) == 0) {
                    func_0032D080(&D_01E898E8, 0, 0x40, 0xF, 0);
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                } else {
                    func_0032D080(&D_01E898E8, 2, 0x42, 0, 0);
                    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                    func_0031ECD0(&D_01E89800, 4, 3);
                }
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x2C, 0);
            }
            break;
        case 1:
            self->field_45D = 5;
            D_01E899C0.Show(1, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x293);
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x105, 0xF);
            break;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x2C, 0);
            break;
        case 3:
            self->field_45D = 7;
            func_0032D080(&D_01E898E8, 7, 0x36, 5, 0);
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x104, 0xC);
            break;
        case 4:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x2A, 0);
            return;
        default:
            break;
        }
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        if (D_01E8954E.field_0 != 0) {
            ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
        }
        func_00396D30(self);
    } else {
        if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360(&self->field_2C) != 0) {
            return;
        }
        if (D_004F50C0.GetMenuDown(0) != 0) {
            switch (func_00319330(&self->field_2C)) {   // s321: switch form as in sibling func_00397FA0 (beqz; nop; b out)
            case 0:
                break;
            default:
                return;
            }
        }
        if (func_0022CBE0(&D_004F50C0, 0) != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x24, 0);
            return;
        }
    }
}
