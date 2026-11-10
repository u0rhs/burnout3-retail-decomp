// CB3HardCodedTrackRegionList -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HARDCODEDTRACKREGIONLIST_H
#define B3_CLASSES_CB3HARDCODEDTRACKREGIONLIST_H

#include "b3/classes/EB3TrackRegion.h"

class CB3HardCodedTrackRegionList;

class CB3HardCodedTrackRegionList {
public:
    static int GetFakeMipImage(EB3TrackRegion p0, int p1);
    static int GetSatMapImage(EB3TrackRegion p0, int p1);
    static int GetZoomImage(EB3TrackRegion p0, int p1);

    unsigned char pad_0[0x1];
};

#endif
