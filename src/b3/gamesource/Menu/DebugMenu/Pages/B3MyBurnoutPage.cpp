// B3MyBurnoutPage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3MyBurnoutPage.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, same unit as the hand-placed file there (its docs/layout.md row).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MenuComponentSelectionData.h"
#include "b3/classes/CB3Profile.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3VSelectComponentEntryData.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_0051BF9C.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_00322450;

struct UnkStruct_00322450 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x800];
    int field_808;
    short field_80C;
    short field_80E;
    int field_810;
    unsigned char field_814;
    unsigned char field_815;
    unsigned char pad_816[0x2];
    int field_818;
    unsigned char field_81C;
    unsigned char field_81D;
    unsigned char pad_81E[0x2];
    int field_820;
    unsigned char field_824;
    unsigned char field_825;
    unsigned char pad_826[0x2];
    int field_828;
    unsigned char field_82C;
    unsigned char field_82D;
    unsigned char pad_82E[0x2];
    int field_830;
    unsigned char field_834;
    unsigned char field_835;
    unsigned char pad_836[0x2];
    int field_838;
    unsigned char field_83C;
    unsigned char field_83D;
    unsigned char pad_83E[0x2];
    int field_840;
    unsigned char field_844;
    unsigned char field_845;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
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
extern "C" void func_00139F20(CB3Profile *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00321870(UnkStruct_00322450 *, int);

// func_00322450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00322450
extern "C" int func_00322450(UnkStruct_00322450 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    CB3Profile * t0 = D_0051BF9C.field_0;
    t0->Evaluate();
    func_00139F20(t0);
    self->field_80C = self->field_4;
    self->field_80E = 7;
    int r3 = func_00271A00(&D_0051BA44, 452);
    self->field_810 = r3;
    self->field_814 = 0;
    self->field_815 = 0;
    int r4 = func_00271A00(&D_0051BA44, 899);
    self->field_818 = r4;
    self->field_81C = 0;
    self->field_81D = 0;
    int r5 = func_00271A00(&D_0051BA44, 664);
    self->field_820 = r5;
    self->field_824 = 0;
    self->field_825 = 0;
    int r6 = func_00271A00(&D_0051BA44, 453);
    self->field_828 = r6;
    self->field_82C = 0;
    self->field_82D = 0;
    int r7 = func_00271A00(&D_0051BA44, 454);
    self->field_830 = r7;
    self->field_834 = 0;
    self->field_835 = 0;
    int r8 = func_00271A00(&D_0051BA44, 241);
    self->field_838 = r8;
    self->field_83C = 0;
    self->field_83D = 0;
    int r9 = func_00271A00(&D_0051BA44, 3064);
    self->field_840 = r9;
    self->field_844 = 0;
    self->field_845 = 0;
    self->field_808 = -1;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (const CB3MenuComponentSelectionData*)((char *)self + 0x80C), (CB3VSelectComponentEntryData*)((char *)self + 0x810), 192.0f);
    func_00319C80(&D_01E89518, 222, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    int r15 = func_00271A00(&D_0051BA44, 237);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r15, 0, 80.0f);
    func_00321870(self, self->field_4);
    return 1;
}
