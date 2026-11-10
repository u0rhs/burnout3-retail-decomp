// CB3ReplayPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3REPLAYPAGE_H
#define B3_CLASSES_CB3REPLAYPAGE_H

#include "b3/GtMath.h"

class CB3ReplayPage;

class CB3ReplayPage {
public:
    int Prepare(bool p0);

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
};

#endif
