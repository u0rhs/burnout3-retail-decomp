// B3HUDScore.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3HUDScore.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Hud, [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDScore.h"

// CB3HUDScore::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDScore.cpp.
// 0x001A2260
void CB3HUDScore::Update(float p0)
{
    UpdateSmallMessage(p0);
    UpdateScoreObject(p0);
}
