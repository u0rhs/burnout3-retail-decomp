// CB3AIDriver -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AIDRIVER_H
#define B3_CLASSES_CB3AIDRIVER_H

#include "b3/GtMath.h"

class CB3AIDriver;

class CB3AIDriver {
public:
    void Construct();
    void Release();

    unsigned char pad_0[0x1];
};

#endif
