// CB3StreamedTrack::GetUnitOriginalID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3StreamedTrack.h"

// 0x00302610
int CB3StreamedTrack::GetUnitOriginalID(int p0)
{
    if (p0 < 0) return -1;
    UnkStruct_00302610_u * u;
    if (field_24 != field_2C && p0 == field_24 % field_C) {
        u = 0;
        goto test;
    }
    if (p0 >= 0 && p0 < field_C) {
        UnkStruct_00302610_u * x = field_17C[p0];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) { u = x; goto test; }
        u = 0;
        goto test;
    }
    u = 0;
test: // [G] goto-per-arm form keeps retail's direct branches to the u test (inlined lookup flattened)
    return u != 0 ? u->field_4 : -1;
}
