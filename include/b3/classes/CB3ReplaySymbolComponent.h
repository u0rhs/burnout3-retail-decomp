// CB3ReplaySymbolComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3REPLAYSYMBOLCOMPONENT_H
#define B3_CLASSES_CB3REPLAYSYMBOLCOMPONENT_H

#include "b3/GtMath.h"

class CB3ReplaySymbolComponent;

class CB3ReplaySymbolComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
