// func_003F39C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
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

struct UnkStruct_003F39C0;

struct UnkStruct_003F39C0 {
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
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003F39C0
extern "C" int func_003F39C0(UnkStruct_003F39C0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = 0;
    self->field_6 = 5;
    int r1 = func_00271A00(&D_0051BA44, 2450);
    self->field_8 = r1;
    self->field_C = 0;
    self->field_D = 0;
    int r2 = func_00271A00(&D_0051BA44, 408);
    self->field_10 = r2;
    self->field_14 = 0;
    self->field_15 = 0;
    int r3 = func_00271A00(&D_0051BA44, 134);
    self->field_18 = r3;
    self->field_1C = 0;
    self->field_1D = 0;
    int r4 = func_00271A00(&D_0051BA44, 199);
    self->field_20 = r4;
    self->field_24 = 0;
    self->field_25 = 0;
    int r5 = func_00271A00(&D_0051BA44, 409);
    self->field_28 = r5;
    self->field_2C = 0;
    self->field_2D = 0;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x4), (CB3VSelectComponentEntryData*)((char *)self + 0x8), 640.0f);
    func_00319C80(&D_01E89518, 454, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    return 1;
}
