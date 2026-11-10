// CB3NetworkCarPhysics -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKCARPHYSICS_H
#define B3_CLASSES_CB3NETWORKCARPHYSICS_H

#include "b3/GtMath.h"

#include "b3/classes/CB3RaceCarPhysics.h"

class CB3NetworkCarPhysics;

class CB3NetworkCarPhysics : public CB3RaceCarPhysics {
public:
    void Destruct();
    void Release();

    unsigned char pad_0[0x1];
};

#endif
