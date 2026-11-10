// func_0042E5D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_0042E5D0;

struct UnkStruct_0042E5D0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00449150(void *, int, int);

// 0x0042E5D0
extern "C" void func_0042E5D0(UnkStruct_0042E5D0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int r0 = func_00449150(&D_01E8F360, 0, 1);
    self->field_4 = r0;
    switch (r0) {
    case 4:
        switch (self->field_8) {
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
            break;
        }
        break;
    case 5:
        switch (self->field_8) {
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
            break;
        }
        break;
    case 0:
    case 1:
        break;
    }
}
