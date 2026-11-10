// B3NetworkGameModeStatusMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkGameModeStatusMessage.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkGameModeStatusMessage.h"

// CB3NetworkGameModeStatusMessage::Retrieve(signed char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkGameModeStatusMessage.cpp.
// 0x003CC240
int CB3NetworkGameModeStatusMessage::Retrieve(signed char* p0)
{
    if ((field_0 & 1) != 1) {
        return 0;
    }
    *p0 = field_10;
    field_0 = (field_0 & -2);
    return 1;
}
