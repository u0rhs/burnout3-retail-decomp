// CB3SoundDoppler -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDDOPPLER_H
#define B3_CLASSES_CB3SOUNDDOPPLER_H

#include "b3/GtMath.h"

class CB3SoundDoppler;

class CB3SoundDoppler {
public:
    void Construct();
    void SetMaxVolBoost(float p0);
    void SetMaxVolLinear(float p0);
    void SetMaxVolToPower(float p0);

    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
    float field_20;
};

#endif
