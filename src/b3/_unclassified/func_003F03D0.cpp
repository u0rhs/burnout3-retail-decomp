// func_003F03D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E8EB40.h"
#include "b3/classes/UnkStruct_D_01E8EC30.h"
#include "b3/classes/UnkStruct_D_01E8EE68.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003F03D0;

struct UnkStruct_003F03D0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    unsigned char field_10;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8EE68 D_01E8EE68;
extern UnkStruct_D_01E89788 D_01E89788;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8EC30 D_01E8EC30;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E8EB40 D_01E8EB40;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" int func_0042BC70(void *);
extern "C" unsigned long func_0042B700(void *, int);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAEA0(int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0042C240(void *);
extern "C" void func_0042C020(void *);
extern "C" int func_0042C270(void *);
extern "C" void func_0042C090(void *);
extern "C" int func_0042C160(void *);
extern "C" void func_0042BD70(void *);
extern "C" int func_0042C1A0(void *);
extern "C" void func_0042BEA0(void *);
extern "C" void func_0042B010(void *, unsigned long, int);
extern "C" int func_0042B6A0(void *, int);
extern "C" int func_0042B5F0(void *, int);

// 0x003F03D0
extern "C" void func_003F03D0(UnkStruct_003F03D0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (self->field_4 <= 0) {
        return;
    }
    if (D_01E8EE68.field_0 != 0) {
        self->field_10 = 1;
    } else if (self->field_10 != 0) {
        ((UnkStruct_D_01E89788 *)&D_01E89788)->vfunc_C();
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, func_003EAEA0(func_003EB060(func_0042B700(&D_01E8EC30, func_0042BC70(&D_01E8EC30))))), 0, 80.0f);
        self->field_10 = 0;
    }
    int n = -1;
    if (D_004F50C0.GetMenuUp(0) != 0 && func_0042C240(&D_01E8EC30) != 0) {
        func_0042C020(&D_01E8EC30);
        n = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (D_004F50C0.GetMenuDown(0) != 0 && func_0042C270(&D_01E8EC30) != 0) {
        func_0042C090(&D_01E8EC30);
        n = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (D_004F50C0.GetMenuLeft(0) != 0 && func_0042C160(&D_01E8EC30) != 0) {
        func_0042BD70(&D_01E8EC30);
        n = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (D_004F50C0.GetMenuRight(0) != 0 && func_0042C1A0(&D_01E8EC30) != 0) {
        func_0042BEA0(&D_01E8EC30);
        n = func_0042BC70(&D_01E8EC30);
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    }
    if (n < 0) {
        return;
    }
    unsigned long r = func_0042B700(&D_01E8EC30, n);
    if (r != 0) {
        if (func_0042B6A0(&D_01E8EC30, n) != 0) {
            func_0042B010(&D_01E8EB40, r, func_0042B5F0(&D_01E8EC30, n));
        } else {
            func_0042B010(&D_01E8EB40, 0, 0);
        }
    } else {
        func_0042B010(&D_01E8EB40, 0, 0);
    }
}
