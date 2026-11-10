// B3ChatDisplayComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ChatDisplayComponent.h"
#include "b3/classes/EB3ChatDisplayOrientation.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

extern UnkStruct_D_01E90438 D_01E90438;
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// CB3ChatDisplayComponent::Prepare(EB3ChatDisplayOrientation) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// 0x00332570
void CB3ChatDisplayComponent::Prepare(EB3ChatDisplayOrientation p0)
{
    for (int i = 0; (i < 10); i++) {
        int r0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 17);
        field_7F0[i] = (UnkStruct_00332570_2 *)r0;
        field_7F0[i]->field_0 = 0;
        int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 64);
        field_818[i] = (UnkStruct_00332570_4 *)r1;
        field_818[i]->field_0 = 0;
    }
    PrepareWithoutStrings(p0);
}

// CB3ChatDisplayComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// 0x00332960
void CB3ChatDisplayComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 2);
    field_864 = 0;
    field_860 = 0;
    field_868 = 0;
}
