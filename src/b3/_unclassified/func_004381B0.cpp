// func_004381B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004B0334.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

struct UnkStruct_004381B0;
struct UnkStruct_004381B0_4;

struct UnkStruct_004381B0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_004381B0 {
    unsigned char pad_0[0x44];
    unsigned short field_44;
    unsigned char pad_46[0x6];
    int field_4C;
    int field_50;
    int field_54;
};

extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_004B0334 D_004B0334;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_003361C0(void *, void *, unsigned short);
extern "C" int func_00319330(void *);
extern "C" int func_00271A00(void *, int);
extern "C" int func_00319360(void *);

// 0x004381B0
extern "C" void func_004381B0(UnkStruct_004381B0 * self)
{
    if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x44) != 0)
     || (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((char *)self + 0x44) != 0)) {
        ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, D_004B0334.field_0[self->field_44].field_0), 0, 80.0f);
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        if (self->field_54 != 1 && self->field_44 < 2) {
            func_003361C0(&D_01E3CD44, (void *)(self->field_4C), self->field_44);
            func_0032D080(&D_01E898E8, 2, 972, 15, 0);
            self->field_50 = 2;
        } else {
            func_0032D080(&D_01E898E8, 7, 3445, 5, 0);
            self->field_50 = 1;
        }
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        if (self->field_54 == 1) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)37, 0);
        } else {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
    }
}
