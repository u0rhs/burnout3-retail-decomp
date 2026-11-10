// B3NetworkRaceReadyMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkRaceReadyMessage.cpp.
// Area: src/b3/gamesource/Network/Messages, [L] Revenge (SLUS_212.42) GameSource/Network/Messages/B4NetworkRaceReadyMessage.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkMessage.h"
#include "b3/classes/CB3NetworkRaceReadyMessage.h"

// CB3NetworkRaceReadyMessage::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkRaceReadyMessage.cpp.
// 0x0026BD30
void CB3NetworkRaceReadyMessage::Prepare()
{
    CB3NetworkMessage::Prepare(10, 1);
}
