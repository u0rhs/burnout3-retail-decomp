// CB3OnlineStageLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINESTAGELOGIC_H
#define B3_CLASSES_CB3ONLINESTAGELOGIC_H

#include "b3/GtMath.h"

class CB3OnlineStageLogic;
class CB3RaceCar;

class CB3OnlineStageLogic {
public:
    void OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1);
    int StartReplay();

    unsigned char pad_0[0x4];
    unsigned char field_4;
};

#endif
