// B3SoundTrafficManager.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area: src/b3/gamesource/Sound/Traffic, [L] Revenge (SLUS_212.42) GameSource/Sound/Traffic/B4SoundTrafficManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundTrafficManager.h"

// CB3SoundTrafficManager::CanStartHorning() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// 0x00276C10
bool CB3SoundTrafficManager::CanStartHorning()
{
    return (field_D4 < 2);
}
