// func_0043F570 -- tiny-function batch (tools/tiny_batch.py, lifted).
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

struct UnkStruct_0043F570;

struct UnkStruct_0043F570 {
    unsigned char pad_0[0x4];
    int field_4;
    short field_8;
    short field_A;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char pad_12[0x2];
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
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

// 0x0043F570
extern "C" int func_0043F570(UnkStruct_0043F570 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_8 = self->field_4;
    self->field_A = 2;
    int r1 = func_00271A00(&D_0051BA44, 2455);
    self->field_C = r1;
    self->field_10 = 0;
    self->field_11 = 0;
    int r2 = func_00271A00(&D_0051BA44, 2456);
    self->field_14 = r2;
    self->field_18 = 0;
    self->field_19 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x8), (CB3VSelectComponentEntryData*)((char *)self + 0xC), 640.0f);
    func_00319C80(&D_01E89518, 241, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    int r8 = func_00271A00(&D_0051BA44, 246);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r8, 0, 80.0f);
    return 1;
}
