// func_00318340 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3ScrollingTextData.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"
#include "b3/classes/UnkStruct_D_01E7A888.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_00318340;

struct UnkStruct_00318340_14 {
    short field_0;
    short field_2;
};

struct UnkStruct_00318340_18 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_00318340_40 {
    unsigned char pad_0[0x4];
};

struct UnkStruct_00318340 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8[5];
    unsigned char pad_D[0x3];
    int field_10;
    UnkStruct_00318340_14 field_14;
    UnkStruct_00318340_18 field_18[5];
    UnkStruct_00318340_40 field_40[5];
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void SetData__20CB3ScrollingTextDataF14EGlobalStrings(void *, EGlobalStrings);  // CB3ScrollingTextData::SetData(EGlobalStrings)
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);  // CB3VSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 1 more argument(s) [G]
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPC29CB3MenuComponentSelectionDataPC20CB3ScrollingTextDatabf(void *, const void *, const void *, bool, float);  // CB3HelpBarComponent::Prepare(const CB3MenuComponentSelectionData*,const CB3ScrollingTextData*,bool,float)
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00130D00(void *);
extern "C" void func_003FA600(void *, int);

// 0x00318340
extern "C" int func_00318340(UnkStruct_00318340 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    unsigned char t0 = self->field_8[0];
    self->field_18[0].field_0 = func_00271A00(&D_0051BA44, 229);
    self->field_18[0].field_4 = t0;
    self->field_18[0].field_5 = 0;
    unsigned char t1 = self->field_8[1];
    self->field_18[1].field_0 = func_00271A00(&D_0051BA44, 230);
    self->field_18[1].field_4 = t1;
    self->field_18[1].field_5 = 0;
    unsigned char t2 = self->field_8[2];
    self->field_18[2].field_0 = func_00271A00(&D_0051BA44, 231);
    self->field_18[2].field_4 = t2;
    self->field_18[2].field_5 = 0;
    unsigned char t3 = self->field_8[3];
    self->field_18[3].field_0 = func_00271A00(&D_0051BA44, 184);
    self->field_18[3].field_4 = t3;
    self->field_18[3].field_5 = 0;
    unsigned char t4 = self->field_8[4];
    self->field_18[4].field_0 = func_00271A00(&D_0051BA44, 232);
    self->field_18[4].field_4 = t4;
    self->field_18[4].field_5 = 0;
    SetData__20CB3ScrollingTextDataF14EGlobalStrings(&self->field_40[0], (EGlobalStrings)233);
    SetData__20CB3ScrollingTextDataF14EGlobalStrings(&self->field_40[1], (EGlobalStrings)234);
    SetData__20CB3ScrollingTextDataF14EGlobalStrings(&self->field_40[2], (EGlobalStrings)235);
    SetData__20CB3ScrollingTextDataF14EGlobalStrings(&self->field_40[3], (EGlobalStrings)236);
    SetData__20CB3ScrollingTextDataF14EGlobalStrings(&self->field_40[4], (EGlobalStrings)237);
    self->field_14.field_0 = self->field_4;
    self->field_14.field_2 = 5;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)&self->field_14, (CB3VSelectComponentEntryData*)self->field_18, 480.0f);
    func_00319C80(&D_01E89518, 222, 4);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    Prepare__19CB3HelpBarComponentFPC29CB3MenuComponentSelectionDataPC20CB3ScrollingTextDatabf(&D_01E89788, (const CB3MenuComponentSelectionData*)&self->field_14, (const CB3ScrollingTextData*)self->field_40, 0, 80.0f);
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_64();
    func_0031ECD0(&D_01E89800, 260, 3);
    D_01E894FC.Prepare();
    self->field_10 = 1;
    func_00130D00(&D_0051A6A8);
    func_003FA600(&D_01E7A888, 1);
    return 1;
}
