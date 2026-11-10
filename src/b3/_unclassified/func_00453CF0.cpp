// func_00453CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E898A4.h"
#include "b3/classes/UnkStruct_D_01E8F09A.h"
#include "b3/classes/UnkStruct_D_01E8F1CC.h"
#include "b3/classes/UnkStruct_D_01E8F294.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E8F09A D_01E8F09A;
extern UnkStruct_D_01E8F294 D_01E8F294;
extern UnkStruct_D_01E898A4 D_01E898A4;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8F1CC D_01E8F1CC;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]

// 0x00453CF0
extern "C" void func_00453CF0()
{
    int v0 = (D_01E8F09A.field_0 != 0);
    if ((D_01E8F09A.field_0 != 0) != false) {
        v0 = ((D_01E8F294.field_0 != 0) ^ 1);
    }
    D_01E898A4.field_0 = v0;
    if (D_01E90424.field_0 == 5) {
        if ((v0 & 255) != 0) {
            int r2 = D_004F50C0.GetMenuConfirm(0);
            if (r2 != 0) {
                D_01E8F1CC.field_0 = 600.0f;
            }
            return;
        }
        int r0 = D_004F50C0.GetMenuConfirm(0);
        if (r0 == 0) {
            return;
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
        return;
    }
}
