// CB3BehaviourEffect -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BEHAVIOUREFFECT_H
#define B3_CLASSES_CB3BEHAVIOUREFFECT_H

#include "b3/GtMath.h"

class CB3BehaviourEffect;
class CB3PlayerCameraManager;

class CB3BehaviourEffect {
public:
    void Construct(CB3PlayerCameraManager* p0);
    void Destruct();
    void Release(void* p0);

    unsigned char pad_0[0x8];
    CB3PlayerCameraManager * field_8;
};

#endif
