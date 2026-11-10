// CB3SoundTurboModel -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDTURBOMODEL_H
#define B3_CLASSES_CB3SOUNDTURBOMODEL_H

#include "b3/GtMath.h"

class CB3SoundTurboModel;

class CB3SoundTurboModel {
public:
    void Construct();
    void Destruct();

    int field_0;
    int field_4;
    unsigned char pad_8[0xC];
    int field_14;
};

#endif
