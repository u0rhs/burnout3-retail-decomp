// B3TrafficLight.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3TrafficLight.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficLight.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficLight.h"
#include "b3/classes/CB3TrafficLightPositionStruct.h"

// CB3TrafficLight::UseNewTimingsData(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLight.cpp.
// 0x00265C60
void CB3TrafficLight::UseNewTimingsData(float p0)
{
    field_C = field_4->field_0;
    field_8 = p0;
    field_14 = 2;
}

// CB3TrafficLight::Prepare(CB3TrafficLightPositionStruct*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLight.cpp.
// 0x00266260
int CB3TrafficLight::Prepare(CB3TrafficLightPositionStruct* p0)
{
    field_14 = 2;
    field_8 = 0;
    for (int i = 0; (i < 4); i++) {
        field_10[i] = 255;
    }
    field_0 = (CB3TrafficLightPositionStruct *)p0;
    field_C = field_4->field_0;
    return 1;
}
