// GtUnicodeUtils.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtUnicodeUtils.cpp.
// Area: src/b3/GameShared/GameClasses/System, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/GtUnicodeUtils.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtUnicodeUtils.h"

// CGtUnicodeUtils::Compare(unsigned short*,unsigned short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtUnicodeUtils.cpp.
// 0x0035EFA0
int CGtUnicodeUtils::Compare(unsigned short *a, unsigned short *b)
{
    while (true) {
        unsigned short ca = *a;
        if (ca == 0 && *b == 0) return 0;
        if (ca == 0) return -1;
        if (*b == 0) return 1;
        unsigned short cb = *b;
        if (ca < cb) return -1;
        if (ca > cb) return 1;
        a++; b++;
    }
}
