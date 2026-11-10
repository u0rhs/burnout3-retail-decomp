// CGtSoundListenerManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDLISTENERMANAGER_H
#define B3_CLASSES_CGTSOUNDLISTENERMANAGER_H

#include "b3/GtMath.h"

class CGtSoundListenerManager;

class CGtSoundListenerManager {
public:
    void Destruct();
    int GetFixedListener() const;

    int field_0;
};

#endif
