// CB3RadialBlur -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3RADIALBLUR_H
#define B3_CLASSES_CB3RADIALBLUR_H

#include "b3/GtMathPs2.h"

class CB3RadialBlur;

class CB3RadialBlur {
public:
    int Prepare();

    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    int field_1C;
    GtMathPs2::CGtV3d field_20;
    unsigned char field_30;
    unsigned char pad_31[0xF];
    int field_40;
};

#endif
