// CB3PropManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PROPMANAGER_H
#define B3_CLASSES_CB3PROPMANAGER_H

#include "b3/GtMath.h"

class CB3PropManager;

class CB3PropManager {
public:
    void Construct();
    void Update();

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    short field_10;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    int field_14;
    int field_18;
};

#endif
