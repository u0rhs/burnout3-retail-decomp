// CB3TableComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TABLECOMPONENT_H
#define B3_CLASSES_CB3TABLECOMPONENT_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

class CB3TableComponent;
class CGt2dFrame;

class CB3TableComponent {
public:
    void Construct();
    void GetImageAndTextSize(GtMathPs2::CGtV2d* p0, const CGt2dFrame& p1, const void* p2);

    float field_0;
    float field_4;
    unsigned char pad_8[0x4];
    int field_C;
};

#endif
