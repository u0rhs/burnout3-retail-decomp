// B3HUDEscapeDistance.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3HUDEscapeDistance.cpp.
// Area: src/b3/gamesource/Hud, [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDEscapeDistance.h"
#include "b3/classes/EHUDAlign.h"

// CB3HUDEscapeDistance::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDEscapeDistance.cpp.
// 0x003D8D40
int CB3HUDEscapeDistance::Prepare(int p0, EHUDAlign p1, int p2)
{
    field_40 = 0;
    field_44 = p1;
    field_48 = p2;
    return 1;
}
