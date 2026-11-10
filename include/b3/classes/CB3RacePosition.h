// CB3RacePosition -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3RACEPOSITION_H
#define B3_CLASSES_CB3RACEPOSITION_H

#include "b3/GtMath.h"

class CB3RacePosition;

class CB3RacePosition {
public:
    void Construct();
    void Destruct();
    int Prepare();
    void Release();

    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x14];
    int field_18;
    int field_1C;
    int field_20;
};

#endif
