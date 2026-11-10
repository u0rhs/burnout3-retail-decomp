// CB3SoundESMLow -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDESMLOW_H
#define B3_CLASSES_CB3SOUNDESMLOW_H

#include "b3/GtMath.h"

class CB3SoundESMLow;

class CB3SoundESMLow {
public:
    void Construct();

    unsigned char pad_0[0x56];
    unsigned char field_56;
};

#endif
