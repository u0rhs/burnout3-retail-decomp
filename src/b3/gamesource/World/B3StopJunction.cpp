// B3StopJunction.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3StopJunction.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4StopJunction.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3StopJunction.h"
#include "b3/classes/CB3StopJunctionStruct.h"

// CB3StopJunction::Prepare(CB3StopJunctionStruct*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StopJunction.cpp.
// 0x002B6BC0
int CB3StopJunction::Prepare(CB3StopJunctionStruct* p0)
{
    field_0 = p0;
    field_14 = 0;
    for (int i = 0; (i < 4); i++) {
        field_10[i] = 255;
    }
    field_15 = 255;
    field_16 = 255;
    field_17 = 255;
    field_18 = 255;
    field_4 = 0;
    field_8 = 0;
    field_C = 0;
    field_19 = 0;
    field_1A = 0;
    field_1B = 0;
    field_1C = (p0->field_50 == 4);
    return 1;
}
