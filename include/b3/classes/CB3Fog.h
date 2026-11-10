// CB3Fog -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3FOG_H
#define B3_CLASSES_CB3FOG_H

#include "b3/GtMath.h"

class CB3Fog;

class CB3Fog {
public:
    void CalculateClipPlanes(float* p0, float* p1, float p2);

    float field_0;
};

#endif
