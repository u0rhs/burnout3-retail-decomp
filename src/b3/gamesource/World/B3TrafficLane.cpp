// B3TrafficLane.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3TrafficLane.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficLane.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficLane.h"

// CB3TrafficLane::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// 0x00160570
void CB3TrafficLane::Release()
{
    field_48 = 0;
    field_49 = 0;
    field_46 = 255;
    field_47 = 255;
    field_4 = 0;
}

// CB3TrafficLane::Prepare(int,unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// 0x00160590
void * CB3TrafficLane::Prepare(int p0, unsigned char p1)
{
    field_4 = p0;
    field_48 = 0;
    field_49 = 0;
    field_46 = 255;
    field_47 = p1;
    return ((char *)(p0 + (int)field_0->field_10));
}
