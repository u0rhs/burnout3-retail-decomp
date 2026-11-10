// func_0045BDD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_0045BDD0;
struct UnkStruct_0045BDD0_4;

struct UnkStruct_0045BDD0_4 {
    int field_0;
    short field_4;
    short field_6;
};

struct UnkStruct_0045BDD0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x40];
    UnkStruct_0045BDD0_4 * field_50;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern int D_004D3730[];  // [G] element count unknown
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 2 more argument(s) [G]
extern "C" int func_0022CBE0(void *, int);
extern "C" void func_0045BC50(UnkStruct_0045BDD0 *);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// 0x0045BDD0
extern "C" void func_0045BDD0(UnkStruct_0045BDD0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
    } else if (func_0022CBE0(&D_004F50C0, 0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)36, 0);
    } else if (D_004F50C0.GetMenuConfirm(0) != 0) {
        self->field_50->field_0 = D_004D3730[self->field_4];
        self->field_50->field_4 = self->field_8;
        self->field_50->field_6 = self->field_C;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
    } else {
        if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x10) != 0) {
            return;
        }
        if (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((char *)self + 0x10) != 0) {
            return;
        }
        func_0045BC50(self);
    }
}
