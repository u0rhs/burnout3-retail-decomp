// func_0013B0E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedTrackList.h"

struct UnkStruct_0013B0E0;

struct UnkStruct_0013B0E0 {
    unsigned char pad_0[0x20C];
    float field_20C[1];  // [G] element count unknown
    unsigned char pad_210[0x8C];
    int field_29C;
};

extern "C" int func_003EB060(unsigned long);

// 0x0013B0E0
extern "C" void func_0013B0E0(UnkStruct_0013B0E0 * self, unsigned long p0, unsigned long p1, float f0)
{
    float * pp = (float *)((char *)self->field_20C + CB3HardCodedTrackList::FindTrack(p1) * 4);
    if (*pp < f0) {
        int i;
        bool best = true;
        for (i = 0; i < 36; i++) {
            if (!(self->field_20C[i] < f0)) {
                best = false;
                break;
            }
        }
        if (best) {
            int r1 = func_003EB060(p0);
            if (r1 != -1) {
                self->field_29C = r1;
            }
        }
        *pp = f0;
    }
}
