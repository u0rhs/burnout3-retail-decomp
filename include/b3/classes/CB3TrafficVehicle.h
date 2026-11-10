// CB3TrafficVehicle -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICVEHICLE_H
#define B3_CLASSES_CB3TRAFFICVEHICLE_H

#include "b3/GtMath.h"

#include "b3/classes/CB3TrafficAxle.h"

class CB3TrafficParam;
class CB3TrafficVehicle;

class CB3TrafficVehicle {
public:
    void Construct();
    int Prepare();
    void Release();
    void RemoveFromLanes();
    void ResetMemberVariables();

    unsigned char pad_0[0x30];
    CB3TrafficAxle field_30;
    unsigned char pad_31[0x7F];
    int field_B0;
    unsigned char pad_B4[0x5C];
    CB3TrafficVehicle * field_110;
    CB3TrafficParam * field_114;
    int field_118;
    float field_11C;
    unsigned char pad_120[0x4C];
    void * field_16C;
    unsigned char pad_170[0x4];
    unsigned char field_174;
    unsigned char pad_175[0x5];
    unsigned char field_17A;
};

#endif
