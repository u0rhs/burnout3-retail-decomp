// func_003EFEC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E8E5D8.h"
#include "b3/classes/UnkStruct_D_01E8E5E2.h"
#include "b3/classes/UnkStruct_D_01E8F960.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003EFEC0;
struct UnkStruct_003EFEC0_4;

struct UnkStruct_003EFEC0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003EFEC0 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8E5E2 D_01E8E5E2;
extern UnkStruct_D_01E8E5D8 D_01E8E5D8;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8F960 D_01E8F960;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void func_003A5CC0(void *);
extern "C" void func_003A5C70(void *);
extern "C" unsigned long func_0045FEF0(void *);
extern "C" int func_003A5C60(void *);
extern "C" bool func_003A6330(void *, int, unsigned long, int, int, int);
extern "C" unsigned long func_0045FF40(void *);

// 0x003EFEC0
extern "C" void func_003EFEC0(UnkStruct_003EFEC0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int r0 = D_004F50C0.GetMenuBack(0);
    if (r0 != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    int r2 = D_004F50C0.GetMenuLeft(0);
    if (r2 == 0) {
        int r3 = D_004F50C0.GetMenuRight(0);
        if (r3 == 0) {
            int r4 = D_004F50C0.GetMenuUp(0);
            if (r4 != 0) {
                func_003A5CC0(&D_01E8E5D8);
                return;
            }
            int r6 = D_004F50C0.GetMenuDown(0);
            if (r6 != 0) {
                func_003A5C70(&D_01E8E5D8);
                return;
            }
            return;
        }
        if (D_01E8E5E2.field_0 != 0) {
            ((UnkStruct_D_01E8E5D8 *)&D_01E8E5D8)->vfunc_C();
        }
        unsigned long r9 = func_0045FEF0(&D_01E8F960);
        switch (self->field_4) {
        case 0:
            int r10 = func_003A5C60(&D_01E8E5D8);
            func_003A6330(&D_01E8E5D8, 0, r9, r10, 0, 0);
            break;
        case 1:
            int r12 = func_003A5C60(&D_01E8E5D8);
            func_003A6330(&D_01E8E5D8, 1, r9, r12, 0, 0);
            break;
        case 2:
            int r14 = func_003A5C60(&D_01E8E5D8);
            func_003A6330(&D_01E8E5D8, 2, r9, r14, 0, 0);
            break;
        }
        return;
    }
    if (D_01E8E5E2.field_0 != 0) {
        ((UnkStruct_D_01E8E5D8 *)&D_01E8E5D8)->vfunc_C();
    }
    unsigned long r17 = func_0045FF40(&D_01E8F960);
    switch (self->field_4) {
    case 0:
        int r18 = func_003A5C60(&D_01E8E5D8);
        func_003A6330(&D_01E8E5D8, 0, r17, r18, 0, 0);
        break;
    case 1:
        int r20 = func_003A5C60(&D_01E8E5D8);
        func_003A6330(&D_01E8E5D8, 1, r17, r20, 0, 0);
        break;
    case 2:
        int r22 = func_003A5C60(&D_01E8E5D8);
        func_003A6330(&D_01E8E5D8, 2, r17, r22, 0, 0);
        break;
    }
}
