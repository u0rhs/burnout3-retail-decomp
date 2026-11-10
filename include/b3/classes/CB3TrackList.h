// CB3TrackList -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRACKLIST_H
#define B3_CLASSES_CB3TRACKLIST_H

#include "b3/GtMath.h"

class CB3TrackList;

class CB3TrackList {
public:
    void CreateTrackPathFromID(unsigned long p0, char* p1, int p2);
    void CreateTrackPathFromIndex(int p0, char* p1, int p2);
    int DoesTrackExist(unsigned long);
    int GetTrackIndexFromID(unsigned long p0);
    int GetTrackRegion(unsigned long p0);
    bool IsTrackMarathon(unsigned long p0);
    bool IsTrackPointToPoint(unsigned long p0);

    unsigned char pad_0[0x4];
    int field_4;
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x3FC];
    unsigned long field_408[1];  // [G] element count unknown
};

#endif
