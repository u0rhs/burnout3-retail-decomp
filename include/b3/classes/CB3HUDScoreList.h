// CB3HUDScoreList -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDSCORELIST_H
#define B3_CLASSES_CB3HUDSCORELIST_H

#include "b3/classes/EHUDAlign.h"

class CB3HUDScoreList;

class CB3HUDScoreList {
public:
    int Prepare(EHUDAlign p0, int p1);
    void Update(float p0);

    unsigned char pad_0[0x260];
    unsigned char field_260;
    unsigned char pad_261[0x3];
    EHUDAlign field_264;
    int field_268;
};

#endif
