// CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3MenuPageManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_004F6060.h"

extern UnkStruct_D_004F6060 D_004F6060;
extern CB3HUDSoundManager D_01E7A800;

// 0x0030D500
void CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents p0, bool p1)
{
    field_1E8 = p0;
    field_19FF = p1;
    field_1DC = 0.4f;
    field_1E4 = 4;
    if (field_1E8 < 3) {
        field_1EC = D_004F6060.field_0;
    }
    D_01E7A800.FEBack();
}
