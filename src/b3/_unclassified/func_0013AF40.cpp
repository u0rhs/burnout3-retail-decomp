// func_0013AF40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HardCodedTrackList.h"

struct UnkStruct_0013AF40;

struct UnkStruct_0013AF40 {
    unsigned char pad_0[0x2A0];
    float field_2A0[1];  // [G] element count unknown
    unsigned char pad_2A4[0x8C];
    int field_330;
};

extern "C" int func_003EB060(unsigned long);

// 0x0013AF40
extern "C" void func_0013AF40(UnkStruct_0013AF40 * self, unsigned long p0, unsigned long p1, float f0)
{
    int r0 = CB3HardCodedTrackList::FindTrack(p1);
    if (self->field_2A0[r0] < f0) {
        int i;
        bool best = true;
        for (i = 0; i < 36; i++) {
            if (!(self->field_2A0[i] < f0)) {
                best = false;
                break;
            }
        }
        if (best) {
            int r1 = func_003EB060(p0);
            if (r1 != -1) {
                self->field_330 = r1;
            }
        }
        self->field_2A0[r0] = f0;
    }
}
