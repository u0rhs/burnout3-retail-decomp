// B3SoundListener.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundListener.cpp.
// Area: src/b3/gamesource/Sound/Core, [L] Revenge (SLUS_212.42) GameSource/Sound/Core/B4SoundListener.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundListener.h"
#include "b3/classes/CGtSoundListener.h"

extern "C" void Construct__16CGtSoundListenerFv(void *);  // CGtSoundListener::Construct()

// CB3SoundListener::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundListener.cpp.
// 0x0028AC50
void CB3SoundListener::Construct()
{
    Construct__16CGtSoundListenerFv(this);
    field_10 = 0;
}
