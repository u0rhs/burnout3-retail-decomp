// func_00379140 -- tiny-function batch (tools/tiny_batch.py, lifted).
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
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_00379140;

struct UnkStruct_00379140 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[0x2];
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
};

extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int FindCrashStageName__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);

// 0x00379140
extern "C" int func_00379140(UnkStruct_00379140 * self, unsigned long p0)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int r1 = FindCrashStageName__26CB3HardCodedCrashStageListFUl(p0);
    func_00319C80(&D_01E89518, r1, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 325, 3);
    D_01E894FC.Prepare();
    self->field_4 = 0;
    self->field_6 = 2;
    int r6 = func_00271A00(&D_0051BA44, 689);
    self->field_8 = r6;
    self->field_C = 0;
    self->field_D = 0;
    int r7 = func_00271A00(&D_0051BA44, 690);
    self->field_10 = r7;
    self->field_14 = 0;
    self->field_15 = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 640.0f);
    return 1;
}
