// CB3BehaviourTrackSide -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BEHAVIOURTRACKSIDE_H
#define B3_CLASSES_CB3BEHAVIOURTRACKSIDE_H

#include "b3/classes/EB3BehaviourType.h"

class CB3AttribsTrackSide;
class CB3BehaviourTrackSide;

class CB3BehaviourTrackSide {
public:
    void Construct();
    void Construct(int p0);
    void Destruct();
    void Release(void* p0);
    void SetParameters(EB3BehaviourType p0, CB3AttribsTrackSide* p1, int p2);

    unsigned char pad_0[0x10];
    CB3AttribsTrackSide * field_10;
    int field_14;
    unsigned char pad_18[0x8];
    EB3BehaviourType field_20;
};

#endif
