// func_0013AEB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_gCalculatedData.h"

extern UnkStruct_gCalculatedData gCalculatedData;
extern "C" unsigned long GetTrackGtID__21CB3HardCodedTrackListFi(int);

// 0x0013AEB0
extern "C" unsigned long func_0013AEB0(void *a0 /* passed by every caller, not read here */)
{
    int t0 = gCalculatedData.field_C;
    if (t0 == -1) {
        return 0;
    }
    unsigned long r0 = GetTrackGtID__21CB3HardCodedTrackListFi(t0);
    return r0;
}
