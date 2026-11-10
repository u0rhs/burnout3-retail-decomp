// CB3DNASPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3DNASPAGE_H
#define B3_CLASSES_CB3DNASPAGE_H

#include "b3/GtMath.h"

class CB3DNASPage;

class CB3DNASPage {
public:
    int Prepare();
    void Release();

    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
};

#endif
