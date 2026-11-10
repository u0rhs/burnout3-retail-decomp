// CGtSoundStream -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDSTREAM_H
#define B3_CLASSES_CGTSOUNDSTREAM_H

#include "b3/GtMath.h"

class CGtSoundStream;

class CGtSoundStream {
public:
    void SetMediaBuffer(void* p0, int p1);

    unsigned char pad_0[0x134];
    void* field_134;
    int field_138;
};

#endif
