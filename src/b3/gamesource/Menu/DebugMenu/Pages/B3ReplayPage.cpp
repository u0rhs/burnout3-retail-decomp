// B3ReplayPage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ReplayPage.cpp.
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/CB3ReplayPage.h"
#include "b3/classes/CB3ReplaySymbolComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89788 D_01E89788;
extern CB3ReplaySymbolComponent D_01E8E5BC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);  // CB3HelpBarComponent::Prepare()
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// CB3ReplayPage::Prepare(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplayPage.cpp.
// 0x003C5FB0
int CB3ReplayPage::Prepare(bool p0)
{
    field_8 = p0;
    Prepare__15CB3MenuPageBaseFb(this, 1);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)8);
    func_0031ECD0(&D_01E89800, 16, 3);
    if (field_8 != 0) {
        D_01E894FC.Prepare();
        Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    }
    field_4 = 0;
    D_01E8E5BC.Prepare();
    return 1;
}
