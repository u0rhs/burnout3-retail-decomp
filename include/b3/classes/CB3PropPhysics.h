// CB3PropPhysics -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PROPPHYSICS_H
#define B3_CLASSES_CB3PROPPHYSICS_H

#include "b3/GtMath.h"

class CB3PropPhysics;

class CB3PropPhysics {
public:
    void Destruct();
    void Release();

    unsigned char pad_0[0x220];
    int field_220;
    float field_224;
};

#endif
