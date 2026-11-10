// B3HUDPrimaryMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// Area: src/b3/gamesource/Hud, [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDPrimaryMessage.h"
#include "b3/classes/EHUDMode.h"

// CB3HUDPrimaryMessage::StartTransition(bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// 0x003D8070
void CB3HUDPrimaryMessage::StartTransition(bool p0, EHUDMode p1, EHUDMode p2)
{
    if ((field_4C != 0) != false) {
        field_40.ClearMessage(0);
    } else {
    }
    if (p1 == 2) {
        field_34 = 0.5f;
        field_38 = 0;
    }
}

// CB3HUDPrimaryMessage::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// 0x003D8230
void CB3HUDPrimaryMessage::Update(float p0)
{
    UpdateCrashText(p0);
    UpdateMessage(p0);
    field_40.Update(p0);
}
