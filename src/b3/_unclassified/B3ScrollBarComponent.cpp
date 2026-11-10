// B3ScrollBarComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3ScrollBarComponent.cpp.
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ScrollBarComponent.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// CB3ScrollBarComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrollBarComponent.cpp.
// 0x0041EAF0
void CB3ScrollBarComponent::Release()
{
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    int t0 = field_8;
    Release__20CB3MenuComponentBaseFv(this);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, (CGt2dObject*)field_14);
    field_14 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, (CGt2dObject*)field_18);
    field_18 = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, (CGt2dObject*)field_10);
    field_10 = 0;
}
