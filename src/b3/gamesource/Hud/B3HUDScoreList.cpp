// B3HUDScoreList.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3HUDScoreList.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Hud, [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDScoreList.h"
#include "b3/classes/EHUDAlign.h"

extern "C" void func_003CAAB0(CB3HUDScoreList *, float);

// CB3HUDScoreList::Update(float) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDScoreList.cpp.
// 0x003CB080
void CB3HUDScoreList::Update(float p0)
{
    func_003CAAB0(this, p0);
}

// CB3HUDScoreList::Prepare(EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDScoreList.cpp.
// 0x003CB400
int CB3HUDScoreList::Prepare(EHUDAlign p0, int p1)
{
    field_260 = 0;
    field_264 = p0;
    field_268 = p1;
    return 1;
}
