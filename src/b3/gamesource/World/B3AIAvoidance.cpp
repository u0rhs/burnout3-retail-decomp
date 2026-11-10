// B3AIAvoidance.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3AIAvoidance.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4AIAvoidance.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3AIAvoidance.h"
#include "b3/classes/CB3AIAvoidanceMap.h"
#include "b3/classes/CB3AICar.h"
#include "b3/classes/UnkStruct__gnAIAvoidanceMonitorID.h"

extern UnkStruct__gnAIAvoidanceMonitorID _gnAIAvoidanceMonitorID;
extern "C" void Prepare__17CB3AIAvoidanceMapFP8CB3AICar(void *, void *);  // CB3AIAvoidanceMap::Prepare(CB3AICar*)

// CB3AIAvoidance::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// 0x00141880
void CB3AIAvoidance::Release()
{
}

// CB3AIAvoidance::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// 0x001418F0
int CB3AIAvoidance::Prepare()
{
    Prepare__17CB3AIAvoidanceMapFP8CB3AICar(this, (CB3AICar*)field_4A4);
    field_460.Zero();
    field_470.Zero();
    field_484 = 1.0f;
    field_480 = 0;
    field_488 = 0;
    field_490 = 0;
    field_494 = 0;
    field_498 = 0;
    field_49C = 0;
    field_4AD = 0;
    field_4AE = 0;
    field_48C = 0;
    field_4AC = 16;
    field_4AF = (field_4A4->field_19AC % 3);
    return 1;
}

// CB3AIAvoidance::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// 0x00141980
void CB3AIAvoidance::Construct()
{
    if (_gnAIAvoidanceMonitorID.field_0 == -1) {
        _gnAIAvoidanceMonitorID.field_0 = 0;
    }
}
