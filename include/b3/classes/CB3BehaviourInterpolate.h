// CB3BehaviourInterpolate -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BEHAVIOURINTERPOLATE_H
#define B3_CLASSES_CB3BEHAVIOURINTERPOLATE_H

#include "b3/GtMath.h"

#include "b3/classes/CB3CameraBehaviour.h"

class CB3BehaviourInterpolate;

class CB3BehaviourInterpolate : public CB3CameraBehaviour {
public:
    void Construct();
    void Destruct();
    void Release(void* p0);

    unsigned char pad_0[0x1];
};

#endif
