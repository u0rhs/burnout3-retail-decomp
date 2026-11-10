// CGtTimer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTTIMER_H
#define B3_CLASSES_CGTTIMER_H

#include "b3/GtMath.h"

class CGtTimer;

class CGtTimer {
public:
    static float mgrBaseTimestepSeconds;
    static int mgnBaseTimestepMilliSeconds;
    static int mguFrames;
    int GetFrameCount();
    void SetSlowMo(int p0);

    unsigned char pad_0[0x24];
    int field_24;
};

#endif
