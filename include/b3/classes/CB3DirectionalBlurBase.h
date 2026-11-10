// CB3DirectionalBlurBase -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3DIRECTIONALBLURBASE_H
#define B3_CLASSES_CB3DIRECTIONALBLURBASE_H

#include "b3/GtMathPs2.h"

class CB3DirectionalBlurBase;

class CB3DirectionalBlurBase {
public:
    int Prepare();

    GtMathPs2::CGtV3d field_0;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    float field_24;
};

#endif
