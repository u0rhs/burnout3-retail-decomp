// func_003EFC00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E8EFB8.h"

struct UnkStruct_003EFC00;

struct UnkStruct_003EFC00 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned short field_8;
    short field_A;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char pad_12[0x2];
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char pad_1A[0x2];
    int field_1C;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0x2];
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
};

extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E8EFB8 D_01E8EFB8;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_0043E320(void *, int);
extern "C" void func_0043E130(void *, int);
extern "C" void func_0043E120(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003EFC00
extern "C" int func_003EFC00(UnkStruct_003EFC00 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_8 = self->field_4;
    self->field_A = 4;
    int r1 = func_00271A00(&D_0051BA44, 2556);
    self->field_C = r1;
    self->field_10 = 0;
    self->field_11 = 0;
    int r2 = func_00271A00(&D_0051BA44, 2557);
    self->field_14 = r2;
    self->field_18 = 0;
    self->field_19 = 0;
    int r3 = func_00271A00(&D_0051BA44, 2558);
    self->field_1C = r3;
    self->field_20 = 0;
    self->field_21 = 0;
    int r4 = func_00271A00(&D_0051BA44, 458);
    self->field_24 = r4;
    self->field_28 = 0;
    self->field_29 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x8), (CB3VSelectComponentEntryData*)((char *)self + 0xC), 640.0f);
    func_00319C80(&D_01E89518, 452, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    int r9 = func_00271A00(&D_0051BA44, 1796);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r9, 0, 80.0f);
    func_0043E320(&D_01E8EFB8, 1);
    switch (self->field_4) {
    case 0:
        func_0043E130(&D_01E8EFB8, 1);
        break;
    case 1:
        func_0043E130(&D_01E8EFB8, 2);
        break;
    case 2:
        func_0043E130(&D_01E8EFB8, 0);
        break;
    case 3:
        func_0043E120(&D_01E8EFB8);
        break;
    }
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    } else {
    }
    switch (self->field_8) {
    case 0:
    case 1:
    case 2:
        func_0031ECD0(&D_01E89800, 257, 3);
        break;
    case 3:
        func_0031ECD0(&D_01E89800, 261, 3);
        break;
    default:
        break;
    }
    return 1;
}
