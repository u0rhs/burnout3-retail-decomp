// B3CameraBehaviour.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CameraBehaviour.cpp.
// Area: src/b3/gamesource/Camera/Behaviours, [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4CameraBehaviour.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CameraBehaviour.h"
#include "b3/classes/CGtCameraBehaviour.h"

extern "C" void Construct__18CGtCameraBehaviourFv(void *);  // CGtCameraBehaviour::Construct()

// CB3CameraBehaviour::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraBehaviour.cpp.
// 0x00374290
void CB3CameraBehaviour::Construct()
{
    Construct__18CGtCameraBehaviourFv(this);
    field_4 = 0;
}
