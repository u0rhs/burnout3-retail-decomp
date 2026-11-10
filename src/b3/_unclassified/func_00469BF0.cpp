// func_00469BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3InputManager D_004F50C0;
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_0032B2C0(void *, int, int);

// 0x00469BF0
extern "C" void func_00469BF0()
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
    case 5:
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    case 4:
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        break;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
    }
}
