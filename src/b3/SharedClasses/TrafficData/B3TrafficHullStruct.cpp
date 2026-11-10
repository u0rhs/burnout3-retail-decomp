// B3TrafficHullStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TrafficHullStruct.cpp.
// Area: src/b3/SharedClasses/TrafficData, [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficHullStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficHullStruct.h"

// CB3TrafficHullStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficHullStruct.cpp.
// 0x0032EDD0
void CB3TrafficHullStruct::Fixup(unsigned int p0)
{
    field_0 = (UnkStruct_0032EDD0_e0 *)&field_0[p0];
    field_C = (UnkStruct_0032EDD0_e1 *)&field_C[p0];
    field_10 = (UnkStruct_0032EDD0_e2 *)&field_10[p0];
}
