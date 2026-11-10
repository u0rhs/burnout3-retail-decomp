// B3HUDComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3HUDComponent.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Hud, [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDComponent.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDComponent.h"
#include "b3/classes/CB3HUDManager.h"
#include "b3/classes/EHUDMode.h"

// CB3HUDComponent::StartTransition(bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDComponent.cpp.
// 0x0019F4A0
void CB3HUDComponent::StartTransition(bool p0, EHUDMode p1, EHUDMode p2)
{
}

// CB3HUDComponent::Construct(CB3HUDManager*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// 0x0019F770
void CB3HUDComponent::Construct(CB3HUDManager* p0)
{
    field_4 = p0;
    field_C = 0;
}

// CB3HUDComponent::Update() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// 0x0019F780
void CB3HUDComponent::Update()
{
}
