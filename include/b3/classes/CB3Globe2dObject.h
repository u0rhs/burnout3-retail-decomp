// CB3Globe2dObject -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3GLOBE2DOBJECT_H
#define B3_CLASSES_CB3GLOBE2DOBJECT_H

#include "b3/GtMath.h"

class CB3Globe2dObject;

class CB3Globe2dObject {
public:
    static int gmpStaticGlobeData;
    void SetGlobeLocation(float p0, float p1);
    void SetHighlight(signed char p0, float p1);
    void SetShape(float p0, float p1);

    unsigned char pad_0[0x2C];
    short field_2C;
    short field_2E;
    short field_30;
    short field_32;
    unsigned char pad_34[0x2];
    unsigned char field_36;
    unsigned char field_37;
};

#endif
