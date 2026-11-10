// CB3PageTextComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PAGETEXTCOMPONENT_H
#define B3_CLASSES_CB3PAGETEXTCOMPONENT_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

#include "b3/classes/EGlobalStrings.h"

class CB3PageTextComponent;

class CB3PageTextComponent {
public:
    void Construct();
    void Prepare(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, EGlobalStrings p2, unsigned int p3);

    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

#endif
