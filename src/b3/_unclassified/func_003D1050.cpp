// GetTrackRecords__10CB3RecordsFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedTrackList.h"

struct UnkStruct_003D1050;
struct UnkStruct_003D1050_e0;

struct UnkStruct_003D1050_e0 {
    unsigned char pad_0[0x230];
};

struct UnkStruct_003D1050 {
    UnkStruct_003D1050_e0 field_0[1];  // [G] element count unknown
};

// 0x003D1050
extern "C" void * GetTrackRecords__10CB3RecordsFUl(UnkStruct_003D1050 * self, unsigned long p0)
{
    int r0 = CB3HardCodedTrackList::FindTrack(p0);
    return &self->field_0[r0];
}
