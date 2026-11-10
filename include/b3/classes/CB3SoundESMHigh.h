// CB3SoundESMHigh -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDESMHIGH_H
#define B3_CLASSES_CB3SOUNDESMHIGH_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SoundDoppler.h"

class CB3SoundESMHigh;

class CB3SoundESMHigh {
public:
    void Construct();

    unsigned char pad_0[0x56];
    unsigned char field_56;
    unsigned char pad_57[0x39];
    int field_90;
    CB3SoundDoppler field_94;
};

#endif
