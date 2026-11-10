// func_00397FA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3NetworkManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_00397FA0;
struct UnkStruct_00397FA0_3;
struct UnkStruct_00397FA0_5;

struct UnkStruct_00397FA0_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00397FA0_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00397FA0 {
    unsigned char pad_0[0x2C];
    unsigned short field_2C;
    unsigned char pad_2E[0x42E];
    unsigned char field_45C;
    unsigned char field_45D;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_003362B0(void *);
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00319330(unsigned short *);
extern "C" int func_00319360(unsigned short *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00396D30(UnkStruct_00397FA0 *);

// 0x00397FA0
extern "C" void func_00397FA0(UnkStruct_00397FA0 * self)
{
    if (self->field_45D == 9) {
        if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 0) {
            return;
        }
        self->field_45D = 0;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        switch (self->field_2C) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 1:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 2:
            if (D_01E8954E.field_0 != 0) {
                ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
            }
            self->field_45C = self->field_45D;
            self->field_45D = 1;
            if (D_01E8954E.field_0 != 0) {
                ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
            }
            D_01E899C0.Show(1, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0031ECD0(&D_01E89800, 0x40000144, 15);
            D_01E8CBE0.SetOrientation((EB3ChatDisplayOrientation)0);
            D_01E7A800.FESelect();
            break;
        case 3:
            if (D_01E8954E.field_0 != 0) {
                ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
            }
            func_00396D30(self);
            D_01E7A800.FESelect();
            break;
        }
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        self->field_45D = 8;
        func_0032D080(&D_01E898E8, 0, 3155, 15, 0);
        func_003362B0(&D_01E3CD44);
    } else {
        if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360(&self->field_2C) != 0) {
            return;
        }
        if (D_004F50C0.GetMenuDown(0) != 0) {
            switch (func_00319330(&self->field_2C)) {
            case 0:
                break;
            default:
                return;
            }
        }
        if (func_0022CBE0(&D_004F50C0, 0) != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)36, 0);
            return;
        }
    }
}
