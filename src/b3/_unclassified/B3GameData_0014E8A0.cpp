// CB3GameData::GetNumStartLines() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3GameData.h"

// 0x0014E8A0
int CB3GameData::GetNumStartLines()
{
    int v0 = 0;
    if (field_560 != 0) {
        v0 = field_56C->field_3EC;
    }
    return v0;
}
