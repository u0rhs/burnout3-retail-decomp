// CB3OfflineStageLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3OFFLINESTAGELOGIC_H
#define B3_CLASSES_CB3OFFLINESTAGELOGIC_H

#include "b3/GtMath.h"

class CB3OfflineStageLogic;
class CB3RaceCar;
struct UnkStruct_003957D0_e0;

struct UnkStruct_003957D0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

class CB3OfflineStageLogic {
public:
    void Construct();
    void OnTakedown(CB3RaceCar*, CB3RaceCar*);

    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x1A];
    UnkStruct_003957D0_e0 field_20[1];  // [G] element count unknown
    unsigned char pad_30[0x10];
    int field_40;
};

#endif
