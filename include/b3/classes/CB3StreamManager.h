// CB3StreamManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STREAMMANAGER_H
#define B3_CLASSES_CB3STREAMMANAGER_H

#include "b3/GtMath.h"

class CB3StreamManager;
class CB3StreamedTrackHighData;
class CB3StreamedTrackLODAndCollisionData;

class CB3StreamManager {
public:
    void Construct();
    void Destruct();
    void ReleaseHighDetailUnit(CB3StreamedTrackHighData* p0);
    void ReleaseLODUnit(CB3StreamedTrackLODAndCollisionData* p0);

    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0xB];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x48];
    int field_5C[1];  // [G] element count unknown
    unsigned char pad_60[0x88];
    int field_E8;
    int field_EC;
    int field_F0;
};

#endif
