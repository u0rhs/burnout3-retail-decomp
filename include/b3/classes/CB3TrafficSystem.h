// CB3TrafficSystem -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICSYSTEM_H
#define B3_CLASSES_CB3TRAFFICSYSTEM_H

#include "b3/GtMath.h"

class CB3TrafficParam;
class CB3TrafficSystem;
struct UnkStruct_00167B90_e2;

struct UnkStruct_00167B90_e2 {
    unsigned char pad_0[0x180];
};

class CB3TrafficSystem {
public:
    void AddToDeadTrafficParamList(CB3TrafficParam*);
    void Construct();

    UnkStruct_00167B90_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_180[0x34210];
    unsigned long field_34390[1];  // [G] element count unknown
    unsigned char pad_34398[0x58];
    int field_343F0[1];  // [G] element count unknown
    unsigned char pad_343F4[0x5C];
    unsigned char field_34450;
    unsigned char pad_34451[0x30A7];
    int field_374F8;
    int field_374FC;
};

#endif
