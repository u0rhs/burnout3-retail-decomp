// CB3GameData::SetStageID(unsigned long) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3GameData.h"

// 0x0014EBC0
void CB3GameData::SetStageID(unsigned long p0)
{
    field_558 = p0;
    field_58A = 1;
}
