// CB3ControllerMapping -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CONTROLLERMAPPING_H
#define B3_CLASSES_CB3CONTROLLERMAPPING_H

#include "b3/GtMath.h"

#include "b3/classes/CB3MenuInput.h"

class CB3ControllerMapping;

class CB3ControllerMapping {
public:
    void Construct(unsigned int p0);
    void Prepare();
    void ResetControllerDeadTime();

    int field_0;
    void * field_4;
    void * field_8;
    CB3MenuInput field_C;
    unsigned char pad_D[0x11B];
    float field_128;
};

#endif
