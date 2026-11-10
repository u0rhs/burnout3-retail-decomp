// CB3OnlineRoadRageRaceLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINEROADRAGERACELOGIC_H
#define B3_CLASSES_CB3ONLINEROADRAGERACELOGIC_H

#include "b3/GtMath.h"

#include "b3/classes/EB3DamageType.h"

class CB3OnlineRoadRageRaceLogic;
class CB3RaceCar;
class CB3RaceCarPhysics;

class CB3OnlineRoadRageRaceLogic {
public:
    void DamageRaceCar(CB3RaceCar* p0, CB3RaceCar* p1, EB3DamageType p2);
    void OnPostCrashReset(CB3RaceCarPhysics* p0);

    unsigned char pad_0[0x1];
};

#endif
