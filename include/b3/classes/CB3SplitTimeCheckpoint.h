// CB3SplitTimeCheckpoint -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SPLITTIMECHECKPOINT_H
#define B3_CLASSES_CB3SPLITTIMECHECKPOINT_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SpatialTrigger.h"

class CB3SplitTimeCheckpoint;

class CB3SplitTimeCheckpoint : public CB3SpatialTrigger {
public:
    void Destruct();

    unsigned char pad_0[0x1];
};

#endif
