// func_0043C470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
#include "b3/classes/UnkStruct_D_01E90430.h"
#include "b3/classes/UnkStruct_D_01EA2984.h"

struct UnkStruct_0043C470;

struct UnkStruct_0043C470 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char field_5;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00131CA0(void *);

// 0x0043C470
extern "C" void func_0043C470(UnkStruct_0043C470 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (self->field_5 != 0) {
        if (!((D_004F50A0.field_0 - D_01EA2984.field_0) < 3.0f)) {
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
        }
    }
    if (self->field_4 != 0) {
        if (D_004F50C0.GetMenuConfirm(0) != 0 || (D_004F50C0.GetMenuConfirm(1) != 0 && func_00131CA0(&D_004EE040) != 0)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 1);
            return;
        }
    }
}
