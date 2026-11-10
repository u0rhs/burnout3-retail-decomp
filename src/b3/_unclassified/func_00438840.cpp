// func_00438840 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_00438840;

struct UnkStruct_00438840 {
    unsigned char pad_0[0x14];
    float field_14;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)

// 0x00438840
extern "C" void func_00438840(UnkStruct_00438840 * self)
{
    if (D_01E90424.field_0 == 5) {
        float r0 = D_004F50C0.GetDeadInputTime(-1);
        if (r0 <= 90.0f) {
            int r2 = D_004F50C0.GetStartButton(1, -1);
            if (r2 != 0) {
                float t0 = D_004F50A0.field_0;
                if (!(t0 <= (2.0f + self->field_14))) {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
                    return;
                }
                return;
            }
            return;
        }
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)5, 1);
        return;
    }
}
