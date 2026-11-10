// CB3StartPoint -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STARTPOINT_H
#define B3_CLASSES_CB3STARTPOINT_H

#include "b3/GtMath.h"

class CB3StartPoint;
class CB3StartPositionStruct;

class CB3StartPoint {
public:
    void Construct();
    void Destruct();
    int Prepare(CB3StartPositionStruct* p0);
    void Release();

    CB3StartPositionStruct * field_0;
};

#endif
