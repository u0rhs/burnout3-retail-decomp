// func_00439D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" int func_0022B9E0(void *);
extern "C" void func_0032CF60(void *, int, void *, int, int);

// 0x00439D00
extern "C" void func_00439D00()
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int r0 = func_00271A00(&D_0051BA44, 133);
    if (func_0022B9E0(&D_004F50C0) == 0) {
        if (D_01E898F2.field_0 == 0) {
            func_0032CF60(&D_01E898E8, 0, (void *)(r0), 15, 0);
        }
    } else {
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
    }
}
