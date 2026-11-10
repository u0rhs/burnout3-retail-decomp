// CB3OfflineSingleRaceLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3OFFLINESINGLERACELOGIC_H
#define B3_CLASSES_CB3OFFLINESINGLERACELOGIC_H

#include "b3/GtMath.h"

class CB3OfflineSingleRaceLogic;
class CB3RaceCar;

class CB3OfflineSingleRaceLogic {
public:
    int GetHUDType();
    int GetScoreModeFlags();
    void OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1);

    unsigned char pad_0[0x1];
};

#endif
