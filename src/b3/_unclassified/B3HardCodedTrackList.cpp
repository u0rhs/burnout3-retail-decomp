// B3HardCodedTrackList.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3HardCodedTrackList.cpp, 1 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HardCodedTrackList.h"

extern unsigned long kaB3HardCodedTrackList[];  // [G] element count unknown

// GetTrackGtID__21CB3HardCodedTrackListFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003EAB70
extern "C" unsigned long GetTrackGtID__21CB3HardCodedTrackListFi(int n0)
{
    return kaB3HardCodedTrackList[n0];
}

// CB3HardCodedTrackList::FindTrack(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedTrackList.cpp.
// 0x003EAB90
int CB3HardCodedTrackList::FindTrack(unsigned long p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (p0 == kaB3HardCodedTrackList[i]) {
            return i;
        }
    }
    i++;
loop0_test:
    if (i < 36) goto loop0_body;
    return -1;
}
