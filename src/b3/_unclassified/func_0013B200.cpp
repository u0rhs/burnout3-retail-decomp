// func_0013B200 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedTrackList.h"
#include "b3/classes/UnkStruct_gCalculatedData.h"

struct UnkStruct_0013B200;

struct UnkStruct_0013B200 {
    unsigned char pad_0[0x170];
    int field_170[1];  // [G] element count unknown
    unsigned char pad_174[0x8C];
    int field_200;
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013B200
extern "C" int func_0013B200(UnkStruct_0013B200 * self, unsigned long p0, int p1)
{
    if (p0 == 0) {
        int v0;
        if (p1 != 0) {
            v0 = self->field_200;
        } else {
            v0 = gCalculatedData.field_20;
        }
        return v0;
    }
    int r0 = CB3HardCodedTrackList::FindTrack(p0);
    return self->field_170[r0];
}
