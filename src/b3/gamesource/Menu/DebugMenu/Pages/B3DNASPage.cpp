// B3DNASPage.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3DNASPage.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3DNASPage.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004C7170.h"
#include "b3/classes/UnkStruct_D_004C7178.h"
#include "b3/classes/UnkStruct_D_004C7180.h"
#include "b3/classes/UnkStruct_D_004C7188.h"
#include "b3/classes/UnkStruct_D_004C7190.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E7A888.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E8D4B0.h"

extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_004C7170 D_004C7170;
extern UnkStruct_D_004C7178 D_004C7178;
extern UnkStruct_D_004C7180 D_004C7180;
extern UnkStruct_D_004C7188 D_004C7188;
extern UnkStruct_D_004C7190 D_004C7190;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_003FA600(void *, int);
extern "C" void func_003FC470(void *);

// CB3DNASPage::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3DNASPage.cpp.
// 0x003530E0
void CB3DNASPage::Release()
{
}

// CB3DNASPage::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DNASPage.cpp.
// 0x00353520
int CB3DNASPage::Prepare()
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)12);
    func_00319C80(&D_01E89518, 1070, 14);
    D_01E894FC.Prepare();
    int r4 = func_00271A00(&D_0051BA44, 1071);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r4, 1, 80.0f);
    func_00351F00(&D_01E8D4B0, &D_004C7170, &D_004C7178, &D_004C7180, &D_004C7188, &D_004C7190, 1071, 2, 0, 1, 0, 26.0f, 400.0f);
    func_00130C70(&D_0051A6A8);
    func_00130D00(&D_0051A6A8);
    field_8 = 0;
    field_9 = 0;
    func_003FA600(&D_01E7A888, 3);
    func_003FC470(&D_01E7A888);
    return 1;
}
