// B3MyBurnoutRewardsHeadlinesPage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3MyBurnoutRewardsHeadlinesPage.cpp.
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MyBurnoutRewardsHeadlinesPage.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3RewardImageComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EB3RewardImageType.h"
#include "b3/classes/EB3RewardPageType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8E7A0.h"
#include "b3/classes/UnkStruct_D_01E8EC30.h"

extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E8EC30 D_01E8EC30;
extern UnkStruct_D_01E8E7A0 D_01E8E7A0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);  // CB3HelpBarComponent::Prepare()
extern "C" bool Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(void *, EB3RewardPageType, EB3RewardImageType, int, int);  // CB3RewardImageComponent::Prepare(EB3RewardPageType,EB3RewardImageType,int), passed 1 more argument(s) [G]
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_0042D2B0(void *, int, int, int, int);
extern "C" int func_0042B6A0(void *, int);
extern "C" int GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(void *, int, int);
extern "C" int func_003F64D0(void *, int, int);

// CB3MyBurnoutRewardsHeadlinesPage::Prepare(EB3RewardImageType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MyBurnoutRewardsHeadlinesPage.cpp.
// 0x003F0B30
int CB3MyBurnoutRewardsHeadlinesPage::Prepare(EB3RewardImageType p0)
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    field_4 = p0;
    switch (p0) {
    case 0:
        func_00319C80(&D_01E89518, 1772, 14);
        break;
    case 1:
        func_00319C80(&D_01E89518, 1773, 14);
        break;
    case 2:
        func_00319C80(&D_01E89518, 1774, 14);
        break;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 259, 3);
    D_01E894FC.Prepare();
    Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    func_0042D2B0(&D_01E8EC30, 1, field_4, 0, 1);
    int v4;
    if (func_0042B6A0(&D_01E8EC30, 0) != 0) {
        Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, 0, 0);
        v4 = func_003F64D0(&D_01E8E7A0, field_4, 0);
    } else {
        Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, 0, 1);
        v4 = GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(&D_01E8E7A0, field_4, 0);
    }
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)v4, 1, 0, 80.0f);
    return 1;
}
