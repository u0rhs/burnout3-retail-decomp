// B3ErrorPage.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ErrorPage.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ErrorPage.h"
#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/EB3MessageBoxType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90240.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89518 D_01E89518;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00319C80(void *, EGlobalStrings, int);
extern "C" void func_0032D080(void *, EB3MessageBoxType, EGlobalStrings, int, int);

// CB3ErrorPage::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ErrorPage.cpp.
// 0x00352030
void CB3ErrorPage::Release()
{
}

// Update__12CB3ErrorPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00352040
extern "C" void Update__12CB3ErrorPageFv()
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int r0 = func_0032B2C0(&D_01E898E8, 0, 1);
    switch (r0) {
    case 0:
    case 3:
    case 4:
    case 13:
        D_01E7A800.FESelect();
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        break;
    case 1:
    case 2:
    case 5:
    case 14:
        D_01E7A800.FEBack();
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        break;
    default:
        break;
    }
}

// CB3ErrorPage::Prepare(EGlobalStrings,EGlobalStrings,EB3MessageBoxType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ErrorPage.cpp.
// 0x00352210
int CB3ErrorPage::Prepare(EGlobalStrings p0, EGlobalStrings p1, EB3MessageBoxType p2)
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 8, 3);
    D_01E894FC.Prepare();
    func_00319C80(&D_01E89518, p0, 14);
    func_0032D080(&D_01E898E8, p2, p1, 15, 0);
    return 1;
}
