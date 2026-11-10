// GtSoundUtils.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtSoundUtils.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundUtils.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundUtils.h"

// CGtSoundUtils::IntToAsciiVariant(unsigned char,char&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundUtils.cpp.
// 0x00386EE0
int CGtSoundUtils::IntToAsciiVariant(unsigned char p0, char& p1)
{
    if (!(p0 < 10) && p0 < 36) {
        p1 = p0 + 55;
        return 1;
    }
    if (p0 > 10) {
        return 0;
    }
    p1 = p0 + 48;
    return 1;
}
