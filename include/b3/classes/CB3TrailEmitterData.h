// CB3TrailEmitterData -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAILEMITTERDATA_H
#define B3_CLASSES_CB3TRAILEMITTERDATA_H

#include "b3/GtMath.h"

class CB3TrailEmitterData;

class CB3TrailEmitterData {
public:
    CB3TrailEmitterData();

    unsigned char pad_0[0x1];
};

#endif
