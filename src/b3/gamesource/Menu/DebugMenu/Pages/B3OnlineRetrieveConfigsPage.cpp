// B3OnlineRetrieveConfigsPage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineRetrieveConfigsPage.cpp.
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnlineRetrieveConfigsPage.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_00271A00(void *, int);

// CB3OnlineRetrieveConfigsPage::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineRetrieveConfigsPage.cpp.
// 0x0034A430
int CB3OnlineRetrieveConfigsPage::Prepare()
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    func_00319C80(&D_01E89518, 1073, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    func_0032D080(&D_01E898E8, 1, 120, 15, 0);
    int r5 = func_00271A00(&D_0051BA44, 119);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r5, 1, 80.0f);
    field_4 = 1;
    return 1;
}
