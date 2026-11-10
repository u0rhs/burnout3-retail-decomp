// CGtSoundWave -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDWAVE_H
#define B3_CLASSES_CGTSOUNDWAVE_H

#include "b3/GtMath.h"

class CGtSoundWave;
struct RwaSPU2Wave;

class CGtSoundWave {
public:
    void Construct(RwaSPU2Wave* p0);
    void Destruct();

    unsigned long field_0;
    RwaSPU2Wave * field_8;
};

#endif
