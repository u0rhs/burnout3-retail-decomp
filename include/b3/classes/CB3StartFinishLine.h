// CB3StartFinishLine -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STARTFINISHLINE_H
#define B3_CLASSES_CB3STARTFINISHLINE_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SplitTimeCheckpoint.h"

class CB3StartFinishLine;

class CB3StartFinishLine : public CB3SplitTimeCheckpoint {
public:
    void Destruct();

    unsigned char pad_0[0x1];
};

#endif
