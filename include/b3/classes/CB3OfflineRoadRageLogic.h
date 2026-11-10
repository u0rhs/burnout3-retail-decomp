// CB3OfflineRoadRageLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3OFFLINEROADRAGELOGIC_H
#define B3_CLASSES_CB3OFFLINEROADRAGELOGIC_H

#include "b3/GtMath.h"

class CB3OfflineRoadRageLogic;
class CB3RaceCar;

class CB3OfflineRoadRageLogic {
public:
    int GetHUDType();
    int GetScoreModeFlags();
    void RaceCarKilled(CB3RaceCar*, CB3RaceCar*);

    unsigned char pad_0[0x1];
};

#endif
