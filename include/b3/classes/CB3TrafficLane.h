// CB3TrafficLane -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICLANE_H
#define B3_CLASSES_CB3TRAFFICLANE_H

#include "b3/GtMath.h"

class CB3TrafficLane;
struct UnkStruct_00160590_1;
struct UnkStruct_00160590_e0;

struct UnkStruct_00160590_1 {
    unsigned char pad_0[0x10];
    UnkStruct_00160590_e0 * field_10;
};

struct UnkStruct_00160590_e0 {
    unsigned char pad_0[0x1];
};

class CB3TrafficLane {
public:
    void * Prepare(int p0, unsigned char p1);
    void Release();

    UnkStruct_00160590_1 * field_0;
    short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
    unsigned char field_47;
    unsigned char field_48;
    unsigned char field_49;
};

#endif
