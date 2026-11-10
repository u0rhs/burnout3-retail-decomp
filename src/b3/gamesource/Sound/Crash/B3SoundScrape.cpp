// B3SoundScrape.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundScrape.cpp.
// Area: src/b3/gamesource/Sound/Crash, [L] Revenge (SLUS_212.42) GameSource/Sound/Crash/B4SoundScrape.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundScrape.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/UnkStruct_D_004E1038.h"

extern UnkStruct_D_004E1038 D_004E1038;

// CB3SoundScrape::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundScrape.cpp.
// 0x00283560
void CB3SoundScrape::Release()
{
    CGtSoundVirtualVoice * t0 = field_10;
    if (t0 != 0) {
        t0->ForgetMe(D_004E1038.field_0);
        field_10 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_14;
    if (t1 != 0) {
        t1->ForgetMe(D_004E1038.field_0);
        field_14 = 0;
    }
    field_20 = 0;
    field_24 = 0;
}
