// func_00445730 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00131CA0(void *);

// 0x00445730
extern "C" void func_00445730()
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) == 0) {
        if (D_004F50C0.GetMenuConfirm(1) == 0 || func_00131CA0(&D_004EE040) == 0) {
            return;
        }
    }
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 1);
}
