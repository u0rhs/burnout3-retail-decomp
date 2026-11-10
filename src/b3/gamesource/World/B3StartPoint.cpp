// B3StartPoint.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3StartPoint.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4StartPoint.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3StartPoint.h"
#include "b3/classes/CB3StartPositionStruct.h"

// CB3StartPoint::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartPoint.cpp.
// 0x0015E8A0
void CB3StartPoint::Destruct()
{
}

// CB3StartPoint::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartPoint.cpp.
// 0x0015E8B0
void CB3StartPoint::Release()
{
    field_0 = 0;
}

// CB3StartPoint::Prepare(CB3StartPositionStruct*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartPoint.cpp.
// 0x0015E8C0
int CB3StartPoint::Prepare(CB3StartPositionStruct* p0)
{
    field_0 = p0;
    return 1;
}

// CB3StartPoint::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartPoint.cpp.
// 0x0015E8D0
void CB3StartPoint::Construct()
{
    field_0 = 0;
}
