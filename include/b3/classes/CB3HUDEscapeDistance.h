// CB3HUDEscapeDistance -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDESCAPEDISTANCE_H
#define B3_CLASSES_CB3HUDESCAPEDISTANCE_H

#include "b3/classes/EHUDAlign.h"

class CB3HUDEscapeDistance;

class CB3HUDEscapeDistance {
public:
    int Prepare(int p0, EHUDAlign p1, int p2);

    unsigned char pad_0[0x40];
    unsigned char field_40;
    unsigned char pad_41[0x3];
    EHUDAlign field_44;
    int field_48;
};

#endif
