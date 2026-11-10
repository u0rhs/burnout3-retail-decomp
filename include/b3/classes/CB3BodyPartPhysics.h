// CB3BodyPartPhysics -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BODYPARTPHYSICS_H
#define B3_CLASSES_CB3BODYPARTPHYSICS_H

#include "b3/GtMath.h"

class CB3BodyPartPhysics;

class CB3BodyPartPhysics {
public:
    void Destruct();
    void Release();
    void StopCrashing();

    unsigned char pad_0[0x2B0];
    int field_2B0;
    int field_2B4;
    unsigned char pad_2B8[0x2];
    unsigned char field_2BA;
    unsigned char field_2BB;
    unsigned char pad_2BC[0x214];
    unsigned char field_4D0;
};

#endif
