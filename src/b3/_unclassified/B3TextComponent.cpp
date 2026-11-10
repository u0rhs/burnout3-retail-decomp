// B3TextComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TextComponent.cpp.
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TextComponent.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// CB3TextComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TextComponent.cpp.
// 0x00351A90
void CB3TextComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, (field_8 + 1), field_30);
    if (field_34 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, field_8, field_34);
        field_34 = 0;
    }
    field_30 = 0;
}
