// B3TrafficValveStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3TrafficValveStruct.cpp.
// Area: src/b3/SharedClasses/TrafficData, [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficValveStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3FormationBehaviourStruct.h"
#include "b3/classes/CB3TrafficValvePositionStruct.h"

// CB3FormationBehaviourStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValveStruct.cpp.
// 0x00269EC0
void CB3FormationBehaviourStruct::Fixup(unsigned int p0)
{
    field_0 = (UnkStruct_00269EC0_e0 *)&field_0[p0];
    field_4 = (UnkStruct_00269EC0_e1 *)&field_4[p0];
    field_8 = (UnkStruct_00269EC0_e2 *)&field_8[p0];
}

// CB3TrafficValvePositionStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValveStruct.cpp.
// 0x00269EF0
void CB3TrafficValvePositionStruct::Fixup(unsigned int p0)
{
    field_0 = (UnkStruct_00269EF0_e0 *)&field_0[p0];
    field_4 = (UnkStruct_00269EF0_e1 *)&field_4[p0];
}
