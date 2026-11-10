// func_0044A1E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E89538.h"
#include "b3/classes/UnkStruct_D_01E8953C.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E898A4.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"
#include "b3/classes/UnkStruct_D_01E91C3D.h"

struct UnkStruct_0044A1E0;

struct UnkStruct_0044A1E0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char field_C;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898A4 D_01E898A4;
extern UnkStruct_D_01E91C3D D_01E91C3D;
extern UnkStruct_D_01E8953C D_01E8953C;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89538 D_01E89538;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;
extern CB3InputManager D_004F50C0;
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_00271A00(void *, int, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0032B2C0(void *, int, int);

// 0x0044A1E0
extern "C" void func_0044A1E0(UnkStruct_0044A1E0 * self, int p0, int p1)
{
    int t0 = D_01E90424.field_0;
    D_01E898A4.field_0 = self->field_C;
    if (t0 != 5) {
        return;
    }
    unsigned char t1 = D_01E91C3D.field_0;
    if (self->field_C != t1) {
        self->field_C = t1;
        if (self->field_C != 0) {
            D_01E8953C.field_0 = 214;
            int r0 = func_00271A00(&D_0051BA44, 214, p1, 5);
            Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r0, 0, 80.0f);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        } else {
            func_0032D080(&D_01E898E8, 7, self->field_8, 5, 1);
            D_01E89538.field_0 = 0;
            ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
        }
    }
    if (self->field_C == 0) {
        int r5 = func_0032B2C0(&D_01E898E8, 0, 1);
        switch (r5) {
        case 4:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)self->field_4, 0);
            return;
        case 5:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        default:
            int r8 = D_004F50C0.GetMenuBack(0);
            if (r8 == 0) {
                return;
            }
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        }
    }
}
