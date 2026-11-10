// func_00372E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_00372E00;

struct UnkStruct_00372E00 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x22];
    int field_28;
};

extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// 0x00372E00
extern "C" void func_00372E00(UnkStruct_00372E00 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
    switch (self->field_4) {
    case 1:
        self->field_28 = 1;
        D_01E899C0.Show(1, 0);
        D_01E899C0.SetAllowableCharacters((EGlobalStrings)659);
        break;
    case 0:
        self->field_28 = 3;
        func_0032D080(&D_01E898E8, 4, 33, 1, 0);
        break;
    case 2:
        self->field_28 = 4;
        func_0032D080(&D_01E898E8, 7, 54, 5, 0);
        break;
    case 3:
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)38, 0);
        break;
    }
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        func_0032D080(&D_01E898E8, 4, 33, 1, 0);
        self->field_28 = 3;
    } else if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360(((char *)self + 0x4)) != 0) {
        return;
    } else if (D_004F50C0.GetMenuDown(0) != 0 && func_00319330(((char *)self + 0x4)) != 0) {
        return;
    }
}
