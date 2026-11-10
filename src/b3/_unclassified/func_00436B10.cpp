// func_00436B10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuFlowFSM.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"
#include "b3/classes/UnkStruct_D_01ECD584.h"

struct UnkStruct_00436B10;

struct UnkStruct_00436B10 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01ECD584 D_01ECD584;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern CB3MenuFlowFSM D_01EA2970;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00449150(void *, int, int);
extern "C" void func_004365B0(UnkStruct_00436B10 *, int);
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *);

// 0x00436B10
extern "C" void func_00436B10(UnkStruct_00436B10 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (func_00449150(&D_01E8F360, 0, 1)) {
    case 0:
        switch (self->field_4) {
        case 3:
            if (D_01ECD584.field_0 / 1024 < 94) {
                func_004365B0(self, 3);
                self->field_4 = 2;
            } else {
                D_01EA2970.ApplyEvent(1, 0);
            }
            break;
        default:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        }
        break;
    case 1:
        self->field_4 = 0;
        func_004365B0(self, 0);
        StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    }
}
