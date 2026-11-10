// CGtSoundStreamManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDSTREAMMANAGER_H
#define B3_CLASSES_CGTSOUNDSTREAMMANAGER_H

#include "b3/GtMath.h"

class CGtSoundStreamManager;

class CGtSoundStreamManager {
public:
    void Destruct();
    void PauseAll(bool);
    void StopAll();
    void Update();

    unsigned char pad_0[0x18];
    int field_18;
};

#endif
