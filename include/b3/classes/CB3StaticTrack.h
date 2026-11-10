// CB3StaticTrack -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STATICTRACK_H
#define B3_CLASSES_CB3STATICTRACK_H

#include "b3/GtMath.h"

struct CB3BackdropObject;
class CB3StaticTrack;

class CB3StaticTrack {
public:
    void Construct();
    void Destruct();
    void RenderBackdrop(const CB3BackdropObject& p0);

    unsigned char field_0;
    unsigned char pad_1[0x3];
    int field_4;
    int field_8;
    int field_C;
};

#endif
