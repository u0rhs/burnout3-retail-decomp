// B3NetworkHasHeadsetMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3NetworkHasHeadsetMessage.cpp.
// Area: src/b3/gamesource/Network/Messages, [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkHasHeadsetMessage.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkHasHeadsetMessage.h"
#include "b3/classes/CB3NetworkMessage.h"

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// CB3NetworkHasHeadsetMessage::Retrieve(unsigned char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkHasHeadsetMessage.cpp.
// 0x00341C70
int CB3NetworkHasHeadsetMessage::Retrieve(unsigned char* p0)
{
    if ((field_0 & 1) != 1) {
        return 0;
    }
    *p0 = field_10;
    field_0 = (field_0 & -2);
    return 1;
}

// CB3NetworkHasHeadsetMessage::Prepare(unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkHasHeadsetMessage.cpp.
// 0x00341CB0
void CB3NetworkHasHeadsetMessage::Prepare(unsigned char p0)
{
    if ((field_0 & 1) == 1) return;
    field_10 = p0;
    Prepare__17CB3NetworkMessageFib(this, 17, 0);
}
