// B3EventFinishedComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3EventFinishedComponent.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3EventFinishedComponent.h"

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// CB3EventFinishedComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EventFinishedComponent.cpp.
// 0x003B8E80
void CB3EventFinishedComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 1);
    field_C = 0;
    field_14 = 0;
    field_10 = 0;
}
