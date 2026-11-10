// B3NetworkPlayerStartCountdownMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkPlayerStartCountdownMessage.cpp.
// Area: src/b3/gamesource/Network/Messages, [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkPlayerStartCountdownMessage.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkPlayerStartCountdownMessage.h"

// CB3NetworkPlayerStartCountdownMessage::Retrieve(int*,float*,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkPlayerStartCountdownMessage.cpp.
// 0x001A8550
int CB3NetworkPlayerStartCountdownMessage::Retrieve(int* p0, float* p1, int* p2)
{
    if ((field_0 & 1) == 1) {
        *p0 = field_10;
        *p1 = field_14;
        for (int i = 0; (i < 8); i++) {
            p2[i] = field_18[i];
        }
        field_0 = (field_0 & -2);
        return 1;
    }
    return 0;
}
