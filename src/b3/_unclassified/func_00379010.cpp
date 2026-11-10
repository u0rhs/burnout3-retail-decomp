// func_00379010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_0022CBE0(void *, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// 0x00379010
extern "C" void func_00379010(int n0)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        return;
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
        return;
    }
    if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360((void *)(n0 + 4)) != 0) || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((void *)(n0 + 4)) != 0)) return;
    if (func_0022CBE0(&D_004F50C0, 0) != 0) { StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)36, false); }
}
