// B3BuddyDisplayComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3BuddyDisplayComponent.cpp, 1 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BuddyDisplayComponent.h"
#include "b3/classes/CGtBuddiesPS2DirtySock.h"

extern CGtBuddiesPS2DirtySock D_01E3D390;
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// CB3BuddyDisplayComponent::GetSelectedBuddyName(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// 0x00366400
bool CB3BuddyDisplayComponent::GetSelectedBuddyName(char* p0)
{
    int r0 = D_01E3D390.GetBuddyName((field_E80 + field_E78), p0);
    return (r0 == 0);
}

// func_00366560 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00366560
extern "C" void func_00366560(void *a0, void *a1 /* passed by every caller, not read here */)
{
}

// CB3BuddyDisplayComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// 0x00367E40
void CB3BuddyDisplayComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 3);
    field_E70 = 0;
    field_E6C = 0;
}
