// func_003F0FF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
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

struct UnkStruct_003F0FF0;

struct UnkStruct_003F0FF0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    short field_C;
    short field_E;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
    int field_18;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char pad_1E[0x2];
    int field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char pad_26[0x2];
    int field_28;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[0x2];
    int field_30;
    unsigned char field_34;
    unsigned char field_35;
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003F0CE0(UnkStruct_003F0FF0 *, int);

// 0x003F0FF0
extern "C" int func_003F0FF0(UnkStruct_003F0FF0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_C = self->field_4;
    self->field_E = 5;
    int r1 = func_00271A00(&D_0051BA44, 455);
    self->field_10 = r1;
    self->field_14 = 0;
    self->field_15 = 0;
    int r2 = func_00271A00(&D_0051BA44, 2559);
    self->field_18 = r2;
    self->field_1C = 0;
    self->field_1D = 0;
    int r3 = func_00271A00(&D_0051BA44, 1774);
    self->field_20 = r3;
    self->field_24 = 0;
    self->field_25 = 0;
    int r4 = func_00271A00(&D_0051BA44, 3053);
    self->field_28 = r4;
    self->field_2C = 0;
    self->field_2D = 0;
    int r5 = func_00271A00(&D_0051BA44, 3054);
    self->field_30 = r5;
    self->field_34 = 0;
    self->field_35 = 0;
    self->field_8 = -1;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0xC), (CB3VSelectComponentEntryData*)((char *)self + 0x10), 640.0f);
    func_00319C80(&D_01E89518, 899, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    int r11 = func_00271A00(&D_0051BA44, 1797);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r11, 0, 80.0f);
    func_003F0CE0(self, self->field_4);
    return 1;
}
