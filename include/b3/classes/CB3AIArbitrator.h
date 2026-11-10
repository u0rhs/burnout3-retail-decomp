// CB3AIArbitrator -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AIARBITRATOR_H
#define B3_CLASSES_CB3AIARBITRATOR_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

#include "b3/classes/CB3AIAvoidance.h"

class CB3AIArbitrator;

class CB3AIArbitrator {
public:
    void Construct();
    int Prepare();
    void Release();

    unsigned char pad_0[0x2B0];
    CB3AIAvoidance field_2B0;
    unsigned char pad_760[0x10];
    GtMathPs2::CGtV3d field_770;
    int field_780;
    int field_784;
    unsigned char field_788;
    unsigned char field_789;
    unsigned char pad_78A[0x2];
    int field_78C;
    int field_790;
    int field_794;
    unsigned char field_798;
};

#endif
