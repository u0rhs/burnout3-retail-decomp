// OnKeyboardCancel__32CB3MyBurnoutProfileCreateNewPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051A998.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_003F40E0;

struct UnkStruct_003F40E0 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_0051A998 D_0051A998;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_003F4600(UnkStruct_003F40E0 *, int);

// 0x003F40E0
extern "C" void OnKeyboardCancel__32CB3MyBurnoutProfileCreateNewPageFv(UnkStruct_003F40E0 * self)
{
    if (self->field_4 != 17) {
        return;
    }
    if (D_0051A998.field_0 == 0) {
        self->field_4 = 1;
        func_003F4600(self, 1);
    } else {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
    }
    D_01E899C0.Show(0, 0);
}
